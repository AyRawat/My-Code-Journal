function lower_bound(nums, target) {
  let n = nums.length;
  let ans = n;
  let low = 0;
  let high = n - 1;

  while (low <= high) {
    let mid = Math.floor((low + high) / 2);
    if (nums[mid] >= target) {
      high = mid - 1;
      ans = mid;
    } else {
      low = mid + 1;
    }
  }
  return ans;
}
var searchInsert = function (nums, target) {
  return lower_bound(nums, target);
};
