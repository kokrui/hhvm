<?hh

function f(string $s): void {}

function main1(dynamic $d): void {
  f($d);
}

function main2(dynamic $d): void {
  f($d);
}
