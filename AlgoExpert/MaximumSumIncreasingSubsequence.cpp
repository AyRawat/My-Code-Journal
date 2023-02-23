//The Sequence needs to be strictly increasing.
#include<bits/stdc++.h>
#include<vector>

using namespace std;
vector<vector<int>> buildSeq(vector<int> arr, int indx , vector<int> sequence, int sum);
//My Own Reccursive solution .. Poor
vector<vector<int>> maxSumSub(vector<int> arr, int index, int sum,vector<int> elements){
    if(arr.size() == 0){
        return {{0},elements};
    }
    if(arr.size()==1){
        return {{arr[0]},arr};
    }
    if(index == -1){
        return {{sum},elements};
    }
    
    if(elements.size()==0){
        vector<int> y;
        y.push_back(arr[index]);
        return max(maxSumSub(arr,index-1,sum+=arr[index],y), maxSumSub(arr,index-1,sum,elements));
    }
    if(elements.size()!=0 && arr[index] > elements[elements.size()-1])
    {
        vector<int> y = elements;
        y.push_back(arr[index]);
    return max(maxSumSub(arr,index-1,sum+=arr[index],y) , maxSumSub(arr,index-1,sum,elements));
    }
    else
    {
        return maxSumSub(arr,index-1,sum,elements);
    }
  
}
// DP Solution O(n)^2
vector<vector<int>> maxSumIncSub(vector<int> arr)
{
    vector<int> sums=arr;
    vector<int> sequence(arr.size() , INT_MIN);
    int maxSumIdx = 0;
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<i;j++){
            if(arr[i] > arr[j] && arr[i]+sums[j] >= sums[i]){
                sums[i] = arr[i] + sums[j];
                sequence[i] = j;
                }
        }
    cout<<sums[maxSumIdx]<<endl;
    if(sums[i] >= sums[maxSumIdx]){
        maxSumIdx = i;
    }
    cout<<arr[maxSumIdx];
    return buildSeq(arr, maxSumIdx , sequence , arr[maxSumIdx]);
    }

}
vector<vector<int>> buildSeq(vector<int> arr, int indx , vector<int> sequence, int sum){
    vector<vector<int>> result = {{},{}};
    result[0].push_back(sum);
    //result[1].push_back(arr[indx]);
    while(sequence[indx]!=INT_MIN){
       result[1].push_back(arr[sequence[indx] ] );
       indx = sequence[indx];
    }
    return result;
}

int main(){          
    vector<int> x =  {10,70,20,30,50,11,30};
    vector<int> elements;
    vector<vector<int> > result;
    result = maxSumIncSub(x);
    cout<<result[0][0];
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
        cout<<result[i][j];
        }
        cout<<endl;
    }
    return 0;
}
