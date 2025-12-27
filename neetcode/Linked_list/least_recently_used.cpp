#include <bits/stdc++.h>
using namespace std;

// Implement a Least recently used cache
// we will use doubly linked list and hashmap for this
class Node{
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int key, int val){
        key = key;
        val = val;
        prev = nullptr;
        next = nullptr;
    }
};

// we will have hashmap, left and right pointer
// whenever we try to insert an element we will insert on the right
// during the get operation we will remove and insert, so that the curr element is placed on the right
// everytime we will lru element at the next of left and most recently used element at the prev of right
// hashmap to get val in O(1) and doubly linkedlist to get lru in O(1)
class LRUCache
{
private:
    /* data */
    unordered_map<int,Node*> cache;
    Node* left;
    Node* right;
    int cap;

    void insert(Node* node){
        Node* temp = right->prev;
        right->prev = node;
        node->next = right;
        node->prev = temp;
        temp->next = node;
    }

    void remove(Node* node){
        Node* next = node->next;
        Node* prev = node->prev;
        next->prev = prev;
        prev->next = next;
    }
public:
    LRUCache(int capacty){
        this->cap = capacty;
        this->left = new Node(0,0);
        this->right = new Node(0,0);
        this->left->next = this->right;
        this->right->prev = this->left;
    }
    int get(int key){
        if(cache.find(key) != cache.end()){
            remove(cache[key]);
            insert(cache[key]);
            return cache[key]->val;
        }
        return -1;
    }
    void put(int key, int val){
        if(cache.find(key) != cache.end()){
            remove(cache[key]);
            insert(cache[key]);
            cache[key]->val = val;
        }else{
            Node* newNode = new Node(key, val);
            cache[key] = newNode; 
            insert(newNode);
            if(cache.size() > this->cap){
                Node* lru = this->left->next;
                remove(lru);
                cache.erase(lru->key);
                delete lru; 
            }
        }
    }
};
