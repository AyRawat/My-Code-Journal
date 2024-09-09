let arr = [1, 2, 3, 4, 5];
//MAP
let map_arr = arr.map((x) => x + 3);

//console.log(new_arr);
Array.prototype.custom_map = function (fn) {
  console.log(this);
  let new_arr = [];
  for (let x of this) {
    new_arr.push(fn(x));
  }
  return new_arr;
};

console.log(arr.custom_map((x) => x + 3));

//Filter
let filter_arr = arr.map((x) => x > 3);
Array.prototype.custom_filter = function (fn) {
  console.log(this);
  let new_arr = [];
  for (let x of this) {
    if (fn(x)) new_arr.push(x);
  }
  return new_arr;
};
console.log(arr.custom_filter((x) => x > 3));

//Reduce

Array.prototype.custom_reduce = function (cb, initialValue) {
  let accumulator = initialValue ? initialValue : 0;
  for (let x of this) {
    accumulator = cb(accumulator, x);
  }
  return accumulator;
};

const reducer = (sum, val) => sum + val;
console.log(arr.custom_reduce(reducer, 0));

//find max values from reducer
const max_reducer = (max, d) => (max ? d : max);
console.log(arr.custom_reduce(max_reducer, -1));

const characters = [
  { name: "Jean-Luc Picard", age: 59 },
  { name: "Will Riker", age: 29 },
  { name: "Deanna Troi", age: 29 },
];

//Grouping values using Reduce
const group_reducer = (map, val) => {
  if (map[val] == null) {
    map[val] = 1;
  } else {
    ++map[val];
  }
  return map;
};
console.log(
  characters.map((char) => char.age).custom_reduce(group_reducer, {})
);

//Executing Async Functions in series
const func_arr = [
  async function () {
    return 1;
  },
  async function () {
    return 2;
  },
  async function () {
    return 3;
  },
];

const resp = func_arr.reduce(
  (
    promise,
    fn // This promise is the result of the previous resolved promise
  ) =>
    promise.then(async (results) => {
      const result = await fn(); // Wait for the current function to resolve
      results.push(result); // Add the result to the array
      return results; // Return the accumulated results
    }),
  Promise.resolve([]) // Start with an empty array to accumulate results
);

resp.then((results) => console.log(results)); // Output: [1, 2, 3]
// const res = await functions.reduce(
//   (promise, fn) => promise.then(fn),
//   Promise.resolve()
// );
// res;
