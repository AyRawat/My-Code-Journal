/**
 * You are given the head of a non-empty linked list representing a non-negative integer without leading zeroes.

Return the head of the linked list after doubling it.

Input: head = [1,8,9]
Output: [3,7,8]
 **/
#include<bits/stdc++.h>
using namespace std;


 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
//Two Pointer approach
//Time: O(n)
//Space: O(1)
    ListNode* doubleIt(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;

        // Traverse the linked list
        while (curr != nullptr) {
            int twiceOfVal = curr->val * 2;

            // If the doubled value is less than 10
            if (twiceOfVal < 10) {
                curr->val = twiceOfVal;
            } 

            // If doubled value is 10 or greater
            else if (prev != nullptr) { // other than first node
                // Update current node's value with units digit of the doubled value
                curr->val = twiceOfVal % 10;
                // Add the carry to the previous node's value
                prev->val = prev->val + 1;
            } 
            // If it's the first node and doubled value is 10 or greater
            else { // first node
                // Create a new node with carry as value and link it to the current node
                head = new ListNode(1, curr);
                // Update current node's value with units digit of the doubled value
                curr->val = twiceOfVal % 10;
            }

            // Update prev and curr pointers
            prev = curr;
            curr = curr->next;
        }
        return head;
    }
};



//Reccursive approach
// Time: O(n)
// Space: O(n)
int twiceOfVal(ListNode* head){
  if(!head) return 0;

  int doubledValue = head->val * 2 + twiceOfVal(head->next);

  head->val = doubledValue % 10;

  return doubledValue / 10;
}


ListNode* solveIt(ListNode* head){
  int carry = twiceOfVal(head);
  if(carry)
    head = new ListNode(carry, head);
  return head;
}


int main(){
  ListNode* node1 = new ListNode(1);
  ListNode* node2 = new ListNode(8);
  ListNode* node3 = new ListNode(9);
  
  node1->next = node2;
  node2->next = node3;

  ListNode* temp = solveIt(node1 , 0);

  return 0;
}
