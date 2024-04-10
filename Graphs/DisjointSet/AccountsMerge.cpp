// 
// Should be a Hard Question. You first need to figure out how this falls in 
// the category of Disjoint set. The intuition behind this is, the Union of the accounts, based on the parent
//
//https://www.geeksforgeeks.org/problems/connecting-the-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=connecting-the-graph

class DisjointSet {
    public:
    vector<int> parent,size;
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i=0;i<n;i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findParent(int node){
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }
    void unionBySize(int u, int v){
        int ult_u = findParent(u);
        int ult_v = findParent(v);
        if(ult_u == ult_v) return;
        int size_u = size[ult_u];
        int size_v = size[ult_v];
        if(size_u < size_v){
            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u];
        }else{
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];
        }
    }
};
class Solution{
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        // code here
        int n = accounts.size();
        unordered_map<string,int > mailNodeMap;
        DisjointSet dSet(n);
        sort(accounts.begin(), accounts.end());
       for(int i=0;i<n;i++){
           for(int j=1; j<accounts[i].size();j++){
               string mail = accounts[i][j];
               if(mailNodeMap.find(mail)== mailNodeMap.end()){
                   mailNodeMap[mail] = i;
               }else{
                   int existingValue = mailNodeMap[mail];
                   dSet.unionBySize(existingValue, i);
               }
           }
       }
       vector<vector<string>> mergedMail(n);
       for(auto it : mailNodeMap){
           string mail = it.first;
           int node = dSet.findParent(it.second);
           mergedMail[node].push_back(mail);
       }
       vector<vector<string>> result;
       for(int i=0;i<n;i++){
           if(mergedMail[i].size() == 0) continue;
           sort(mergedMail[i].begin(), mergedMail[i].end());
           vector<string> temp;
           temp.push_back(accounts[i][0]);
           for(auto it: mergedMail[i]) temp.push_back(it);
           result.push_back(temp);
       }
       return result;
    }
};


#include<bits/stdc++.h>
using namespace std;

int main(){
  return 0;
}
