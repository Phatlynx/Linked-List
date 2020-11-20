// Implementation file for the Linked List Class

#include "LinkedList.h"

// *********************
// Default Constructor *
// *********************
LinkedList::LinkedList() {
    // initialize new list to empty list
    head = nullptr;
}

// ******************
// Class Destructor *
// ******************
LinkedList::~LinkedList() // class destructor
{
    ListNode* nodePtr; // to traverse the list
    ListNode* nextNode; // to point to the next node

    nodePtr = head; // position nodePtr at the head of the list

    while (nodePtr != nullptr)
    {
        nextNode = nodePtr->next; // save a pointer to the next node

        delete nodePtr; // delete the current node

        nodePtr = nextNode; // position nodePtr at the next node
    }
}

// ******************
// Copy Constructor *
// ******************
LinkedList::LinkedList(const LinkedList& other) : head(nullptr) {

    ListNode* current = other.head;

    while (current != nullptr) {
        /* insert value of current node in this list */
        insertNode(current->value);
        current = current->next;
    }

   
   /* ListNode* p1 = 0;
    ListNode* p2 = 0;


    if (other.head == 0)
    {
        head = 0;
        return;
    }
    else
    {
        head = new ListNode;

        head->value = other.head->value;
        head->next = other.head->next;
    }

    while (p2)
    {
        p1->next = new ListNode;
        p1 = p1->next;
        p1->next = p2->next;
        p1->value = p2->value;

        p2 = p2->next;

    }
    p1->next = 0;*/
}

// *************************************************************
// Insert new node in proper sorted order list is left sorted. *
// *************************************************************
void LinkedList::insertNode(int num) {
    ListNode* newNode;                // a new node
    ListNode* nodePtr;                // to traverse the list
    ListNode* previousNode = nullptr; // to point to previous node

    // allocate new node and store num there
    newNode = new ListNode;
    newNode->value = num;

    if (!head) // if no nodes in the list, make newNode the first node
    { 
        head = newNode;
        newNode->next = nullptr;
    }
    else // otherwise insert newNode
    { 
        nodePtr = head; // place nodePtr at the head of list
        previousNode = nullptr; // initialize previousNode to nullptr
        
        while(nodePtr!= nullptr && nodePtr->value < num) // skip all nodes whose value is less than num
        { 
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        if (previousNode == nullptr) // if new node is to be first in the list, insert before all other nodes
        { 
            head = newNode;
            newNode->next = nodePtr;
        }
        else // otherwise insert after the previous node
        { 
            previousNode->next = newNode;
            newNode->next = nodePtr;
        }
    }
}

// ***********************************************************************************
// Removes item from list if found. Does do anything if not found. Leave list sorted *
// ***********************************************************************************
void LinkedList::deleteNode(int num) {
    
    ListNode* nodePtr; // to traverse the list
    ListNode* previousNode = nullptr; // to point to previous node

    // if the list is empty, do nothing
    if (!head)
        return;

    // determine if the first node is the one
    if (head->value == num) 
    {
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    }
    else 
    {
        nodePtr = head;

        while (nodePtr != nullptr && nodePtr->value != num) // skip all nodes whos value member is not equal to num
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        if (nodePtr) // if nodePtr is not at the end of list, link the previous node to node after nodePtr, then delete nodePtr
        {
            previousNode->next = nodePtr->next;
            delete nodePtr;
        }
    }
}

// **************************************************
// Return position of node in list; -1 if not found *
// **************************************************
int LinkedList::searchList(int num) const {
    
    int position = 0;
    ListNode* nodePtr = head; // to traverse the list

    // find node and update position if found
    while (nodePtr != nullptr && nodePtr->value != num)
    {
        position++;
        nodePtr = nodePtr->next; // to move to the next node
    }
    if(nodePtr == nullptr) // if not found, return -1
    {
        return -1;
    }
    return position;
}

// **************************************************
// Returns the count of number of nodes in the list *
// **************************************************
int LinkedList::lengthList() const {

    ListNode* nodePtr = head; // to traverse the list
    int count = 0;

    while (nodePtr != nullptr)
    {
        nodePtr = nodePtr->next;
        count++;
    }
    cout << "List Length: " << count << endl;
    return count;
}

// ******************************************************
// Displays entire linked list as nodes become populated*
// ******************************************************
void LinkedList::displayList() const {

    ListNode* nodePtr = head; // to traverse the list

    while (nodePtr) 
    {
        cout << nodePtr->value << " "; // display the value in this node
        nodePtr = nodePtr->next; // move to the next node
    }
    
    cout << endl;
}