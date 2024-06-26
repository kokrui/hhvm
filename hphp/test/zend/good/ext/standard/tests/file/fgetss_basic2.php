<?hh
/*
 Prototype: string fgetss ( resource $handle [, int $length [, string $allowable_tags]] );
 Description: Gets line from file pointer and strip HTML tags
*/

/* try fgetss on files which are opened in read/write modes
    w+, w+b, w+t,
    a+, a+b, a+t,
    x+, x+b, x+t
*/

<<__EntryPoint>> function main(): void {
echo "*** Testing fgetss() : basic operations ***\n";

/* string with html and php tags */
$string_with_tags = <<<EOT
<test>Testing fgetss() functions</test>
<?hh echo "this string is within php tag"; ?> {;}<{> this
is a heredoc string. <pg>ksklnm@@$$&$&^%&^%&^%&</pg>
<html> html </html> <?hh echo "php"; ?>
EOT;

$filename = sys_get_temp_dir().'/'.'fgetss_basic2.tmp';

/* try reading the file opened in different modes of reading */
$file_modes = vec["w+","w+b", "w+t","a+", "a+b", "a+t","x+","x+b","x+t"];

for($mode_counter = 0; $mode_counter < count($file_modes); $mode_counter++) {
  echo "\n-- Testing fgetss() with file opened using $file_modes[$mode_counter] mode --\n";

  /* create an empty file and write the strings with tags */
  $file_handle = fopen($filename, $file_modes[$mode_counter]);
  fwrite($file_handle,$string_with_tags); //writing data to the file
  if(!$file_handle) {
    echo "Error: failed to open file $filename!\n";
    exit();
  }
  
  // rewind the file pointer to beginning of the file
  var_dump( filesize($filename) );
  var_dump( rewind($file_handle) );
  var_dump( ftell($file_handle) );
  var_dump( feof($file_handle) );

  /* read entire file and strip tags */
  echo "-- fgetss() with default length, file pointer at 0 --\n";
  var_dump( fgetss($file_handle) ); // no length and allowable tags provided, reads entire file
  var_dump( ftell($file_handle) );
  var_dump( feof($file_handle) );

  rewind($file_handle);
  /* read entire file and strip tags tags */
  echo "-- fgets() with length = 30, file pointer at 0 --\n";
  var_dump( fgetss($file_handle ,30) ); // length parameter given,not reading entire file
  var_dump( ftell($file_handle) ); // checking file pointer position initially
  var_dump( feof($file_handle) ); // confirm file pointer is not at eof
 
  // close the file 
  fclose($file_handle);
   
  // delete the file 
  unlink($filename);
} // end of for - mode_counter

echo "Done\n";
}
