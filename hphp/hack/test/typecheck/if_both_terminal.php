<?hh
/**
 * Copyright (c) 2014, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the "hack" directory of this source tree.
 *
 *
 */

function g(int $x): void {}

function f(): void {
  $x = 2;
  foreach (vec[] as $_) {
    g($x);

    if (true) {
      continue;
    } else {
      $x = null;
      return;
    }
  }
}
