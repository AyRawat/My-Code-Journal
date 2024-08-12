const fs = require("fs/promises");

//Using Promise
fs.readFile("./file.txt", "utf-8")
  .then((data) => console.log(data))
  .catch((err) => console.log(err));

//Using Async

async function readFile() {
  try {
    const data = await fs.readFile("./file.txt", "utf-8");
    console.log(data);
  } catch (err) {
    console.log(err);
  }
}

readFile();
