<?hh

class test {
    function  __toString() {
        return "10";
    }
}
<<__EntryPoint>> function main(): void {
$r = fopen(__FILE__, "r");

$o = new test;

$vars = varray[
    "string",
    "8754456",
    "",
    "\0",
    9876545,
    0.10,
    array(),
    varray[1,2,3],
    false,
    true,
    NULL,
    $r,
    $o
];

foreach ($vars as $var) {
    $tmp = (bool)$var;
    var_dump($tmp);
}

echo "Done\n";
}
