const hi = () => console.log("hi");

const greeting = () => {
  console.log("GM");

  setTimeout(() => {
    console.log("Set timeout");
  }, 0);

  new Promise((resolve, reject) => resolve("promise")).then((resolve) =>
    console.log(resolve)
  );

  process.nextTick(() => {
    console.log("nextTick");
  });

  setImmediate(() => {
    console.log("setImmediate");
  });
  hi();
};

greeting();

// GM
// hi
// nextTick
// promise
// setImmediate
// Set timeout

// setTimeout(() => {
//   console.log("hi");
// }, 0);
// setImmediate(() => {
//   console.log("immediate");
// });
