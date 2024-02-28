function PromisePollyFill(executor){
    let onResolve
    this.then = function (callback){
       onResolve = callback
       return this;
    }

    this.catch = function (callback){
        return this;
    }
    ecx
}