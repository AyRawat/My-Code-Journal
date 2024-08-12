const crypto = require("crypto");
const https = require("https");
// process.env.UV_THREADPOOL_SIZE = 6;

// const MAX_CALLS = 3;
// for (let i = 0; i < MAX_CALLS; i++) {
//   crypto.pbkdf2("password", "salt", 100000, 512, "sha512", () => {
//     console.log(`Hash: ${i + 1}`, Date.now() - start);
//   });
// }

//http does not uses multiple threads and is independent of the cores. It is an Network IO call
const MAX_CALLS = 3;
const start = Date.now();
for (let i = 0; i < MAX_CALLS; i++) {
  https
    .request("https://www.google.com", (res) => {
      res.on("data", (data) => {});
      res.on("end", () => console.log(`Request: ${i + 1}`, Date.now() - start));
    })
    .end();
}
