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

function without_arg(): void {
  foreach (varray[1, 2, 3] as $a) {
    foreach (varray[1, 2, 3, 4] as $b) {
      foreach (varray[1, 2, 3, 4] as $c) {
        continue;
      }
    }
  }
}
