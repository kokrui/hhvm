<?hh // strict
/**
 * Copyright (c) 2014, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the "hack" directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 *
 */

function foo(): void {
  $y = 2;

  $x = $z ==> $y + $z; // $y is captured
  $l = $x(2);

  $x = function($z) use ($y) {
    return $y + $z; // $y is captured
  }
  $l = $x(2);

  $x = ($a, $b) ==> $a + $b; // no captures
  $l = $x(2, $y)
}
