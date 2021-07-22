<?hh // partial
// generated by idl-to-hni.php

namespace {
/** Serialize data into a compact format that can be unserialized by
 * fb_unserialize().
 *
 * @param mixed $thing - What to serialize. Note that objects are not
 * supported.
 * @param options bitmask of options:
 *
 * FB_SERIALIZE_VARRAY_DARRAY
 * FB_SERIALIZE_HACK_ARRAYS
 * FB_SERIALIZE_HACK_ARRAYS_AND_KEYSETS
 * FB_SERIALIZE_POST_HACK_ARRAY_MIGRATION
 *
 * Of these options, the last one is the best to use: it works on vecs, dicts,
 * and keysets, and deserializes the result with no change to types or values.
 *
 * All other modes are deficient to the post-HAM mode in some way:
 *
 *  - VARRAY_DARRAY rejects keysets, and does intish-cast-ing of dict keys.
 *  - HACK_ARRAYS rejects keysets, and converts legacy vecs inputs to dicts.
 *  - HACK_ARRAYS_AND_KEYSETS converts legacy vec inputs to dicts.
 *
 * @return mixed - Serialized data.
 */
<<__Native>>
function fb_serialize(mixed $thing, int $options = 0)[]: mixed;

/** Unserialize previously fb_serialize()-ed data.
 * @param mixed $thing - What to unserialize.
 * @param mixed $success - Whether it was successful or not.
 * @param options bitmask of options (see fb_serialize for details)
 * @return mixed - Unserialized data.
 */
<<__Native>>
function fb_unserialize(mixed $thing,
                        <<__OutOnly("KindOfBoolean")>>
                        inout mixed $success,
                        int $options = 0): mixed;

/** Serialize data into a compact format that can be unserialized by
 * fb_compact_unserialize(). In general produces smaller output compared to
 * fb_serialize(). Largest savings are on arrays with sequential (or almost
 * sequential) indexes, i.e. simple arrays like array($a, $b, $c). NOTE:
 * unlike serialize(), does not preserve internal references, i.e. array(&$a,
 * &$a) will become array($a, $a).
 * @param mixed $thing - What to serialize. Note that objects are not
 * supported.
 * @param options bitmask of options:
 *  - FB_COMPACT_SERIALIZE_FORCE_PHP_ARRAYS: use the legacy encoding format
 *    for vecs and dicts, matching varrays and darrays. This format is always
 *    more compact than the Hack array format, and produces the same darray
 *    results on deserialization, so we want to make it the new default.
 * @return mixed - Serialized data.
 */
<<__Native>>
function fb_compact_serialize(mixed $thing, int $options = 0)[]: mixed;

/** Unserialize a previously fb_compact_serialize()-ed data.
 * @param mixed $thing - What to unserialize.
 * @param mixed $success - Whether it was successful or not.
 * @param mixed $errcode - One of those FB_UNSERIALIZE_ constants to describe
 * what the decoding error was, if it failed.
 * @return mixed - Unserialized data.
 */
<<__Native>>
function fb_compact_unserialize(mixed $thing,
                                <<__OutOnly("KindOfBoolean")>>
                                inout mixed $success,
                                <<__OutOnly>>
                                inout mixed $errcode): mixed;

/**
 * Invokes a user handler upon calling a function or a class method. This
 * handler is expected to have signature similar to:
 *
 *   function intercept_handler($name, $obj, $params)
 *
 * Where $name is original function's fully-qualified name ('Class::method'),
 * $obj is $this for an instance method call or null for static method call or
 * function calls and $params are original call's parameters.
 *
 * This handler is expected to return a shape where if the shape contains
 * 'value' field, then this value is returned as the result of the original
 * function, if the shape contains 'callback' field, then the callback is
 * called as the result of the original function, if the shape contains
 * 'prepend_this' field, then 'this' or lsb class is prepended as the first
 * argument to the callback, if neither value nor callback is given, then the
 * original function is executed.
 *
 * If the function does not return a shape, then a runtime exception is raised.
 * Signature of the callback and the original function are required to be the
 * same including the arity and parity of reified arguments, otherwise, the
 * regular error mechanism will raise an error/throw an exception accordingly.
 * Note that built-in functions are not interceptable.
 * @param string $name - The function or class method name to intercept. Use
 * "class::method" for method name.
 * @param mixed $handler - Callback to handle the interception. Use null,
 * false or empty string to unregister a previously registered handler. If
 * name is empty, all previously registered handlers, including those that are
 * set by individual function names, will be removed.
 * @return bool - TRUE if successful, FALSE otherwise
 */
<<__Native>>
function fb_intercept2(string $name, mixed $handler): bool;

/** Rename a function, so that a function can be called with the new name.
 * When writing unit tests, one may want to stub out a function. To do so,
 * call fb_rename_function('func_to_stub_out', 'somename') then
 * fb_rename_function('new_func_to_replace_with', 'func_to_stub_out'). This
 * way, when calling func_to_stub_out(), it will actually execute
 * new_func_to_replace_with().
 * @param string $orig_func_name - Which function to rename.
 * @param string $new_func_name - What is the new name.
 * @return bool - TRUE if successful, FALSE otherwise.
 */
<<__Native("NoFCallBuiltin")>>
function fb_rename_function(string $orig_func_name,
                            string $new_func_name): bool;

/** Sanitize a string to make sure it's legal UTF-8 by stripping off any
 * characters that are not properly encoded.
 * @param mixed $input - What string to sanitize.
 * @return bool - Sanitized string.
 */
<<__Native, __Pure>>
function fb_utf8ize(inout mixed $input): bool;

/** Count the number of UTF-8 code points in string or byte count if it's not
 * valid UTF-8.
 * @param string $input - The string.
 * @return int - Returns the count of code points if valid UTF-8 else byte
 * count.
 */
<<__Native, __IsFoldable, __Pure>>
function fb_utf8_strlen_deprecated(string $input): int;

/** Count the number of UTF-8 code points in string, substituting U+FFFD for
 * invalid sequences.
 * @param string $input - The string.
 * @return int - Returns the number of code points interpreting string as
 * UTF-8.
 */
<<__Native, __IsFoldable>>
function fb_utf8_strlen(string $input)[]: int;

/** Cuts a portion of str specified by the start and length parameters.
 * @param string $str - The original string.
 * @param int $start - If start is non-negative, fb_utf8_substr() cuts the
 * portion out of str beginning at start'th character, counting from zero.  If
 * start is negative, fb_utf8_substr() cuts out the portion beginning at the
 * position, start characters away from the end of str.
 * @param int $length - If length is given and is positive, the return value
 * will contain at most length characters of the portion that begins at start
 * (depending on the length of string).  If negative length is passed,
 * fb_utf8_substr() cuts the portion out of str from the start'th character up
 * to the character that is length characters away from the end of the string.
 * In case start is also negative, the start position is calculated beforehand
 * according to the rule explained above.
 * @return string - Returns the portion of str specified by the start and
 * length parameters.  If str is shorter than start characters long, the empty
 * string will be returned.
 */
<<__Native, __IsFoldable>>
function fb_utf8_substr(string $str,
                        int $start,
                        int $length = PHP_INT_MAX)[]: string;

/** Returns code coverage data collected so far. Turn on code coverage by
 * Eval.RecordCodeCoverage or by using fb_enable_code_coverage and call this
 * function periodically to get results. Eval.CodeCoverageOutputFile allows
 * you to specify an output file to store results at end of a script run from
 * command line. Use this function in server mode to collect results instead.
 * @param bool $flush - Whether to clear data after this function call.
 * @return darray<string,mixed>|false
 */
<<__Native>>
function fb_get_code_coverage(bool $flush): mixed;

/** Enables code coverage. The coverage information is cleared.
 */
<<__Native("NoFCallBuiltin")>>
function fb_enable_code_coverage(): void;

/** Disables and returns code coverage. The coverage information is cleared.
 */
<<__Native("NoFCallBuiltin")>>
function fb_disable_code_coverage(): darray<string, mixed>;

/** Toggles the compression status of HipHop output, if headers have already
 * been sent this may be ignored.
 * @param bool $new_value - The new value for the compression state.
 * @return bool - The old value.
 */
<<__Native>>
function fb_output_compression(bool $new_value): bool;

/** Set a callback function that is called when php tries to exit.
 * @param mixed $function - The callback to invoke. An exception object will
 * be passed to the function
 */
<<__Native>>
function fb_set_exit_callback(mixed $function): void;

/** Get stats on flushing the last data chunk from server.
 * @return int - Total number of bytes flushed since last flush
 */
<<__Native>>
function fb_get_last_flush_size(): int;

/** Gathers the statistics of the file named by filename, like lstat(), except
 * uses cached information from an internal inotify-based mechanism that may
 * not be updated during the duration of a request.
 * @param string $filename - Path to a file or a symbolic link.
 * @return mixed - Same format as the normal php lstat() function.
 */
<<__Native>>
function fb_lazy_lstat(string $filename): mixed;

/** Returns a canonicalized version of the input path that contains no symbolic
 * links, like realpath(), except uses cached information from an internal
 * inotify-based mechanism that may not be updated during the duration of a
 * request.
 * @param string $filename - Fake path to the file.
 * @return string - Real path of the file.
 */
<<__Native>>
function fb_lazy_realpath(string $filename): mixed;

} // namespace

namespace HH {
/** Disables and returns code coverage that contains file to coverage frequency.
 * The coverage information is cleared.
 */
<<__Native("NoFCallBuiltin")>>
function disable_code_coverage_with_frequency(): darray<string, mixed>;

/** Returns an int for the upper (first) 64 bits of an md5 hash of a string.
 * The MD5 hash, usually presented as a hex value, is taken as big endian, and
 * this int result is the signed counterpart to the unsigned upper 64 bits.
 *
 * This function and the _lower version are generally only intended for
 * legacy use cases in which an MD5 hash is used to compute a number
 * of 64 bits or less. These functions are faster and prettier than calling
 * unpack+substr+md5/raw or hexdec+substr+md5. Note that hexdec converts
 * to floating point (information loss) for some 64-bit unsigned values.
 *
 * The faster and quite effective xxhash64 is generally recommended for
 * non-crypto hashing needs when no backward compatibility is needed.
 */
<<__Native, __IsFoldable>>
function non_crypto_md5_upper(string $str)[]: int;

/** Returns an int for the lower (last) 64 bits of an md5 hash of a string.
 * The MD5 hash, usually presented as a hex value, is taken as big endian, and
 * this int result is the signed counterpart to the unsigned lower 64 bits.
 *
 * This function and the _upper version are generally only intended for
 * legacy use cases in which an MD5 hash is used to compute a number
 * of 64 bits or less. These functions are faster and prettier than calling
 * unpack+substr+md5/raw or hexdec+substr+md5. Note that hexdec converts
 * to floating point (information loss) for some 64-bit unsigned values.
 *
 * The faster and quite effective xxhash64 is generally recommended for
 * non-crypto hashing needs when no backward compatibility is needed.
 */
<<__Native, __IsFoldable>>
function non_crypto_md5_lower(string $str)[]: int;

/** Returns the overflow part of multiplying two ints, as if they were unsigned.
 * In other words, this returns the upper 64 bits of the full product of
 * (unsigned)$a and (unsigned)$b. (The lower 64 bits is just `$a * $b`
 * regardless of signed/unsigned).
 */
<<__Native, __IsFoldable, __Pure>>
function int_mul_overflow(int $a, int $b): int;

/** Returns the overflow part of multiplying two ints plus another int, as if
 * they were all unsigned. Specifically, this returns the upper 64 bits of
 * full (unsigned)$a * (unsigned)$b + (unsigned)$bias. $bias can be used to
 * manipulate rounding of the result.
 */
<<__Native, __IsFoldable, __Pure>>
function int_mul_add_overflow(int $a, int $b, int $bias): int;

type INCORRECT_TYPE<T> = T;
} // HH namespace
