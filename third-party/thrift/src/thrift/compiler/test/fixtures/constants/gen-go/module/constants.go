// Autogenerated by Thrift Compiler (facebook)
// DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
// @generated

package module

import (
	"bytes"
	"context"
	"sync"
	"fmt"
	thrift "github.com/facebook/fbthrift/thrift/lib/go/thrift"
)

// (needed to ensure safety because of naive import list construction.)
var _ = thrift.ZERO
var _ = fmt.Printf
var _ = sync.Mutex{}
var _ = bytes.Equal
var _ = context.Background

const MyInt = 1337
const Name = "Mark Zuckerberg"
const MultiLineString = "This\nis a\nmulti line string.\n"
var States []map[string]int32
const X = 1
const Y = 1000000
const Z = 1e+09
const ZeroDoubleValue = 0
const LongDoubleValue = 2.59961e-05
var MyCompany MyCompany
var Foo MyStringIdentifier
var Bar MyIntIdentifier
var Mymap MyMapIdentifier
var Instagram *Internship
var PartialConst *Internship
var KRanges []*Range
var InternList []*Internship
var Pod_0 *Struct1
var PodS_0 *Struct1
var Pod_1 *Struct1
var PodS_1 *Struct1
var Pod_2 *Struct2
var PodTrailingCommas *Struct2
var PodS_2 *Struct2
var Pod_3 *Struct3
var PodS_3 *Struct3
var Pod_4 *Struct4
var U_1_1 *Union1
var U_1_2 *Union1
var U_1_3 *Union1
var U_2_1 *Union2
var U_2_2 *Union2
var U_2_3 *Union2
var U_2_4 *Union2
var U_2_5 *Union2
var U_2_6 *Union2
const Apostrophe = "'"
const TripleApostrophe = "'''"
const QuotationMark = "\""
const Backslash = "\\"
const EscapedA = "a"
var Char2ascii map[string]int32
var EscapedStrings []string
const FalseC = false
const TrueC = true
const ZeroByte = 0
const Zero16 = 0
const Zero32 = 0
const Zero64 = 0
const ZeroDotZero = 0
const EmptyString = ""
var EmptyIntList []int32
var EmptyStringList []string
var EmptyIntSet []int32
var EmptyStringSet []string
var EmptyIntIntMap map[int32]int32
var EmptyIntStringMap map[int32]string
var EmptyStringIntMap map[string]int32
var EmptyStringStringMap map[string]string
const MaxIntDec = 9223372036854775807
const MaxIntOct = 9223372036854775807
const MaxIntHex = 9223372036854775807
const MaxIntBin = 9223372036854775807
const MaxDub = 1.79769e+308
const MinDub = 2.22507e-308
const MinSDub = 4.94066e-324
const MaxPIntDec = 9223372036854775807
const MaxPIntOct = 9223372036854775807
const MaxPIntHex = 9223372036854775807
const MaxPIntBin = 9223372036854775807
const MaxPDub = 1.79769e+308
const MinPDub = 2.22507e-308
const MinPSDub = 4.94066e-324
const MinIntDec = -9223372036854775808
const MinIntOct = -9223372036854775808
const MinIntHex = -9223372036854775808
const MinIntBin = -9223372036854775808
const MaxNDub = -1.79769e+308
const MinNDub = -2.22507e-308
const MinNSDub = -4.94066e-324
var const_lit_Instagram_employer Company = 3
var const_lit_Instagram_compensation float64 = 1200
var const_lit_Instagram_school string = "Monters University"
var const_lit_InternList_0_employer Company = 3
var const_lit_InternList_0_compensation float64 = 1200
var const_lit_InternList_0_school string = "Monters University"
var const_lit_InternList_1_employer Company = 0
var const_lit_InternList_1_compensation float64 = 1000
var const_lit_Pod_4_b float64 = 0.333
var const_lit_Pod_4_c int8 = 25
var const_lit_U_1_1_i int32 = 97
var const_lit_U_1_2_d float64 = 5.6
var const_lit_U_2_1_i int32 = 51
var const_lit_U_2_2_d float64 = 6.7
var const_lit_U_2_4_u_i int32 = 43
var const_lit_U_2_5_u_d float64 = 9.8

func init() {
States = []map[string]int32{
  map[string]int32{
    "San Diego": 3211000,
    "Sacramento": 479600,
    "SF": 837400,
  },
  map[string]int32{
    "New York": 8406000,
    "Albany": 98400,
  },
}

MyCompany = 0

Foo = "foo"

Bar = 42

Mymap = map[string]string{
  "keys": "values",
}

Instagram = &Internship{
  Weeks: 12,
  Title: "Software Engineer",
  Employer: &const_lit_Instagram_employer,
  Compensation: &const_lit_Instagram_compensation,
  School: &const_lit_Instagram_school,
}

PartialConst = &Internship{
  Weeks: 8,
  Title: "Some Job",
}

KRanges = []*Range{
  &Range{
    Min: 1,
    Max: 2,
  },
  &Range{
    Min: 5,
    Max: 6,
  },
}

InternList = []*Internship{
  &Internship{
    Weeks: 12,
    Title: "Software Engineer",
    Employer: &const_lit_InternList_0_employer,
    Compensation: &const_lit_InternList_0_compensation,
    School: &const_lit_InternList_0_school,
  },
  &Internship{
    Weeks: 10,
    Title: "Sales Intern",
    Employer: &const_lit_InternList_1_employer,
    Compensation: &const_lit_InternList_1_compensation,
  },
}

Pod_0 = &Struct1{
}

PodS_0 = &Struct1{
}

Pod_1 = &Struct1{
  A: 10,
  B: "foo",
}

PodS_1 = &Struct1{
  A: 10,
  B: "foo",
}

Pod_2 = &Struct2{
  A: 98,
  B: "gaz",
  C: &Struct1{
    A: 12,
    B: "bar",
  },
  D: []int32{
    11,
    22,
    33,
  },
}

PodTrailingCommas = &Struct2{
  A: 98,
  B: "gaz",
  C: &Struct1{
    A: 12,
    B: "bar",
  },
  D: []int32{
    11,
    22,
    33,
  },
}

PodS_2 = &Struct2{
  A: 98,
  B: "gaz",
  C: &Struct1{
    A: 12,
    B: "bar",
  },
  D: []int32{
    11,
    22,
    33,
  },
}

Pod_3 = &Struct3{
  A: "abc",
  B: 456,
  C: &Struct2{
    A: 888,
    C: &Struct1{
      B: "gaz",
    },
    D: []int32{
      1,
      2,
      3,
    },
  },
}

PodS_3 = &Struct3{
  A: "abc",
  B: 456,
  C: &Struct2{
    A: 888,
    C: &Struct1{
      B: "gaz",
    },
    D: []int32{
      1,
      2,
      3,
    },
  },
}

Pod_4 = &Struct4{
  A: 1234,
  B: &const_lit_Pod_4_b,
  C: &const_lit_Pod_4_c,
}

U_1_1 = &Union1{
  I: &const_lit_U_1_1_i,
}

U_1_2 = &Union1{
  D: &const_lit_U_1_2_d,
}

U_1_3 = &Union1{
}

U_2_1 = &Union2{
  I: &const_lit_U_2_1_i,
}

U_2_2 = &Union2{
  D: &const_lit_U_2_2_d,
}

U_2_3 = &Union2{
  S: &Struct1{
    A: 8,
    B: "abacabb",
  },
}

U_2_4 = &Union2{
  U: &Union1{
    I: &const_lit_U_2_4_u_i,
  },
}

U_2_5 = &Union2{
  U: &Union1{
    D: &const_lit_U_2_5_u_d,
  },
}

U_2_6 = &Union2{
  U: &Union1{
  },
}

Char2ascii = map[string]int32{
  "'": 39,
  "\"": 34,
  "\\": 92,
  "a": 97,
}

EscapedStrings = []string{
  "",
  "",
  " ",
  "'",
  "\"",
  "\n",
  "\r",
  "\t",
  "a",
  "«",
  "j",
  "¦",
  "ayyy",
  "«yyy",
  "jyyy",
  "¦yyy",
  "zzza",
  "zzz«",
  "zzzj",
  "zzz¦",
  "zzzayyy",
  "zzz«yyy",
  "zzzjyyy",
  "zzz¦yyy",
}

EmptyIntList = []int32{
}

EmptyStringList = []string{
}

EmptyIntSet = []int32{
}

EmptyStringSet = []string{
}

EmptyIntIntMap = map[int32]int32{
}

EmptyIntStringMap = map[int32]string{
}

EmptyStringIntMap = map[string]int32{
}

EmptyStringStringMap = map[string]string{
}

}

