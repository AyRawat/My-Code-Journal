/*
The super keyword is used to access properties on an object literal or class's [[Prototype]],
 or invoke a superclass's constructor.
*/

class Foo {
  constructor(name) {
    this.name = name;
  }

  getNameSeparator() {
    return "-";
  }
}

class FooBar extends Foo {
  constructor(name, index) {
    super(name);
    this.index = index;
  }

  getFullName() {
    return this.name + super.getNameSeparator() + this.index;
  }
}

const firstFooBar = new FooBar("foo", 1);

console.log(firstFooBar.name);
// Expected output: "foo"

console.log(firstFooBar.getFullName());
// Expected output: "foo-1"

//1.) Using super in classes

class Rectangle {
  constructor(height, width) {
    (this.name = "Rectangle"), (this.height = height), (this.width = width);
  }
  sayName() {
    console.log(`Hi I am ${this.name}`);
  }
  get area() {
    return this.height * this.width;
  }
  set area(value) {
    this._area = value;
  }
}

class Square extends Rectangle {
  constructor(length) {
    super(length, length);
    this.name = "Square";
  }
}

//2.) You are also able to call super on static methods.
class Rectangle {
  static logNbSides() {
    return "I have 4 sides";
  }
}

class Square extends Rectangle {
  static logDescription() {
    return `${super.logNbSides()} which are all equal`;
  }
}

Square.logDescription();

//3.) Tricky  : Instance fields are set on the instances, instead of consturctor's prototype
// so, you can't use super to access instance fields of a superclass.

class Base {
  baseField = 10;
}

class Extended extends Base {
  extendedField = super.baseField; // undefined
}

/**
 * Here, extendedField is undefined instead of 10, because baseField is defined as an own property of the Base instance,
 *  instead of Base.prototype. super, in this context, only looks up properties on Base.prototype,
 *  because that's the [[Prototype]] of Extended.prototype
 */

//4.) Using super.prop in object literals

const obj1 = {
  method1() {
    console.log("method 1");
  },
};

const obj2 = {
  method2() {
    super.method1();
  },
};

Object.setPrototypeOf(obj2, obj1);
obj2.method2(); // Logs "method 1"

//5.) Setting super.prop sets the property on this instead
class A {}
class B extends A {
  setX() {
    super.x = 1;
  }
}
const a = new A();
const b = new B();
b.setX();
console.log(b); // B { x: 1 }
console.log(Object.hasOwn(b, "x")); // true
console.log(Object.hasOwn(a, "x")); //false
