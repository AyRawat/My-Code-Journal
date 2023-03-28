    #include<bits/stdc++.h>
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

    
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next==NULL) return NULL;
        ListNode* fast = head;
        ListNode* slow  = head;
        do{
            if(fast->next==NULL || fast->next->next == NULL)return NULL;
            slow = slow->next;
            fast = fast->next->next;
        }while(fast!=slow);
        
        fast = head;
        
        while(slow!=fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }