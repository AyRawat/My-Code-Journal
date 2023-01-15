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

bool identical(BinaryTree *rootOne, BinaryTree *rootTwo)
{
    if (rootOne == NULL && rootTwo == NULL)
        return true;
    if ((rootOne == NULL && rootTwo != NULL) || (rootOne != NULL && rootTwo == NULL))
        return false;

    if (rootOne->val != rootTwo->val)
        return false;
    return identical(rootOne->left, rootTwo->left) &&
           identical(rootOne->right, rootTwo->right);
}
int main()
{
    struct BinaryTree *rootOne = new BinaryTree(1);
    rootOne->left = new BinaryTree(5);
    rootOne->right = new BinaryTree(6);
    struct BinaryTree *rootTwo = new BinaryTree(1);
    rootTwo->left = new BinaryTree(5);
    rootTwo->right = new BinaryTree(6);
    cout << identical(rootOne, rootTwo);
    return 0;
}