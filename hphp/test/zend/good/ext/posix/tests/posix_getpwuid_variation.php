<?hh
/* Prototype  : proto array posix_getpwuid(long uid)
 * Description: User database access (POSIX.1, 9.2.2)
 * Source code: ext/posix/posix.c
 * Alias to functions:
 */
<<__EntryPoint>>
function main(): void {
  echo "*** Testing posix_getpwuid() : usage variations ***\n";

  // Initialise function arguments not being substituted (if any)


  //array of values to iterate over
  $values = varray[

    // float data
    10.5,
    -10.5,
    10.1234567e10,
    10.7654321E-10,
    .5,


    // null data
    NULL,
    null,

    // boolean data
    true,
    false,
    TRUE,
    FALSE,

    // empty data
    "",
    '',

    // string data
    "string",
    'string',


    // object data
    new stdClass(),
  ];

  // loop through each element of the array for uid

  foreach ($values as $value) {
    $value__str = (string)($value);
    echo "\nArg value $value__str\n";
    try {
      $result = posix_getpwuid($value);
      if ((is_array($result) && (count($result) == 7)) || ($result === false)) {
        echo "valid output\n";
      } else {
        var_dump($result);
      }
    } catch (Exception $e) {
      echo "\n".
        'Warning: '.
        $e->getMessage().
        ' in '.
        __FILE__.
        ' on line '.
        __LINE__.
        "\n";
    }
  }
  ;

  echo "Done";
}
