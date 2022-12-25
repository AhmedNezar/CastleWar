//
//  Queue.hpp
//  CastleTowers
//
//  Created by Ahmed Nezar on 23/12/2022.
//

#ifndef Queue_hpp
#define Queue_hpp

#include <stdio.h>
#include <iostream>

class Enemy;


using namespace std;
typedef Enemy* ElementType;
 class Queue
{
public:
   
    Queue();
    Queue(const Queue & original);
    ~Queue();
    bool empty() const;
    void enqueue(const ElementType & value, int key);
    ElementType front() const;
    ElementType back() const;
    void dequeue();
private:
   class Node{
    public:
        ElementType data;
        int key;
        Node*  next;
        Node*  previous;
        Node(ElementType value, int k=0, Node * n = 0, Node * p = 0)
        { data = value; key=k; next = n; previous = p;}
    };
    typedef Node* NodePointer;
    NodePointer MyFront, MyBack;
};

 

#endif

