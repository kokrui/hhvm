/**
 * Copyright (c) 2016, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the "hack" directory of this source tree. An additional
 * directory.
 *
 **
 *
 * THIS FILE IS @generated; DO NOT EDIT IT
 * To regenerate this file, run
 *
 *   buck run //hphp/hack/src:generate_full_fidelity
 *
 **
 *
 */

use ocamlrep_derive::{FromOcamlRep, ToOcamlRep};

use crate::token_kind::TokenKind;

#[derive(Debug, Copy, Clone, FromOcamlRep, ToOcamlRep, PartialEq)]
pub enum SyntaxKind {
    Missing,
    Token(TokenKind),
    SyntaxList,
    EndOfFile,
    Script,
    QualifiedName,
    SimpleTypeSpecifier,
    LiteralExpression,
    PrefixedStringExpression,
    PrefixedCodeExpression,
    VariableExpression,
    PipeVariableExpression,
    FileAttributeSpecification,
    EnumDeclaration,
    EnumUse,
    Enumerator,
    EnumClassDeclaration,
    EnumClassEnumerator,
    RecordDeclaration,
    RecordField,
    AliasDeclaration,
    PropertyDeclaration,
    PropertyDeclarator,
    NamespaceDeclaration,
    NamespaceDeclarationHeader,
    NamespaceBody,
    NamespaceEmptyBody,
    NamespaceUseDeclaration,
    NamespaceGroupUseDeclaration,
    NamespaceUseClause,
    FunctionDeclaration,
    FunctionDeclarationHeader,
    Contexts,
    WhereClause,
    WhereConstraint,
    MethodishDeclaration,
    MethodishTraitResolution,
    ClassishDeclaration,
    ClassishBody,
    TraitUsePrecedenceItem,
    TraitUseAliasItem,
    TraitUseConflictResolution,
    TraitUse,
    RequireClause,
    ConstDeclaration,
    ConstantDeclarator,
    TypeConstDeclaration,
    ContextConstDeclaration,
    DecoratedExpression,
    ParameterDeclaration,
    VariadicParameter,
    OldAttributeSpecification,
    AttributeSpecification,
    Attribute,
    InclusionExpression,
    InclusionDirective,
    CompoundStatement,
    ExpressionStatement,
    MarkupSection,
    MarkupSuffix,
    UnsetStatement,
    UsingStatementBlockScoped,
    UsingStatementFunctionScoped,
    WhileStatement,
    IfStatement,
    ElseifClause,
    ElseClause,
    TryStatement,
    CatchClause,
    FinallyClause,
    DoStatement,
    ForStatement,
    ForeachStatement,
    SwitchStatement,
    SwitchSection,
    SwitchFallthrough,
    CaseLabel,
    DefaultLabel,
    ReturnStatement,
    YieldBreakStatement,
    ThrowStatement,
    BreakStatement,
    ContinueStatement,
    EchoStatement,
    ConcurrentStatement,
    SimpleInitializer,
    AnonymousClass,
    AnonymousFunction,
    AnonymousFunctionUseClause,
    LambdaExpression,
    LambdaSignature,
    CastExpression,
    ScopeResolutionExpression,
    MemberSelectionExpression,
    SafeMemberSelectionExpression,
    EmbeddedMemberSelectionExpression,
    YieldExpression,
    PrefixUnaryExpression,
    PostfixUnaryExpression,
    BinaryExpression,
    IsExpression,
    AsExpression,
    NullableAsExpression,
    ConditionalExpression,
    EvalExpression,
    IssetExpression,
    FunctionCallExpression,
    FunctionPointerExpression,
    ParenthesizedExpression,
    BracedExpression,
    ETSpliceExpression,
    EmbeddedBracedExpression,
    ListExpression,
    CollectionLiteralExpression,
    ObjectCreationExpression,
    ConstructorCall,
    RecordCreationExpression,
    DarrayIntrinsicExpression,
    DictionaryIntrinsicExpression,
    KeysetIntrinsicExpression,
    VarrayIntrinsicExpression,
    VectorIntrinsicExpression,
    ElementInitializer,
    SubscriptExpression,
    EmbeddedSubscriptExpression,
    AwaitableCreationExpression,
    XHPChildrenDeclaration,
    XHPChildrenParenthesizedList,
    XHPCategoryDeclaration,
    XHPEnumType,
    XHPLateinit,
    XHPRequired,
    XHPClassAttributeDeclaration,
    XHPClassAttribute,
    XHPSimpleClassAttribute,
    XHPSimpleAttribute,
    XHPSpreadAttribute,
    XHPOpen,
    XHPExpression,
    XHPClose,
    TypeConstant,
    VectorTypeSpecifier,
    KeysetTypeSpecifier,
    TupleTypeExplicitSpecifier,
    VarrayTypeSpecifier,
    FunctionCtxTypeSpecifier,
    TypeParameter,
    TypeConstraint,
    ContextConstraint,
    DarrayTypeSpecifier,
    DictionaryTypeSpecifier,
    ClosureTypeSpecifier,
    ClosureParameterTypeSpecifier,
    ClassnameTypeSpecifier,
    FieldSpecifier,
    FieldInitializer,
    ShapeTypeSpecifier,
    ShapeExpression,
    TupleExpression,
    GenericTypeSpecifier,
    NullableTypeSpecifier,
    LikeTypeSpecifier,
    SoftTypeSpecifier,
    AttributizedSpecifier,
    ReifiedTypeArgument,
    TypeArguments,
    TypeParameters,
    TupleTypeSpecifier,
    UnionTypeSpecifier,
    IntersectionTypeSpecifier,
    ErrorSyntax,
    ListItem,
    EnumClassLabelExpression,

}

impl SyntaxKind {
    pub fn to_string(&self) -> &str {
        match self {
            SyntaxKind::SyntaxList => "list",
            SyntaxKind::Missing => "missing",
            SyntaxKind::Token(_) => "token",
            SyntaxKind::EndOfFile                         => "end_of_file",
            SyntaxKind::Script                            => "script",
            SyntaxKind::QualifiedName                     => "qualified_name",
            SyntaxKind::SimpleTypeSpecifier               => "simple_type_specifier",
            SyntaxKind::LiteralExpression                 => "literal",
            SyntaxKind::PrefixedStringExpression          => "prefixed_string",
            SyntaxKind::PrefixedCodeExpression            => "prefixed_code",
            SyntaxKind::VariableExpression                => "variable",
            SyntaxKind::PipeVariableExpression            => "pipe_variable",
            SyntaxKind::FileAttributeSpecification        => "file_attribute_specification",
            SyntaxKind::EnumDeclaration                   => "enum_declaration",
            SyntaxKind::EnumUse                           => "enum_use",
            SyntaxKind::Enumerator                        => "enumerator",
            SyntaxKind::EnumClassDeclaration              => "enum_class_declaration",
            SyntaxKind::EnumClassEnumerator               => "enum_class_enumerator",
            SyntaxKind::RecordDeclaration                 => "record_declaration",
            SyntaxKind::RecordField                       => "record_field",
            SyntaxKind::AliasDeclaration                  => "alias_declaration",
            SyntaxKind::PropertyDeclaration               => "property_declaration",
            SyntaxKind::PropertyDeclarator                => "property_declarator",
            SyntaxKind::NamespaceDeclaration              => "namespace_declaration",
            SyntaxKind::NamespaceDeclarationHeader        => "namespace_declaration_header",
            SyntaxKind::NamespaceBody                     => "namespace_body",
            SyntaxKind::NamespaceEmptyBody                => "namespace_empty_body",
            SyntaxKind::NamespaceUseDeclaration           => "namespace_use_declaration",
            SyntaxKind::NamespaceGroupUseDeclaration      => "namespace_group_use_declaration",
            SyntaxKind::NamespaceUseClause                => "namespace_use_clause",
            SyntaxKind::FunctionDeclaration               => "function_declaration",
            SyntaxKind::FunctionDeclarationHeader         => "function_declaration_header",
            SyntaxKind::Contexts                          => "contexts",
            SyntaxKind::WhereClause                       => "where_clause",
            SyntaxKind::WhereConstraint                   => "where_constraint",
            SyntaxKind::MethodishDeclaration              => "methodish_declaration",
            SyntaxKind::MethodishTraitResolution          => "methodish_trait_resolution",
            SyntaxKind::ClassishDeclaration               => "classish_declaration",
            SyntaxKind::ClassishBody                      => "classish_body",
            SyntaxKind::TraitUsePrecedenceItem            => "trait_use_precedence_item",
            SyntaxKind::TraitUseAliasItem                 => "trait_use_alias_item",
            SyntaxKind::TraitUseConflictResolution        => "trait_use_conflict_resolution",
            SyntaxKind::TraitUse                          => "trait_use",
            SyntaxKind::RequireClause                     => "require_clause",
            SyntaxKind::ConstDeclaration                  => "const_declaration",
            SyntaxKind::ConstantDeclarator                => "constant_declarator",
            SyntaxKind::TypeConstDeclaration              => "type_const_declaration",
            SyntaxKind::ContextConstDeclaration           => "context_const_declaration",
            SyntaxKind::DecoratedExpression               => "decorated_expression",
            SyntaxKind::ParameterDeclaration              => "parameter_declaration",
            SyntaxKind::VariadicParameter                 => "variadic_parameter",
            SyntaxKind::OldAttributeSpecification         => "old_attribute_specification",
            SyntaxKind::AttributeSpecification            => "attribute_specification",
            SyntaxKind::Attribute                         => "attribute",
            SyntaxKind::InclusionExpression               => "inclusion_expression",
            SyntaxKind::InclusionDirective                => "inclusion_directive",
            SyntaxKind::CompoundStatement                 => "compound_statement",
            SyntaxKind::ExpressionStatement               => "expression_statement",
            SyntaxKind::MarkupSection                     => "markup_section",
            SyntaxKind::MarkupSuffix                      => "markup_suffix",
            SyntaxKind::UnsetStatement                    => "unset_statement",
            SyntaxKind::UsingStatementBlockScoped         => "using_statement_block_scoped",
            SyntaxKind::UsingStatementFunctionScoped      => "using_statement_function_scoped",
            SyntaxKind::WhileStatement                    => "while_statement",
            SyntaxKind::IfStatement                       => "if_statement",
            SyntaxKind::ElseifClause                      => "elseif_clause",
            SyntaxKind::ElseClause                        => "else_clause",
            SyntaxKind::TryStatement                      => "try_statement",
            SyntaxKind::CatchClause                       => "catch_clause",
            SyntaxKind::FinallyClause                     => "finally_clause",
            SyntaxKind::DoStatement                       => "do_statement",
            SyntaxKind::ForStatement                      => "for_statement",
            SyntaxKind::ForeachStatement                  => "foreach_statement",
            SyntaxKind::SwitchStatement                   => "switch_statement",
            SyntaxKind::SwitchSection                     => "switch_section",
            SyntaxKind::SwitchFallthrough                 => "switch_fallthrough",
            SyntaxKind::CaseLabel                         => "case_label",
            SyntaxKind::DefaultLabel                      => "default_label",
            SyntaxKind::ReturnStatement                   => "return_statement",
            SyntaxKind::YieldBreakStatement               => "yield_break_statement",
            SyntaxKind::ThrowStatement                    => "throw_statement",
            SyntaxKind::BreakStatement                    => "break_statement",
            SyntaxKind::ContinueStatement                 => "continue_statement",
            SyntaxKind::EchoStatement                     => "echo_statement",
            SyntaxKind::ConcurrentStatement               => "concurrent_statement",
            SyntaxKind::SimpleInitializer                 => "simple_initializer",
            SyntaxKind::AnonymousClass                    => "anonymous_class",
            SyntaxKind::AnonymousFunction                 => "anonymous_function",
            SyntaxKind::AnonymousFunctionUseClause        => "anonymous_function_use_clause",
            SyntaxKind::LambdaExpression                  => "lambda_expression",
            SyntaxKind::LambdaSignature                   => "lambda_signature",
            SyntaxKind::CastExpression                    => "cast_expression",
            SyntaxKind::ScopeResolutionExpression         => "scope_resolution_expression",
            SyntaxKind::MemberSelectionExpression         => "member_selection_expression",
            SyntaxKind::SafeMemberSelectionExpression     => "safe_member_selection_expression",
            SyntaxKind::EmbeddedMemberSelectionExpression => "embedded_member_selection_expression",
            SyntaxKind::YieldExpression                   => "yield_expression",
            SyntaxKind::PrefixUnaryExpression             => "prefix_unary_expression",
            SyntaxKind::PostfixUnaryExpression            => "postfix_unary_expression",
            SyntaxKind::BinaryExpression                  => "binary_expression",
            SyntaxKind::IsExpression                      => "is_expression",
            SyntaxKind::AsExpression                      => "as_expression",
            SyntaxKind::NullableAsExpression              => "nullable_as_expression",
            SyntaxKind::ConditionalExpression             => "conditional_expression",
            SyntaxKind::EvalExpression                    => "eval_expression",
            SyntaxKind::IssetExpression                   => "isset_expression",
            SyntaxKind::FunctionCallExpression            => "function_call_expression",
            SyntaxKind::FunctionPointerExpression         => "function_pointer_expression",
            SyntaxKind::ParenthesizedExpression           => "parenthesized_expression",
            SyntaxKind::BracedExpression                  => "braced_expression",
            SyntaxKind::ETSpliceExpression                => "et_splice_expression",
            SyntaxKind::EmbeddedBracedExpression          => "embedded_braced_expression",
            SyntaxKind::ListExpression                    => "list_expression",
            SyntaxKind::CollectionLiteralExpression       => "collection_literal_expression",
            SyntaxKind::ObjectCreationExpression          => "object_creation_expression",
            SyntaxKind::ConstructorCall                   => "constructor_call",
            SyntaxKind::RecordCreationExpression          => "record_creation_expression",
            SyntaxKind::DarrayIntrinsicExpression         => "darray_intrinsic_expression",
            SyntaxKind::DictionaryIntrinsicExpression     => "dictionary_intrinsic_expression",
            SyntaxKind::KeysetIntrinsicExpression         => "keyset_intrinsic_expression",
            SyntaxKind::VarrayIntrinsicExpression         => "varray_intrinsic_expression",
            SyntaxKind::VectorIntrinsicExpression         => "vector_intrinsic_expression",
            SyntaxKind::ElementInitializer                => "element_initializer",
            SyntaxKind::SubscriptExpression               => "subscript_expression",
            SyntaxKind::EmbeddedSubscriptExpression       => "embedded_subscript_expression",
            SyntaxKind::AwaitableCreationExpression       => "awaitable_creation_expression",
            SyntaxKind::XHPChildrenDeclaration            => "xhp_children_declaration",
            SyntaxKind::XHPChildrenParenthesizedList      => "xhp_children_parenthesized_list",
            SyntaxKind::XHPCategoryDeclaration            => "xhp_category_declaration",
            SyntaxKind::XHPEnumType                       => "xhp_enum_type",
            SyntaxKind::XHPLateinit                       => "xhp_lateinit",
            SyntaxKind::XHPRequired                       => "xhp_required",
            SyntaxKind::XHPClassAttributeDeclaration      => "xhp_class_attribute_declaration",
            SyntaxKind::XHPClassAttribute                 => "xhp_class_attribute",
            SyntaxKind::XHPSimpleClassAttribute           => "xhp_simple_class_attribute",
            SyntaxKind::XHPSimpleAttribute                => "xhp_simple_attribute",
            SyntaxKind::XHPSpreadAttribute                => "xhp_spread_attribute",
            SyntaxKind::XHPOpen                           => "xhp_open",
            SyntaxKind::XHPExpression                     => "xhp_expression",
            SyntaxKind::XHPClose                          => "xhp_close",
            SyntaxKind::TypeConstant                      => "type_constant",
            SyntaxKind::VectorTypeSpecifier               => "vector_type_specifier",
            SyntaxKind::KeysetTypeSpecifier               => "keyset_type_specifier",
            SyntaxKind::TupleTypeExplicitSpecifier        => "tuple_type_explicit_specifier",
            SyntaxKind::VarrayTypeSpecifier               => "varray_type_specifier",
            SyntaxKind::FunctionCtxTypeSpecifier          => "function_ctx_type_specifier",
            SyntaxKind::TypeParameter                     => "type_parameter",
            SyntaxKind::TypeConstraint                    => "type_constraint",
            SyntaxKind::ContextConstraint                 => "context_constraint",
            SyntaxKind::DarrayTypeSpecifier               => "darray_type_specifier",
            SyntaxKind::DictionaryTypeSpecifier           => "dictionary_type_specifier",
            SyntaxKind::ClosureTypeSpecifier              => "closure_type_specifier",
            SyntaxKind::ClosureParameterTypeSpecifier     => "closure_parameter_type_specifier",
            SyntaxKind::ClassnameTypeSpecifier            => "classname_type_specifier",
            SyntaxKind::FieldSpecifier                    => "field_specifier",
            SyntaxKind::FieldInitializer                  => "field_initializer",
            SyntaxKind::ShapeTypeSpecifier                => "shape_type_specifier",
            SyntaxKind::ShapeExpression                   => "shape_expression",
            SyntaxKind::TupleExpression                   => "tuple_expression",
            SyntaxKind::GenericTypeSpecifier              => "generic_type_specifier",
            SyntaxKind::NullableTypeSpecifier             => "nullable_type_specifier",
            SyntaxKind::LikeTypeSpecifier                 => "like_type_specifier",
            SyntaxKind::SoftTypeSpecifier                 => "soft_type_specifier",
            SyntaxKind::AttributizedSpecifier             => "attributized_specifier",
            SyntaxKind::ReifiedTypeArgument               => "reified_type_argument",
            SyntaxKind::TypeArguments                     => "type_arguments",
            SyntaxKind::TypeParameters                    => "type_parameters",
            SyntaxKind::TupleTypeSpecifier                => "tuple_type_specifier",
            SyntaxKind::UnionTypeSpecifier                => "union_type_specifier",
            SyntaxKind::IntersectionTypeSpecifier         => "intersection_type_specifier",
            SyntaxKind::ErrorSyntax                       => "error",
            SyntaxKind::ListItem                          => "list_item",
            SyntaxKind::EnumClassLabelExpression          => "enum_class_label",
        }
    }

    pub fn ocaml_tag(self) -> u8 {
        match self {
            SyntaxKind::Missing => 0,
            SyntaxKind::Token(_) => 0,
            SyntaxKind::SyntaxList => 1,
            SyntaxKind::EndOfFile => 2,
            SyntaxKind::Script => 3,
            SyntaxKind::QualifiedName => 4,
            SyntaxKind::SimpleTypeSpecifier => 5,
            SyntaxKind::LiteralExpression => 6,
            SyntaxKind::PrefixedStringExpression => 7,
            SyntaxKind::PrefixedCodeExpression => 8,
            SyntaxKind::VariableExpression => 9,
            SyntaxKind::PipeVariableExpression => 10,
            SyntaxKind::FileAttributeSpecification => 11,
            SyntaxKind::EnumDeclaration => 12,
            SyntaxKind::EnumUse => 13,
            SyntaxKind::Enumerator => 14,
            SyntaxKind::EnumClassDeclaration => 15,
            SyntaxKind::EnumClassEnumerator => 16,
            SyntaxKind::RecordDeclaration => 17,
            SyntaxKind::RecordField => 18,
            SyntaxKind::AliasDeclaration => 19,
            SyntaxKind::PropertyDeclaration => 20,
            SyntaxKind::PropertyDeclarator => 21,
            SyntaxKind::NamespaceDeclaration => 22,
            SyntaxKind::NamespaceDeclarationHeader => 23,
            SyntaxKind::NamespaceBody => 24,
            SyntaxKind::NamespaceEmptyBody => 25,
            SyntaxKind::NamespaceUseDeclaration => 26,
            SyntaxKind::NamespaceGroupUseDeclaration => 27,
            SyntaxKind::NamespaceUseClause => 28,
            SyntaxKind::FunctionDeclaration => 29,
            SyntaxKind::FunctionDeclarationHeader => 30,
            SyntaxKind::Contexts => 31,
            SyntaxKind::WhereClause => 32,
            SyntaxKind::WhereConstraint => 33,
            SyntaxKind::MethodishDeclaration => 34,
            SyntaxKind::MethodishTraitResolution => 35,
            SyntaxKind::ClassishDeclaration => 36,
            SyntaxKind::ClassishBody => 37,
            SyntaxKind::TraitUsePrecedenceItem => 38,
            SyntaxKind::TraitUseAliasItem => 39,
            SyntaxKind::TraitUseConflictResolution => 40,
            SyntaxKind::TraitUse => 41,
            SyntaxKind::RequireClause => 42,
            SyntaxKind::ConstDeclaration => 43,
            SyntaxKind::ConstantDeclarator => 44,
            SyntaxKind::TypeConstDeclaration => 45,
            SyntaxKind::ContextConstDeclaration => 46,
            SyntaxKind::DecoratedExpression => 47,
            SyntaxKind::ParameterDeclaration => 48,
            SyntaxKind::VariadicParameter => 49,
            SyntaxKind::OldAttributeSpecification => 50,
            SyntaxKind::AttributeSpecification => 51,
            SyntaxKind::Attribute => 52,
            SyntaxKind::InclusionExpression => 53,
            SyntaxKind::InclusionDirective => 54,
            SyntaxKind::CompoundStatement => 55,
            SyntaxKind::ExpressionStatement => 56,
            SyntaxKind::MarkupSection => 57,
            SyntaxKind::MarkupSuffix => 58,
            SyntaxKind::UnsetStatement => 59,
            SyntaxKind::UsingStatementBlockScoped => 60,
            SyntaxKind::UsingStatementFunctionScoped => 61,
            SyntaxKind::WhileStatement => 62,
            SyntaxKind::IfStatement => 63,
            SyntaxKind::ElseifClause => 64,
            SyntaxKind::ElseClause => 65,
            SyntaxKind::TryStatement => 66,
            SyntaxKind::CatchClause => 67,
            SyntaxKind::FinallyClause => 68,
            SyntaxKind::DoStatement => 69,
            SyntaxKind::ForStatement => 70,
            SyntaxKind::ForeachStatement => 71,
            SyntaxKind::SwitchStatement => 72,
            SyntaxKind::SwitchSection => 73,
            SyntaxKind::SwitchFallthrough => 74,
            SyntaxKind::CaseLabel => 75,
            SyntaxKind::DefaultLabel => 76,
            SyntaxKind::ReturnStatement => 77,
            SyntaxKind::YieldBreakStatement => 78,
            SyntaxKind::ThrowStatement => 79,
            SyntaxKind::BreakStatement => 80,
            SyntaxKind::ContinueStatement => 81,
            SyntaxKind::EchoStatement => 82,
            SyntaxKind::ConcurrentStatement => 83,
            SyntaxKind::SimpleInitializer => 84,
            SyntaxKind::AnonymousClass => 85,
            SyntaxKind::AnonymousFunction => 86,
            SyntaxKind::AnonymousFunctionUseClause => 87,
            SyntaxKind::LambdaExpression => 88,
            SyntaxKind::LambdaSignature => 89,
            SyntaxKind::CastExpression => 90,
            SyntaxKind::ScopeResolutionExpression => 91,
            SyntaxKind::MemberSelectionExpression => 92,
            SyntaxKind::SafeMemberSelectionExpression => 93,
            SyntaxKind::EmbeddedMemberSelectionExpression => 94,
            SyntaxKind::YieldExpression => 95,
            SyntaxKind::PrefixUnaryExpression => 96,
            SyntaxKind::PostfixUnaryExpression => 97,
            SyntaxKind::BinaryExpression => 98,
            SyntaxKind::IsExpression => 99,
            SyntaxKind::AsExpression => 100,
            SyntaxKind::NullableAsExpression => 101,
            SyntaxKind::ConditionalExpression => 102,
            SyntaxKind::EvalExpression => 103,
            SyntaxKind::IssetExpression => 104,
            SyntaxKind::FunctionCallExpression => 105,
            SyntaxKind::FunctionPointerExpression => 106,
            SyntaxKind::ParenthesizedExpression => 107,
            SyntaxKind::BracedExpression => 108,
            SyntaxKind::ETSpliceExpression => 109,
            SyntaxKind::EmbeddedBracedExpression => 110,
            SyntaxKind::ListExpression => 111,
            SyntaxKind::CollectionLiteralExpression => 112,
            SyntaxKind::ObjectCreationExpression => 113,
            SyntaxKind::ConstructorCall => 114,
            SyntaxKind::RecordCreationExpression => 115,
            SyntaxKind::DarrayIntrinsicExpression => 116,
            SyntaxKind::DictionaryIntrinsicExpression => 117,
            SyntaxKind::KeysetIntrinsicExpression => 118,
            SyntaxKind::VarrayIntrinsicExpression => 119,
            SyntaxKind::VectorIntrinsicExpression => 120,
            SyntaxKind::ElementInitializer => 121,
            SyntaxKind::SubscriptExpression => 122,
            SyntaxKind::EmbeddedSubscriptExpression => 123,
            SyntaxKind::AwaitableCreationExpression => 124,
            SyntaxKind::XHPChildrenDeclaration => 125,
            SyntaxKind::XHPChildrenParenthesizedList => 126,
            SyntaxKind::XHPCategoryDeclaration => 127,
            SyntaxKind::XHPEnumType => 128,
            SyntaxKind::XHPLateinit => 129,
            SyntaxKind::XHPRequired => 130,
            SyntaxKind::XHPClassAttributeDeclaration => 131,
            SyntaxKind::XHPClassAttribute => 132,
            SyntaxKind::XHPSimpleClassAttribute => 133,
            SyntaxKind::XHPSimpleAttribute => 134,
            SyntaxKind::XHPSpreadAttribute => 135,
            SyntaxKind::XHPOpen => 136,
            SyntaxKind::XHPExpression => 137,
            SyntaxKind::XHPClose => 138,
            SyntaxKind::TypeConstant => 139,
            SyntaxKind::VectorTypeSpecifier => 140,
            SyntaxKind::KeysetTypeSpecifier => 141,
            SyntaxKind::TupleTypeExplicitSpecifier => 142,
            SyntaxKind::VarrayTypeSpecifier => 143,
            SyntaxKind::FunctionCtxTypeSpecifier => 144,
            SyntaxKind::TypeParameter => 145,
            SyntaxKind::TypeConstraint => 146,
            SyntaxKind::ContextConstraint => 147,
            SyntaxKind::DarrayTypeSpecifier => 148,
            SyntaxKind::DictionaryTypeSpecifier => 149,
            SyntaxKind::ClosureTypeSpecifier => 150,
            SyntaxKind::ClosureParameterTypeSpecifier => 151,
            SyntaxKind::ClassnameTypeSpecifier => 152,
            SyntaxKind::FieldSpecifier => 153,
            SyntaxKind::FieldInitializer => 154,
            SyntaxKind::ShapeTypeSpecifier => 155,
            SyntaxKind::ShapeExpression => 156,
            SyntaxKind::TupleExpression => 157,
            SyntaxKind::GenericTypeSpecifier => 158,
            SyntaxKind::NullableTypeSpecifier => 159,
            SyntaxKind::LikeTypeSpecifier => 160,
            SyntaxKind::SoftTypeSpecifier => 161,
            SyntaxKind::AttributizedSpecifier => 162,
            SyntaxKind::ReifiedTypeArgument => 163,
            SyntaxKind::TypeArguments => 164,
            SyntaxKind::TypeParameters => 165,
            SyntaxKind::TupleTypeSpecifier => 166,
            SyntaxKind::UnionTypeSpecifier => 167,
            SyntaxKind::IntersectionTypeSpecifier => 168,
            SyntaxKind::ErrorSyntax => 169,
            SyntaxKind::ListItem => 170,
            SyntaxKind::EnumClassLabelExpression => 171,
        }
    }
}
