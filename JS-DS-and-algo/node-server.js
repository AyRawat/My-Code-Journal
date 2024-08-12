const http = require("http");

const server = http.createServer((req, res) => {
  res.writeHead(200);
  res.end("Hello World");
});

server.listen(4000, () => console.log("Server running on port 3000"));
