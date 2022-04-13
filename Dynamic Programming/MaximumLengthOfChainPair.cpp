/*
You are given n pairs of numbers.
 In every pair, the first number is always smaller than the second number.
  A pair (c, d) can follow another pair (a, b) if b < c. 
  Chain of pairs can be formed in this fashion.
   Find the longest chain which can be formed from a given set of pairs. 
\
For example,
 if the given pairs are {{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} }, then the longest chain that can be formed is of length 3, and the chain is {{5, 24}, {27, 40}, {50, 90}}
*/
#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> maxLenOfChain(vector<pair<int,int>>&chains){
    int len = chains.size();
    vector<pair<int,int> > result;
    vector<int> lis(len+1, 1);
    for(int i=1;i<len;i++){
       vector<pair<int,int> >  temp;
        for(int j=0;j<i;j++){
            if( (chains[j].second < chains[i].first) && (lis[i]<=lis[j]) ){
                temp.push_back(chains[j]);
                lis[i] = lis[j]+1;
            }
        }
        if(temp.size()>result.size()){
            result = temp;
        }
        int maxV = INT_MIN;
        for(int i=0;i<len;i++){
            maxV = max(maxV, lis[i]);
        }
        cout<<maxV<<endl;
    }
    return result;
}

int main(){
     vector<pair<int,int> > p =  {{5, 24}, {39, 60}, {15, 28}, {27, 40}, {50, 90} };
     vector<pair<int,int> >res = maxLenOfChain(p);
     for(auto i : res){
         cout<<i.first<<" "<<i.second<<endl;
     }
    return 0;
}