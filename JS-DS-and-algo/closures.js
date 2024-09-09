//Q1
let count = 0;
(function printCount() {
  if (count === 0) {
    let count = 1;
    console.log(count);
  }
  console.log(count);
})();
// O/P - 1
//       0

//Q2 Write a function that would allow to do this
var addSiz = createBase(6);
addSiz(10); //returns 16
addSiz(21); //returns 27

function createBase(num) {
  return function addV(n) {
    console.log(num + n);
  };
}

//Q3 Time Optimization using Closure
function find(index) {
  let a = [];
  for (let i = 0; i < 1000000; i++) {
    a[i] = i * i;
  }
  console.log(a[index]);
}

//Optimized
function find() {
  let a = [];
  for (let i = 0; i < 1000000; i++) {
    a[i] = i * i;
  }
  return function (index) {
    console.log(a[index]);
  };
}
console.time("6");
find(6);
console.timeEnd("6");
console.time("12");
find("12");
console.timeEnd("12");

//How would you use closure to create a private counter

function Counter() {
  var _counter = 0;
  function add(increment) {
    _counter += increment;
  }
  function get() {
    return "Counter " + _counter;
  }
  return { add, get };
}

const c = Counter();
c.add(5);
c.get(10);

//What is a module Pattern ?
var ModulePattern = (function () {
  function PrivateMethod() {
    //do Something
    console.log("Private");
  }

  return {
    publicMethod: function () {
      //can call Private Method
      console.log("PUblic");
    },
  };
})();

//Make this function run only Once

let view;
function likeTheVideo() {
  view = "Ayush";
  console.log(view);
}
function likeTheVideoOp() {
  let called = 0;
  return function () {
    if (called > 0) {
      console.log("Already Called");
    } else {
      view = "Ayush";
      console.log("Result ", view);
      called++;
    }
  };
}
likeTheVideo();
//This above is not a generic function, You have to create something like ONCE , present in _lodash
//Pollyfill
function once(func, context) {
  let ran;

  return function () {
    if (func) {
      ran = func.apply(context || this, arguments);
      func = null;
    }
    return ran;
  };
}

//Create a Pollyfill  for Memoize/Caching Function, for this clumsyFUnction
// which  calculates every time, even for the same arguments

const clumsySquare = (num1, num2) => {
  for (let i = 1; i <= 1000_000_000; i++) {}
  return num1 * num2;
};

console.time("First Call");
console.log(clumsySquare(9467, 7649));
console.timeEnd("First Call");

console.time("Second Call");
console.log(clumsySquare(9467, 7649));
console.timeEnd("Second Call");

function myMemoise(fn, context) {
  const res = {};
  return function (...args) {
    var argsCache = JSON.stringify(args);
    if (!res[argsCache]) {
      res[argsCache] = fn.call(context || this, ...args);
    }
    return res[argsCache];
  };
}

const myMemoizeF = myMemoise(clumsySquare);

console.time("First Call");
console.log(myMemoizeF(9467, 7649));
console.timeEnd("First Call");

console.time("Second Call");
console.log(myMemoizeF(9467, 7649));
console.timeEnd("Second Call");

function test() {
  for (var i = 0; i < 5; i++) {
    setTimeout(() => {
      console.log(i);
    }, i * 1000);
  }
  console.log("Hello");
}
//Running this with var
function testV() {
  for (var i = 0; i < 5; i++) {
    function close(y) {
      setTimeout(() => {
        console.log(y);
      }, y * 1000);
    }
    close(i);
  }
}

test();
