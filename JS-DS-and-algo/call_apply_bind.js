const age = 10;
var person = {
    name: "Ayush",
    age: 20,
    getAge: function(){
        return this.age; 
    }
}

var person2 = {age :24};
person.getAge.call(person2);

//Append an array to another array without concat
const array = ["a" , "b"];
const elements = [0 ,1 ,2];

array.push.apply(array , elements);

//Fin min/max in an array

const numbers = [5,6,7,8,9];
console.log(Math.max.apply(null, numbers));
console.log(Math.min.apply(null, numbers));

//What is the O/p
function f(){
    console.log(this);
}

let user = {
    g: f.bind(null)
}
user.g();

//O/P Window

//Bind Chaining
function f(){
    console.log(this.name);
}

f=f.bind({name:"John"}).bind({name: "Ann"});
f(); 

//O/P JOhn
//Bind Chaining Doesn't exist

//Explicit Binding With Arrow Functions
//Arrow functions behave as they normally behave, so there is no use of call apply and bind with these