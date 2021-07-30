//
//  unorderedLinkedList.cpp
//  LinkedList
//
//  Created by Philip Nguyen on 7/29/21.
//

#include <stdio.h>
#include <iostream>
#include "unorderedLinkedList.h"

template<class Type>
bool unorderedLinkedList<Type>::search(const Type& searchItem) const {
    nodeType<Type> *current;
    current = first;
    
    while(current) {
        if(current->info == searchItem) // found the searchItem
            return true;
        else
            current = current->link;
    }
    return false;
}

template<class Type>
void unorderedLinkedList<Type>::insertFirst(const Type& newItem) {
    nodeType<Type> *newNode;
    newNode->info = newItem;
    newNode->link = this->first;
    
    first = newNode;
    count++;
    
    if(last == nullptr)
        last = newNode;
}

template<class Type>
void unorderedLinkedList<Type>::insertLast(const Type& newItem) {
    nodeType<Type> *newNode;
    newNode->info = newItem;
    newNode->link = nullptr; //necessary?
    
    if(first == nullptr) { // if list is empty
        first = newNode;
        last = newNode;
    }
    else { // list is not empty
        last->link = newNode;
        last = newNode;
    }
    count++;
}

template<class Type>
void unorderedLinkedList<Type>::deleteNode(const Type& deleteItem) {
    nodeType<Type> *current;
    nodeType<Type> *trailCurrent; // pointer just before current
    bool found;
    
    
    // if list is empty
    if(first == nullptr)
        std::cout << "Cannot delete from an empty list" << std::endl;
    else { // the list is NOT empty
        // CASE 1: DeleteItem is the first node
        if(first->info == deleteItem) {
            current = first;
            first = first->link;
            count--;
            
            if(first == nullptr) // the list only HAD 1 node
                last = nullptr;
            
            delete current;
        }
        // CASE 2: deleteItem is NOT the first node
        else {
            found = false;
            trailCurrent = first;
            current = first->link;
            
            // traverse the list until deleteNode is found or no more nodes
            while(current != nullptr && !found) {
                if(current->info != deleteItem) {
                    // not found
                    trailCurrent = current;
                    current = current->link;
                }
                else
                    found = true;
            }
            
            if(found) {
                trailCurrent->link = current->link;
                count--;
                
                if(last == current)
                    last = trailCurrent;
            }
            else {
                std::cout << "The item to be deleted is not in the list" << std::endl;
            }
            
        }
    }
        
    
}
