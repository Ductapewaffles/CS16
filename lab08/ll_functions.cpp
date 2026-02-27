// file: ll_functions.cpp
#include "ll_headers.h"

// Used in the function createLL()
// This function is started for you correctly - you have to complete it.
//   Use the comments to help you figure out what to do.
void h_insert(LinkNodePtr& head, string nom, int num) {
    LinkNodePtr tmp_ptr;
    tmp_ptr = new LinkNode;

    tmp_ptr->name = nom;
    tmp_ptr->number = num;
    tmp_ptr->link = nullptr; 
    
    LinkNodePtr traversal_ptr; //create a pointer to traverse the list to get to the last node
   if(head == NULL){ //if list is empty, set the head pointer to the node tmp_ptr points to
        head = tmp_ptr;
    }
    else{
        traversal_ptr = head; 
        while(traversal_ptr->link != NULL){ //gets to the last node
            traversal_ptr = traversal_ptr->link; 
        }
        traversal_ptr->link = tmp_ptr; //Pointer of last node changed to new node
    }
}

void createLL(LinkNodePtr& h){
    // Incomplete function - student must complete
    string nom = "";
    int num;
    while(nom != "0" || num != 0){
        cout << "Enter name, then a number. To quit, enter 0 for the name AND 0 for the number:\n";
        cin >> nom >> num;
        if(nom != "0" || num != 0){
            h_insert(h, nom, num);
        }
    }
}

void printLL(LinkNodePtr h){
    LinkNodePtr traversalPtr = nullptr;
    if(h == NULL){
        cout << "This list is empty\n";
        return;
    }
    else{
        cout << "Printing the list:\n";
        traversalPtr = h;
        int count(0);
        while(traversalPtr != NULL){
            cout << "Node #" << count << ": ";
            cout << traversalPtr->name << ", ";
            cout << traversalPtr->number << "\n";
            traversalPtr = traversalPtr->link;
            count++;
        }
    }
}

void insertNodeAfter(LinkNodePtr& h) {
    if(h == nullptr){
        cout << "Cannot insert in a non-existing link\n";
        cout << "This list is empty\n";
        return;
    }
    int nodeAfter;
    LinkNodePtr traversalPtr = nullptr;
    cout << "Enter node position to insert new node after (enter negative number to exit): ";
    cin >> nodeAfter;
    if(nodeAfter < 0){
        return;
    }
    else{
        traversalPtr = h;
        int count(0);
        while(traversalPtr != NULL){
            count++;
            traversalPtr = traversalPtr->link;
        }
        if(nodeAfter >= count){
            cout << "Position entered is illegal. Nothing inserted\n";
            return;
        }
        string nom = "";
        int num;
        cout << "Enter data (name, then number): ";
        cin >> nom >> num;
        traversalPtr = h;
        LinkNodePtr tempPtr = nullptr;
        tempPtr = new LinkNode;
        tempPtr->name = nom;
        tempPtr->number = num;
        for(int i = 0; i < nodeAfter; i++){
            if(traversalPtr == nullptr){
                cout << "Cannot insert in a non-existing link\n";
                return;
            }
            traversalPtr = traversalPtr->link;
        }
        if(traversalPtr == nullptr){
            cout << "Cannot insert in a non-existing link\n";
            return;
        }
        tempPtr->link = traversalPtr->link;
        traversalPtr->link = tempPtr;
    }        
}

void findMax(LinkNodePtr h) {
    int max(0), current;
    LinkNodePtr traversalPtr;
    traversalPtr = h;
    if(h == nullptr){
        cout << "This list is empty\n";
        return;
    }
    while(traversalPtr != NULL){
        current = traversalPtr->number;
        if(max < current){
            max = current;
        }
        traversalPtr = traversalPtr->link;
    }
    cout << "Largest number in the list is: " << max << endl;
}

void findMin(LinkNodePtr h) {
    // Incomplete function - student must complete
    int min(0), current;
    LinkNodePtr traversalPtr;
    traversalPtr = h;
    if(h == nullptr){
        cout << "This list is empty\n";
        return;
    }
    min = traversalPtr->number;
    while(traversalPtr != NULL){
        current = traversalPtr->number;
        if(min > current){
            min = current;
        }
        traversalPtr = traversalPtr->link;
    }
    cout << "Smallest number in the list is: " << min << endl;
}


