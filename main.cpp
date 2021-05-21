#include <iostream>
#include "DoublyLinkedList.h"
#include "DoublyLinkedList.cpp"

using namespace std;

int main() {
    DoublyLinkedList list1;
    DoublyLinkedList list2;
    
    list1.push(5);
    list1.push(6);
    list1.push(7);
    list1.push(8);
    
    list1.print();
    
    cout << "pop: " << list1.pop() << endl;
    
    list1.print();
    
    cout << "size: " << list1.size() << endl;
    
    list1.insert (3, 3);
    
    list1.print();
    cout << "size: " << list1.size() << endl;
    
    list1.Remove(2);
    list1.print(); 
    
    list2 = list1;
    list2.print();
    
    
    return 0;
}