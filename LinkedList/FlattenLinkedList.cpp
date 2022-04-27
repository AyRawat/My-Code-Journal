#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

Node *merge(Node*l1, Node*l2){
    if(l1==NULL&&l2==NULL) return NULL;
    if(l1==NULL)return l2;
    if(l2==NULL) return l1;
    Node *head = NULL;
    Node *tail = NULL;
    if(l1->data <= l2->data){
        head = tail =l1;
        l1 = l1->bottom;
    }else{
        head=tail=l2;
        l2 = l2->bottom;
    }
    
    while(l1!=NULL && l2!=NULL){
        if(l1->data<=l2->data){
            tail->bottom = l1;
            tail = l1;
            l1=l1->bottom;
        }else{
            tail->bottom = l2;
            tail = l2;
            l2 = l2->bottom;
        }
    }
    if(l1==NULL){
        tail->bottom = l2;
    }else{
        tail->bottom =l1;
    }
   
    return head;
}
Node *flatten(Node *root)
{
   // Your code here
if(root == NULL || root->next==NULL) return root;
root->next = flatten(root->next);
root = merge(root, root->next);
return root;
    
}