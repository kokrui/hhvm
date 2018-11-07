<?hh

class B {
  public function f() {
    var_dump("hellooooo");
  }
}

class C<reified T> {
  public function f() {
    var_dump("yep!");
    $b = new T();
    $b->f();
  }
}

class D<reified T> {
  function f<reified T1>() {
    $x = () ==> {
      $c = new T1<reified T>();
      $c->f();
    };
    $x();
  }
}

$d = new D<reified B>();
$d->f<reified C>();
