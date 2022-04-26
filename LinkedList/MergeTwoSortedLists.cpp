#include<bits/stdc++.h>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      ListNode* head = NULL;
    ListNode* tail = NULL;
    if(l1==NULL){
        return l2;
    }else if(l2==NULL){
        return l1;
    }
    if(l1->val <= l2->val){
        head = tail = l1;
        l1=l1->next;
    }else {
        head = tail = l2;
        l2=l2->next;
    }
    while(l1!=NULL && l2!=NULL){
        if(l1->val <= l2->val)
        {
            tail->next = l1;
            tail = l1;
            l1=l1->next;
        }else if(l2->val < l1->val)
        {
            tail->next = l2;
            tail = l2;
            l2 = l2->next;
        }
     
    }
        if(l1==NULL){
            tail->next = l2;
        }else{
            tail->next = l1;
        }
    return head;
    }