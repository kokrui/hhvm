<?hh
// Copyright 2004-present Facebook. All Rights Reserved.

function get_int(): int {
  return 0;
}

function test(): void {
  $_ = ((int, int) $mt = tuple(get_int(), get_int())): void ==> {};
}

class A {
  public function test(): void {
    $_ = ((int, int) $mt = tuple(get_int(), get_int())): void ==> {};
  }
}
