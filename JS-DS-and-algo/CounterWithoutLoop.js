let increase = (function () {
  let i = 0;
  return function () {
    i++;
    return i;
  };
})();

console.log(increase());
console.log(increase());
console.log(increase());
