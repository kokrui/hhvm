<?hh <<__EntryPoint>> function main(): void {
$vals = vec[
"
 ",
" ",
" 123",
" 123.01 ",
];

foreach ($vals as $var) {
    var_dump(filter_var($var, FILTER_VALIDATE_FLOAT));
}
}
