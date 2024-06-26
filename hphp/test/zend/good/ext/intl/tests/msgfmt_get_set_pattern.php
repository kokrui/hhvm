<?hh

/*
 * Get/set pattern.
 */


function ut_main()
:mixed{
    $res_str = '';
    $fmt = ut_msgfmt_create( "en_US", "{0,number} monkeys on {1,number} trees" );

    // Get default patten.
    $res_str .= "Default pattern: '" . ut_msgfmt_get_pattern( $fmt ) . "'\n";
    $res_str .= "Formatting result: " . ut_msgfmt_format( $fmt, dict[0 => 123, 1 => 456] ) . "\n";

    // Set a new pattern.
    $pattern = "{0,number} trees hosting {1,number} monkeys";
    $res = ut_msgfmt_set_pattern( $fmt, $pattern );
    if( $res === false )
        $res_str .= ut_msgfmt_get_error_message( $fmt ) . " (" . ut_msgfmt_get_error_code( $fmt ) . ")\n";

    // Check if the pattern has been changed.
    $res = ut_msgfmt_get_pattern( $fmt );
    if( $res === false )
        $res_str .= ut_msgfmt_get_error_message( $fmt ) . " (" . ut_msgfmt_get_error_code( $fmt ) . ")\n";
    $res_str .= "New pattern: '" . ut_msgfmt_get_pattern( $fmt ) . "'\n";
    $res_str .= "Formatted message: " . ut_msgfmt_format( $fmt, dict[0 => 123, 1 => 456] ) . "\n";

    ut_msgfmt_set_pattern($fmt, str_repeat($pattern, 10));
    $res_str .= "New pattern: '" . ut_msgfmt_get_pattern( $fmt ) . "'\n";
    $res_str .= "Formatted message: " . ut_msgfmt_format( $fmt, dict[0 => 123, 1 => 456] ) . "\n";


    return $res_str;
}

<<__EntryPoint>> function main_entry(): void {
    include_once( 'ut_common.inc' );
    ut_run();
}
