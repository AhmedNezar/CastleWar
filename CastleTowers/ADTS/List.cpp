//
//  List.cpp
//  DSLabs
//
//  Created by Ahmed Nezar on 23/11/2022.
//

#include "List.hpp"

using namespace std;

List::List() : mySize(0), first(0) {}

List::List(const List & origList) : first(0), mySize(origList.mySize) {
    if(mySize == 0) return;
    List::NodePointer origPtr, lastPtr;
    first = new Node(origList.first->data);
    lastPtr = first;
    origPtr = origList.first->next;
    while(origPtr != 0) {
        lastPtr->next = new Node(origPtr->data);
        origPtr = origPtr->next;
        lastPtr = lastPtr->next;
    }
}

List::~List() {
    NodePointer ptr, prev;
    prev = first;
    while(prev != 0) {
        ptr = prev->next;
        delete prev;
        prev = ptr;
    }
}

const List & List::operator=(const List &rightSide) {
    mySize = rightSide.mySize;
    if(mySize == 0) {
        this->~List();
        first = 0;
        return *this;
    }
    if(this != &rightSide) {
        this->~List();
        NodePointer origPtr, ptr;
        origPtr = rightSide.first;
        first = new Node(origPtr->data);
        ptr = first;
        origPtr = origPtr->next;
        while(origPtr != 0) {
            ptr->next = new Node(origPtr->data);
            origPtr = origPtr->next;
            ptr = ptr->next;
        }
    }
    return *this;
}

void List::insert(ElementType dataVal, int index) {
    if(index < 0 || index > mySize) return;
    NodePointer predptr = first, newPtr;
    newPtr = new Node(dataVal);
    if(index == 0) {
        newPtr->next = first;
        first = newPtr;
    }
    else {
        for(int i = 1; i < index; i++)
            predptr = predptr->next;
        newPtr->next = predptr->next;
        predptr->next = newPtr;
    }
    mySize++;
}

void List::erase(int index) {
    if(index < 0 || index >= mySize) return;
    NodePointer predptr = first, ptr;
    if(index == 0) {
        ptr = first;
        first = ptr->next;
        mySize--;
        delete ptr;
    }
    else {
        for(int i = 1; i < index; i++)
            predptr = predptr->next;
        ptr = predptr->next;
        predptr->next = ptr->next;
        mySize--;
        delete ptr;
    }
}

bool List::compare(const List &rhs) {
    NodePointer lptr = first, rptr = rhs.first;
    while(lptr != 0) {
        if(lptr->data != rptr->data) return false;
        lptr = lptr->next;
        rptr = rptr->next;
    }
    return rptr == 0;
}

void List::insertBeforeLast(ElementType dataVal) {
    NodePointer predptr = first, next = first->next, newPtr;
    newPtr = new Node(dataVal);
    while(next->next != 0) {
        predptr = predptr->next;
        next = next->next;
    }
    predptr->next = newPtr;
    newPtr->next = next;
}

void List::insertLast(ElementType dataVal) {
    NodePointer predptr = first, newPtr;
    newPtr = new Node(dataVal);
    if(predptr == 0) {
        first = newPtr;
        newPtr->next = 0;
    }
    else {
        while(predptr->next != 0)
            predptr = predptr->next;
        predptr->next = newPtr;
        newPtr->next = 0;
    }
    mySize++;
}

void List::printAllIndices(ElementType key) {
    NodePointer predptr = first;
    int index = 0;
    while(predptr != 0) {
        if(predptr->data == key) cout << index << endl;
        index++;
        predptr = predptr->next;
    }
}

void List::insertAfter(ElementType predVal, ElementType dataVal) {
    NodePointer predptr = first, newPtr;
    newPtr = new Node(dataVal);
    while(predptr != 0 && predptr->data != predVal)
        predptr = predptr->next;
    if(predptr != 0) {
        newPtr->next = predptr->next;
        predptr->next = newPtr;
    }
    else cout << "Not Exist" << endl;
}

void List::traverse(void (Enemy::*func)()) {
    NodePointer predptr = first;
    while(predptr != 0) {
        (predptr->data->*func)();
        predptr = predptr->next;
    }
}

int List::nodeCount() {
    return mySize;
}


void List::eraseEnemy() {
    NodePointer predptr = first;
    int index = 0;
    while (predptr != 0) {
//        if(predptr->data->getHealth() == 0) {
        if(Castle::castles[predptr->data->getRegion()].isKilled() || predptr->data->getHealth() == 0) {
            predptr = predptr->next;
            erase(index);
        }
        else {
            predptr = predptr->next;
            index++;
        }
    }
}


ElementType List::get(int index) {
    NodePointer ptr = first;
    for(int i = 1; i <= index; i++) {
        ptr = ptr->next;
    }
    return ptr->data;
}
