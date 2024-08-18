(function (num) {
  console.log(num * num);
})(5);

(function (x) {
  return (function (y) {
    console.log(x, " ", y);
  })(2);
})(1);
