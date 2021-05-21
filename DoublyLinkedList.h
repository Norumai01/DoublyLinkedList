#ifndef DoublyLinkedList_h
#define DoublyLinkedList_h

#include <iostream>

using namespace std;

struct node {
    int data;
    node* next;
    node* prev;
};

class DoublyLinkedList {
    private:
    node* head;
    int count;
    
    public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    DoublyLinkedList(const DoublyLinkedList& newNode);
    DoublyLinkedList& operator=(const DoublyLinkedList& NewNodetoCpy);
        
    
    void push(int newdata);
    void print();
    int pop();
    int size();
    void insert(int dataToInsert, unsigned int index);
    void Remove(unsigned int index);
};

#endif