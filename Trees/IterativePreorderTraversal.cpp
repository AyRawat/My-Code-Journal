#include<bits/stdc++.h>
using namespace std;

struct BinaryTree {
   int val ;
   BinaryTree *left;
   BinaryTree *right;
    BinaryTree() : val(0), left(nullptr) , right(nullptr) {}
    BinaryTree(int x): val(x), left(nullptr) , right(nullptr) {}
    BinaryTree(int x, BinaryTree *left, BinaryTree *right) : val(x), left(left) , right(right) {}  
};

void traversal(BinaryTree* root){
    if(root == NULL) return ;
    stack<BinaryTree*> st;
    q.push(root);
    while(!st.empty()){
        BinaryTree* curr = st.top();
        st.pop();
        cout<<curr->val;
        if(curr->right!=NULL) st.push(curr->right);
        if(curr->left!=NULL) st.push(curr->left);
    }
}

int main(){
    return 0;
}