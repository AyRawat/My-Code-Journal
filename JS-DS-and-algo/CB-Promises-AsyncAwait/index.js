//Callback example

function printUsername(username, cb) {
  setTimeout(() => {
    cb(username);
  }, 1000);
}

printUsername("Ayush", (message) => {
  console.log(message);
});

//Promise example

const sub = new Promise((resolve, reject) => {
  setTimeout(() => {
    const result = true;
    if (result) resolve(result);
    else reject(new Error("Failed"));
  });
});

sub.then();

//Converting callback to Promise

function newPrintUserName(username) {
  return new Promise((resolve, reject) => {
    setTimeout(() => {
      resolve(username);
    }, 1000);
  });
}

newPrintUserName.then();

Promise.all([])
  .then((res) => console.log(res))
  .catch((err) => console.log(err));
Promise.race([]).then(res).catch(err);
Promise.any([]).then().catch();
Promise.allSettled([]);
