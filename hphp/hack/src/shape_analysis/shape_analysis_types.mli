(*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the "hack" directory of this source tree.
 *
 *)

module A = Ast_defs
module T = Typing_defs
module LMap = Local_id.Map
module KMap = Typing_continuations.Map
module HT = Hips_types

(** A generic exception for all shape analysis specific failures *)
exception Shape_analysis_exn of string

(** Container to collect potential dicts that can be addressed with the shape
    analysis. *)
type potential_targets = {
  expressions_to_modify: Pos.t list;
  hints_to_modify: Pos.t list;
}

type mode =
  | FlagTargets
      (** Flag all possible targets, e.g., `dict['k1' => 42, 'k2' =>
          'meaning']` without performing any analysis *)
  | DumpConstraints  (** Dump constraints generated by analysing the program *)
  | SimplifyConstraints
      (** Partially solve key constraints within functions and methods and
          report back summaries about which `dict`s might be `shape`s and which
          functions/methods they depend on. *)
  | Codemod
      (** Same as simplify constraints, but outputs JSON that represents
          instructions to codemod source code. *)
  | SolveConstraints
      (** Globally solve the key constraints and report back `dict`s that can
          be `shape`s along with the `shape` keys *)

type options = {
  mode: mode;
      (** The mode of oepration. See the `mode` type documentation for distinct
          modes. *)
  verbosity: int;
      (** Controls how much debug information to output. 0 means no extra debug
          information. Particularly, tests use 0. *)
}

type entity_ =
  | Literal of Pos.t
  | Variable of int
  | Inter of HT.entity
[@@deriving eq, ord]

type entity = entity_ option

type shape_keys = T.locl_phase T.shape_field_type T.TShapeMap.t

type marker_kind =
  | Allocation  (** A dict allocation such as `dict[]` or `dict['a' => 42]` *)
  | Parameter
      (** A dict parameter to a function or method such as `function
          f(dict<string,int> $d): void {...}` *)
  | Return
      (** A dict return of a function or method such as `function
          f(): dict<string,int> {...}` *)
  | Debug
      (** A dict argument to a function or method such as `$d = dict[]; f($d)`
       *)
[@@deriving ord, show]

module Codemod : sig
  type kind =
    | Allocation  (** Codemod `dict[...]` syntax to `shape(...)` syntax. *)
    | Hint
        (** Codemod to change the `dict<key,ty>` hint to `shape(...)` hint. *)
  [@@deriving show { with_path = false }]
end

type constraint_ =
  | Marks of marker_kind * Pos.t  (** Marks a point of interest *)
  | Has_static_key of entity_ * T.TShapeField.t * T.locl_ty
      (** Records a static key an entity is accessed with along with the Hack
          type of that key *)
  | Has_optional_key of entity_ * T.TShapeField.t
      (** Records an optional static key *)
  | Has_dynamic_key of entity_
      (** Records that an entity is accessed with a dynamic key *)
  | Subsets of entity_ * entity_
      (** Records that the first keys of the first entity are all present in
          the second. *)
  | Joins of {
      left: entity_;
      right: entity_;
      join: entity_;
    }
      (** `Join(e,e',e'')` represents that `e''` is the join point of `e` and
          `e'` for example as a result of merging environments after an if
          statement. *)
[@@deriving ord]

(** Interprocedural constraint: currently only `Arg((f, 0), p)`, which models
    a function call f(p, _, ...). *)
type inter_constraint_ = Arg of HT.param_entity * entity_

type shape_result =
  | Shape_like_dict of Pos.t * marker_kind * shape_keys
      (** A dict that acts like a shape along with its keys, types the keys
          point to, and the keys are optional. The marker kind distinguishes
          for what we are reporting a result. *)
  | Dynamically_accessed_dict of entity_
      (** A dict that is accessed or used dynamically. This is important
          in inter-procedural setting where a locally static dict calls a
          function where the parameter is accessed dynamically. In that case,
          the original result on static access should be invalidated. *)

(** Local variable environment. Its values are `entity`, i.e., `entity_
    option`, so that we can avoid pattern matching in constraint extraction. *)
type lenv = entity LMap.t KMap.t

(** Dressing on top of constraints that are solely used to help debug constraints *)
type 'constraint_ decorated = {
  hack_pos: Pos.t;  (** Hack source code position that led to the constraint *)
  origin: int;
      (** The origin of the constraint from Shape_analysis_walker.ml *)
  constraint_: 'constraint_;  (** The constraint proper *)
}

(** Tuple of lists of decorated intra- and inter-procedural constraints *)
type decorated_constraints =
  constraint_ decorated list * inter_constraint_ decorated list

type env = {
  constraints: constraint_ decorated list;
      (** Append-only set of intra-procedural constraints *)
  inter_constraints: inter_constraint_ decorated list;
      (** Append-only set of inter-procedural constraints *)
  lenv: lenv;  (** Local variable information *)
  return: entity;  (** Entity for the return of a callable *)
  tast_env: Tast_env.env;
      (** TAST env associated with the definition being analysed *)
}

module PointsToSet : Set.S with type elt = entity_ * entity_

module EntityMap : Map.S with type key = entity_

module EntitySet : Set.S with type elt = entity_

module ConstraintSet : Set.S with type elt = constraint_

(** Events used for logging purposes *)
type log_event =
  | Result of {
      id: string;
      shape_result: shape_result;
    }  (** Indicates a successfuly analysis result *)
  | Failure of {
      id: string;
      error_message: string;
    }  (** Indicates that the analysis malfunctioned *)

type any_constraint =
  | Intra of constraint_
  | Inter of inter_constraint_
