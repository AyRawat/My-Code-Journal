function  frequencyCount(arr,N,P){
    //code here
    let hashMap = new Map();
    arr.forEach(ele=>{
       if(hashMap.has(ele)){
            hashMap.set(ele, hashMap.get(ele) + 1);
        }else{
            hashMap.set(ele , 1);
        }        
    })

    for(let i = 1; i<= N ;i++){
         if(hashMap.has(i)){
             let val = hashMap.get(i);
             console.log(val);
         }else{
             console.log(0);
         }
    } 
   // return result;
    }