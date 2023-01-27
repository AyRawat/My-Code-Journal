/*
Problem statement: Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order.
 Merge them in sorted order.
 Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.
*/
#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr1, vector<int> &arr2, int m, int n)
{
  int start = 0;
  int gap = ceil((float)(m + n) / 2);
  int end = (start + gap) % (gap);
  while (gap >= 1)
  {
    int start = 0;
    int end = gap;
    while (end < (m + n))
    {
      if (end < n && arr1[start] > arr1[end])
      {
        swap(arr1[start], arr2[end]);
      }
      else if (end >= n && arr1[start] > arr2[end - n])
      {
        swap(arr1[start], arr2[end - n]);
      }
      else if (end >= n && start >= n && arr2[start - n] > arr2[end - n])
      {
        swap(arr2[start - n], arr2[end - n]);
      }
      start++;
      end++;
    }
    if (gap == 1)
    {
      gap = 0;
    }
    else
    {
      gap = ceil((float)gap / 2);
    }
  }

}

int main()
{
  return 0;
}