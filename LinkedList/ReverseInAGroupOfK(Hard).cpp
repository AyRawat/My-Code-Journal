#include<bits/stdc++.h>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || k == 1) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        //Initialization
        ListNode *curr=dummy, *nex=dummy, *prev=dummy;
        int count = 0;
        
        //Finding the length of the linked list
        while(curr->next!=NULL){
            curr = curr->next;
            count++;
        }
        //Main Operation
        while(count>=k){
            curr = prev->next;
            nex = curr->next;
            //Reversing a K Group of Nodes.
              //For a group of K there will be K-1 operation.
            for(int i=1;i<k;i++){
                curr->next = nex->next;
                nex->next = prev->next;
                prev->next = nex;
                nex=curr->next;
            }
            prev = curr;
            count-=k;
        }
        return dummy->next;
    }