////file1.php
<?hh

<<file:__EnableUnstableFeatures('newtype_super_bounds')>>
newtype X super int = arraykey;
////file2.php
<?hh

function test(float $f): X {
  return $f;
}
