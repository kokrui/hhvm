// Copyright (c) Facebook, Inc. and its affiliates.
//
// This source code is licensed under the MIT license found in the
// LICENSE file in the "hack" directory of this source tree.

#![cfg(test)]

use crate::{FacebookInit, TestContext};
use anyhow::Result;
use hh24_types::ToplevelSymbolHash;
use maplit::btreemap;
use oxidized::naming_types;
use pos::{FunName, Prefix, RelativePath, TypeName};
use rpds::HashTrieSet;
use std::path::PathBuf;

fn make_dep_from_typename(typename: &str) -> deps_rust::Dep {
    deps_rust::Dep::new(ToplevelSymbolHash::from_type(typename).as_u64())
}

fn make_relative_path_from_str(test_path: &str) -> RelativePath {
    RelativePath::new(Prefix::Root, PathBuf::from(test_path))
}

#[fbinit::test]
fn type_test(fb: FacebookInit) -> Result<()> {
    let ctx = TestContext::new(
        fb,
        btreemap! {
            "a.php" => "class A extends B {}",
            "b.php" => "class B {}"
        },
    )?;

    let naming_table = ctx.provider_backend.naming_table;

    let a_type = TypeName::new(r#"\A"#);
    let a_relative_path = make_relative_path_from_str("a.php");

    // Retrieve a typename
    let (pos, kindof) = naming_table.get_type_pos(a_type).unwrap().unwrap();

    let rp: RelativePath = pos.path().into();
    assert_eq!(rp, a_relative_path);
    assert_eq!(kindof, naming_types::KindOfType::TClass);

    // Remove a typename
    naming_table.remove_type_batch(&[a_type])?;
    assert_eq!(naming_table.get_type_pos(a_type).unwrap(), None);

    // Add a typename
    naming_table.add_type(
        a_type,
        &(
            oxidized::file_info::Pos::File(
                oxidized::file_info::NameType::Class,
                ocamlrep::rc::RcOc::new(a_relative_path.into()),
            ),
            naming_types::KindOfType::TClass,
        ),
    )?;

    let (pos, kindof) = naming_table.get_type_pos(a_type).unwrap().unwrap();
    let rp: RelativePath = pos.path().into();
    assert_eq!(rp, a_relative_path);
    assert_eq!(kindof, naming_types::KindOfType::TClass);

    // Get name from its lowercase version
    assert_eq!(
        naming_table
            .get_canon_type_name(TypeName::new(r#"\a"#))
            .unwrap()
            .unwrap(),
        a_type
    );

    Ok(())
}

#[fbinit::test]
fn fun_test(fb: FacebookInit) -> Result<()> {
    let ctx = TestContext::new(
        fb,
        btreemap! {
            "a.php" => "function A(): void { b(); }",
            "b.php" => "function b(): void { A(); }",
        },
    )?;

    let naming_table = ctx.provider_backend.naming_table;

    let a_fun = FunName::new(r#"\A"#);
    let a_relative_path = make_relative_path_from_str("a.php");

    // Retrieve a fun
    let pos = naming_table.get_fun_pos(a_fun).unwrap().unwrap();
    let rp: RelativePath = pos.path().into();
    assert_eq!(rp, a_relative_path);

    // Remove a fun
    naming_table.remove_fun_batch(&[a_fun])?;
    assert_eq!(naming_table.get_fun_pos(a_fun).unwrap(), None);

    // Add a fun
    naming_table.add_fun(
        a_fun,
        &oxidized::file_info::Pos::File(
            oxidized::file_info::NameType::Fun,
            ocamlrep::rc::RcOc::new(a_relative_path.into()),
        ),
    )?;

    let pos = naming_table.get_fun_pos(a_fun).unwrap().unwrap();
    let rp: RelativePath = pos.path().into();
    assert_eq!(rp, a_relative_path);

    // Get canon name from its lowercase version
    assert_eq!(
        naming_table
            .get_canon_fun_name(FunName::new(r#"\a"#))
            .unwrap()
            .unwrap(),
        a_fun
    );

    Ok(())
}

#[fbinit::test]
fn get_filenames_by_hash_test(fb: FacebookInit) -> Result<()> {
    let ctx = TestContext::new(
        fb,
        btreemap! {
            "a.php" => "class A extends B {}",
            "b.php" => "class B {}"
        },
    )?;
    let naming_table = ctx.provider_backend.naming_table;
    let a_type = make_dep_from_typename(r#"\A"#);
    let b_type = make_dep_from_typename(r#"\B"#);
    let a_relative_path = make_relative_path_from_str("a.php");
    let b_relative_path = make_relative_path_from_str("b.php");

    let depset = HashTrieSet::new();
    let depset = depset.insert(a_type);
    let dep_paths = naming_table
        .get_filenames_by_hash(&deps_rust::DepSet::from(depset))
        .unwrap();
    assert!(dep_paths.contains(&a_relative_path));
    assert!(!dep_paths.contains(&b_relative_path));

    let depset = HashTrieSet::new();
    let depset = depset.insert(a_type);
    let depset = depset.insert(b_type);
    let dep_paths = naming_table
        .get_filenames_by_hash(&deps_rust::DepSet::from(depset))
        .unwrap();
    assert!(dep_paths.contains(&a_relative_path));
    assert!(dep_paths.contains(&b_relative_path));

    let depset = HashTrieSet::new();
    let dep_paths = naming_table
        .get_filenames_by_hash(&deps_rust::DepSet::from(depset))
        .unwrap();
    assert!(dep_paths.is_empty());

    let depset = HashTrieSet::new();
    let depset = depset.insert(make_dep_from_typename(r#"\C"#));
    let dep_paths = naming_table
        .get_filenames_by_hash(&deps_rust::DepSet::from(depset))
        .unwrap();
    assert!(dep_paths.is_empty());
    Ok(())
}
