//Example of variable shadowing

function hoist() {
  let a = "Hello";
  if (true) {
    let a = "Hi";
    console.log(a);
  }

  console.log(a);
}
hoist();

function abc() {
  console.log(a, b, c);

  var a = 10;
  const b = 20;
  let c = 30;
}

/// 3.
var x = 21;

var func = function () {
  console.log(x);
  var x = 30;
};

func(); //O/P : undefined because we have the same variable available in our block scope
