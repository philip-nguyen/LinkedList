//
//  unorderedLinkedList.h
//  LinkedList
//
//  Created by Philip Nguyen on 7/29/21.
//

#ifndef unorderedLinkedList_h
#define unorderedLinkedList_h

#include "linkedList.h"

template<class Type>
class unorderedLinkedList: public linkedListType<Type> // inherits from ADT linkedListType
{
public:
    // Implements the virtual functions from linkedList ADT
    
    bool search(const Type& searchItem) const;
    // Function to determine whether searchItem is in the list
    // Postcondition: Returns true if searchItem is in the list
    // otherwise returns false
    
    void insertFirst(const Type& newItem);
    // Function to insert newItem at the beginning of the list
    // Postcondition: first points to the new list, newItem is
    // inserted at the beginning of the list, count++
    
    void insertLast(const Type& newItem);
    // Function to insert newItem at the end of the list
    // POstcondition: last points to the new item, last = last->link, count++
    
    void deleteNode(const Type& deleteItem);
    // Function to delete deleteItem from the list.
    // Postcondition: if found, the node containing deleteItem
    // is deleted from the list, count--
    
private:
    using linkedListType<Type>::first;
    using linkedListType<Type>::last;
    using linkedListType<Type>::count;
    // USING parent's protected vars
    // this is an alternative to:
    // this->first, this->last, this->count
    // in the function definitions for this class
};

// Place the definitions of the functions search, insertNode,
// insertFirst, insertLast, and deleteNode here

#endif /* unorderedLinkedList_h */
