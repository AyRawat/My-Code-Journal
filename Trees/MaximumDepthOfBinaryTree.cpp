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
int heightOfBinaryTree(BinaryTree *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(heightOfBinaryTree(root->left), heightOfBinaryTree(root->right));
}

int main()
{
    struct BinaryTree *root = newBinaryTree(1);
    root->left = newBinaryTree(2);
    root->right = newBinaryTree(3);
    root->left->left = newBinaryTree(4);
    root->left->right = newBinaryTree(5);
    root->left->right->left = newBinaryTree(8);
    root->right->left = newBinaryTree(6);
    root->right->right = newBinaryTree(7);
    root->right->right->left = newBinaryTree(9);
    root->right->right->right = newBinaryTree(10);
    cout<<heightOfBinaryTree(root);
    return 0;
}

/*
      1
    /   \
    2     3
 /   \   / \
 4    5  

*/