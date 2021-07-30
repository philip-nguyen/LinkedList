//
//  linkedListType.h
//  LinkedList
//
//  Created by Philip Nguyen on 7/29/21.
//
#include "nodeType.h"
#include "linkedListIterator.h"

#ifndef linkedListType_h
#define linkedListType_h

template<class Type>
class linkedListType {
public:
    const linkedListType<Type>& operator=(const linkedListType<Type>&);
    // Overload the assignment operator
    
    void initializeList();
    // INitialize the list to an empty state
    // Postcondition: first = NULL< last = NULL, count = 0
    
    bool isEmptyList() const;
    // FUnction to determine whether the list is empty
    // Postcondition: Returns true if the list is empty
    
    void print() const;
    // Function to output the data contained in EACH node
    // Postcondition: none
    
    int length() const;
    // Function returns length of list
    
    void destroyList();
    // Function to delete all the node from the list.
    // Postcondition: first = NULL, last = NULL, count = 0;
    
    Type front() const;
    // Function to return the first element of the list
    // Precondition: the list must exist and must not be empty
    // Postcondition: If the list is empty, the program terminates
    // otherwise, the first element is returned
    
    Type back() const;
    // FUnction to return the back element of the list
    // Pre and postconditions same but for back
    
    virtual bool search(const Type& searchItem) const = 0;
    // Function to determine whether searchItem is in the list.
    // Postcondition: Returns true if searchItem is in the list
    // otherwise returns false
    
    virtual void insertFirst(const Type& newItem) = 0;
    // Function to insert newItem at the beginning of the list
    // Postcondition: first points to the new list, newItem is
    // inserted at the beginning of the list, count++
    
    virtual void insertLast(const Type& newItem) = 0;
    // Function to insert newItem at the end of the list
    // POstcondition: last points to the new item, last = last->link
    
    virtual void deleteNode(const Type& deleteItem) = 0;
    // Function to delete deleteItem from the list.
    // Postcondition: if found, the node containing deleteItem
    // is deleted from the list
    
    linkedListIterator<Type> begin();
    // Function to return an iterator at teh beginning of the list
    // Postcondition: returns an iterator such that curent is set
    // to first
    
    linkedListIterator<Type> end();
    // Function to return an iterator one element past the
    // last element of the linked list
    // Postcondition: returns an iterator such that current
    // is set to NULL
    
    linkedListType();
    // default constructor
    // init the list to an empty state
    // Postcondition: first = null, last = null, count = 0
    
    linkedListType(const linkedListType<Type>& otherList);
    // copy constructor
    
    ~linkedListType();
    // destructor
    // Deleted all the nodes from the list
    // Postcondition: the list object is destroyed
    
protected:
    int count; // num of node in list
    nodeType<Type> *first;
    nodeType<Type> *last;
    
private:
    void copyList(const linkedListType<Type>& otherList);
    // Function to make a copy of otherList.
    // Postcondition: a copy of otherList is created and assigned
    // to this list
};


#endif /* linkedListType_h */
