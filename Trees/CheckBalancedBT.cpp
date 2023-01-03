#include <bits/stdc++.h>
using namespace std;

// A Balanced Binary Tree is height(left) - height(right) <= 1

struct BinaryTree
{
    int val;
    BinaryTree *left;
    BinaryTree *right;
    BinaryTree(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};
struct BinaryTree *newBinaryTree(int data)
{
    struct BinaryTree *BinaryTree = (struct BinaryTree *)malloc(sizeof(struct BinaryTree));
    BinaryTree->val = data;
    BinaryTree->left = NULL;
    BinaryTree->right = NULL;

    return (BinaryTree);
}

//Better soln: 
int height(BinaryTree *root)
{
    if (root == NULL)
        return 0;
    int lH = height(root->left);
    if(lH == -1) return -1;
    int rH = height(root->right);
    if(rH == -1) return -1;
    if(abs(lH - rH) > 1) return -1;
    return 1 + max(lH , rH);
}
bool checkBalancedBT(BinaryTree* root){
 if(height(root) == -1) return false;
 return true;
}
//Naive Soln: O(n)^2
// bool isBalanceBT(BinaryTree *root)
// {
//     if (root == NULL)
//         return true;
//     if(root->left!=NULL && root->right!=NULL){
//     if(abs(heightOfBinaryTree(root->left) - heightOfBinaryTree(root->right)) > 1) return false;
//     }
//     bool left = isBalanceBT(root->left);
//     bool right = isBalanceBT(root->right);
//     if(!left || !right) return false;
//     return true;
// }

int main()
{
    struct BinaryTree *root = newBinaryTree(3);
    root->left = newBinaryTree(9);
    root->right = newBinaryTree(20);
    // root->left->left = newBinaryTree(4);
    // root->left->right = newBinaryTree(5);
    // root->left->right->left = newBinaryTree(8);
    root->right->left = newBinaryTree(15);
    root->right->right = newBinaryTree(7);
    // root->right->right->left = newBinaryTree(9);
    // root->right->right->right = newBinaryTree(10);
    cout << isBalanceBT(root);
    return 0;
}