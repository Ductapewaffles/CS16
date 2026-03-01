// file: ll_functions.cpp
#include "ll_headers.h"

// Used in the function createLL()
// This function is started for you correctly - you have to complete it.
//   Use the comments to help you figure out what to do.
void h_insert(LinkNodePtr& head, string nom, int num) {
    //Preconditions: Takes in the head pointer passed by reference, a string, and an integer. The string and integer will be the values associated with the new Node
    //Postconditions: Adds a new node to the linked list with the associated values
    LinkNodePtr tmp_ptr; //pointer creation
    tmp_ptr = new LinkNode; //Temporary node creation

    tmp_ptr->name = nom; //the new node's name is now the string nom
    tmp_ptr->number = num; //the new node's number is now the integer num
    tmp_ptr->link = nullptr;  //set the link of the node to NULL as it will be inserted at the end of the linked list
    
    LinkNodePtr traversal_ptr; //create a pointer to traverse the list to get to the last node
   if(head == NULL){ //if list is empty, set the head pointer to the node tmp_ptr points to
        head = tmp_ptr;
    }
    else{
        traversal_ptr = head; //traversal pointer set to the same value as the head pointer
        while(traversal_ptr->link != NULL){ //gets to the last node
            traversal_ptr = traversal_ptr->link; 
        }
        traversal_ptr->link = tmp_ptr; //Pointer of last node changed to new node
    }
}

void createLL(LinkNodePtr& h){
    //Preconditions: Takes in the head pointer by reference
    //Postconditions: inserts a node to the end of the linked list evey time the user gives a new set of info, stop when user types: 0 0
    string nom = "";
    int num;
    while(nom != "0" || num != 0){
        cout << "Enter name, then a number. To quit, enter 0 for the name AND 0 for the number:\n"; //user prompt to get name and number
        cin >> nom >> num; //user input
        if(nom != "0" || num != 0){ //if the user decided not to exit, insert the node with the given information
            h_insert(h, nom, num);
        }
    }
}

void printLL(LinkNodePtr h){
    //Preconditions: The head pointer
    //Postconditions: Prints out the linked list
    LinkNodePtr traversalPtr = nullptr; //pointer created to traverse nodes
    if(h == NULL){ //if the list is empty (h points to nothing)
        cout << "This list is empty\n";
        return;
    }
    else{ //the list has entries
        cout << "Printing the list:\n"; 
        traversalPtr = h; //traversal pointer points to the same node h points to
        int count(0);
        while(traversalPtr != NULL){ //if the pointer no longer points to a node, then stop the loop
            cout << "Node #" << count << ": "; //giving the node position
            cout << traversalPtr->name << ", "; //outputs name within node
            cout << traversalPtr->number << "\n"; //outputs number within node
            traversalPtr = traversalPtr->link; //point to the next node
            count++; //increment the count as one node has been added to our knowledge
        }
    }
}

void insertNodeAfter(LinkNodePtr h) {
    //Preconditions: Takes in the head pointer by reference
    //Postconditions: Inserts a node with given information after the specified position
    if(h == nullptr){ //if the list is empty (h points to nothing)
        cout << "Cannot insert in a non-existing link\n";
        cout << "This list is empty\n";
        return;
    }
    int nodeAfter;
    LinkNodePtr traversalPtr = nullptr; //pointer created to traverse linked list
    cout << "Enter node position to insert new node after (enter negative number to exit): "; //user prompt
    cin >> nodeAfter; //user input
    if(nodeAfter < 0){ //if the user chose to exit (entered a negative number)
        return;
    }
    else{
        traversalPtr = h; //traversalPtr now points to the first node
        int count(0);
        while(traversalPtr != NULL){ //loop continues unless traversalPtr does not point to a node
            count++; //increment the count to get the amount of nodes
            traversalPtr = traversalPtr->link; //point to the next node
        }
        if(nodeAfter >= count){ //if the user inputs a position that is out of the node range then give an error
            cout << "Position entered is illegal. Nothing inserted\n";
            return;
        }
        string nom = "";
        int num;
        cout << "Enter data (name, then number): "; //user prompt
        cin >> nom >> num; //user input
        traversalPtr = h; //traversalPtr now points to first node
        LinkNodePtr tempPtr = nullptr; //create a pointer to point to the node with the information to add
        tempPtr = new LinkNode; //new node created
        tempPtr->name = nom; //data insertion
        tempPtr->number = num; //data insertion
        for(int i = 0; i < nodeAfter; i++){ //gets to the node you want to insert after
            if(traversalPtr == nullptr){ //for any reason, if the traversalPtr becomes NULL, then it gives an error (should already be handled by a previous error)
                cout << "Cannot insert in a non-existing link\n";
                return;
            }
            traversalPtr = traversalPtr->link; //points to next node
        }
        if(traversalPtr == nullptr){ //again if traversalPtr no longer points to anything, gives an error
            cout << "Cannot insert in a non-existing link\n";
            return;
        }
        tempPtr->link = traversalPtr->link; //the inserted node's link is now the node that nodeAfter was pointing to
        traversalPtr->link = tempPtr; //nodeAfter now points to inserted node
    }        
}

void findMax(LinkNodePtr h) {
    //Preconditions: Takes in the pointer to the linked list
    //Postconditions: Finds the maximum value for number among all the nodes within the linked list
    int max(0), current;
    LinkNodePtr traversalPtr; //pointer created to traverse linked list
    traversalPtr = h;
    if(h == nullptr){ //if the list is empty (h points to nothing), return
        cout << "This list is empty\n";
        return;
    }
    max = traversalPtr->number; //this sets the maximum to the first number in the linked list (if there is only one value it is the maximum)
    while(traversalPtr != NULL){ //exits loop if traversalPtr no longer points to a node
        current = traversalPtr->number; //the current value is assigned to the value within the given node
        if(max < current){ //if the "max" is less than the current value, set max to that value
            max = current;
        }
        traversalPtr = traversalPtr->link; //move onto the next node
    }
    cout << "Largest number in the list is: " << max << endl; //output
}

void findMin(LinkNodePtr h) {
    //Preconditions: Takes in the pointer to the linked list
    //Postconditions: Find the minimum value for number among all the nodes within the linked list
    int min(0), current;
    LinkNodePtr traversalPtr; //pointer creation to traverse linked list
    traversalPtr = h; //traversalPtr now points to start of linked list
    if(h == nullptr){ //if h points to nothing then the list is empty
        cout << "This list is empty\n";
        return;
    }
    min = traversalPtr->number; //this sets the minimum to the first number in the linked list
    while(traversalPtr != NULL){ //exits loop if traversalPtr no longer points to a node
        current = traversalPtr->number; //the current value is assigned to the value within the given node
        if(min > current){ //if "min" is less than the current value, set min to that value
            min = current;
        }
        traversalPtr = traversalPtr->link; //move onto the next node
    }
    cout << "Smallest number in the list is: " << min << endl; //output
}


