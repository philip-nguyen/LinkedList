//
//  linkedListIterator.cpp
//  LinkedList
//
//  Created by Philip Nguyen on 7/29/21.
//
#include "linkedListIterator.h"
#include <stdio.h>

template<class Type>
linkedListIterator<Type>::linkedListIterator() {
    current = nullptr;
}

template<class Type>
linkedListIterator<Type>::linkedListIterator(nodeType<Type> *ptr) {
    current = ptr;
}

template<class Type>
Type linkedListIterator<Type>::operator* () {
    return current->info;
}

template<class Type>
linkedListIterator<Type> linkedListIterator<Type>::operator++() {
    current = current->link;
}

template<class Type>
bool linkedListIterator<Type>::operator==(const linkedListIterator<Type> &right) const {
    return (current == right.current);
}

template<class Type>
bool linkedListIterator<Type>::operator!=(const linkedListIterator<Type> &right) const {
    return (current == right.current);
}
