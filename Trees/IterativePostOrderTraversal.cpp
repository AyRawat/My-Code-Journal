#include<bits/stdc++.h>
using namespace std;

struct BinaryTree
{
	int val;
	BinaryTree *left;
	BinaryTree *right;
	BinaryTree(int x) {
		val = x;
		left = NULL;
		right=NULL;
	}
};
//Using 2 stacks

/*

*/
vector<int> iterativePostOrder(BinaryTree* root) {
    vector<int> result;
    if(root == NULL) result;
  //Create 2 stacks
    stack<BinaryTree*> st1 , st2;
  //Start by putting root in st1. 
  // Put top of the stack in st2 and put its left 
  //and right values to st1 , if they exist
   st1.push(root);
   while(!st1.empty()){
    st2.push(st1.top());
    st1.pop();
    BinaryTree* curr = st2.top();
     if(curr->left!=NULL) st1.push(curr->left);
     if(curr->right!=NULL) st1.push(curr->right);      
   }
   while(!st2.empty()){
    result.push_back(st2.top()->val);
    st2.pop();
   }
   return result;
}

int main() {
    return 0;
}