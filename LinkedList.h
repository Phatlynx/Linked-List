// Header file for the Linked List Class

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
using namespace std;

class LinkedList 
{
    struct ListNode 
    {
        int value;
        ListNode* next;
    };

private:
    ListNode* head;

public:
    LinkedList(); // default class constructor
    ~LinkedList(); // class destructor
    LinkedList(const LinkedList& obj); // class copy constructor
    void insertNode(int item);
    void deleteNode(int item);
    int searchList(int item) const; // return position of node in list; -1 if not found
    int lengthList() const;
    void displayList() const;
};

#endif