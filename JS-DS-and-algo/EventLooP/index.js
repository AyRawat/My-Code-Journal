//import { readFile } from "fs";
const fs = require("fs");
//MICROTASK QUEUE
//1
console.log("Log- 1");
process.nextTick(() => {
  console.log("Process");
});
console.log("Log- 2");

//o/p
// Log- 1
// Log- 2
// Process

//2
Promise.resolve().then(() => console.log("this is Promise . resolve 1"));

process.nextTick(() => {
  console.log("Process next tick");
});

//o/p
// Process next tick
// this is Promise, resolve 1

//3
process.nextTick(() => console.log("this is the process.nextTick 1"));
process.nextTick(() => {
  console.log("This is the next tick 2");
  process.nextTick(() => {
    console.log("This is the inner next tick");
  });
});
process.nextTick(() => console.log("this is next tick 3"));

Promise.resolve().then(() => console.log("This is promise . resolve 1"));
Promise.resolve().then(() => {
  console.log("this is Promise. resolve 2");
  process.nextTick(() => {
    console.log("this is the inner next tick inside the promise");
  });
});
Promise.resolve().then(() => console.log("This is promise . resolve 3"));

// this is the process.nextTick 1
// This is the next tick 2
// this is next tick 3
// This is the inner next tick
// this is Promise . resolve 1
// This is promise . resolve 1
// this is Promise. resolve 2
// This is promise . resolve 3
// this is the inner next tick inside the promise

//TIMER QUEUE
setTimeout(() => console.log("this is the settime out 1"), 0);
setTimeout(() => {
  console.log("This is the set timeout 2");
  process.nextTick(() => {
    console.log("This is the inner next tick setTimeout");
  });
}, 0);
process.nextTick(() => console.log("this is the process.nextTick 1"));
process.nextTick(() => {
  console.log("This is the next tick 2");
  process.nextTick(() => {
    console.log("This is the inner next tick");
  });
});
process.nextTick(() => console.log("this is next tick 3"));

Promise.resolve().then(() => console.log("This is promise . resolve 1"));
Promise.resolve().then(() => {
  console.log("this is Promise. resolve 2");
  process.nextTick(() => {
    console.log("this is the inner next tick inside the promise");
  });
});
Promise.resolve().then(() => console.log("This is promise . resolve 3"));

// I/O Queue
// Strange behavior. You cannot guess the output

setTimeout(() => console.log("SetTimeout 1"), 0);

fs.readFile(__filename, () => {
  console.log("Log from fs");
});

// 2 polling

fs.readFile(__filename, () => {
  console.log("Log from fs");
});
process.nextTick(() => console.log("this is the process nextTick 1"));
Promise.resolve().then(() => console.log("promise resolved"));
setTimeout(() => console.log("executing the setTimeout"), 0);
setImmediate(() => console.log("this is setImmediate 1"));

// this is the process nextTick 1
// promise resolved
// executing the setTimeout
// this is setImmediate 1
// Log from fs

//3.

fs.readFile(__filename, () => {
  console.log("Log from fs");
  setImmediate(() => console.log("this is inner setImmediate 1"));
});
process.nextTick(() => console.log("this is the process nextTick 1"));
Promise.resolve().then(() => console.log("promise resolved"));
setTimeout(() => console.log("executing the setTimeout"), 0);

// this is the process nextTick 1
// promise resolved
// executing the setTimeout
// Log from fs
// this is inner setImmediate 1

//4
fs.readFile(__filename, () => {
  console.log("Log from fs");
  setImmediate(() => console.log("this is inner setImmediate 1"));
  process.nextTick(() => console.log("this is the inner process nextTick 2"));
  Promise.resolve().then(() => console.log("inner promise resolved"));
});
process.nextTick(() => console.log("this is the process nextTick 1"));
Promise.resolve().then(() => console.log("promise resolved"));
setTimeout(() => console.log("executing the setTimeout"), 0);

for (let i = 0; i < 2000000; i++) {}

// this is the process nextTick 1
// promise resolved
// executing the setTimeout
// Log from fs
// this is the inner process nextTick 2
// inner promise resolved
// this is inner setImmediate 1

// 5
setImmediate(() => console.log("setImmediate 1"));
setImmediate(() => {
  console.log("setImmediate innner 2");
  process.nextTick(() => console.log("Inner process next tic"));
  Promise.resolve().then(() => console.log("Nested Promise"));
});

setImmediate(() => console.log("setImmediate 3"));

// setImmediate 1
// setImmediate innner 2
// Inner process next tic
// Nested Promise
//setImmediate 3

// CLOSE QUEUE

const fs = require("fs");
const readableStream = fs.createReadStream(__filename);
readableStream.close();

readableStream.on("close", () => {
  console.log("This is the readable stream close event callback");
});

setImmediate(() => console.log("This is set Immediate"));
setTimeout(() => console.log("this is set timeout 1"), 0);
Promise.resolve().then(() => console.log("this is Promise.resolve 1"));
process.nextTick(() => console.log("This is the process.nextTick"));

for (let i = 0; i < 2000000; i++) {}

// This is the process.nextTick
// this is Promise.resolve 1
// this is set timeout 1
// This is set Immediate
// This is the readable stream close event callback
