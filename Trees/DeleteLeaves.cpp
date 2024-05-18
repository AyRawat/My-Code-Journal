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

    bool solve(TreeNode* root, int k){
      if(root == NULL) return false;
     //We found the target node.
      if(root->val == k && root->left == nullptr && root->right == nullptr) return true;
    
//Check both the sides for the target node.
      bool checkLeft = solve(root->left , k);
      bool checkRight = solve(root->right, k);
//Remove the respective node.
      if(checkLeft) root->left = nullptr;
      if(checkRight) root->right = nullptr;

//Now, this condition tackles the case, when we have removed the child target nodes, but what if their parent was also the target node.
     if(root->val == k && root->left == nullptr && root->right == nullptr) return true;

      return false;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        solve(root, target);
//If the last remaining node, (Root) itself is the target node.
        if(root->val == target && root->left == NULL && root->right == NULL) root = NULL;
        return root;
    }
int main(){
  return 0;
}
