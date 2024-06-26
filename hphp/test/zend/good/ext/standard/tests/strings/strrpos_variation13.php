<?hh
/* Prototype  : int strrpos ( string $haystack, string $needle [, int $offset] );
 * Description: Find position of last occurrence of 'needle' in 'haystack'.
 * Source code: ext/standard/string.c
*/

/* Test strrpos() function with null terminated strings for 'needle' argument 
 *  in order to check binary safe 
*/
<<__EntryPoint>> function main(): void {
echo "*** Test strrpos() function: binary safe ***\n";
$haystack = "\0Hello\0World\0";

$needles = vec[
  "Hello".chr(0)."World",
  chr(0)."Hello\0",
  chr(0),
  "Hello\0world",
  "\0Hello\0world\0",
  "\0Hello",
  "Hello\0"
];

for($index = 0; $index < count($needles); $index++ ) {
  var_dump( strrpos($haystack, $needles[$index]) );
  var_dump( strrpos($haystack, $needles[$index], $index) );
}
echo "*** Done ***";
}
