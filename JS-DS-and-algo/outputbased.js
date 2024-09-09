//1.)
function sum() {
  let a = 8;
  const b = 2;
  var c = a + b;
}
// console.log(a, b, c);
// sum();
// console.log(a, b, c);

//2.)
let arr = [1, 2, 3, 4, 5];
console.log(arr[2], arr.length);
arr.length = 0;
console.log(arr[2], arr.length);

//3.)
let count = 0;
(function immediate() {
  if (count === 0) {
    let count = 1;
    console.log(count); // What is logged?
  }
  console.log(count); // What is logged?
})();

//4.)
console.log(1 + false); // 1
console.log(1 + true); // 2
console.log(1 - false); // 1
console.log(1 + "2" - 1); // 11

//5.)
console.log("5------");

(function fnA(a) {
  return (function fnB(b) {
    console.log(a); // What is logged?
  })(1);
})(0);

// const nums = [1,2,3,4,5,6,7];
// nums.forEach((n) => {
//     if(n%2 === 0)
//       break;
//     console.log(n);
// });

let a = true;
setTimeout(() => {
  a = false;
}, 2000);

while (a) {
  console.log(" -- inside whilee -- ");
}
//INFINITE TIMES

async function foo() {
  console.log("A");
  await Promise.resolve();
  console.log("B");
  await new Promise((resolve) => setTimeout(resolve, 0));
  console.log("C");
}

console.log("D");
foo();
console.log("E");

//D,A,E,B,C
