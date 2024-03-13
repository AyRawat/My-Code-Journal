//We are using Set instead of PQ here because, the reason for choosing PQ was the minimum distance that we wanted
//was always kept on top.
//Set behaves int the similar Manner.
//Apart from this, if we have two distances for the same node in PQ, for E.g(10,5) was already there. Now we 
//find a better one E.g(8,5), we will still iterate for (10,5) we do not have the provision for 
//removing the longer one from PQ. But, we do have in SET.
//erase -> logN but in future we can save some iteration. But we need to make sure what approach to choose.
#include<bits/stdc++.h>
using namespace std;

vector<int> shortestDistance(int V, vector<vector<int>> adj[], int S){
  //Declare a min heap which will keep minimum distance at the top
  set<pair<int,int>> st;
  vector<int> distance(V,1e9);
 distance[S] = 0;
  st.insert({0,S});
  while(!st.empty()){
    auto it = *(st.begin());
    int curr_node = it.second;
    int curr_distance = it.first;
    st.erase(it);
    for(auto it: adj[curr_node]){
      int node = it[0];
      int node_distance = it[1];
      if(node_distance+curr_distance < distance[node]){
        //erase the longer distance node that is already present, 
        //because we dont want to loop it again in future iterations.
        st.erase({distance[node], node});
        distance[node] = node_distance + curr_distance;
        st.insert({distance[node], node});
      }
    }
  }
  return distance;
}
 
int main(){
  return 0;
}
