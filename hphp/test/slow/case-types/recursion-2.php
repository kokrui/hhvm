<?hh

<<file:__EnableUnstableFeatures('case_types')>>

case type C1 = int | C2;
case type C2 = int | C1;

<<__EntryPoint>>
function main() {
  type_structure_for_alias('C1');
}