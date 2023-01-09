#include <bits/stdc++.h>
using namespace std;
// Brute Force Solution

int maxPointsBrute(vector<vector<int>> &points)
{
    int n = points.size();
    // You can always draw a line between any two points.
    if (n <= 2)
        return n;

    // The Minimum Maximum number of points on a line will always be 2.
    int maxi = 2;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int count = 2;
            for (int k = 0; k <n ;k++){
                if(k==i || k== j) continue;
                /*
                (y2 - y1)    (y3-y1)
                ---------  = -------     ==> (y2 - y1) * (x3 - x1) = (y3 -y1) * (x2 - x1)
                (x2 - x1)    (x3 - x1)
                */

               if( (points[j][1] - points[i][1]) * (points[k][0]-points[i][0]) 
               == (points[k][1] - points[i][1]) *  (points[j][0] - points[i][0])) count++;
            }
            maxi = max(maxi , count);
        }
    
    }
    return maxi;
}

//Optimal Solution
int maxPointsBrute(vector<vector<int>> &points)
{
    int n = points.size();
    // You can always draw a line between any two points.
    if (n <= 2)
        return n;
    int ans = 0;
    for( auto it1 : points){
        unordered_map<double, int> mp;
        double x1 = it1[0] , y1= it1[1];
        for(auto it2 : points) {
            if(it1 == it2) continue;
            double x2 = it2[0], y2 = it2[1];
            double slope;
            if(x2 - x1 == 0){
                slope = INT_MAX; //Slope is Infinite for a vertical line
            }else{
                slope = (y2-y1) / (x2-x1);
            }
            mp[slope]++;
            ans = max(ans , mp[slope]);
        }
    }
    return ans + 1;
 
}
int main()
{
    vector<vector<int>> points = {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
     int ans = maxPointsBrute(points);
     cout<<ans;
    return 0;
}