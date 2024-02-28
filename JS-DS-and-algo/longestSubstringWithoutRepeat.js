function longestSubWithoutRepeatingCharacters(str) {
  let arr = new Array(256);
  arr.fill(-1);
  let l = 0;
  let r = 0;
  let len = Number.MIN_SAFE_INTEGER;
  while (r < str.length) {
    if (arr[str.charCodeAt(r)] != -1)
      l = Math.max(arr[str.charCodeAt(r)] + 1, l);
    arr[str.charCodeAt(r)] = r;
    len = Math.max(len, r - l + 1);
    r++;
  }
  return len;
}
let res = longestSubWithoutRepeatingCharacters("aabbcd");
console.log(res);
