// Megan Gillen CSC 250
// IntList class function declarations

#include <iostream>
#include "IntList.h"
using namespace std;

// CLASS FUNCTIONS

IntList::IntList(const IntList &obj){   // copy constructor - dynamically allocated space for the new head pointer
    ListNode *oldNodePtr;

    head = nullptr;
    oldNodePtr = obj.head;
    while(oldNodePtr != nullptr){ // move thru old list, append a node to this list for each node in the old list
        appendNode(oldNodePtr->value);
        oldNodePtr = oldNodePtr->next;
    }
    return;
}

IntList::~IntList(){    // destructor - deletes the node list to free up space
    ListNode *tempPtr;
    ListNode *nextNode; 
    tempPtr = head;
    // while tempPtr is not at the end of the list
    while(tempPtr){
        // save a pointer to the next node
        nextNode = tempPtr->next;
        // delete current node
        delete tempPtr;
        //position current node at next node
        tempPtr = nextNode;
    }
}

void IntList::appendNode(int num){  // allocates a new node, stores the passed value into the node,
                                        // and appends the node to the end of the list.
    ListNode *newNode = nullptr; 
    ListNode *tempNode = nullptr;

    //create a new node
    newNode = new ListNode;

    // copy num into new node and set its pointer to null
    newNode->value = num;
    newNode->next = nullptr;

    // if list is empty
    if (head == nullptr){
        head = newNode;
    }
    else{ // else move to end of list and attach newNode
        tempNode = head;
        while(tempNode->next != nullptr){ // while node is not the end, point tempNode to the next node
            tempNode = tempNode->next;
        }
        // attatch new node to end of list
        tempNode->next = newNode;
    }
    return;
}


void IntList::insertNode(int num){  // allocates a new node, stores the passed value into the node, and inserts the node 
                                        // into the list so that the nodes are in increasing numerical order
    ListNode *newNode;
    ListNode *tempNode;
    ListNode *prevNode;

    // allocate new node and store num
    newNode = new ListNode;
    newNode->value = num;
    
    if(head == nullptr){ // if there are no nodes make newNode the first node
        head = newNode;
        newNode->next = nullptr;
    }
    else{ // else insert newNode
        tempNode = head;
        prevNode = nullptr;

        // skip all values which are less than num
        while(tempNode != nullptr && tempNode->value < num){ 
            prevNode = tempNode;
            tempNode = tempNode->next;
        }
        // if the new node is to be the first in the list, insert it at beginning
        if(prevNode == nullptr){
            head = newNode;
            newNode->next = tempNode;
        }
        else{ // else insert newNode after prevNode
            prevNode->next = newNode;
            newNode->next = tempNode;
        }
    }
    return;
}


void IntList::deleteNode(int num){  // searches for the node that contains the passed value and deletes it from the list

    ListNode *tempNode;
    ListNode *prevNode;

    // if the list is empty, do nothing
    if(head == nullptr){
        return;
    }
    
    if(head->value == num){ // if head is the num
        tempNode = head->next;
        delete head;
        head = tempNode;
    }
    else{ // else find matching node
        tempNode = head;

        while(tempNode->value != num && tempNode != nullptr){
            prevNode = tempNode;
            tempNode = tempNode->next;
        }
        // if tempNode is not at the end of the list, link prevNode to the node after tempNode, then delete tempNode
        if(tempNode != nullptr){
            prevNode->next = tempNode->next;
            delete tempNode;
        }
    }

    return;
}


void IntList::displayList(){    // displays the entire list to the monitor
    ListNode *tempNode;

    tempNode = head;
    while(tempNode != nullptr){// move through list to print each value
        cout << tempNode->value << endl;
        tempNode = tempNode->next;
    }
    return;
}

int IntList::addList(ListNode *nodePtr) const{  // private member function that returns the sum of the integers in the list
    // base case: if list is empty or at the end, do nothing and return
    if(nodePtr == nullptr){
        return 0;
    }
    else{ // else return the value plus the recursive call
        return nodePtr->value + addList(nodePtr->next);
    }
}
