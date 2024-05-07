//You are given the head of a linked list.
//Remove every node which has a node with a greater value anywhere to the right side of it.
//Return the head of the modified linked list.
/*
 *
 *
 *We can use recursion to traverse the linked list and at each step, we compare the current node's value with the value of the next greater node. If the next greater node has a value less than the current node, we keep the current node; otherwise, we skip the current node.

🧠 Approach:

- Recursively traverse the linked list.
- At each step, compare the current node's value with the value of the next greater node.
- If the next greater node has a value less than the current node, keep the current node; otherwise, skip the current node.
- Return the head of the modified linked list.

📒 Complexity:

⏰ Time complexity: O(n), where n is the number of nodes in the linked list.

🧺 Space complexity: O(n), due to the recursive stack space.

 *
 * **/



#include<bits/stdc++.h>
using namespace std;


struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0) , next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next){}
};

ListNode* removeNodes(ListNode* head){
if(head == nullptr) return nullptr;
ListNode* node = head;
ListNode* nextNode = head->next;

if(nextNode == nullPtr || node->val >= nextNode->val) return node;

return nextNode;
}

int main(){
  return 0;
}
