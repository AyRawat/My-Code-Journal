#include<bits/stdc++.h>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };


//My Approach
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int count1=0;
        int count2=0;
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        while(temp1!=NULL){
            count1++;
            temp1=temp1->next;
        }
        while(temp2!=NULL){
            count2++;
            temp2=temp2->next;
        }
            ListNode* curr1 = headA;
            ListNode* curr2 = headB;
        if(count1 >= count2){
            int val = count1-count2;
            while(val-- > 0){
                curr1=curr1->next;
            }
        }else{
            int val = count2-count1;
            while(val-- > 0){
                curr2=curr2->next;
            }
            
        }
        
         while(curr1!=NULL && curr2!=NULL){
                if(curr1 == curr2){
                    return curr1;
                }
             curr1=curr1->next;
             curr2=curr2->next;
            }
        return NULL;
    }

//Super Concise Approach
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *cur1 = headA, *cur2 = headB;
    while(cur1 != cur2){
        cur1 = cur1?cur1->next:headB;
        cur2 = cur2?cur2->next:headA;
    }
    return cur1;
}
int main(){
    return 0;
}