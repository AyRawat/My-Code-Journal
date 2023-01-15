#include <bits/stdc++.h>
using namespace std;


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
int height(BinaryTree *root)
{
    if (root == NULL)
        return 0;
    int lH = height(root->left);
    int rH = height(root->right);

    return 1 + max(lH, rH);
}

int maxPathSum(BinaryTree *root, int &maxH)
{
    if (root == NULL)
        return 0;
    int lH = maxPathSum(root->left, maxH);
    int rH = maxPathSum(root->right,maxH);
    maxH = max(maxH , lH + rH +root->val);
    return root->val + max(lH, rH);
}
int main()
{
    struct BinaryTree *root = newBinaryTree(3);
    root->left = newBinaryTree(9);
    root->right = newBinaryTree(20);
    root->left->left = newBinaryTree(4);
    root->left->right = newBinaryTree(5);
    root->left->right->left = newBinaryTree(8);
    root->right->left = newBinaryTree(15);
    root->right->right = newBinaryTree(7);
    root->right->right->left = newBinaryTree(9);
    root->right->right->right = newBinaryTree(10);
    int maxH = 0;
     maxPathSum(root,maxH);
    cout<<maxH<<endl;
    return 0;
}