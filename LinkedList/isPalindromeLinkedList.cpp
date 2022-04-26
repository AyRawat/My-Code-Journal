  #include<bits/stdc++.h>
using namespace std;

struct LL{
    LL* next;
    int val;
    LL():val(0),next(nullptr){}
    LL(int data): val(data), next(nullptr){}
    LL(int data, LL *next): val(data) , next(next){}
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