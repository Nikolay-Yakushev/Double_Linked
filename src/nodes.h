#pragma once

#include<iostream>

class Node{
    friend std::ostream& operator << (std::ostream& os, Node* node);
    private:
        int value;
        Node* prev;
        Node* next;
        
    public:
        Node(int val){
            value=val;
        }
    const int get_nd_val();
    Node* get_prev();
    Node* get_next();
    void set_next(Node* nd);
    void set_prev(Node* nd);

};

class NodesList{
    public:
        Node *first;
        Node *last;

    ~NodesList(){};

    Node* find(int val, Node* nd);
    void remove(int val);
    void push_front(int val);
    void push_back(int val);
    void insert_before(int val_node, int val);
    void insert_after(int val_node, int val);
};

NodesList* allocate_list();