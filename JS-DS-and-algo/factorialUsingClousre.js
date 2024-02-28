function factorialFinder() {
  let dp = {};

  return function calculateFactorials(arr) {
    return arr.map((num) => {
      if (num < 0) {
        return 1;
      }

      if (dp[num]) {
        return dp[num];
      }

      fact(num);
      return dp[num];
    });
  };

  function fact(num) {
    dp[0] = 1;
    for (let i = 1; i <= num; i++) {
      dp[i] = i * dp[i - 1];
    }
  }
}

const calcFactorials = factorialFinder();

const numbers = [10, 4, 2, 5, 6];
const result = calcFactorials(numbers);
console.log(result);
