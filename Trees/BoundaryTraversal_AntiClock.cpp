#include <bits/stdc++.h>
using namespace std;

/*First you take -> Left Boundary excluding leaf
                    Leaf Nodes
                    Right Boundary on the Reverse excluding leaf
*/

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
bool isLeaf(BinaryTree *root)
{
    if (root->left == NULL && root->right == NULL)
        return true;
    return false;
}
void addLeftBoundary(BinaryTree *root, vector<int> &res)
{
    if (root == NULL)
        return;
    BinaryTree *curr = root->left;
    while (curr)
    {
        if (!isLeaf(curr))
            res.push_back(curr->val);
        if (curr->left)
            curr = curr->left;
        else
            curr = curr->right;
    }
}
void addRightBoundary(BinaryTree *root, vector<int> &res)
{
    if (root == NULL)
        return;
    BinaryTree *curr = root->right;
    vector<int> temp;
    while (curr)
    {
        if (!isLeaf(curr))
            temp.push_back(curr->val);
        if (curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }
    for(int i=0;i<temp.size();i++){
        res.push_back(temp[i]);
    }
}
void addLeaves(BinaryTree *root, vector<int> &res) {
    if(isLeaf(root)){
        res.push_back(root->val);
    }
    if(root->left) addLeaves(root->left, res);
    if(root->right) addLeaves(root->right, res);
}
vector<int> boundary(BinaryTree *root)
{
        vector<int> result;
    if (root == NULL)
        return result;
     if(!isLeaf(root)) result.push_back(root->val);
    addLeftBoundary(root, result);
    addLeaves(root, result);
    addRightBoundary(root,result);
    return result;
}

int main()
{
    return 0;
}