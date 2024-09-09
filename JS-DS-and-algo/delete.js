const http = require("http");

const server = http.createServer((req, res) => {
  if (req.url === "/") {
    res.writeHead(200, { "Content-Type": "text/plain" });
    res.end("home page");
  } else if (req.url === "/slow-page") {
    for (let i = 0; i < 600_000_000; i++) {}
    res.writeHead(200, { "Content-Type": "text/plain" });
    res.end("slow Page");
  }
});

server.listen(4000, () => console.log("Server is listening at port 4000"));

const cluster = require("cluster");
const OS = require("os");

if (cluster.isMaster) {
  console.log(` Master ${process.pid} is running`);
  cluster.fork();
  cluster.fork();
} else {
  console.log(`Wroker ${process.pid} is running`);
  const server = http.createServer((req, res) => {
    if (req.url === "/") {
      res.writeHead(200, { "Content-Type": "text/plain" });
      res.end("home ");
    } else if (req.url == "/slow-page") {
      for (let i = 0; i < 6_00_000_000; i++) {}
      res.writeHead(200, { "Content-Type": "text/plain" });
      res.send("Slow");
    }
  });
  server.listen(4000, () => console.log("Server is runnning at 40000"));
}

const { Worker } = require("worker_threads");
const server2 = http.createServer((req, res) => {
  if (req.url === "/") {
    res.writeHead(200, { "Content-Type": "text/plain" });
    res.end("home ");
  } else if (req.url == "/slow-page") {
    Worker.on("message", (j) => {
      res.writeHead(200, { "Content-Type": "text/plain" });
      res.send("Slow");
    });
  }
});
server2.listen(4000, () => console.log("Server is runnning at 40000"));

//
const { parentPort } = require("worker_threads");
let j = 0;
for (let i = 0; i < 600000000; i++) {
  j++;
}
parentPort.postMessage(i);

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

//lowest common ancestor
function isValid(s) {
  let stack = [];
  let str = s.split("");
  const bMap = {
    "(": ")",
    "{": "}",
    "[": "]",
  };
  let result = true;
  for (const char of str) {
    if ((stack.length == 0 && char === ")") || char === "}" || char === "]") {
      result = false;
      break;
    }
    if (char === "(" || char === "{" || char === "[") {
      stack.push(char);
    } else {
      let top = st[st.length - 1];
      if (char !== bMap[top]) {
        result = false;
        break;
      } else {
        st.pop();
      }
    }
  }
  return stack.length !== 0 ? false : true;
}
//Flatten an Object
function Flattenobjec(obj, parentKey = "", result = {}) {
  for (let key in obj) {
    if (obj.hasOwnProperty(key)) {
      const newKey = parentKey ? `${parentKey}.${key}` : key;
      if (
        typeof obj[key] === "object" &&
        obj[key] !== null &&
        !Array.isArray(obj[key])
      ) {
        FlattenObject(obj[key], newKey, result);
      } else {
        result[newKey] = obj[key];
      }
    }
  }
}
