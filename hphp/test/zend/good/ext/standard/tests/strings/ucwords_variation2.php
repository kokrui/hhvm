<?hh
/* Prototype  : string ucwords ( string $str )
 * Description: Uppercase the first character of each word in a string
 * Source code: ext/standard/string.c
*/

/*
 * test ucwords() with different string prepared using heredoc
*/
<<__EntryPoint>> function main(): void {
echo "*** Testing ucwords() : usage variations ***\n";

// Null here doc string
$null_string = <<<EOT
EOT;

// Heredoc string with blank line
$blank_line = <<<EOT

EOT;

// here doc with multiline string
$multiline_string = <<<EOT
testing ucword() with
multiline string using
heredoc
EOT;

// here doc with different whitespaces
$diff_whitespaces = <<<EOT
testing\rucword(str)\twith
multiline   string\t\tusing
heredoc\nstring.with\vdifferent\fwhite\vspaces
EOT;

// here doc with numeric values
$numeric_string = <<<EOT
12sting 123string 4567
string\t123string\r12 test\n5test
EOT;

// heredoc with quote chars & slash
$quote_char_string = <<<EOT
it's bright,but i cann't see it.
"things in double quote"
'things in single quote'
this\line is /with\slashs
EOT;

$heredoc_strings = vec[
  $null_string,
  $blank_line,
  $multiline_string,
  $diff_whitespaces,
  $numeric_string,
  $quote_char_string
];

// loop through $heredoc_strings element and check the working on ucwords()
$count = 1;
for($index =0; $index < count($heredoc_strings); $index ++) {
  echo "-- Iteration $count --\n";
  var_dump( ucwords($heredoc_strings[$index]) );
  $count ++;
}

echo "Done\n";
}
