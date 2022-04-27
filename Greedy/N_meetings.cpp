/*
the form of (start[i], end[i]) where start[i] is start time of meeting i and end[i] is finish time of meeting i.
What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can be held in the meeting room at a particular time?

Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.


Example 1:

Input:
N = 6
start[] = {1,3,0,5,8,5}
end[] =  {2,4,6,7,9,9}
Output: 
4
Explanation:
Maximum four meetings can be held with
given start and end timings.
The meetings are - (1, 2),(3, 4), (5,7) and (8,9)
*/
#include<bits/stdc++.h>
using namespace std;


    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
         vector<pair<int,int> > totalMeetings;
         for(int i=0;i<n;i++){
             totalMeetings.push_back(make_pair(end[i] , start[i]));
         }
         sort(totalMeetings.begin() ,totalMeetings.end());
         int counting = 1;
         int limit = totalMeetings[0].first;
         for(int i=1;i<n;i++){
             if(totalMeetings[i].second > limit){
                 counting++;
                 limit = totalMeetings[i].first;
             }
         }
        return counting;
    }