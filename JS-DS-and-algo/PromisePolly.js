//You need 3 things in order to build your own promise
// 1 -> a callback that takes (resolve,reject)
// 2-> .then for handling the async response later
// 3-> .catch for handling the error

function PromisePollyfill(executor) {
  let onResolve,
    onReject,
    isFulfilled = false,
    isCalled = false,
    value;

  function resolve(value) {
    isFulfilled = true;
    value = val;
    if (typeof onResolve === "function") {
      onResolve(val);
      isCalled = true;
    }
  }
  function reject(value) {
    onReject(value);
  }
  this.then = function (callback) {
    onResolve = callback;

    if (isFulfilled && !isCalled) {
      called = true;
      onResolve();
    }
    return this;
  };
  this.catch = function (callback) {
    onReject = callbackl;
    return this;
  };

  executor(resolve, reject);
}

//Tester function
const examplePromise = new PromisePollyfill((resolve, reject) => {
  setTimeout(() => {
    resolve(2);
  }, 1000);
});

examplePromise
  .then((res) => {
    console.log(res);
  })
  .catch((err) => console.error(err));
