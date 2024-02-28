const url = "https://jsonplaceholder.typicode.com/users/1";
/** 
  // Sample Response
  {
    id: 1,
    name: "Leanne Graham",
    username: "Bret",
    email: "Sincere@april.biz",
    phone: "1-770-736-8031 x56442",
    website: "hildegard.org"
  }
**/

/** 
  Challenge: Given the url above, make this app fetch the data and display them in the browser (Small Hint: use `React.useEffect and fetch api`)
  
  Solution: https://codepen.io/angelo_jin/pen/zYEWZdW
  Video for reference: https://youtu.be/VzNNjNmbXpY
**/

//APPROACH 1
/**
 * 
 * function App() {
  const [userData, setUserData] = React.useState({});

  const getUserData = async () => {
    const response = await fetch(url);
    const jsonData = await response.json();
    setUserData(jsonData);
  };

  React.useEffect(() => {
    getUserData();
  }, []); 
 */
function App() {
  const [userData, setUserData] = React.useState({});
  const useEffect = React.useEffect;
  // No need to touch code below
  useEffect(() => {
    let data = fetch(url)
      .then((res) => res.json())
      .then((res) => setUserData(res));
  }, []);
  return (
    <div className="App">
      <h2>User Data</h2>
      <p>
        <strong>Name: </strong>{" "}
        {userData.name || "(Need to populate name here)"}
      </p>
      <p>
        <strong>Website: </strong>
        {userData.website || "(Need to populate website here)"}
      </p>
      <p>
        <strong>Email: </strong>
        {userData.email || "(Need to populate email here)"}
      </p>
      <p>
        <strong>Phone: </strong>
        {userData.phone || "(Need to populate phone here)"}
      </p>
    </div>
  );
}

ReactDOM.render(<App />, document.getElementById("root"));
