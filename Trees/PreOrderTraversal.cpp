#include<bits/stdc++.h>
using namespace std;

struct BinaryTree{
int root;
BinaryTree* left=NULL;
BinaryTree* right=NULL;
};

void preOrder(BinaryTree* node){
  if(node == NULL) return ;
  cout<<node->root;
  preOrder(node->left);
  preOrder(node->right);
}


int main(){
  return 0;
}