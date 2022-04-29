#include<bits/stdc++.h>
using namespace std;


class LRUCache {
public:
class node{
    public:
        int key;
        int val;
        node *next;
        node *prev;
        node(int _key,int _val){
            key = _key;
            val = _val;
        }
    };
    
    unordered_map<int, node *> uMap;
    node *head = new node(-1,-1);
    node *tail = new node(-1,-1);
    int cap;
    
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(node *newNode){
        node *temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }
    void deleteNode(node *newNode){
        node* dNext = newNode->next;
        node* dPrev = newNode->prev;
        dPrev->next = dNext;
        dNext->prev = dPrev;
    }
    
    int get(int key) {
        if(uMap.find(key)!=uMap.end()){
            node *key_address = uMap[key];
            int ans = key_address->val;
            uMap.erase(key);
            deleteNode(key_address);
            addNode(key_address);
            uMap[key] = head->next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(uMap.find(key)!=uMap.end()){
            node *existing_node = uMap[key];
            uMap.erase(key);
            deleteNode(existing_node);
        }
        if(uMap.size() == cap){
            uMap.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new node(key,value));
        uMap[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */