#include<bits/stdc++.h>
using namespace std;

struct LL{
    LL* next;
    int val;
    LL():val(0),next(nullptr){}
    LL(int data): val(data), next(nullptr){}
    LL(int data, LL *next): val(data) , next(next){}
};

//Iterative Method for reversing
LL* reverseListIteratively(LL* head){
    LL* newHead = NULL;
    while(head!=NULL){
        LL* next = head->next;
        head->next = newHead;
        newHead = head;
        head = next;
    }
    return newHead;
}
LL* reverseLinkedList(LL* head){
    if(head->next == NULL) return head;
   LL*rest_head =  reverseLinkedList(head->next);
   LL* rest_tail =head->next;
   rest_tail->next = head;
   head->next = NULL;
   return rest_head;
}
int main(){
    return 0;
}