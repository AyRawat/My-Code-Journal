#include<bits/stdc++.h>
using namespace std;
static bool comparator(vector<int> &a , vector<int> &b){
    return a[1]< b[1];
}

int findMinArrowShots(vector<vector<int>>& points){
   if(points.size() ==0) return 0;
    sort(points.begin() ,points.end(),comparator);
    for(auto it: points){
        cout<<it.front()<<it.back()<<endl;
    }
    int answer = 1;
     int curr = points[0][1];
     for(int i=1;i<points.size();i++){
         if(points[i][0] >= curr){
            answer++;
            curr = points[i][1];
         }
     }
    return answer;
}

int main(){
      vector<vector<int>> vec = {{{9,12},{1,10},{4,11},{8,12},{3,9},{6,9},{6,7}}};
      cout<<findMinArrowShots(vec);
    return 0;
}