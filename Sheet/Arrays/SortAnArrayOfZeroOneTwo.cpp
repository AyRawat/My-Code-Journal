#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr)
{
  if (arr.size() <= 1)
    return;

  int start = 0;
  int end = arr.size() - 1;
  for (int i = 0; i < end; i++)
  {
    if (arr[i] == 0)
    {
      swap(arr[i], arr[start]);
      start++;
    }
    else if (arr[i] == 2)
    {
      swap(arr[i], arr[end]);
      end--;
    }
  }
}

int main()
{
  vector<int> arr = {2,0,1};
  solve(arr);
  for(auto i: arr){
    cout<<i<<" ";
  }
  return 0;
}