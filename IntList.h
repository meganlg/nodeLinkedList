// Megan Gillen CSC 250

/* IntList class declaration and constants
    This IntLIst class creates an object that holds a node list. 
    The class provides function to edit, display and add the contents of the node list */
    
// INCLUDE GUARDS
#ifndef INTLIST_H 

#define INTLIST_H
using namespace std;


// CLASS
class IntList{
    private:
        struct ListNode{int value; ListNode *next;};
        ListNode *head; // contains the address of the first node

        int addList(ListNode *nodePtr) const; // private member function that returns the sum of the integers in the list


    public:
        IntList(){  // default constructor - sets head to nullptr
            head = nullptr;
        }
        IntList(const IntList &obj); // copy constructor - dynamically allocated space for the new head pointer
        ~IntList(); // destructor - deletes the node list to free up space
        void appendNode(int num);   // allocates a new node, stores the passed value into the node,
                                        // and appends the node to the end of the list.
        void insertNode(int num);   // allocates a new node, stores the passed value into the node, and inserts the node 
                                        // into the list so that the nodes are in increasing numerical order
        void  deleteNode(int num); // searches for the node that contains the passed value and deletes it from the list
        void displayList(); // displays the entire list to the monitor
        int addList(){ // calls private addList recursive function, passing in the head member variable 
            return addList(head);   //and returning the value returned by the recursive function
        }
        
        




};
#endif