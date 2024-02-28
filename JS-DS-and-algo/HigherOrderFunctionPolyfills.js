
//MAP

//Filter

//Reduce
var reduce = function(nums, fn, init) {
    if(nums.length == 0) return init;
    let acc = init;
    nums.forEach((elem, index)=>{
      acc = fn(acc,elem);
    })
    return acc;
};
