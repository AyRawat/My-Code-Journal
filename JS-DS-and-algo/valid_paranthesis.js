
function main(){
        let answer = ispar("{{}}");
        console.log(answer);
}
function ispar(x){
    //your code here
    let stack = [];
    let result = true;
    let words = x.split("");
    for(const ele of words){
        if(stack.length == 0 && (ele === ')' || ele === '}' || ele === ']')){
            result = false;
            break;
        }
        if(ele === '(' || ele === "{" || ele === "["){
            stack.push(ele);
        }else if(ele === ')' || ele === '}' || ele === ']'){
            const top = stack[stack.length - 1];
            if(top === '(' && ele !== ')'){
                result = false;
                break;
            }
            if(top === '{' && ele !== '}'){
                result = false;
                break;
            }
            if(top === '[' && ele !== ']'){
                result = false;
                break;
            }
            stack.pop();
        }
    }
    return stack.length!==0 ? false : result;
}

    main();