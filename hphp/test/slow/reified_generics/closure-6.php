<?hh

class C {
  public function f() {
    var_dump("yep!");
  }
}

function f<reified T1>() {
  $x = function() {
    $c = new T1();
    $c->f();
  };
  $x();
}

f<reified C>();
