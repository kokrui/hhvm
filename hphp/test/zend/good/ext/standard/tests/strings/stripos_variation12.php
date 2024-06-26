<?hh
/* Prototype  : int stripos ( string $haystack, string $needle [, int $offset] );
 * Description: Find position of first occurrence of a case-insensitive string
 * Source code: ext/standard/string.c
*/

/* Test stripos() function with null terminated strings for 'haystack' argument 
 *  in order to check the binary safe 
*/
<<__EntryPoint>> function main(): void {
echo "*** Test stripos() function: binary safe ***\n";
$haystacks = vec[
  "Hello".chr(0)."World",
  chr(0)."Hello World",
  "Hello World".chr(0),
  chr(0).chr(0).chr(0),
  "Hello\0world",
  "\0Hello",
  "Hello\0"
];

for($index = 0; $index < count($haystacks); $index++ ) {
  var_dump( stripos($haystacks[$index], "\0") );
  var_dump( stripos($haystacks[$index], "\0", $index) );
}
echo "*** Done ***";
}
