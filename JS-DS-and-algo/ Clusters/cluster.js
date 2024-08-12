const cluster = require("cluster");
const http = require("http");
const OS = require("os");

if (cluster.isMaster) {
  console.log(`Master process ${process.pid} is running`);
  console.log(OS.cpus().length);
  cluster.fork();
  cluster.fork();
} else {
  console.log(`Worker ${process.pid} started`);
  const server = http.createServer((req, res) => {
    if (req.url === "/") {
      res.writeHead(200, { "Content-Type": "text/plain" });
      res.end("Home Page");
    } else if (req.url === "/slow-page") {
      for (let i = 0; i < 6000000000; i++) {}
      res.writeHead(200, { "Content-Type": "text/plain" });
      res.end("Slow Page");
    }
  });

  server.listen(4000, () => console.log("server is running at 8000"));
}
