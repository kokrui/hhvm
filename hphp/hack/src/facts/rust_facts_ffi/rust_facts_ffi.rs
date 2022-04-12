// Copyright (c) 2019, Facebook, Inc.
// All rights reserved.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the "hack" directory of this source tree.

use direct_decl_parser::DeclParserOptions;
use facts_rust::facts::Facts;
use hhbc_string_utils::without_xhp_mangling;
use ocamlrep::{bytes_from_ocamlrep, ptr::UnsafeOcamlPtr};
use ocamlrep_ocamlpool::ocaml_ffi;
use oxidized::relative_path::RelativePath;

ocaml_ffi! {
    fn extract_as_json_ffi(
        flags: i32,
        auto_namespace_map: Vec<(String, String)>,
        filename: RelativePath,
        text_ptr: UnsafeOcamlPtr,
        mangle_xhp: bool,
    ) -> Option<String> {
        // Safety: the OCaml garbage collector must not run as long as text_ptr
        // and text_value exist. We don't call into OCaml here, so it won't.
        let text_value = unsafe { text_ptr.as_value() };
        let text = bytes_from_ocamlrep(text_value).expect("expected string");
        extract_facts_as_json_ffi(
            ((1 << 0) & flags) != 0, // php5_compat_mode
            ((1 << 1) & flags) != 0, // hhvm_compat_mode
            ((1 << 2) & flags) != 0, // allow_new_attribute_syntax
            ((1 << 3) & flags) != 0, // enable_xhp_class_modifier
            ((1 << 4) & flags) != 0, // disable_xhp_element_mangling
            auto_namespace_map,
            filename,
            text,
            mangle_xhp,
        )
    }
}

fn extract_facts_as_json_ffi(
    php5_compat_mode: bool,
    hhvm_compat_mode: bool,
    allow_new_attribute_syntax: bool,
    enable_xhp_class_modifier: bool,
    disable_xhp_element_mangling: bool,
    auto_namespace_map: Vec<(String, String)>,
    filename: RelativePath,
    text: &[u8],
    mangle_xhp: bool,
) -> Option<String> {
    let bump = bumpalo::Bump::new();
    let alloc: &'static bumpalo::Bump =
        unsafe { std::mem::transmute::<&'_ bumpalo::Bump, &'static bumpalo::Bump>(&bump) };
    let auto_namespace_map =
        alloc.alloc_slice_fill_iter(auto_namespace_map.iter().map(|(k, v)| {
            (
                alloc.alloc_str(k.as_str()) as &str,
                alloc.alloc_str(v.as_str()) as &str,
            )
        }));
    let opts = DeclParserOptions {
        auto_namespace_map,
        hhvm_compat_mode,
        php5_compat_mode,
        allow_new_attribute_syntax,
        enable_xhp_class_modifier,
        disable_xhp_element_mangling,
        ..Default::default()
    };
    let decls =
        direct_decl_parser::parse_decls_without_reference_text(&opts, filename, text, alloc);

    if decls.has_first_pass_parse_errors {
        None
    } else if mangle_xhp {
        let facts = Facts::facts_of_decls(
            &decls.decls,
            decls.file_attributes,
            disable_xhp_element_mangling,
        );
        Some(facts.to_json(text))
    } else {
        without_xhp_mangling(|| {
            let facts = Facts::facts_of_decls(
                &decls.decls,
                decls.file_attributes,
                disable_xhp_element_mangling,
            );
            Some(facts.to_json(text))
        })
    }
}
