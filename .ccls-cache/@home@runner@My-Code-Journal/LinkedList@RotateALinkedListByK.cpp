  #include<bits/stdc++.h>
  using namespace std;
    struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };   
   ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return NULL;
        if(head->next==NULL || k==0) return head;
        ListNode* curr = head;
        int len = 1;
        while(curr->next!=NULL){
            curr=curr->next;
            len++;
        }
        cout<<len<<endl;
         k = k%len;
        cout<<k<<endl;
        k  = len-k;
        curr->next= head;
        while(k--){
            curr=curr->next;
        }
        head = curr->next;
        curr->next = NULL;
        return head;
    }