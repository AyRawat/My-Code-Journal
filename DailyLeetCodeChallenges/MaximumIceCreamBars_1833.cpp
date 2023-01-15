#include<bits/stdc++.h>
using namespace std;
//Reccursive Solution 

int MaxIceCream(vector<int>& costs, int coins, int index, int total){
    if(coins == 0) return 0;
    if(index > costs.size()) return total;

    if(costs[index] <= coins){
        return max(MaxIceCream(costs, coins-costs[index],index+1,total+1) ,
         MaxIceCream(costs,coins,index+1,total));
    }else{
        MaxIceCream(costs,coins,index+1,total);
    }
    return total;
}
int main(){
    vector<int> costs ={1,3,2,4,1};
    int total =0;
    int ans = MaxIceCream(costs,7,0,total);
    cout<<ans<<endl;
    return 0;
}