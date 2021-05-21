#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

DoublyLinkedList::DoublyLinkedList() {      //Default Constructor
    head = nullptr;
    count = 0;
}

DoublyLinkedList::~DoublyLinkedList() {     //Destructor
    cout << "Destructor called." << endl;
    
    node* tmp = head;
    node* newNode = nullptr;
    
    while (tmp->next != nullptr) {
        newNode = tmp->next;
        
        delete tmp;
        tmp = newNode; 
    } 
}

DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& newNode) {
    cout << "Copy constructor called." << endl;
    
    node* tmp = head;
    node* tempCopy = newNode.head;

    while (tmp->next != nullptr) {
            tmp = tmp->next;
            
        }
    tempCopy = tmp->next;  
} 

DoublyLinkedList& DoublyLinkedList::operator=(const DoublyLinkedList& NewNodetoCpy) {
    cout << "Assignment op called." << endl;
    
    node* tmp = head;
    node* tmpCopyNode = NewNodetoCpy.head;

    while (tmp->next != nullptr) {
        tmp->data = tmpCopyNode->data;
        tmp = tmp->next;
        tmpCopyNode = tmpCopyNode->next;
    }
    
    return *this;
} 


void DoublyLinkedList::push(int newdata) {      //Pushing data into a node
    
    if (head == nullptr) {      //If list starts off empty. Place null at next and prev of the node.
            
        head = new node;
        head->data = newdata;
            
        head->prev = nullptr;
        head->next = nullptr;
            
        }
        
    else {                  //If list already had numbers. Also place null at next and prev of the node.
        node* tmp = head;
        while (tmp->next != nullptr) {
                tmp = tmp->next;
        }
        tmp->next = new node;
        (tmp->next)->data = newdata;
        (tmp->next)->prev = nullptr;
        (tmp->next)->next = nullptr;
            
    }
    
    count++;
}

void DoublyLinkedList::print() {    //Scan through each nodes and print out the data.
    node* tmp = head;
    while (tmp->next != nullptr) {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
        
    cout << tmp->data << " ";
    cout << endl;
}

int DoublyLinkedList::pop() {   //Remove an element and its memory.
    int ret;
        
        node* tmp = head;
        node* prev = nullptr;
        while (tmp->next != nullptr) {
            prev = tmp;
            tmp = tmp->next;
        }
        
        ret = tmp->data;
        
        
        delete tmp;
        prev->next = nullptr;
        count--;
        
        return ret;
}

int DoublyLinkedList::size() {      // Print out the size of data of nodes.
     
        return count;    
}    

void DoublyLinkedList::insert(int dataToInsert, unsigned int index) {   //Insert a data to specific position of node.
    node* tmp = head;
        
    if (index > count) {
        "Error: Boundary limit threshold reached.";     //User cannot use a number higher then the amount of nodes.
    }
    
    if (index == 0) {
        node* backup = head;
        head = new node;
        head->data = dataToInsert;
        head->next = backup;  
    }
    
    else {
        for (int i = 0; i < index - 1; i++) {
            tmp = tmp->next;
        }
        
        node* backup = tmp->next;
        tmp->next = new node;
        (tmp->next)->data = dataToInsert;
        (tmp->next)->next = backup;  // address of the old nth element.
    }
    
    count++;  

}

void DoublyLinkedList::Remove(unsigned int index) {     // Remove the data of the element.
    node* tmp = head;
    
    for (int i = 0; i < index - 1; i++){
        tmp = tmp->next;
    }
    
    delete tmp->next;
} 


    