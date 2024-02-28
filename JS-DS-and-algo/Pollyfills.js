//Structure for map
// Array.map((num,i,arr)=>{})
Array.prototype.ayushMap = function(cb){
    let temp = [];
    for(let i=0;i<this.length;i++){
        temp.push(cb(this[i] , i, this))
    }
    return temp;
}

//filter's Pollyfill

Array.prototype.ayushFilter = function(cb){
    let temp = [];
    for(let i=0;i<this.length;i++){
      if(cb(this[i] , i, this)) temp.push(cb(this[i]))
    }
    return temp;
}

//Reduce's Prototype
//arr.reduce((acc, curr , i, arr)=>{} , intitialValue)
Array.prototype.ayushReduce = function(cb, initialValue){
   let accumulator = initialValue;

   for(let i = 0;i < this.length;i++){
    accumulator = accumulator ? cb(accumulator, this[i] ,i ,this) : this[i];
   }
   return accumulator;
}