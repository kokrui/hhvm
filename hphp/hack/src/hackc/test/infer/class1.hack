// RUN: %hackc compile-infer %s | FileCheck %s

// TEST-CHECK-BAL: define C._86pinit
// CHECK: define C._86pinit($this: *C) : *HackMixed {
// CHECK: #b0:
// CHECK:   ret null
// CHECK: }

class C {
  const A = 5;
}

// TEST-CHECK-BAL: define D._86pinit
// CHECK: define D._86pinit($this: *D) : *HackMixed {
// CHECK: #b0:
// CHECK:   n0: *D = load &$this
// CHECK:   n1 = C._86pinit(n0)
// CHECK:   ret null
// CHECK: }

class D extends C { }

// TEST-CHECK-BAL: define E._86pinit
// CHECK: define E._86pinit($this: *E) : *HackMixed {
// CHECK: #b0:
// CHECK:   n0: *E = load &$this
// CHECK:   n1 = D._86pinit(n0)
// CHECK:   n2 = null
// CHECK:   n3: *HackMixed = load &$this
// CHECK:   store n3.?.prop <- n2: *HackMixed
// CHECK:   jmp b1, b2
// CHECK: #b1:
// CHECK:   prune $builtins.hack_is_true($builtins.hack_bool(false))
// CHECK:   jmp b3
// CHECK: #b2:
// CHECK:   prune ! $builtins.hack_is_true($builtins.hack_bool(false))
// CHECK:   n4 = __sil_lazy_class_initialize(<C>)
// CHECK:   n5 = $builtins.hack_field_get(n4, "A")
// CHECK:   n6: *HackMixed = load &$this
// CHECK:   store n6.?.prop <- n5: *HackMixed
// CHECK:   jmp b3
// CHECK: #b3:
// CHECK:   ret null
// CHECK: }

class E extends D {
  public int $prop = C::A;
}
