#include<bits/stdc++.h>
using namespace std;

static const int MOD = 10000000007;
int solve(string s, int n, char parent, bool absent){

//Base 
if(s.length() == n) {
cout<<s<<"--";
  return 1;}

//Condition 1 : if pupil is absent
int attendance_with_absent = 0;
int attendance_with_late = 0;
int attendance_with_present = 0;
if(!absent){
 string temp = s;
 s+="A";
 attendance_with_absent = solve(s,n,'A',true);
 s = temp;
}

//Condition 2 : if pupil was late, and he cannot be late for 3 consecutive days
//check whether for the last two days whether pupil was late or not
string last_two_days = "";
if(s.length() > 2){

last_two_days = s.substr(s.length()-2);
}

if(last_two_days != "LL"){
  string temp = s;
  s += "L";
  attendance_with_late = solve(s,n,'L',absent);
  s = temp;
}

string temp = s;
s += "P";
attendance_with_present = solve(s,n,'P',absent);
s = temp;

return attendance_with_present + attendance_with_late + attendance_with_absent;


}

int reccursive_soln(int index, int n, int count_a, int count_l,
    vector<vector<vector<int>>> &dp){
  if(index == n) return 1;
   if(dp[index][count_a][count_l] != -1) return dp[index][count_a][count_l];
  int with_a_index = count_a == 1 ? 0: reccursive_soln(index+1,n,count_a + 1, count_l);
  int with_l_index = count_l == 2 ? 0 : reccursive_soln(index+1,n,count_a , count_l+1);
  int with_p_index = reccursive_soln(index+1,n,count_a,count_l);

  return dp[index][count_a][count_l] = (with_a_index + with_l_index + with_p_index ) % MOD;
}


int main(){
  int n = 10101;
  int result = solve("",n,' ',false);
   cout<<result<<" ";
  return 0;
}
