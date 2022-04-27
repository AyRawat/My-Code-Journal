#include<bits/stdc++.h>
using namespace std ;
 
 struct Item{
    int value;
    int weight;
};

static bool comparator(Item a, Item b){
        double r1 = (double)a.value / (double)a.weight;
        double r2 = (double)b.value / (double)b.weight;
        return r1 > r2;
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr, arr+n, comparator);
        int curr_weight = 0;
        double profit = 0.0;
        for(int i=0;i<n;i++){
            if(curr_weight+arr[i].weight<=W )
            {
                profit+=arr[i].value;
                curr_weight+=arr[i].weight;
            }else{
                profit += (double)(W-curr_weight) * ((double)arr[i].value / (double)arr[i].weight);
                break;
            }
        }
        return profit;
    }

 int main(){
     return 0;
 }