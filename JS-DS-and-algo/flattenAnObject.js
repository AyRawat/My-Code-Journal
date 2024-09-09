function FlattenObject(obj, parentKey = "", result = {}) {
  for (let key in obj) {
    if (obj.hasOwnProperty(key)) {
      const newKey = parentKey ? `${parentKey}.${key}` : key;
      if (
        typeof obj[key] === "object" &&
        obj[key] !== null &&
        !Array.isArray(obj[key])
      ) {
        FlattenObject(obj[key], newKey, result);
      } else {
        result[newKey] = obj[key];
      }
    }
  }
}

function func1() {
  // setTimeout(()=>{
  console.log(x);
  console.log(y);
  // },3000);

  var x = 2;
  let y = 12;
}
func1();

//Output
// 2
// 12
// //
// undefined
// ReferenceError

// GEC

// let isLoopRunning = true

// setTimeout(() => {isLoopRunning = false}, 2000)

// while(isLoopRunning) {
//   console.log('loop is running')
// }

const timer1 = setTimeout(() => {
  console.log("timer1");

  const promise1 = Promise.resolve().then(() => {
    console.log("promise1");
  });
}, 2000);

const timer2 = setTimeout(() => {
  console.log("timer2");
}, 2000);

// const a = []
// console.lg()

//Output
// timer1
// promise1
// timer2

// timerQ = [];

let obj1 = { x: 1, y: { z: 2 } };
let obj2 = deepCopy(obj1);

obj2.x = 10;
obj2.y.z = 20;
console.log("Obj2 -> ", obj2);
console.log("obj1 -> ", obj1);
//params
function deepCopy(obj1) {
  let result = {};
  for (let key in obj1) {
    if (typeof obj1[key] === "object") {
      result[key] = deepCopy(obj1[key]);
    } else {
      result[key] = obj1[key];
      console.log("Result ", key);
    }
  }
  return result;
}
//
//Output
// obj1 = {x:1, y: {z: 20}, d:6};
// obj2 = {x:10, y: {z: 20}, d:60};
