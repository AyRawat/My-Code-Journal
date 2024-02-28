/**
  Challenge: Show entire Child component content inside Parent component. Only add code on Parent Component below
  
  Solution: https://codepen.io/angelo_jin/pen/MWEVJNb
  Video for Reference: https://youtu.be/VzNNjNmbXpY
**/
function Child() {
  return <div>This is children content</div>;
}

// Add code only here
function Parent({ children }) {
  return (
    <div>
      <h3>Parent Component</h3>
      {children}
    </div>
  );
}

function App() {
  return (
    <Parent>
      <Child />
    </Parent>
  );
}

ReactDOM.render(<App />, document.getElementById("root"));
