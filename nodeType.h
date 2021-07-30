//
//  nodeType.h
//  LinkedList
//
//  Created by Philip Nguyen on 7/29/21.
//

#ifndef nodeType_h
#define nodeType_h

// Definition of the node
template <class Type>
struct nodeType {
    Type info;
    nodeType<Type> *link;
};


#endif /* nodeType_h */
