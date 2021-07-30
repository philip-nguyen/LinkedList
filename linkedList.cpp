//
//  linkedListType.cpp
//  LinkedList
//
//  Created by Philip Nguyen on 7/29/21.
//
#include "linkedList.h"
#include "linkedListIterator.h"
#include <stdio.h>
#include <iostream>

// Nonabstract functions

template<class Type>
bool linkedListType<Type>::isEmptyList() const {
    return (first == nullptr);
}

// default constructor
template<class Type>
linkedListType<Type>::linkedListType() {
    first = nullptr;
    last = nullptr;
    count = 0;
}

// Delete the list
template<class Type>
void linkedListType<Type>::destroyList() {
    nodeType<Type> *temp;
    
    while(first != nullptr) {
        temp = first;
        first = first->link;
        // garbage collection! Deallocate memory occupied by temp
        delete temp;
    }
    // last and count postconditions
    last = nullptr;
    count = 0;
}

// initializes the list to an empty state
// ... or RE-initializes to be empty
// so it must delete the nodes (if any)
template<class Type>
void linkedListType<Type>::initializeList() {
    destroyList();
}

// Print the list
template<class Type>
void linkedListType<Type>::print() const {
    nodeType<Type> *current; // pointer to traverse the list
    
    current = first;
    while(current != nullptr) {
        std::cout << current->info << " ";
        current = current->link;
    }
}

// Get the length
template<class Type>
int linkedListType<Type>::length() const {
    return count;
}

// Retrieve data from the first Node
template<class Type>
Type linkedListType<Type>::front() const {
    assert(first != nullptr);
    
    return first->info;
}

// Retrieve the data from the last Node
template<class Type>
Type linkedListType<Type>::back() const {
    assert(last != nullptr);
    
    return last->info;
}

// returns the iterator to the first node
template<class Type>
linkedListIterator<Type> linkedListType<Type>::begin() {
    linkedListIterator<Type> temp(first);
    
    return temp;
}

// returns the iterator to the last node
template<class Type>
linkedListIterator<Type> linkedListType<Type>::end() {
    linkedListIterator<Type> temp(last);
    
    return temp;
}

// Copy the list
template<class Type>
void linkedListType<Type>::copyList(const linkedListType<Type>& otherList) {
    nodeType<Type> *newNode; // pointer to create a node
    nodeType<Type> *current; // pointer to traverse the list
    
    if(first != nullptr) // if the list is nonempty, make it empty!
        destroyList();
    
    if(otherList.first == nullptr) {
        first = nullptr;
        last = nullptr;
        count = 0;
    }
    else {
        current = otherList.first;
        
        count = otherList.count;
        
        // Copy the first node
        first = new nodeType<Type>;     // create the node
        first->info = current->info;    // copy the info
        first->link = nullptr;          // set the link field of teh node to NULL
        last = first;                   // make last point to the first node
        current = current->link;        // make current point to the next node
        
        // copy the remaining list
        while(current != nullptr) {
            newNode = new nodeType<Type>; // create the node
            newNode->info = current->info; // get the data
            newNode->link = nullptr;
            last->link = newNode;
            last = newNode;
            
            // traverse
            current = current->link;
        }
    }
}

// Destructor
template<class Type>
linkedListType<Type>::~linkedListType() {
    destroyList();
}

// Copy constructor
template <class Type>
linkedListType<Type>::linkedListType(const linkedListType<Type>& otherList) {
    first = nullptr;
    copyList(otherList);
}

template<class Type>
const linkedListType<Type>& linkedListType<Type>::operator=
(const linkedListType<Type>& otherList) {
    if(this != &otherList) {// avoid self-copy
        copyList(otherList);
    }
    
    return *this;
}


