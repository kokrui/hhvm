// @generated by Thrift for [[[ program path ]]]
// This file is probably not the place you want to edit!

package service // [[[ program thrift source path ]]]

import (
  "fmt"

  module "module"
  includes "includes"
  "github.com/facebook/fbthrift/thrift/lib/go/thrift"
)

var _ = module.GoUnusedProtection__
var _ = includes.GoUnusedProtection__

// (needed to ensure safety because of naive import list construction)
var _ = fmt.Printf
var _ = thrift.ZERO


type IncludesIncluded = includes.Included

type IncludesTransitiveFoo = includes.TransitiveFoo
