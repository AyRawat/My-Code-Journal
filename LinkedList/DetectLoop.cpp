#include<bits/stdc++.h>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
  
    bool hasCycle(ListNode *head) {
          ListNode* curr = head;
          ListNode* fast = head;
    while(fast!=NULL&&fast->next!=NULL){
        
        curr=curr->next;
        fast = fast->next->next;
        if(curr == fast){
            return true;
        }
    }
    return false;
    }