#include<bits/stdc++.h>
using namespace std;
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
static bool comparison(Job a, Job b){
         return (a.profit > b.profit);
     }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr, arr+n, comparison);
        int maxi = arr[0].dead;
        for(int i=1;i<n;i++){
            maxi = max(maxi , arr[i].dead);
        }
        vector<int>slot(maxi+1, -1);
        int countJobs = 0; 
        int countProfit = 0;
        for(int i=0;i<n;i++){
            for(int j=arr[i].dead; j>0; j--){
                if(slot[j]==-1){
                    countProfit+=arr[i].profit;
                    slot[j] = arr[i].id;
                    countJobs++;
                    break;
                }
            }
        }
        vector<int> result;
        result.push_back(countJobs);
        result.push_back(countProfit);
        return result;
    } 
int main(){

    return 0;
}