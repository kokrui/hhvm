<?hh
/* Prototype: float floatval( mixed $var );
 * Description: Returns the float value of var.
 */
<<__EntryPoint>> function main(): void {
echo "*** Testing floatval() with valid float values ***\n";
// different valid  float values
$valid_floats = vec[
                0.0,
                1.0,
                -1.0,
                1.234,
             -1.234,
                1.2e3,
            -1.2e3,
        10.0000000000000000005,
        10.5e+5,
                1e5,
            -1e5,
                1e-5,
        -1e-1,
        1e+5,
        -1e+5,
        1E5,
        -1E5,
        1E+5,
        -1E+5,
        .5e+7,
        -.5e+7
];

/* loop to check that floatval() recognizes different
   float values, expected output:float value for valid floating point number */

foreach ($valid_floats as $value ) {
   var_dump( floatval($value) );
}


echo "\n*** Testing doubleval() with valid float values ***\n";
/* loop to check that doubleval() also recognizes different
   float values, expected output:float value for valid floating point number */

foreach ($valid_floats as $value ) {
   var_dump( doubleval($value) );
}


echo "\n*** Testing floatval() on non floating types ***\n";

// get a resource type variable
$fp = fopen (__FILE__, "r");
fclose($fp);
$dfp = opendir ( dirname(__FILE__) );
closedir($dfp);

// other types in an array
$not_float_types = vec[
                   -2147483648, // max negative integer value
                   2147483648,  // max positive integer value
                   $fp,  // resource
                   $dfp,
                   "0.0", // string
                   "1.0",
               "-1.3e3",
           "bob-1.3e3",
                   "10 Some dollars",
               "10.2 Some Dollars",
                  HH\Lib\Legacy_FIXME\cast_for_arithmetic("10.0 dollar") + 1,
           HH\Lib\Legacy_FIXME\cast_for_arithmetic("10.0 dollar") + 1.0,
                   "",
                   true,
                   NULL,
                   null,
                 ];
/* loop through the $not_float_types to see working of
   floatval() on non float types, expected output: float value valid floating point numbers */
foreach ($not_float_types as $type ) {
   var_dump( floatval($type) );
}


echo "\n*** Testing doubleval() on non floating types ***\n";

/* loop through the $not_float_types to see working of
   doubleval() on non float types, expected output: float value valid floating point numbers */
foreach ($not_float_types as $type ) {
   var_dump( doubleval($type) );
}




echo "\n*** Testing error conditions ***\n";
//Zero argument
try { var_dump( floatval() ); } catch (Exception $e) { echo "\n".'Warning: '.$e->getMessage().' in '.__FILE__.' on line '.__LINE__."\n"; }
try { var_dump( doubleval() ); } catch (Exception $e) { echo "\n".'Warning: '.$e->getMessage().' in '.__FILE__.' on line '.__LINE__."\n"; }

//arguments more than expected
try { var_dump( floatval(TRUE, FALSE) ); } catch (Exception $e) { echo "\n".'Warning: '.$e->getMessage().' in '.__FILE__.' on line '.__LINE__."\n"; }
try { var_dump( doubleval(TRUE, FALSE) ); } catch (Exception $e) { echo "\n".'Warning: '.$e->getMessage().' in '.__FILE__.' on line '.__LINE__."\n"; }

echo "\nDone\n";
}
