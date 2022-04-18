#include<bits/stdc++.h>

using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
  //My Own Solution

void kSmallest(TreeNode* root, int k, priority_queue<int,vector<int>,greater<int>> &pq){
 if(root==NULL) return ;
 kSmallest(root->left,k,pq);
 pq.push(root->val);
kSmallest(root->right,k,pq);
}
    int kthSmallest(TreeNode* root, int k) {
         priority_queue<int, vector<int>, greater<int> > pq;
        kSmallest(root,k,pq);
        int smallest = 0;
        while(k!=0){
            smallest = pq.top();
            cout<<smallest<<endl;
            pq.pop();
            k--;
        }
        return smallest;
    }
//Reccursive Solution
int ans;
void inOrderTraversal(TreeNode* root,int k){
    if(root == NULL ) return;

    inOrderTraversal(root->left,k);
    if(--k==0){
         ans = root->val;
       return;
    }
    inOrderTraversal(root->right, k);
}
//Solution with a vector;

//In Inorder Traversal you always get a BST in sorted order
  vector<int> a;
    int kthSmallest(TreeNode* root, int k) {
        inorder(root);
        int ans = a[k-1];
        return ans;
    }
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        a.push_back(root->val);
        inorder(root->right);
    }
