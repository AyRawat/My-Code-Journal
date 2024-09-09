//find the duplicate numbers from the array = [1,2,3,2,8,9,8]
sample_arr_1 = [1, 2, 3, 2, 8, 9, 8];

dup_arr = sample_arr_1.filter((ele, index, arr) => {
  return arr.indexOf(ele) != index;
});

console.log(dup_arr);
//Find second largest number

second_max_finder = (arr) => {
  firstLargest = Math.max(...arr);
  indexOfFirstMax = arr.indexOf(firstLargest);
  arr.splice(indexOfFirstMax, 1);
};

//Find vowels in a string

find_vowels = (arr) => {
  vowels = ["a", "e", "i", "o", "u"];
  let count = 0;
  arr.map((c) => {
    if (vowels.indexOf(c.toLowerCase()) != -1) count++;
  });
  return count;
};
let test = "ayush";
let ans = find_vowels(test.split(""));

//Reverse a string in js
reverseString = (arr) => {
  return str.split("").reverse().join("");
};

//Palindrome in js
palindromeCheck = (str) => {
  let temp = str;
  return str == temp.split("").reverse("").join("");
};
console.log(palindromeCheck("madeam"));

//Swap two variables without using a third
//[a, b] = [b, a];

//UNion of two arrays
union_arr = (arr1, arr2) => {
  let unionArr = [...arr1, ...arr2];
  return [...new Set(unionArr)];
};
let arr1 = [1, 2, 6, 8, 17];
let arr2 = [4, 8, 6, 19, 12, 17];

console.log(union_arr(arr1, arr2));

function fibo(n) {
  if (n == 1 || n == 0) return n;
  return fibo(n - 1) + fibo(n - 2);
}

const checkParan = (str) => {
  const brackets = str.split("");
  const stack = [];
  let result = true;
  for (const bracket of brackets) {
    if (
      stack.length == 0 &&
      (bracket == ")" || bracket == "}" || bracket == "]")
    ) {
      result = false;
      break;
    }
    if (bracket == "{" || bracket == "(" || bracket == "[") {
      stack.push(bracket);
    } else {
      const top = stack[stack.length - 1];
      if (top == "(" && bracket != ")") {
        result = false;
        break;
      }
      if (top == "{" && bracket != "}") {
        result = false;
        break;
      }
      if (top == "[" && bracket != "]") {
        result = false;
        break;
      }
      stack.pop();
    }
  }
  return stack.length != 0 ? false : result;
};

console.log(checkParan("[}"));

//Max Subarray sum
function maxSubSum(arr) {
  let sum = 0;
  let maxSum = -1e9;
  for (let i = 0; i < arr.length; i++) {
    sum += arr[i];
    if (sum > maxSum) maxSum = sum;
    if (sum < 0) {
      sum = 0;
    }
  }
  return maxSum < 0 ? 0 : maxSum;
}
function printMaxSubSum(arr) {
  let sum = 0;
  let maxSum = -1e9;
  let subArr = [];
  let ansStart = -1;
  let ansEnd = -1;
  for (let i = 0; i < arr.length; i++) {
    if (sum == 0) start = i;
    sum += arr[i];
    subArr.push();
    if (sum > maxSum) {
      maxSum = sum;
      ansStart = start;
      ansEnd = i;
    }
    if (sum < 0) {
      sum = 0;
    }
  }
  return maxSum < 0 ? 0 : maxSum;
}

//Guess the output
a();
function a() {
  console.log("a");
}
b();
var b = function () {
  console.log("b");
};
