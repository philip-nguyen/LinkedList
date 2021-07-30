//
//  linkedListIterator.h
//  LinkedList
//
//  Created by Philip Nguyen on 7/29/21.
//
#include "nodeType.h"

#ifndef linkedListIterator_h
#define linkedListIterator_h
template<class Type>
class linkedListIterator {
public:
    linkedListIterator();
    // Default Constructor
    // Postcondition: current = nullptr;
    
    linkedListIterator(nodeType<Type> *ptr);
    // Constructor with a parameter
    // Postcondition: current = ptr;
    
    Type operator*();
    // Function to overload teh dereferencing operator *.
    //Postciondition: Returns the info contained in the node
    
    linkedListIterator<Type> operator++();
    // Overload the preincrement operator.
    // Postcodition: the iterator is advanced to the next node
    
    bool operator==(const linkedListIterator<Type>& right) const;
    // Overload the equality operator.
    // Postcondition: returns true if this iterator is equal to the
    // iterator specified by right, otherwise it returns false.
    
    bool operator!=(const linkedListIterator<Type>& right) const;
    // Overload the not equal to operator.
    // Postcondition: Returns true if this iterator is not qual to the iterator specified by right,
    // otherwise it returns false
    
private:
    nodeType<Type> *current; // pointer to point to the current node in the llist
};

#endif /* linkedListIterator_h */
