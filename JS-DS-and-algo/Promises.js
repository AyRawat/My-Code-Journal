console.log("start");
const fn = () =>
  new Promise((resolve, reject) => {
    console.log(1);
    // resolve("Success");
  });
console.log("middle");

fn().then((res) => console.log(res));
console.log("end");
