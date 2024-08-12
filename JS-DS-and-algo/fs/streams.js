const fs = require("fs");

const readableStream = fs.createReadStream("./file.txt", {
  encoding: "UTF-8",
  highWaterMark: 2,
});

const writeableStream = fs.createWriteStream("./file2.txt");

readableStream.on("data", (chunk) => {
  console.log("Event emiited here is the data ", chunk);
  writableStream.write(chunk);
});

readableStream.pipe(writeableStream);
