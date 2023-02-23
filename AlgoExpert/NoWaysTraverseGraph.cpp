#include<bits/stdc++.h>
#include<vector>

using namespace std;
vector<vector <int>> t(1001 , vector<int>(1001 , -1)); 
//Reccursive solution( My Solution) Worked pretty well!
int solveReccusrively(int i, int j, int width, int height)
{
    if(i>=height||j>=width){
        return 0;
    }
    if(i==height-1 || j==width-1){
        return 1;
    }

    return solveReccusrively(i+1,j,width,height) + solveReccusrively(i,j+1,width,height);
}
//Reccursive Bottom Up (Main SOlution)
int reccrsiveBottomUp(int width, int height){
    if(height==1 || width ==1){
        return 1;
    }
    return reccrsiveBottomUp(width-1,height) + reccrsiveBottomUp(width, height-1);
}
//DP SOLUTION (Main SOlution)
int dpSolution(int width, int height){
    int t[height+1][width+1];
    for(int i=0;i<height;i++){
        t[i][0]=1;
    }
    for(int j=0;j<width;j++){
        t[0][j] = 1;
    }
    for(int i=1;i<height;i++){
        for(int j=1;j<width;j++){
           t[i][j] = t[i-1][j] + t[i][j-1];
        }
    }
    return t[height-1][width-1];

}
//Memoized solution. Bottom Up(My solution)
int solve(int i, int j, int width, int height)
{
    if(i>=height||j>=width){
        return 0;
    }
    if(i==height-1 || j==width-1){
        return 1;
    }
    if(t[i][j]!=-1){
        return t[i][j];
    }
    return t[i][j] = solve(i+1,j,width,height) + solve(i,j+1,width,height);
}
//Mathematical Trick. Very Clever!
 //Helper function for Mathematical trick
 int factorial(int num){
    int result = 1;
    for(int i=1; i<=num;i++){
        result *= i;
    }
    return result;
 }
int mathematicalTrickSolution(int width, int height){
    //We are using Permutation to find out this
    /*
    Permutation is the total number of ways.
    here we can choose from either Right or Down ,
    from the starting if we were to choose how many Right movements do
    we need to reach will be R = width-1 similarly, Down would be L = height-1
   e.g,  width = 4 ; height = 3; therefore from [1][1] we need R=3 D=2 movements to reach;
   Therefore the permutation would be Perm = {R,R,R,D,D}, and we can use any order of this to reach to
   the end point. therefore the number of ways Perm can be arranged is our answer.
   
   ( nPr )
     = (R+D)! / (R!) * (D!)
    */
    int numerator = factorial(width-1 + height-1);
    int denominator = factorial(width-1) * factorial(height-1);
    return numerator / denominator;
}
int main(){
    int width = 4;
    int height = 3;
    cout<<mathematicalTrickSolution(width,height);
    return 0;
}