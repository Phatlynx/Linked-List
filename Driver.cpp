//***************************************************************
// Author: Cheng Chun Hsieh
//
// Programming Assignment 2: Program for a linked list to hold a 
// sorted list of integers in ascending order.
//
// Date: 9/18/20
// Version: 1
//***************************************************************

#include "LinkedList.h"

int main() {
    LinkedList myList;

    //Test length, display, and insert
    cout << myList.lengthList();
    myList.insertNode(65);
    myList.insertNode(11);
    myList.insertNode(78);
    myList.insertNode(102);
    myList.insertNode(4);
    myList.insertNode(55);
    myList.displayList();
    myList.lengthList();

   int index = myList.searchList(55);
   cout << endl << "55 is at position: " << index << endl;
   index = myList.searchList(88);
   cout << endl << "88 is at position: " << index << endl;
    //Test remove
    myList.deleteNode(65); // from inside
    myList.displayList();
    myList.deleteNode(4);  // from beginning
    myList.displayList();
    myList.deleteNode(102); // from end
    myList.displayList();
    myList.deleteNode(88);  // not found
    myList.displayList();

    // Test copy constructor
    LinkedList list2 = myList;
    list2.displayList();
    list2.lengthList();

    list2.insertNode(100);
    list2.displayList();
    list2.lengthList();

    return 0;
}
