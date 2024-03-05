#include<bits/stdc++.h>

using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& adj){
  //Craete an Adjacency list
  vector<int> indeg(numCourses,0);
  vector<vector<int> > graph(numCourses);
  vector<int> topoSort;
  for(vector<int> it: adj){
    int from = it[0];
    int to = it[1];
    graph[to].push_back(from);
    indeg[from]++;
  }
  queue<int> q;
  for(int i=0;i< indeg.size();i++){
    if(indeg[i] == 0) q.push(i);
  }
  while(!q.empty()){
    int curr = q.front();
    q.pop();
    topoSort.push_back(curr);
    for(auto it: graph[curr]){
      cout<<"Value of it "<<it<<" "<<endl;
      indeg[it]--;
      if(indeg[it]==0) {
        q.push(it);
      }
    }
  }
  if(topoSort.size() < numCourses) {
    vector<int> result;
    return result;
  }
  return topoSort;
}
int main(){
  vector<vector<int>> input = {{1,0}};
  vector<int> result = findOrder(2,input);
  for(auto i: result){
    cout<<i<<" "<<"--"<<endl;
  }
}
