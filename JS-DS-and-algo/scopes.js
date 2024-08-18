//let and const are blocked scope but var is not

{
  var a = 5;
}

console.log(a); // 5

{
  let b = 5;
  const c = 6;
}

//console.log(b); // Reference Error b is not defined

// Shadowing
function test() {
  let a = "Hello";

  if (true) {
    let a = "Hi";
    console.log(a);
  }
  console.log(a);
}
test();
// O/P
// Hi
// Hello

//Illegal Shadowing
// A variable should not cross the boundary of its scope.
//We can shadow var from let, but vice versa is not true.
//So, if you try to shadow let from var it is known as Illegal Shadowing.

function illegalShadowing() {
  var a = "Hello";
  let b = "Bye";
  if (true) {
    let a = "Hi";
    //  var b = "Goodbye"; //b has already been declared
    console.log(a);
    console.log(b);
  }
}
illegalShadowing();

//Var can be redeclared in the same scope
var a = 34;
var a = 94;
console.log(a);
// Let and const cannot be redeclared
// Uncomment to see
// let b;
// let b;

//Reinitialization
let m = 54;
m = 56;

var x = 34;
x = 78;

//You cannot do same thing with const
const z = 34;
// z = 56; Error:- Assignment to a constant variable
console.log(z);
//Hoisting

function abc() {
  console.log(a);

  var a = 123;
}
abc();

// FUNCTION SCOPES

var func_scoped = 21;

var fun = function () {
  console.log(func_scope); //undefined
  var func_scope = 33;
};

fun();
