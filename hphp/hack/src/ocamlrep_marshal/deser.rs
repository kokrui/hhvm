// Initially generated by c2rust of 'intern.c' at revision
// `15553b77175270d987058b386d737ccb939e8d5a` (that is, the 4.14.0 tag).
//
// We tried generating it from `f14c8ff3f8a164685bc24184fba84904391e378e` as
// 'extern.c' was but that proved to be quite incompatible with the 4.14.0
// runtime.

#![allow(
    clippy::upper_case_acronyms,
    mutable_transmutes,
    non_camel_case_types,
    non_snake_case,
    non_upper_case_globals
)]

use libc::c_char;
use libc::c_double;
use libc::c_int;
use libc::c_long;
use libc::c_schar;
use libc::c_short;
use libc::c_uchar;
use libc::c_uint;
use libc::c_ulong;
use libc::c_ushort;
use libc::c_void;
use libc::memcpy;
use libc::snprintf;
use ocamlrep::Header;
use ocamlrep::Value;

use crate::intext::*;

extern "C" {

    pub type mark_stack;
    pub type caml_custom_table;
    pub type caml_ref_table;
    pub type caml_ephe_ref_table;
    pub type longjmp_buffer;
    pub type FILE;

    static mut caml_allocated_words: uintnat;
    static mut Caml_state: *mut caml_domain_state;
    static mut caml_atom_table: *mut header_t;
    static mut caml_fl_p_make_free_blocks:
        Option<unsafe extern "C" fn(_: *mut value, _: mlsize_t, _: c_int, _: c_int) -> ()>;

    fn caml_memprof_track_interned(block: *mut header_t, blockend: *mut header_t);
    fn caml_process_pending_actions();
    fn caml_alloc_shr_no_track_noexc(_: mlsize_t, _: tag_t) -> value;
    fn caml_allocation_color(hp: *mut c_void) -> color_t;
    fn caml_alloc_for_heap(request: asize_t) -> *mut c_char;
    fn caml_free_for_heap(mem: *mut c_char);
    fn caml_add_to_heap(mem: *mut c_char) -> c_int;
    fn caml_failwith(msg: *const c_char) -> !;
    fn caml_invalid_argument(msg: *const c_char) -> !;
    fn caml_stat_alloc_noexc(_: asize_t) -> caml_stat_block;
    fn caml_raise_out_of_memory() -> !;
    fn caml_stat_free(_: caml_stat_block);
    fn caml_alloc_small_dispatch(_: intnat, _: c_int, _: c_int, _: *mut c_uchar);
    fn caml_string_length(_: value) -> mlsize_t;
    fn caml_set_oo_id(obj: value) -> value;
}

pub type size_t = c_ulong;
pub type __int16_t = c_short;
pub type __uint16_t = c_ushort;
pub type __int32_t = c_int;
pub type __uint32_t = c_uint;
pub type __int64_t = c_long;
pub type __uint64_t = c_ulong;
pub type __off_t = c_long;
pub type __off64_t = c_long;

pub type int16_t = __int16_t;
pub type int32_t = __int32_t;
pub type uint16_t = __uint16_t;
pub type uint32_t = __uint32_t;
pub type intnat = c_long;
pub type uintnat = c_ulong;

type asize_t = size_t;
type backtrace_slot = *mut c_void;
type value = intnat;
type header_t = uintnat;
type mlsize_t = uintnat;
type tag_t = c_uint;
type color_t = uintnat;
type extra_params_area = [value; 64];

#[derive(Copy, Clone)]
#[repr(C)]
struct caml_domain_state {
    pub _young_limit: *mut value,
    pub _young_ptr: *mut value,
    pub _exception_pointer: *mut c_char,
    pub _young_base: *mut c_void,
    pub _young_start: *mut value,
    pub _young_end: *mut value,
    pub _young_alloc_start: *mut value,
    pub _young_alloc_end: *mut value,
    pub _young_alloc_mid: *mut value,
    pub _young_trigger: *mut value,
    pub _minor_heap_wsz: asize_t,
    pub _in_minor_collection: intnat,
    pub _extra_heap_resources_minor: c_double,
    pub _ref_table: *mut caml_ref_table,
    pub _ephe_ref_table: *mut caml_ephe_ref_table,
    pub _custom_table: *mut caml_custom_table,
    pub _mark_stack: *mut mark_stack,
    pub _stack_low: *mut value,
    pub _stack_high: *mut value,
    pub _stack_threshold: *mut value,
    pub _extern_sp: *mut value,
    pub _trapsp: *mut value,
    pub _trap_barrier: *mut value,
    pub _external_raise: *mut longjmp_buffer,
    pub _exn_bucket: value,
    pub _top_of_stack: *mut c_char,
    pub _bottom_of_stack: *mut c_char,
    pub _last_return_address: uintnat,
    pub _gc_regs: *mut value,
    pub _backtrace_active: intnat,
    pub _backtrace_pos: intnat,
    pub _backtrace_buffer: *mut backtrace_slot,
    pub _backtrace_last_exn: value,
    pub _compare_unordered: intnat,
    pub _requested_major_slice: intnat,
    pub _requested_minor_gc: intnat,
    pub _local_roots: *mut caml__roots_block,
    pub _stat_minor_words: c_double,
    pub _stat_promoted_words: c_double,
    pub _stat_major_words: c_double,
    pub _stat_minor_collections: intnat,
    pub _stat_major_collections: intnat,
    pub _stat_heap_wsz: intnat,
    pub _stat_top_heap_wsz: intnat,
    pub _stat_compactions: intnat,
    pub _stat_forced_major_collections: intnat,
    pub _stat_heap_chunks: intnat,
    pub _eventlog_startup_timestamp: uintnat,
    pub _eventlog_startup_pid: c_long,
    pub _eventlog_paused: uintnat,
    pub _eventlog_enabled: uintnat,
    pub _eventlog_out: *mut FILE,
    pub _extra_params: extra_params_area,
}

#[derive(Copy, Clone)]
#[repr(C)]
struct caml__roots_block {
    pub next: *mut caml__roots_block,
    pub ntables: intnat,
    pub nitems: intnat,
    pub tables: [*mut value; 5],
}

#[derive(Copy, Clone)]
#[repr(C)]
pub struct marshal_header {
    pub magic: uint32_t,
    pub header_len: c_int,
    pub data_len: uintnat,
    pub num_objects: uintnat,
    pub whsize: uintnat,
}

#[derive(Copy, Clone)]
#[repr(C)]
pub struct intern_item<'a> {
    pub dest: *mut Value<'a>,
    pub arg: intnat,
    pub op: c_uint,
}

pub const OReadItems: c_uint = 0; // read arg items and store them in dest[0], dest[1], ...
pub const OFreshOID: c_uint = 1; // generate a fresh OID and store it in *dest
pub const OShift: c_uint = 2; // offset *dest by arg

pub type caml_stat_block = *mut c_void;

#[derive(Copy, Clone)]
#[repr(C)]
pub struct heap_chunk_head {
    pub block: *mut c_void,
    pub allocated: asize_t,
    pub size: asize_t,
    pub next: *mut c_char,
    pub redarken_first: mark_entry,
    pub redarken_end: *mut value,
}

#[derive(Copy, Clone)]
#[repr(C)]
pub struct mark_entry {
    pub start: *mut value,
    pub end: *mut value,
}

pub const CAML_FROM_C: caml_alloc_small_flags = 0;
pub const CAML_DONT_TRACK: caml_alloc_small_flags = 0;
pub type caml_alloc_small_flags = c_uint;

// 'config.h'
pub const PAGE_LOG: usize = 12; // A page is 4 kilobytes
pub const PAGE_SIZE: usize = (1_isize << PAGE_LOG) as usize;
// Maximum size of a block allocated in the young generation (words).
// Must be > 4
pub const MAX_YOUNG_WOSIZE: usize = 256;

// ---

#[inline]
unsafe fn Hd_val(v: Value<'_>) -> Header {
    v.as_block().unwrap().header()
}
#[inline]
unsafe fn Hp_val(v: Value<'_>) -> *mut Header {
    (v.to_bits() as *mut Header).offset(-1)
}
#[inline]
const fn Color_hd(hd: header_t) -> c_ulong {
    hd & (ocamlrep::CAML_BLACK as c_ulong)
}
#[inline]
unsafe fn Val_long<'a>(x: isize) -> Value<'a> {
    Value::from_bits(((x << 1) + 1) as usize)
}
#[inline]
unsafe fn Val_int<'a>(x: isize) -> Value<'a> {
    Val_long(x)
}
#[inline]
fn Long_val(x: Value<'_>) -> intnat {
    x.as_int().unwrap() as intnat
}
#[inline]
unsafe fn Val_hp<'a>(hp: *mut Header) -> Value<'a> {
    Value::from_bits(hp.add(1) as usize)
}
#[inline]
unsafe fn Atom<'a>(tag: isize) -> Value<'a> {
    Val_hp(caml_atom_table.offset(tag) as *mut Header)
}
#[inline]
unsafe fn Field(x: Value<'_>, i: usize) -> Value<'_> {
    x.field(i).unwrap()
}
#[inline]
unsafe fn Field_ptr_mut(x: value, i: usize) -> *mut value {
    &mut *(x as *mut value).add(i) as *mut value
}
#[inline]
unsafe fn Byte_ptr_mut(x: value, i: usize) -> *mut c_char {
    &mut *(x as *mut c_char).add(i) as *mut c_char
}
#[inline]
unsafe fn Byte_u_ptr_mut(x: value, i: usize) -> *mut c_uchar {
    &mut *(x as *mut c_uchar).add(i) as *mut c_uchar
}
#[inline]
const fn Wosize_whsize(size: mlsize_t) -> mlsize_t {
    size - 1
}
#[inline]
const fn Bsize_wsize(size: u64) -> u64 {
    size * (std::mem::size_of::<value>() as u64)
}
#[inline]
const fn Wsize_bsize(size: u64) -> u64 {
    size / (std::mem::size_of::<value>() as u64)
}
#[inline]
const fn Make_header(wosize: mlsize_t, tag: tag_t, color: color_t) -> Header {
    Header::from_bits(((wosize << 10) + color as header_t + tag as header_t) as usize)
}

// ---

#[inline]
unsafe fn make_free_blocks(p: *mut value, size: mlsize_t, do_merge: c_int, color: c_int) {
    // `caml_fl_p_make_free_blocks` is an externally linked item defined in
    // 'free_list.c'.
    Some(caml_fl_p_make_free_blocks.expect("non-null function pointer"))
        .expect("non-null function pointer")(p, size, do_merge, color);
}

struct intern_state<'a> {
    intern_src: *mut c_uchar,
    // Reading pointer in block holding input data.
    intern_input: *mut c_uchar,
    // Pointer to beginning of block holding input data, if non-NULL this
    // pointer will be freed by the cleanup function.
    intern_dest: *mut Header,
    // Writing pointer in destination block
    intern_extra_block: *mut c_char,
    // If non-NULL, point to new heap chunk allocated with caml_alloc_for_heap.
    obj_counter: asize_t,
    // Count how many objects seen so far
    intern_obj_table: *mut Value<'a>,
    // The pointers to objects already seen
    intern_color: color_t,
    // Color to assign to newly created headers
    intern_header: Header,
    // Original header of the destination block. Meaningful only if
    // intern_extra_block is NULL.
    intern_block: Value<'a>,
    // Point to the heap block allocated as destination block. Meaningful only
    // if intern_extra_block is NULL.
    stack: Vec<intern_item<'a>>,
    // The recursion stack used in `intern_rec`.
}

impl intern_state<'_> {
    unsafe fn new() -> Self {
        Self {
            intern_src: std::ptr::null_mut(),
            intern_input: std::ptr::null_mut(),
            intern_dest: std::ptr::null_mut(),
            intern_extra_block: std::ptr::null_mut(),
            obj_counter: 0,
            intern_obj_table: std::ptr::null_mut(),
            intern_color: 0,
            intern_header: Header::from_bits(0),
            intern_block: Value::from_bits(0),
            stack: Vec::with_capacity(INTERN_STACK_INIT_SIZE),
        }
    }
}

#[inline]
unsafe fn read8u(is: &mut intern_state<'_>) -> c_uchar {
    let fresh0 = is.intern_src;
    is.intern_src = is.intern_src.offset(1);
    *fresh0
}

#[inline]
unsafe fn read8s(is: &mut intern_state<'_>) -> c_schar {
    let fresh1 = is.intern_src;
    is.intern_src = is.intern_src.offset(1);
    *fresh1 as c_schar
}

#[inline]
unsafe fn read16u(is: &mut intern_state<'_>) -> uint16_t {
    let res: uint16_t = (((*is.intern_src.offset(0) as c_int) << 8)
        + *is.intern_src.offset(1) as c_int) as uint16_t;
    is.intern_src = is.intern_src.offset(2);
    res
}

#[inline]
unsafe fn read16s(is: &mut intern_state<'_>) -> int16_t {
    let res: int16_t =
        (((*is.intern_src.offset(0) as c_int) << 8) + *is.intern_src.offset(1) as c_int) as int16_t;
    is.intern_src = is.intern_src.offset(2);
    res
}

#[inline]
unsafe fn read32u(is: &mut intern_state<'_>) -> uint32_t {
    let res: uint32_t = ((*is.intern_src.offset(0) as uint32_t) << 24)
        + (((*is.intern_src.offset(1) as c_int) << 16) as c_uint)
        + (((*is.intern_src.offset(2) as c_int) << 8) as c_uint)
        + (*is.intern_src.offset(3) as c_uint);
    is.intern_src = is.intern_src.offset(4);
    res
}

#[inline]
unsafe fn read32s(is: &mut intern_state<'_>) -> int32_t {
    let res: int32_t = (((*is.intern_src.offset(0) as uint32_t) << 24 as c_int)
        + (((*is.intern_src.offset(1) as c_int) << 16) as c_uint)
        + (((*is.intern_src.offset(2) as c_int) << 8) as c_uint)
        + (*is.intern_src.offset(3) as c_uint)) as int32_t;
    is.intern_src = is.intern_src.offset(4);
    res
}

unsafe fn read64u(is: &mut intern_state<'_>) -> uintnat {
    let res: uintnat = ((*is.intern_src.offset(0) as uintnat) << 56)
        + ((*is.intern_src.offset(1) as uintnat) << 48)
        + ((*is.intern_src.offset(2) as uintnat) << 40)
        + ((*is.intern_src.offset(3) as uintnat) << 32)
        + ((*is.intern_src.offset(4) as uintnat) << 24)
        + ((*is.intern_src.offset(5) as uintnat) << 16)
        + ((*is.intern_src.offset(6) as uintnat) << 8)
        + (*is.intern_src.offset(7) as uintnat);
    is.intern_src = is.intern_src.offset(8);
    res
}

#[inline]
unsafe fn readblock(is: &mut intern_state<'_>, dest: *mut c_void, len: intnat) {
    memcpy(dest, is.intern_src as *const c_void, len as usize);
    is.intern_src = is.intern_src.offset(len as isize);
}

unsafe fn intern_init(is: &mut intern_state<'_>, src: *mut c_void, input: *mut c_void) {
    // This is asserted at the beginning of demarshaling primitives. If it fails,
    // it probably means that an exception was raised without calling
    // intern_cleanup() during the previous demarshaling.

    is.intern_src = src as *mut c_uchar;
    is.intern_input = input as *mut c_uchar;
}

unsafe fn intern_cleanup(is: &mut intern_state<'_>) {
    if !is.intern_input.is_null() {
        caml_stat_free(is.intern_input as caml_stat_block);
        is.intern_input = std::ptr::null_mut();
    }
    if !is.intern_obj_table.is_null() {
        caml_stat_free(is.intern_obj_table as caml_stat_block);
        is.intern_obj_table = std::ptr::null_mut();
    }
    if !is.intern_extra_block.is_null() {
        // free newly allocated heap chunk
        caml_free_for_heap(is.intern_extra_block);
        is.intern_extra_block = std::ptr::null_mut();
    } else if is.intern_block != Value::from_bits(0) {
        // restore original header for heap block, otherwise GC is confused
        *(Hp_val(is.intern_block)) = is.intern_header;
        is.intern_block = Value::from_bits(0);
    }
    is.stack.clear()
}

unsafe fn readfloat(is: &mut intern_state<'_>, dest: *mut c_double, code: c_uint) {
    if std::mem::size_of::<c_double>() != 8 {
        intern_cleanup(is);
        caml_invalid_argument(b"input_value: non-standard floats\x00".as_ptr() as *const c_char);
    }
    readblock(is, dest as *mut c_void, 8 as intnat);

    let bytes = *(dest as *const [u8; 8]);
    *dest = match code as c_int {
        CODE_DOUBLE_BIG => f64::from_be_bytes(bytes),
        CODE_DOUBLE_LITTLE => f64::from_le_bytes(bytes),
        _ => unreachable!(),
    }
}

// `len` is a number of floats
unsafe fn readfloats(is: &mut intern_state<'_>, dest: *mut c_double, len: mlsize_t, code: c_uint) {
    if std::mem::size_of::<c_double>() != 8 {
        intern_cleanup(is);
        caml_invalid_argument(b"input_value: non-standard floats\x00".as_ptr() as *const c_char);
    }
    readblock(is, dest as *mut c_void, (len * 8) as intnat);

    let mut i = 0;
    while i < len as usize {
        let bytes = *(dest.add(i) as *const [u8; 8]);
        *(dest.add(i)) = match code as c_int {
            CODE_DOUBLE_ARRAY8_BIG | CODE_DOUBLE_ARRAY32_BIG => f64::from_be_bytes(bytes),
            CODE_DOUBLE_ARRAY8_LITTLE | CODE_DOUBLE_ARRAY32_LITTLE => f64::from_le_bytes(bytes),
            _ => unreachable!(),
        };
        i += 1
    }
}

const INTERN_STACK_INIT_SIZE: usize = 256;

const READ_BLOCK_LABEL: u64 = 16649699497103515194;
const READ_STRING_LABEL: u64 = 11970676656440271524;
const READ_SHARED_LABEL: u64 = 8656139126282042408;
const READ_DOUBLE_ARRAY_LABEL: u64 = 8966088013221564425;
const NOTHING_TO_DO_LABEL: u64 = 8288085890650723895;

unsafe fn intern_rec<'a>(is: &mut intern_state<'a>, mut dest: *mut Value<'a>) {
    let mut current_block: u64;
    let mut header: header_t;
    let mut code: c_uint;

    let mut tag: tag_t = 0;
    let mut size: mlsize_t = 0;
    let mut len: mlsize_t = 0;
    let mut ofs_ind: mlsize_t;
    let mut v: Value<'a> = Value::from_bits(0);
    let mut ofs: asize_t = 0;

    // Initially let's try to read the first object from the stream
    is.stack.push(intern_item {
        op: OReadItems,
        dest,
        arg: 1,
    });

    // The un-marshaler loop, the recursion is unrolled
    while let Some(top) = is.stack.last_mut() {
        // Interpret next item on the stack
        dest = top.dest;

        match top.op as c_uint {
            OFreshOID => {
                if Long_val(Field(Value::from_bits(dest as usize), 1)) >= 0 {
                    caml_set_oo_id(dest as value);
                }
                // Pop item and iterate
                is.stack.pop();
            }
            OShift => {
                // Shift value by an offset
                *dest = Value::from_bits((*dest).to_bits() + top.arg as usize);
                // Pop item and iterate
                is.stack.pop();
            }
            OReadItems => {
                // Pop item
                top.dest = top.dest.offset(1);
                top.arg -= 1;
                if top.arg == 0 {
                    is.stack.pop();
                }
                // Read a value and set v to this value
                code = read8u(is) as c_uint;
                if code >= PREFIX_SMALL_INT as c_uint {
                    if code >= PREFIX_SMALL_BLOCK as c_uint {
                        // Small block
                        tag = code & 0xf as c_uint;
                        size = (code >> 4 & 0x7 as c_uint) as mlsize_t;
                        current_block = READ_BLOCK_LABEL;
                    } else {
                        // Small integer
                        v = Val_int((code & 0x3F) as isize);
                        current_block = NOTHING_TO_DO_LABEL;
                    }
                } else {
                    if code >= PREFIX_SMALL_STRING as c_uint {
                        // Small string
                        len = (code & 0x1f) as mlsize_t;
                        current_block = READ_STRING_LABEL;
                    } else {
                        match code as i32 {
                            CODE_INT8 => {
                                v = Value::from_bits(
                                    (((read8s(is) as uintnat) << 1) as intnat + 1) as usize,
                                );
                                current_block = NOTHING_TO_DO_LABEL;
                            }
                            CODE_INT16 => {
                                v = Value::from_bits(
                                    (((read16s(is) as uintnat) << 1) as intnat + 1) as usize,
                                );
                                current_block = NOTHING_TO_DO_LABEL;
                            }
                            CODE_INT32 => {
                                v = Value::from_bits(
                                    (((read32s(is) as uintnat) << 1) as intnat + 1) as usize,
                                );
                                current_block = NOTHING_TO_DO_LABEL;
                            }
                            CODE_INT64 => {
                                v = Value::from_bits(
                                    (((read64u(is) as uintnat) << 1) as intnat + 1) as usize,
                                );
                                current_block = NOTHING_TO_DO_LABEL;
                            }
                            CODE_SHARED8 => {
                                ofs = read8u(is) as asize_t;
                                current_block = READ_SHARED_LABEL;
                            }
                            CODE_SHARED16 => {
                                ofs = read16u(is) as asize_t;
                                current_block = READ_SHARED_LABEL;
                            }
                            CODE_SHARED32 => {
                                ofs = read32u(is) as asize_t;
                                current_block = READ_SHARED_LABEL;
                            }
                            CODE_SHARED64 => {
                                ofs = read64u(is);
                                current_block = READ_SHARED_LABEL;
                            }
                            CODE_BLOCK32 => {
                                header = read32u(is) as header_t;
                                tag = (header & 0xff) as tag_t;
                                size = header >> 10;
                                current_block = READ_BLOCK_LABEL;
                            }
                            CODE_BLOCK64 => {
                                header = read64u(is);
                                tag = (header & 0xff) as tag_t;
                                size = header >> 10;
                                current_block = READ_BLOCK_LABEL;
                            }
                            CODE_STRING8 => {
                                len = read8u(is) as mlsize_t;
                                current_block = READ_STRING_LABEL;
                            }
                            CODE_STRING32 => {
                                len = read32u(is) as mlsize_t;
                                current_block = READ_STRING_LABEL;
                            }
                            CODE_STRING64 => {
                                len = read64u(is);
                                current_block = READ_STRING_LABEL;
                            }
                            CODE_DOUBLE_LITTLE | CODE_DOUBLE_BIG => {
                                v = Val_hp(is.intern_dest);
                                if !is.intern_obj_table.is_null() {
                                    let fresh5 = is.obj_counter;
                                    is.obj_counter += 1;
                                    *is.intern_obj_table.offset(fresh5 as isize) = v
                                }
                                *is.intern_dest = Make_header(
                                    ocamlrep::DOUBLE_WOSIZE as c_ulong,
                                    ocamlrep::DOUBLE_TAG as tag_t,
                                    is.intern_color,
                                );
                                is.intern_dest = is.intern_dest.add(1 + ocamlrep::DOUBLE_WOSIZE);
                                readfloat(is, v.to_bits() as *mut c_double, code);
                                current_block = NOTHING_TO_DO_LABEL;
                            }
                            CODE_DOUBLE_ARRAY8_LITTLE | CODE_DOUBLE_ARRAY8_BIG => {
                                len = read8u(is) as mlsize_t;
                                current_block = READ_DOUBLE_ARRAY_LABEL;
                            }
                            CODE_DOUBLE_ARRAY32_LITTLE | CODE_DOUBLE_ARRAY32_BIG => {
                                len = read32u(is) as mlsize_t;
                                current_block = READ_DOUBLE_ARRAY_LABEL;
                            }
                            CODE_DOUBLE_ARRAY64_LITTLE | CODE_DOUBLE_ARRAY64_BIG => {
                                len = read64u(is);
                                current_block = READ_DOUBLE_ARRAY_LABEL;
                            }
                            CODE_CODEPOINTER => {
                                unimplemented!()
                            }
                            CODE_INFIXPOINTER => {
                                ofs = read32u(is) as asize_t;
                                is.stack.push(intern_item {
                                    op: OShift,
                                    dest,
                                    arg: ofs as intnat,
                                });
                                is.stack.push(intern_item {
                                    op: OReadItems,
                                    dest,
                                    arg: 1,
                                });
                                continue;
                            }
                            CODE_CUSTOM | CODE_CUSTOM_LEN | CODE_CUSTOM_FIXED => {
                                unimplemented!()
                            }
                            _ => {
                                intern_cleanup(is);
                                caml_failwith(b"input_value: ill-formed message\x00".as_ptr()
                                    as *const c_char);
                            }
                        }
                        match current_block {
                            NOTHING_TO_DO_LABEL => {}
                            READ_BLOCK_LABEL => {}
                            READ_STRING_LABEL => {}
                            _ => {
                                match current_block {
                                    READ_SHARED_LABEL => {
                                        v = *is.intern_obj_table.offset((is.obj_counter - ofs) as isize)
                                    }
                                    _ /* READ_DOUBLE_ARRAY_LABEL */ => {
                                        size = len * ocamlrep::DOUBLE_WOSIZE as c_ulong;
                                        v = Val_hp(is.intern_dest);
                                        if !is.intern_obj_table.is_null() {
                                            let fresh6 = is.obj_counter;
                                            is.obj_counter += 1;
                                            *is.intern_obj_table.offset(fresh6 as isize) = v
                                        }
                                        *is.intern_dest = Make_header(size, ocamlrep::DOUBLE_ARRAY_TAG as tag_t, is.intern_color);
                                        is.intern_dest = is.intern_dest.offset((1 + size) as isize);
                                        readfloats(is, v.to_bits() as *mut c_double, len, code);
                                    }
                                }
                                current_block = NOTHING_TO_DO_LABEL;
                            }
                        }
                    }
                    match current_block {
                        NOTHING_TO_DO_LABEL => {}
                        READ_BLOCK_LABEL => {}
                        _ /* READ_STRING_LABEL */ => {
                            size = (len + (std::mem::size_of::<value>() as c_ulong)) / (std::mem::size_of::<value>() as c_ulong);
                            v = Val_hp(is.intern_dest);
                            if !is.intern_obj_table.is_null() {
                                let fresh4 = is.obj_counter;
                                is.obj_counter += 1;
                                *is.intern_obj_table.offset(fresh4 as isize) = v
                            }
                            *is.intern_dest = Make_header(size, ocamlrep::STRING_TAG as tag_t, is.intern_color);
                            is.intern_dest = is.intern_dest.offset((1 + size) as isize);
                            *(Field_ptr_mut(v.to_bits() as value, (size - 1) as usize)) = 0;
                            ofs_ind = Bsize_wsize(size) - (1 as c_ulong);
                            *(Byte_ptr_mut(v.to_bits() as value, ofs_ind as usize)) = (ofs_ind - len) as c_char;
                            readblock(is, v.to_bits() as *mut c_void, len as intnat);
                            current_block = NOTHING_TO_DO_LABEL;
                        }
                    }
                }
                match current_block {
                    READ_BLOCK_LABEL => {
                        if size == 0 {
                            v = Atom(tag as isize)
                        } else {
                            v = Val_hp(is.intern_dest);
                            if !is.intern_obj_table.is_null() {
                                let fresh3 = is.obj_counter;
                                is.obj_counter += 1;
                                *is.intern_obj_table.offset(fresh3 as isize) = v
                            }
                            *is.intern_dest = Make_header(size, tag, is.intern_color);
                            is.intern_dest = is.intern_dest.offset((1 + size) as isize);
                            // For objects, we need to freshen the oid
                            if tag == ocamlrep::OBJECT_TAG as tag_t {
                                // Request to read rest of the elements of the block
                                if size - 2 > 0 {
                                    is.stack.push(intern_item {
                                        op: OReadItems,
                                        dest: Field_ptr_mut(v.to_bits() as value, 2)
                                            as *mut Value<'a>,
                                        arg: (size - 2) as i64,
                                    });
                                }
                                // Request freshing OID
                                is.stack.push(intern_item {
                                    op: OFreshOID,
                                    dest: v.to_bits() as *mut Value<'a>,
                                    arg: 1,
                                });
                                // Finally read first two block elements: method table and old OID
                                is.stack.push(intern_item {
                                    op: OReadItems,
                                    dest: Field_ptr_mut(v.to_bits() as value, 0) as *mut Value<'a>,
                                    arg: 2,
                                });
                            } else {
                                // If it's not an object then read the conents of the block
                                is.stack.push(intern_item {
                                    op: OReadItems,
                                    dest: Field_ptr_mut(v.to_bits() as value, 0) as *mut Value<'a>,
                                    arg: size as i64,
                                });
                            }
                        }
                    }
                    _ => {}
                }
                *dest = v
            }
            _ => {}
        }
    }
}

unsafe fn intern_alloc<'a>(is: &mut intern_state<'a>, whsize: mlsize_t, num_objects: mlsize_t) {
    if whsize == 0 {
        return;
    }
    let wosize = Wosize_whsize(whsize);
    if wosize > ocamlrep::MAX_WOSIZE as mlsize_t {
        // Round desired size up to next page
        let request: asize_t =
            ((Bsize_wsize(whsize) + (PAGE_SIZE as mlsize_t) - 1) >> PAGE_LOG) << PAGE_LOG;
        is.intern_extra_block = caml_alloc_for_heap(request);
        if is.intern_extra_block.is_null() {
            intern_cleanup(is);
            caml_raise_out_of_memory();
        }
        is.intern_color = caml_allocation_color(is.intern_extra_block as *mut c_void);
        is.intern_dest = is.intern_extra_block as *mut Header
    } else {
        // This is a specialized version of caml_alloc from 'alloc.c'
        if wosize <= MAX_YOUNG_WOSIZE as c_ulong {
            if wosize == 0 {
                is.intern_block = Atom(ocamlrep::STRING_TAG as isize);
            } else {
                /*
                #define Setup_for_gc
                #define Restore_after_gc
                Alloc_small_no_track(intern_block, wosize, String_tag);
                #undef Setup_for_gc
                #undef Restore_after_gc
                 */
                (*Caml_state)._young_ptr =
                    (*Caml_state)._young_ptr.offset(-((wosize + 1) as isize));
                if (*Caml_state)._young_ptr < (*Caml_state)._young_limit {
                    caml_alloc_small_dispatch(
                        wosize as intnat,
                        CAML_DONT_TRACK as c_int | CAML_FROM_C as c_int,
                        1,
                        std::ptr::null_mut::<c_uchar>(),
                    );
                }
                *((*Caml_state)._young_ptr as *mut header_t) =
                    Make_header(wosize, ocamlrep::STRING_TAG as tag_t, 0).to_bits() as u64;
                is.intern_block =
                    Value::from_bits(((*Caml_state)._young_ptr as *mut header_t).offset(1) as usize)
            }
        } else {
            is.intern_block = Value::from_bits(caml_alloc_shr_no_track_noexc(
                wosize,
                ocamlrep::STRING_TAG as tag_t,
            ) as usize);
            // do not do the urgent_gc check here because it might darken
            // intern_block into gray and break the intern_color assertion below
            if is.intern_block == Value::from_bits(0) {
                intern_cleanup(is);
                caml_raise_out_of_memory();
            }
        }
        is.intern_header = Hd_val(is.intern_block);
        is.intern_color = Color_hd(is.intern_header.to_bits() as u64);
        is.intern_dest = Hp_val(is.intern_block);
    }
    is.obj_counter = 0;
    if num_objects > 0 {
        is.intern_obj_table =
            caml_stat_alloc_noexc(num_objects * (std::mem::size_of::<value>() as c_ulong))
                as *mut Value<'a>;
        if is.intern_obj_table.is_null() {
            intern_cleanup(is);
            caml_raise_out_of_memory();
        }
    };
}

unsafe fn intern_add_to_heap(is: &mut intern_state<'_>, _whsize: mlsize_t) -> *mut Header {
    let mut res: *mut Header = std::ptr::null_mut();
    if !is.intern_extra_block.is_null() {
        // If heap chunk not filled totally, build free block at end
        let request: asize_t = (*(is.intern_extra_block as *mut heap_chunk_head).offset(-1)).size;

        let end_extra_block: *mut Header =
            (is.intern_extra_block as *mut Header).offset(Wsize_bsize(request) as isize);
        if is.intern_dest < end_extra_block {
            make_free_blocks(
                is.intern_dest as *mut value,
                end_extra_block.offset_from(is.intern_dest) as mlsize_t,
                0,
                ocamlrep::CAML_WHITE as c_int,
            );
        }
        caml_allocated_words += Wsize_bsize(
            (is.intern_dest as *mut c_char).offset_from(is.intern_extra_block) as c_ulong,
        );
        if caml_add_to_heap(is.intern_extra_block) != 0 {
            intern_cleanup(is);
            caml_raise_out_of_memory();
        }
        res = is.intern_extra_block as *mut Header;
        is.intern_extra_block = std::ptr::null_mut() // To prevent intern_cleanup freeing it
    } else if is.intern_block != Value::from_bits(0) {
        res = Hp_val(is.intern_block);
        is.intern_block = Value::from_bits(0); // To prevent intern_cleanup rewriting its header
    }
    res
}

unsafe fn intern_end<'a>(is: &mut intern_state<'a>, mut res: value, whsize: mlsize_t) -> value {
    let caml__frame: *mut caml__roots_block = (*Caml_state)._local_roots;
    let mut caml__roots_res: caml__roots_block = caml__roots_block {
        next: std::ptr::null_mut::<caml__roots_block>(),
        ntables: 0,
        nitems: 0,
        tables: [std::ptr::null_mut::<value>(); 5],
    };
    caml__roots_res.next = (*Caml_state)._local_roots;
    (*Caml_state)._local_roots = &mut caml__roots_res;
    caml__roots_res.nitems = 1;
    caml__roots_res.ntables = 1;
    caml__roots_res.tables[0] = &mut res;
    let _caml__dummy_res: c_int = 0;

    let block: *mut Header = intern_add_to_heap(is, whsize);
    let blockend: *mut Header = is.intern_dest;
    intern_cleanup(is);
    if !block.is_null() {
        caml_memprof_track_interned(block as *mut header_t, blockend as *mut header_t);
    }
    caml_process_pending_actions();

    let caml__temp_result: value = res;
    (*Caml_state)._local_roots = caml__frame;
    caml__temp_result
}

unsafe fn parse_header(
    is: &mut intern_state<'_>,
    fun_name: *mut c_char,
    mut h: *mut marshal_header,
) {
    let mut errmsg: [c_char; 100] = [0; 100];
    (*h).magic = read32u(is);
    match (*h).magic {
        MAGIC_NUMBER_SMALL => {
            (*h).header_len = 20;
            (*h).data_len = read32u(is) as uintnat;
            (*h).num_objects = read32u(is) as uintnat;
            read32u(is);
            (*h).whsize = read32u(is) as uintnat
        }
        MAGIC_NUMBER_BIG => {
            (*h).header_len = 32;
            read32u(is);
            (*h).data_len = read64u(is);
            (*h).num_objects = read64u(is);
            (*h).whsize = read64u(is)
        }
        _ => {
            errmsg[((std::mem::size_of::<[c_char; 100]>() as c_ulong) - 1) as usize] = 0;
            snprintf(
                errmsg.as_mut_ptr() as *mut c_char,
                ((std::mem::size_of::<[c_char; 100]>() as c_ulong) - 1) as usize,
                b"%s: bad object\x00".as_ptr() as *const c_char,
                fun_name,
            );
            caml_failwith(errmsg.as_mut_ptr());
        }
    };
}

unsafe fn input_val_from_string<'a>(
    is: &mut intern_state<'a>,
    mut str: value,
    ofs: intnat,
) -> value {
    let caml__frame: *mut caml__roots_block = (*Caml_state)._local_roots;
    let mut caml__roots_str: caml__roots_block = caml__roots_block {
        next: std::ptr::null_mut::<caml__roots_block>(),
        ntables: 0,
        nitems: 0,
        tables: [std::ptr::null_mut::<value>(); 5],
    };
    caml__roots_str.next = (*Caml_state)._local_roots;
    (*Caml_state)._local_roots = &mut caml__roots_str;
    caml__roots_str.nitems = 1;
    caml__roots_str.ntables = 1;
    caml__roots_str.tables[0] = &mut str;
    let _caml__dummy_str: c_int = 0;
    let mut obj: value = ((0 as uintnat) << 1) as intnat + 1 as c_long;
    let mut caml__roots_obj: caml__roots_block = caml__roots_block {
        next: std::ptr::null_mut::<caml__roots_block>(),
        ntables: 0,
        nitems: 0,
        tables: [std::ptr::null_mut::<value>(); 5],
    };
    caml__roots_obj.next = (*Caml_state)._local_roots;
    (*Caml_state)._local_roots = &mut caml__roots_obj;
    caml__roots_obj.nitems = 1;
    caml__roots_obj.ntables = 1;
    caml__roots_obj.tables[0] = &mut obj;
    let _caml__dummy_obj: c_int = 0;

    let mut h: marshal_header = marshal_header {
        magic: 0,
        header_len: 0,
        data_len: 0,
        num_objects: 0,
        whsize: 0,
    };
    // Initialize global state
    intern_init(
        is,
        Byte_u_ptr_mut(str, ofs as usize) as *mut c_void,
        std::ptr::null_mut::<c_void>(),
    );
    parse_header(
        is,
        b"input_val_from_string\x00".as_ptr() as *mut c_char,
        &mut h,
    );
    if ((ofs + h.header_len as c_long) as c_ulong) + h.data_len > caml_string_length(str) {
        caml_failwith(b"input_val_from_string: bad length\x00".as_ptr() as *const c_char);
    }
    // Allocate result
    intern_alloc(is, h.whsize, h.num_objects);
    is.intern_src = Byte_u_ptr_mut(str, (ofs + h.header_len as c_long) as usize);
    // Fill it in
    intern_rec(is, &mut obj as *mut value as *mut Value<'a>);

    let caml__temp_result: value = intern_end(is, obj, h.whsize);
    (*Caml_state)._local_roots = caml__frame;
    caml__temp_result
}

#[no_mangle]
unsafe extern "C" fn ocamlrep_marshal_input_value_from_string(str: value, ofs: value) -> value {
    input_val_from_string(&mut intern_state::new(), str, ofs >> 1)
}
