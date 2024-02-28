const userActionGet = async () => {
  const response = await fetch("http://example.com/movies.json");
  const myJson = await response.json(); //extract JSON from the http response
  // do something with myJson
};

const userAction = async () => {
  const response = await fetch("http://example.com/movies.json", {
    method: "POST",
    body: myBody, // string or object
    headers: {
      "Content-Type": "application/json",
    },
  });
  const myJson = await response.json(); //extract JSON from the http response
  // do something with myJson
};
