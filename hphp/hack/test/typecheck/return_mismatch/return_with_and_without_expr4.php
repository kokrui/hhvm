<?hh
// Copyright 2004-present Facebook. All Rights Reserved.

function test(bool $b): void {
  if ($b) {
    return 42;
  } else {
    return;
  }
}
