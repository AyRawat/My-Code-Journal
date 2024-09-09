//More Problems
//https://eishta.medium.com/javascript-tricky-questions-promises-12c1ebeff20c

//1.)

console.log("start");
const promise1 = new Promise((resolve, reject) => {
  console.log(1);
  resolve(2);
  console.log(3);
});

promise1.then((res) => {
  console.log(res);
});

console.log("end");
/**
start
1
3
end
2
 */

//2.)
console.log("start");
const fn = () =>
  new Promise((resolve, reject) => {
    console.log(1);
    resolve("success");
  });

console.log("middle");

fn().then((res) => console.log(res));

console.log("end");
/**
 * start
 * middle
 * 1
 * end
 * Success
 */

//3.) Promise Chaining

function job() {
  return new Promise(function (resolve, reject) {
    reject();
  });
}

let promise = job();

promise
  .then(() => {
    console.log("Success 1");
  })
  .then(() => {
    console.log("Success 2");
  })
  .then(() => {
    console.log("Success 3");
  })
  .catch(() => {
    console.log("Error 1");
  })
  .then(() => {
    console.log("Success 4");
  });

//Error1
//Success4

// 4).

function job(state) {
  return new Promise((resolve, reject) => {
    if (state) {
      resolve("Success");
    } else {
      reject("Error");
    }
  });
}

let promise2 = job(true);

promise2
  .then((data) => {
    console.log(data);
    return job(false);
  })
  .catch((error) => {
    console.log(error);
    return "Error Caught";
  })
  .then((data) => {
    console.log(data);
    return job(true);
  })
  .catch((error) => {
    console.log(error);
  });

// Success
// Error
// Error Caught
//
// -> "Error Caught" is a string not a promise and after the last job(true) , there is no
// .then, therefore we will end our search here

// 6).

const firstPromise = new Promise((resolve, reject) => {
  resolve("First");
});

const secondPromise = new Promise((resolve, reject) => {
  resolve(firstPromise);
});

secondPromise
  .then((res) => {
    return res;
  })
  .then((res) => console.log(res));

//7). convert the following code to async await

function loadJson(url) {
  return fetch(url).then((response) => {
    if (response.status == 200) {
      return response.json();
    } else {
      throw new Error(response.status);
    }
  });
}

loadJson("some url").catch((err) => {
  console.log(err);
});

async function loadJsonAsync(url) {
  let res = await fetch(url);
  if (res.status === 200) return res.json();
  else throw new Error(res.status);
}

//8). resolve all the promises reccursively
promReccurse([promise1("A"), promise2("B"), promise3("C")]);

function promReccurse(funcPromises) {
  if (funcPromises.length === 0) return;
  const currPromise = funcPromises.shift();
  currPromise.then((res) => console.log(res)).catch((err) => console.log(err));

  promReccurse(funcPromises);
}

//9.)
function asyncOperation() {
  return new Promise((resolve) => {
    setTimeout(() => resolve("Async Operation"), 100);
  });
}

async function executeAsync() {
  console.log("Start");
  const result = await asyncOperation();
  console.log(result);
  console.log("End");
}

executeAsync();
// Start
// Async Operation
// End
