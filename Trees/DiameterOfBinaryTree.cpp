#include <bits/stdc++.h>
using namespace std;

// Longest Path Between 2 Nodes
// Paths does not need to pass via root node

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


//BruteForce Solution
int height(BinaryTree* root) {
    if(root == NULL) return 0;
    return 1 + max(height(root->left) , height(root->right));
}
void findMaxHeightBF(BinaryTree* root , int &maxH){
    if(root==NULL) return;
    int lH = height(root->left);
    int rH = height(root->right);

    maxH = max(maxH , lH+rH);
    findMaxHeightBF(root->left , maxH);
    findMaxHeightBF(root->right , maxH);
}
struct BinaryTree *newBinaryTree(int data)
{
    struct BinaryTree *BinaryTree = (struct BinaryTree *)malloc(sizeof(struct BinaryTree));
    BinaryTree->val = data;
    BinaryTree->left = NULL;
    BinaryTree->right = NULL;

    return (BinaryTree);
}

//Using the height of tree concep to find the diameter as well
int diameterOfTree(BinaryTree* root, int &maxH){
    if(root == NULL) return 0;

    int lH = diameterOfTree(root->left,maxH);
    int rH = diameterOfTree(root->right, maxH);

    return 1 + max(lH,rH);
}

int main(){
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
    findMaxHeightBF(root,maxH);
    cout<<maxH<<endl;
    return 0;
}