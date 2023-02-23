#include<bits/stdc++.h>
#include<vector>

using namespace std;
vector<vector<int>> temp(1001 , vector<int>(1001,-1));
//Algoexpert's O(n^2)
int minNumerOfJumps(vector<int> array){
    vector<int> jumps(array.size() , INT_MAX);
    jumps[0] = 0;
    for(int i=1;i<array.size();i++){
        for(int j=0;j<i;j++){
            if(array[j]+j >= i){
                jumps[i] = min(jumps[j]+1 , jumps[i]); 
            }
        }
    }
    return jumps[array.size() - 1];
}
//AlgoExperts Tricky and Optimized Solution
int dp(vector<int> array){
    if(array.size() == 1){return 0;}
    int maxReach = array[0];
    int steps = maxReach;
    int jumps = 0;
    for(int i=1;i<array.size()-1;i++){
        
        maxReach = max(array[i]+i, maxReach);
        steps -= 1;

        if(steps == 0){
            jumps+=1;
            steps = maxReach - i;

        }
    }
    return jumps;
}
//My Own Reccursive Solution
vector<int> greatest_val(vector<int> arr, int start, int end){
    vector<int> greatest;
    int maxVal = INT_MIN;
    int index_maxVal = -1;
    for(int i=start+1; i<=end;i++){
        if(arr[i]>maxVal){
            maxVal = arr[i];
            index_maxVal = i;
        }
    }
    greatest.push_back(maxVal);
    greatest.push_back(index_maxVal);
    return greatest;
}
int min_jumps(vector<int> arr, int start, int end){
    if(start >= arr.size()-1){
        return 0;
    }
    vector<int> greatest = greatest_val(arr,start, end);
    return 1 + min_jumps(arr, end, greatest[0]+greatest[1]);
}

int main(){
    vector<int> arr = {2, 1, 2, 2, 1, 1, 1};
    cout<<min_jumps(arr,0,arr[0]);
    return 0;
}