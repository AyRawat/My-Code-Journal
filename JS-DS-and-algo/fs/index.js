const fs = require("fs");

const fileContent = fs.readFileSync("./file.txt", "utf-8");
console.log(fileContent);

const asyncFileContent = fs.readFile("./file.txt", "utf-8", (err, data) => {
  if (err) {
    console.log(err);
  }
  console.log(data);
});

fs.writeFileSync("./file.txt", "WRITE THIS");

fs.writeFile("./asyncFile", "WRITE ASYNCHRONOUSLY", { flag: "a" }, (err) => {
  console.log("An error occured");
});
