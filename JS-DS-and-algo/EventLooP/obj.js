const obj1 = {
  name: " Bruce Wayne ",
};

const obj2 = obj1;
obj2.name = "Clark Kent";

console.log(obj1); // Clark Kent. Due to referencing the value was overwritten

//In order to break this reference, after the initial assignment, instead of assinging a variable
//we a ssign a new object instead of modifying the property on the existing object, that reference is broken

let obj2 = {
  name: "Clark Kent",
};

console.log(obj1); //Bruce Wayne
