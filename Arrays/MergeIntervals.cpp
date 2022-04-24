    #include<bits/stdc++.h>
    using namespace std;

    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
    
        vector<vector<int>> result;
        if(intervals.size() <= 0) return result;
        sort(intervals.begin(), intervals.end());

        vector<int> curr_interval = intervals[0];
        for(int i = 1; i<intervals.size() ; i++){
            if(intervals[i][0] <= curr_interval[1]){
                curr_interval[1] = max(curr_interval[1],intervals[i][1]); 
            }else{
                result.push_back(curr_interval);
                curr_interval = intervals[i];
            }
        }
        result.push_back(curr_interval);
        return result;
    }