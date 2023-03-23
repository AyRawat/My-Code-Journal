#include<bits/stdc++.h>
using namespace std;

bool hasSingleCycle(vector<int> array){
     int s = array.size();
   vector<int> adj[s];
  vector<int> visited(s,0);
  bool result = true;
  int i = 0;
  while(true){
   int pos = 
  }
  for(int i=0;i<s;i++){
      if(visited[i] == 0 || visited[i]>1) result=false;
  }
  return result;
}


int main(){
  vector<int> arr = {1,1,1,1,2};
  bool result = hasSingleCycle(arr);
  cout<<result<<endl;
  return 0;
}