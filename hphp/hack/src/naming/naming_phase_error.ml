(*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the "hack" directory of this source tree.
 *
 *)
open Hh_prelude

exception UnexpectedExpr of Pos.t

type experimental_feature =
  | Like_type of Pos.t
  | Supportdyn of Pos.t
  (* We use this constructor in Rust elaboration *)
  | Const_attr of Pos.t
[@@ocaml.warning "-37"]

type t =
  | Naming of Naming_error.t
  | Nast_check of Nast_check_error.t
  | Unexpected_hint of Pos.t
  | Malformed_access of Pos.t
  | Experimental_feature of experimental_feature

let naming err = Naming err

let nast_check err = Nast_check err

let like_type pos = Experimental_feature (Like_type pos)

let unexpected_hint pos = Unexpected_hint pos

let malformed_access pos = Malformed_access pos

let supportdyn pos = Experimental_feature (Supportdyn pos)

type agg = {
  naming: Naming_error.t list;
  (* TODO[mjt] either these errors shouldn't be raised in naming or they aren't
     really typing errors *)
  (* TODO[mjt] as above, either these should be naming errors or we should
     be raising in NAST checks *)
  nast_check: Nast_check_error.t list;
  (* TODO[mjt] these errors are not represented by any of our conventional
     phase errors; presumably they should all be naming errors? *)
  unexpected_hints: Pos.t list;
  malformed_accesses: Pos.t list;
  experimental_features: experimental_feature list;
}

let empty =
  {
    naming = [];
    nast_check = [];
    unexpected_hints = [];
    malformed_accesses = [];
    experimental_features = [];
  }

let add t = function
  | Naming err -> { t with naming = err :: t.naming }
  | Nast_check err -> { t with nast_check = err :: t.nast_check }
  | Unexpected_hint err ->
    { t with unexpected_hints = err :: t.unexpected_hints }
  | Malformed_access err ->
    { t with malformed_accesses = err :: t.malformed_accesses }
  | Experimental_feature err ->
    { t with experimental_features = err :: t.experimental_features }

let emit_experimental_feature = function
  | Like_type pos -> Errors.experimental_feature pos "like-types"
  | Supportdyn pos -> Errors.experimental_feature pos "supportdyn type hint"
  | Const_attr pos ->
    Errors.experimental_feature pos "The __Const attribute is not supported."

let emit
    {
      naming;
      nast_check;
      unexpected_hints;
      malformed_accesses;
      experimental_features;
    } =
  List.iter ~f:Errors.add_naming_error naming;
  List.iter ~f:Errors.add_nast_check_error nast_check;
  List.iter
    ~f:(fun pos ->
      Errors.internal_error pos "Unexpected hint not present on legacy AST")
    unexpected_hints;
  List.iter
    ~f:(fun pos ->
      Errors.internal_error
        pos
        "Malformed hint: expected Haccess (Happly ...) from ast_to_nast")
    malformed_accesses;
  List.iter ~f:emit_experimental_feature experimental_features

(* Helper for constructing expression to be substituted for invalid expressions
   TODO[mjt] this probably belongs with the AAST defs
*)
let invalid_expr_ expr_opt = Aast.Invalid expr_opt

let invalid_expr ((annot, pos, _) as expr) =
  (annot, pos, Aast.Invalid (Some expr))
