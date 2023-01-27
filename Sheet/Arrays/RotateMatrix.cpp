/*
Rotate the matrix 90 deg.
 - Transpose the Matrix
 - Reverse every Row.
*/

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> rotateMatrix(vector<vector<int>> &arr)
{
  // Transpose the Matrix

  for (int i = 0; i < arr.size(); i++)
  {
    for (int j = 0; j < i; j++)
    {
      swap(arr[i][j], arr[j][i]);
    }
  }

  for (int i = 0; i < arr.size(); i++)
  {
    reverse(arr[i].begin(), arr[i].end());
  }
  return arr;
}

int main()
{
  return 0;
}