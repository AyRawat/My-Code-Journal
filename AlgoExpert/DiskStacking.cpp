#include<bits/stdc++.h>
#include<vector>

using namespace std;
vector<vector<int>> resultBuilder(vector<vector<int>> array , int maxSumIndex, vector<int> sequence, int maxSum);
vector<vector<int>> maxHeight(vector<vector<int>> array){
vector<vector<int>> sums = array;
vector<int> sequence(array.size() , INT_MIN);
int maxSumIndex = 0;
for(int i = 0; i < array.size(); i++){
    for(int j=0;j<i;j++){
        if(
            (
            array[i][0] > array[j][0] 
            && 
            array[i][1] > array[j][1] 
            && 
            array[i][2] > array[j][2]
            ) 
            
            && 
            
             ( 
                array[i][2]+sums[j][2] >= sums[i][2]
             )
            )
            {
                  sums[i][2] = array[i][2] + sums[j][2];
                  sequence[i] = j;
        }
    }
    if(sums[i][2] >= sums[maxSumIndex][2]){
      
        maxSumIndex = i;
      cout<<maxSumIndex<<endl;
    }
}
return resultBuilder(array, maxSumIndex,sequence,maxSumIndex);
}
vector<vector<int>> resultBuilder(vector<vector<int>> array , int maxSumIndex, vector<int> sequence,int maxSum){
//for(int i=0;i<sequence.size();i++){cout<<sequence[i]<<endl;}
vector<vector<int>> result;
result.push_back(array[maxSumIndex]);
while(maxSumIndex!=INT_MIN){
   result.push_back(array[sequence[maxSumIndex]]);
   maxSumIndex = sequence[maxSumIndex];
}
return result;
}


int main(){
   vector<vector<int>> array = {{2,1,2},{3,2,3},{2,2,8},{2,3,4},{1,3,1},{4,4,5}};
   vector<vector<int>> result = maxHeight(array);
   for(int i=0;i<result.size();i++){
       cout<<result[i][0]<< result[i][1]<<result[i][2]<<endl;
   }
    return 0;
}