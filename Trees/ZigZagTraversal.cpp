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

vector<vector<int>> zigZagTraversal(BinayTree* root)
{
    vector<vector<int>> result;
    if (root == NULL) return result;
    // Flag = L to R
    int flag = true;
    queue<BinaryTree*> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> level(size);
        for (int i = 0; i < size; i++)
        {
            BinaryTree *curr = q.front();
            q.pop();
            int index = (flag) ? i : (size - 1 - i);
            level[index] = curr->val;
            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
        }
        flag = !flag;
        result.push_back(level);
    }
    return result;
}

int main()
{
    return 0;
}