// Megan Gillen CSC 250

// main program to test the IntList class
    /* This program creates objects of the IntList class, 
    then uses the member functions and displays the node list to show that the functions worked properly */

#include <iostream>
#include "IntList.h"
using namespace std;


// MAIN

int main(){
    IntList list1;

    cout << "Appending 2, 4, and 8 to list1.\n";
    list1.appendNode(2);
    list1.appendNode(4);
    list1.appendNode(8);

    cout << "Here is the list diplayed using displayList function:\n";
    list1.displayList();

    cout << "Deleting 4 form the list using deleteNode function.\n";
    list1.deleteNode(4);
    cout << "Here is the list again:\n";
    list1.displayList();

    cout << "Inserting 7 in the list using insertNode function.\n";
    list1.insertNode(7);
    cout << "Here is the list again:\n";
    list1.displayList();

    cout << "Creating new object list2 and copying the contents from list1 to list2 using copy constructor.\n";
    IntList list2 = list1;
    cout << "Appending 10 onto list1 and inserting 3, then displaying both to show they were copied correctly.\n";
    list1.appendNode(10);
    list1.insertNode(3);
    cout << "list1:\n";
    list1.displayList();
    cout << "list2:\n";
    list2.displayList(); 

    cout << "Now printing the total of each list using addList function.\n";
    cout << "list1 total: " << list1.addList() << endl;
    cout << "list2 total: " << list2.addList() << endl;


    return 0;
}