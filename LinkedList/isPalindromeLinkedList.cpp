#include<bits/stdc++.h>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

  
  ListNode* reverseList(ListNode *head){
       if(head==NULL || head->next==NULL) return head;
       ListNode* rest_head = reverseList(head->next);
       ListNode* rest_tail = head->next;
       rest_tail->next = head;
       head->next = NULL;
       return rest_head;
   }
    bool isPalindrome(ListNode* head) {
      if(head == NULL ) return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
           slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* rev_list = reverseList(slow->next);
        ListNode* curr = head;
        while(rev_list!=NULL){
            if(rev_list->val != curr->val) return false;
            rev_list = rev_list->next;
            curr = curr->next;
        }
        return true;
        
    }

    //Awesome Soltuion
        ListNode* temp;
    bool isPalindrome(ListNode* head) {
        temp = head;
        return check(head);
    }
    
    bool check(ListNode* p) {
        if (NULL == p) return true;
        bool isPal = check(p->next) & (temp->val == p->val);
        temp = temp->next;
        return isPal;
    }