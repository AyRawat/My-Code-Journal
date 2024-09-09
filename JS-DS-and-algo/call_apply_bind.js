const age = 10;
var person = {
  name: "Ayush",
  age: 20,
  getAge: function () {
    return this.age;
  },
};

var person2 = { age: 24 };
person.getAge.call(person2);
// 2).
let status = "Answer1";

setTimeout(() => {
  const status = "Answer2";

  const data = {
    status: "Answer3",
    getStatus() {
      return this.status;
    },
  };
  console.log(data.getStatus()); //Answer3
  console.log(data.getStatus.call(this)); //Answer 1
}, 0);

// 3).
const animals = [
  { species: "Lion", name: "King" },
  { species: "Whale", name: "Queen" },
];
function printAnimals(i) {
  this.print = function () {
    console.log("#" + i + " " + this.species + ":" + this.name);
  };
  this.print();
}
for (let i = 0; i < animals.length; i++) {
  printAnimals.call(animals[i], i);
}

//Append an array to another array without concat, you need to modify the original array.
const array = ["a", "b"];
const elements = [0, 1, 2];

array.push.apply(array, elements);

//Fin min/max in an array

const numbers = [5, 6, 7, 8, 9];
console.log(Math.max(numbers)); // NaN
console.log(Math.max.apply(null, numbers));
console.log(Math.min.apply(null, numbers));

//What is the O/p
function f() {
  console.log(this); //Window
}

let user = {
  g: f.bind(null),
};
user.g();

//O/P Window

//Bind Chaining
function f() {
  console.log(this.name);
}

f = f.bind({ name: "John" }).bind({ name: "Ann" });
f();

//O/P JOhn
//Bind Chaining Doesn't exist

function checkPassword(success, failed) {
  let password = prompt("Password ?", "");
  if (password == "Roadside Coder") success();
  else failed();
}

let userData = {
  name: "Ayush",
  loginSuccessful() {
    console.log(`${this.name} logged In`);
  },
  loginFailed() {
    console.log(`${this.name} faield to log In`);
  },
};
checkPassword(userData.loginSuccessful, userData.loginFailed);
//Fix the above function, as it fails to return this.name,

checkPassword(
  userData.loginSuccessful.bind(user),
  userData.loginFailed.bind(user)
);
//Explicit Binding With Arrow Functions
//Arrow functions behave as they normally behave, so there is no use of call apply and bind with these

//Pollyfill for CALL, APPLY and BIND

// CALL
Function.prototype.customCall = function (context = {}, ...args) {
  //check if customCall was called on a valid function or not
  if (typeof this !== "function") {
    throw new Error(this + "It's not callable");
  }
  //we add the function, that this function was called on , to the context of our passed object
  context.fn = this;
  //And we immediately invoke it
  context.fn(...args);
};

//APPLY

Function.prototype.customApply = function (context = {}, args) {
  //check if customCall was called on a valid function or not
  if (typeof this !== "function") {
    throw new Error(this + "It's not callable");
  }
  if (Array.isArray(args)) {
    throw new TypeError("CreateListFromArrayLike called on non-object");
  }
  //we add the function, that this function was called on , to the context of our passed object
  context.fn = this;
  //And we immediately invoke it
  context.fn(args);
};

// BIND
Function.prototype.customBind = function (context = {}, ...args) {
  if (typeof this !== "function") {
    throw new Error(this + "cannot be bound as it's not callable");
  }

  context.fn = this;
  return function (...newArgs) {
    return context.fn(...args, ...newArgs);
  };
};

Function.prototype.myCall = function (context, ...args) {
  console.log("this ", this);
  console.log("context ", context);
  console.log("args ", args);
  context.func = this;
  console.log("context1 ", context);
  context.func(...args);
};

let car1 = {
  color: "Red",
  company: "Ferrari",
};

function purchaseCar(currency, price) {
  console.log(
    `I have purchased ${this.color} - ${this.company} car for ${currency}${price}`
  );
}

purchaseCar.myCall(car1, "RS", "10000000");
