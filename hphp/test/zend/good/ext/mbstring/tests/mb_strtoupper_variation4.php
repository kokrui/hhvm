<?hh
/* Prototype  : string mb_strtoupper(string $sourcestring [, string $encoding]
 * Description: Returns a uppercased version of $sourcestring
 * Source code: ext/mbstring/mbstring.c
 */

/*
 * Pass characters from different languages to check that mb_strtoupper is
 * doing a correct case conversion
 */
<<__EntryPoint>> function main(): void {
echo "*** Testing mb_strtoupper() : usage variations ***\n";

$uppers = dict['Basic Latin' => b'ABCDEFGHIJKLMNOPQRSTUVWXYZ',
                'Characters With Accents' => base64_decode('w4DDgcOCw4PDhMOFw4bDh8OIw4nDisOLw4zDjcOOw4/DkMORw5LDk8OUw5XDlg=='),
                'Russian' => base64_decode('0JDQkdCS0JPQlNCV0JbQlw==')];
$lowers = dict['Basic Latin' => b'abcdefghijklmnopqrstuvwxyz',
                'Characters With Accents' => base64_decode('w6DDocOiw6PDpMOlw6bDp8Oow6nDqsOrw6zDrcOuw6/DsMOxw7LDs8O0w7XDtg=='),
                'Russian' => base64_decode('0LDQsdCy0LPQtNC10LbQtw==')];

foreach ($lowers as $lang => $sourcestring) {
    echo "\n-- $lang --\n";
    $a = mb_strtoupper($sourcestring, 'UTF-8');
    var_dump(base64_encode($a));
    if ($a == $uppers[$lang]) {
        echo "Correctly Converted\n";
    } else {
        echo "Incorrectly Converted\n";
    }
}

echo "Done";
}
