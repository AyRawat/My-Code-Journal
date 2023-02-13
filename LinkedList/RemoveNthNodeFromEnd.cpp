   #include<bits/stdc++.h>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

//Optimal Approach
    ListNode* removeNthFromEndOptimal(ListNode* head, int n) {
        ListNode* start = new ListNode();
        start->next = head;
        ListNode* fast = start;
        ListNode* slow = start;
        for(int i=1;i<=n;i++) {
            fast = fast->next;
        }
        while(fast->next!=NULL){
            fast =fast->next;
            slow =slow->next;
        }
        slow->next = slow->next->next;
        return start->next;
    }
   //Naive Approach
   ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return head;
        int count = 0;
        ListNode* dummy = head;
        while(dummy!=NULL){
            dummy=dummy->next;
            count++;
        }
        ListNode *curr=head;
        if(count  == n){
       return head->next; 
        }
        int i = 1;   
        while(i++ != count-n && curr->next){
            curr=curr->next;
        }
       curr->next = curr->next->next;
        return head;
    }