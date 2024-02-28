/** 
  Challenge: Make this app work like a calculator that can add two numbers.
  
  Functionality: When user place numbers on first and second input and hit the button. The sum should appear on the `Total: ` as an output. 

**/
//CSS
/**
 * 
 * div {
  padding: 10px;
}
button {
  margin: 10px 0;
  padding: 5px 10px;
}
input {
  display: block;
  padding: 5px;
  margin-bottom: 5px;
  width: 120px;
}
 * 
 */

function App() {
  const [number1, setNumber1] = React.useState();
  const [number2, setNumber2] = React.useState();
  const [total, setTotal] = React.useState(0);
  const handleSum = () => {
    let totalSum = number1 + number2;
    setTotal(totalSum);
  };
  return (
    <div>
      <h2>Adding Two Numbers</h2>
      <input
        placeholder="First Number"
        type="number"
        onChange={(e) => setNumber1(+e.target.value)}
      />
      <input
        placeholder="Second Number"
        type="number"
        onChange={(e) => setNumber2(+e.target.value)}
      />

      <button onClick={handleSum}>Add Two Numbers</button>
      <p>Total: {total}</p>
    </div>
  );
}

ReactDOM.render(<App />, document.getElementById("root"));
