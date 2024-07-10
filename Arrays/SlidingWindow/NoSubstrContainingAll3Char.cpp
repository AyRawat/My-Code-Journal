//https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/

//LOGIC: We find minimal length / window that contains "abc", and you are currently 
//standing at the last character of the window.
//keep a hash map that stores abc as key and their position as value
//- add on every character to the left of this window, as it adds on to your list of substrings that contains abc.
//- update the position of abc, whenver you encounter any one of these because you need to find , from where this window starts.
//- finding the begining of the window is straight forward as you just need to find the minimum pos from you hash map.

#include<bits/stdc++.h>


int NoSubstrContainingABC(string &s){
  int n = s.size();
  vector<int> hash (3,-1);
  int count = 0;


  for(int r=0 ; r<n;r++){
       hash[s[r] - 'a'] = r;
     //If you encounter a window
       if(hash[0] != -1 && hash[1] != -1 && hash[2] != -1){
       int startingPosition = min(hash[0],min(hash[1], hash[2]) );
       count += 1 + startingPosition;
     }
  }
  return count;

} 


int main(){


  return 0;
}


