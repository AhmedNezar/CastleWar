#ifndef List_hpp
#define List_hpp

#include <stdio.h>
#include <iostream>
#include "Enemy.hpp"
#include "Castle.hpp"

using namespace std;
typedef Enemy * ElementType;

class List
{
private:
    
    class Node {
    public:
        ElementType data;
        Node *  next;
        Node(): next(0) {}
        Node(ElementType dataValue): data(dataValue), next(0) {}
    };
    typedef Node * NodePointer;

public:
    List();
    List(const List & origList);
    ~List();
    const List & operator=(const List & rightSide);
    bool empty();
    void insert(ElementType dataVal, int index);
    void erase(int index);
    int search(ElementType dataVal);
    void display(ostream & out) const;
    int nodeCount();
    void reverse();
    bool ascendingOrder();
    bool compare(const List & rhs);
    void insertBeforeLast(ElementType dataVal);
    void printAllIndices(ElementType key);
    void insertAfter(ElementType predVal, ElementType dataVal);
    void insertLast(ElementType dataVal);
    void traverse(void (Enemy::*func)());
    void eraseEnemy();
    ElementType get(int);

private:
    NodePointer first;
    int mySize;
};

ostream & operator<<(ostream & out, const List & aList);
istream & operator>>(istream & in, List & aList);

#endif
