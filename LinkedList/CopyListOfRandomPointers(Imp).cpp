#include<bits/stdc++.h>
using namespace std;

//This is a solution for a Leetcode question , won't work as a separate executable file
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
   
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* curr = head;
        //Creating Deep Copies along with the nodes
        while(curr!=NULL){  
        Node* deep_copy = new Node(curr->val);
        Node* nex = curr->next;
        curr->next = deep_copy;
        deep_copy->next = nex;
        curr = nex;
        }
        //Adjusting the random Pointers
        Node* iter = head;
        while(iter!=NULL){
            //Check if iterator's random pointer is not pointing to Null
            if(iter->random !=NULL){
                     iter->next->random = iter->random->next;   
            }
    
            //Since you broke the original Links, you need to move iterator twice to reach the original node.
            iter = iter->next->next;
        }
        //Separating the dummy LinkedList from Original
        Node* dummy= new Node(0);
        Node* copy = dummy;
        iter = head;
        while(iter!=NULL){
       Node* front = iter->next->next;
        copy->next = iter->next;
            iter->next = front;
            copy=copy->next;
             iter=iter->next;
        }
        return dummy->next;
        
    }
};