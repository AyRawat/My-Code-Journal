   int distribute(TreeNode* root, TreeNode* parent){
    if(!root) return 0;
    int moves = distribute(root->left, root) + distribute(root->right, root);
    int x = root->val - 1;
    if(parent) parent->val += x;
    moves+=abs(x);
    return moves;
   }

    int distributeCoins(TreeNode* root) {
        return distribute(root, NULL);
    }
