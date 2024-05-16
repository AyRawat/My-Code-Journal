//https://leetcode.com/problems/evaluate-boolean-binary-tree/?envType=daily-question&envId=2024-05-16

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };


   bool evaluateTree(TreeNode* root) {
       if(root->val == 1 || root->val == 0) return root->val;
       bool l = evaluateTree(root->left);
       bool r = evaluateTree(root->right);
        
       return (root->val == 2 ) ? (l || r) :  (l & r);
    }
