<?hh
/* Prototype  : bool usort(&array $array_arg, string $cmp_function)
 * Description: Sort an array by values using a user-defined comparison function
 * Source code: ext/standard/array.c
 */

/*
 * Pass arrays of numeric data to usort() to test how it is re-ordered
 */

function cmp_function($value1, $value2)
:mixed{
  if($value1 == $value2) {
    return 0;
  }
  else if($value1 > $value2) {
    return 1;
  }
  else {
    return -1;
  }
}
<<__EntryPoint>> function main(): void {
echo "*** Testing usort() : usage variation ***\n";

// Int array
$int_values = dict[0 => 3,   1 => 2,   3 => 100,
                    4 => 150, 5 => 25,  6 => 350,
                    7 => 0,   8 => -3,  9 => -1200];

echo "\n-- Sorting Integer array --\n";
var_dump( usort(inout $int_values, cmp_function<>) );
var_dump($int_values);

// Octal array
$octal_values = dict[0 => 056, 1 => 023, 2 => 0,
                      3 => 015, 4 => -045, 5 => 01,  6 => -07];

echo "\n-- Sorting Octal array --\n";
var_dump( usort(inout $octal_values, cmp_function<>) );
var_dump($octal_values);

// Hexadecimal array
$hex_values = dict[0 => 0xAE,  1 => 0x2B, 2 => 0X10,
                    3 => -0xCF, 4 => 0X12, 5 => -0XF2];

echo "\n-- Sorting Hex array --\n";
var_dump( usort(inout $hex_values, cmp_function<>) );
var_dump($hex_values);

// Float array
$float_values = dict[ 0 => 10.2, 1 => 2.4, 2 => -3.4,
                       3 => 0,    4 => 0.5, 5 => 7.3e3, 6 => -9.34E-2];

echo "\n-- Sorting Float array --\n";
var_dump( usort(inout $float_values, cmp_function<>) );
var_dump($float_values);

// empty array
$empty_array = vec[];

echo "\n-- Sorting empty array --\n";
var_dump( usort(inout $empty_array, cmp_function<>) );
var_dump($empty_array);
echo "===DONE===\n";
}
