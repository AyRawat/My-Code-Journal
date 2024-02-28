/** 
 * What is Currying ?
 * Currying is a function that takes one argument at a time and 
 * returns a new function expecting the next argument.
 */
/** 
 * Why should we use Currying ?
 * It makes a function Pure, which makes it less prone to errors and side effects
 * It helps in avoiding the same variable again and again
 * It divides one function into multiple functions so that one handles one set of responsibility
 */

function sum(a){
    return function (b){
        return function (c){
            console.log(a + b + c)
        }
    }
}

sum(5)(6)(7);
/**
 * 
 * Resuing Variable for Logic
 * 
 */

function evaluate(operation){
    return function(a){
        return function(b){
            if(operation === "sum") return a + b;
            else if(operation === "multiply") return a * b;
            else if(operation === "divide") return a / b;
            else if(operation === "subtract") return a - b;
            else return "Invalid"
        }
    }
}

evaluate("sum")(4)(2)
evaluate("multiply")(4)(2)
evaluate("divide")(4)(2)
evaluate("subtract")(4)(2)

//Infinite Currying
//sum(1)(2).....(n);
function add(a){
    return function (b){
        if(b) return a+b;
        return a;
    }
}
console.log(add(5)(6)(4)(7)(6)(8))
//Implementation of currying

function curry(func){
    return function curriedFunc(...args){
        //Base condition
        //As the number of functions should be equal to the number of args passed

        if(args.length >= func.length){
            return func(...args);
        }else{
            return curriedFunc(...args, ...next);
        };
    }
}

const sum = (a , b, c, d) => a + b + c + d;
const totalSum = curry(sum);
console.log(totalSum(1)(6)(5)(7));