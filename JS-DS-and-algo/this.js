//Global
this.a = 5;
console.log(this.a);

function getParam() {
  console.log(this.a);
}
// const getParam = () => {
//   console.log(this.a); //5
// };
getParam(); // 5

let user = {
  name: "Ayush",
  age: 24,
  getDetails() {
    console.log("Normal function ", this.name);
  },
  getNestedNormalFuncDetails: {
    newName: "Rambo",
    getNestedDetails() {
      console.log(
        "Normal Nested function :",
        "Outer Obj Property ->",
        this.name,
        "\nInner Obj Property -> ",
        this.newName
      );
    },
  },
  getArrowDetails: () => {
    console.log("Arrow inside obj ", this.name);
  },
  getArrowDetailsWorking() {
    const nestedArrow = () =>
      console.log("Arrow function inside a normal function -> ", this.name);
    nestedArrow();
  },
};
user.getDetails();
user.getArrowDetails();
user.getNestedNormalFuncDetails.getNestedDetails();
user.getArrowDetailsWorking();

//This keyword inside a class or a constructor
class User {
  constructor(n) {
    this.name = n;
  }
  getName() {
    console.log(this.name);
  }
}
//Inside a constructor this always points to the everything that has been passed while initialisation

const newUser = new User("Rawat");

//Q1.
const userObj = {
  firstName: "Ayush!",
  getName() {
    const firstName = "Lenny";
    return this.firstName;
  },
};

console.log(userObj.getName()); // Ayush!

// Q2

function makeUser() {
  return {
    name: "John",
    ref: this,
  };
}

let userT = makeUser();
console.log(userT.ref.name); //undefined as ref points to Window
//IN order to make this work

function makeUser() {
  return {
    name: "John",
    ref() {
      return this;
    },
  };
}
console.log(userT.ref().name);

// Q3.
const userK = {
  name: "Ayush",
  logMessage() {
    console.log(this.name);
  },
};

setTimeout(userK.logMessage, 1000); // Prints undefined because logMessage is being passed
//as a callback function, therefore it tends to lose the context of its parent

//How to fix this
setTimeout(function () {
  userK.logMessage();
}, 1000);

//Q5.
var length = 4;

function callback() {
  console.log(this.length);
}

const object = {
  length: 5,
  method(fn) {
    fn();
  },
};

object.method(callback); //4

//Variation 2;
const object2 = {
  length: 5,
  method() {
    //arguments = [callback, 2, 3]
    arguments[0](); //3 length of the array
  },
};
object2.method(callback, 2, 3);
