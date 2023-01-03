#include <bits/stdc++.h>
using namespace std;

struct BinaryTree
{
	int val;
	BinaryTree *left;
	BinaryTree *right;
	BinaryTree(int x) {
		val = x;
		left = NULL;
		right=NULL;
	}
};

/*  Imagine how Recursion process the code inside an Auxillary Space
Take a variable and a stack
1. assign the root val to this node.
2. Now start moving to the left and keep pushing the values inside the stack.
3. If you encounter null value in node, pop the stack's top. and assign value of stack's top to right and
	 to node as well.
*/

vector<int> iterativeInorder(BinaryTree *root)
{
	vector<int> result;
	if (root == NULL)
		return result;
	vector<int> order;
	stack<BinaryTree *> st;
	BinaryTree *curr = root;
	st.push(root);
	while (!st.empty())
	{
		// if(curr!=NULL) curr = curr->left;
		if (curr != NULL)
		{
			curr = curr->left;
			st.push(root->left);
		}
		else
		{
			curr = st.top();
			order.push_back(curr->val);
			st.pop();
			curr = curr->right;
	}}
}
int main()
{
	BinaryTree* root;
	root->val =1;
	return 0;
}