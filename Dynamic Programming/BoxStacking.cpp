/*
You are given a set of N types of rectangular 3-D boxes, where the ith box has height h, width w and length l. You task is to create a stack of boxes which is as tall as possible, but you can only stack a box on top of another box if the dimensions of the 2-D base of the lower box are each strictly larger than those of the 2-D base of the higher box. Of course, you can rotate a box so that any side functions as its base.It is also allowable to use multiple instances of the same type of box. You task is to complete the function maxHeight which returns the height of the highest possible stack so formed.
 

Note: 
Base of the lower box should be strictly larger than that of the new box we're going to place. This is in terms of both length and width, not just in terms of area. So, two boxes with same base cannot be placed one over the other.

 

Example 1:

Input:
n = 4
height[] = {4,1,4,10}
width[] = {6,2,5,12}
length[] = {7,3,6,32}
Output: 60
Explanation: One way of placing the boxes is
as follows in the bottom to top manner:
(Denoting the boxes in (l, w, h) manner)
(12, 32, 10) (10, 12, 32) (6, 7, 4) 
(5, 6, 4) (4, 5, 6) (2, 3, 1) (1, 2, 3)
Hence, the total height of this stack is
10 + 32 + 4 + 4 + 6 + 1 + 3 = 60.
No other combination of boxes produces a
height greater than this.
Example 2:

Input:
n = 3
height[] = {1,4,3}
width[] = {2,5,4}
length[] = {3,6,1}
Output: 15
Explanation: One way of placing the boxes is
as follows in the bottom to top manner:
(Denoting the boxes in (l, w, h) manner)
(5, 6, 4) (4, 5, 6) (3, 4, 1), (2, 3, 1) 
(1, 2, 3).
Hence, the total height of this stack is
4 + 6 + 1 + 1 + 3 = 15
No other combination of boxes produces a
height greater than this.
Your Task:
You don't need to read input or print anything. Your task is to complete the function maxHeight() which takes three arrays height[], width[], length[], and N as a number of boxes and returns the highest possible stack height which could be formed.


Expected Time Complexity : O(N*N)
*/
#include<bits/stdc++.h>

using namespace std;

//Defining the structure of the box
    struct box{
    int h,w,l;
    void setBox(int a, int b, int c){
        h = a;
        w = b;
        l = c;
    }
};

bool compare(struct box &a, struct box &b){
    return ( (a.l*a.w) > (b.w*b.l) );
}
    int maxHeight(int h[],int w[],int l[],int n)
    {
        //Your code here
            int len = n*3;
     box arr[len];
     int index = 0;
     for(int i=0;i<n;i++){
         arr[index++].setBox(h[i],max(w[i] , l[i]) , min(w[i],l[i]) );
         arr[index++].setBox(w[i],max(l[i],h[i]), min(l[i],h[i]) );
         arr[index++].setBox(l[i], max(w[i],h[i]) , min(w[i],h[i]) );
     }

     sort(arr,arr+len,[&](box&a, box&b){return ( (a.l*a.w) > (b.w*b.l) ); });

     int lis[len];
     for(int i=0;i<len;i++){
        lis[i] = arr[i].h;
     }
     for(int i=1;i<len;i++){
         for(int j=0;j<i;j++){
             if((arr[i].w<arr[j].w)&&(arr[i].l<arr[j].l)
             &&(lis[i] < lis[j]+arr[i].h)){
                 lis[i] = lis[j]+arr[i].h;
             }
         }
     }
     int mx = 0;
     for(int i=0;i<len;i++){
         mx = max(mx, lis[i]);
     }
     return mx;
    }
int main(){
    return 0;
}