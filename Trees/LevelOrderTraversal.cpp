#include<bits/stdc++.h>
using namespace std;

struct BinaryTree {
   int val ;
   BinaryTree *left;
   BinaryTree *right;
    BinaryTree() : val(0), left(nullptr) , right(nullptr) {}
    BinaryTree(int x): val(x), left(nullptr) , right(nullptr) {}
    BinaryTree(int x, BinaryTree *left, BinaryTree *right) : val(x), left(left) , right(right) {}  
};



vector<vector<int>> levelOrderTraversal(BinaryTree* root){
   vector<vector<int>> ans;
   if(root == NULL) return ans;
    queue<BinaryTree*> q;
    q.push(root);
    while(!q.empty()){
        vector<int> level;
        int size = q.size();
        while(size--){
            BinaryTree* curr = q.front();
            if(curr->left != NULL) q.push(curr->left);
            if(curr->right != NULL) q.push(curr->right);
            q.pop();
            level.push_back(curr->val);
        }
        ans.push_back(level);
    }
    return ans;
}


int main(){
    BinaryTree(1);
    
    return 0;
}