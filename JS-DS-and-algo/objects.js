//Q1

const func = (function (a) {
  delete a;
  return a;
})(5);

//OP-> 5
// delete works only on Object Properties not on local Variables

//Loop throught the keys in an objects

const obj = {
  a: "one",
  b: "two",
  a: "three",
};

for (key in obj) {
  console.log(key);
}

//Q3
const a = {};
const b = { key: "b" };
const c = { key: "c" };

a[b] = 123;
a[c] = 456;

console.log(a[b]);

//O/P ->456
//The object cannot be converted to a key
//Reason , a["[object Object]"] = 123
//a["[object Object]"] = 456;

const settings = {
  username: "Ayush",
  level: 22,
  health: 90,
};

const data = JSON.stringify(settings, ["level", "health"]);
console.log(data);
//This means, it is going to stringify only level and health.
let person = { name: "Lydia" };
const members = [person];
person = null;

//O/P {name:"Lydia"}

//If person.name = null
//O/p {name:null}

//What is the Output
const value = { number: 10 };

const multiply = (x = { ...value }) => {
  console.log((x.number *= 2));
};

multiply(); //20
multiply(); //20
multiply(value); //20
multiply(value); //40

//How to clone an Object

let user = {
  name: "Ayush",
  age: 24,
};

const objClone = Object.assign({}, user);
const objClone2 = JSON.parse(JSON.stringify(user));
