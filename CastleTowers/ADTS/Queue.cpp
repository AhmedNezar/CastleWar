//
//  Queue.cpp
//  CastleTowers
//
//  Created by Ahmed Nezar on 23/12/2022.
//

#include "Queue.hpp"


Queue::Queue(): MyFront(0), MyBack(0){}

Queue ::Queue(const Queue & original){
   MyFront = MyBack = 0;
   if (!original.empty()){
       MyFront = MyBack = new Node(original.front());
       Queue::NodePointer origPtr = original.MyFront->next;
       while (origPtr != 0){
           MyBack->next = new Node(origPtr->data);
           MyBack->next->previous=MyBack;
           MyBack = MyBack->next;
           origPtr = origPtr->next;
       }
   }
}

Queue::~Queue(){
   Queue::NodePointer prev = MyFront, ptr;
   while (prev != 0){
       ptr = prev->next;
       delete prev;
       prev = ptr;
   }
}


bool Queue ::empty() const
{
   return (MyFront == 0);
}

void Queue::enqueue(const ElementType & value, int key){
   Queue::NodePointer newptr = new Node(value, key), loc=MyBack;
   if (empty()){
       MyFront = MyBack = newptr;
       return;
   }
   if(key<=MyBack->key){
       MyBack->next = newptr;
       newptr->previous=MyBack;
       MyBack = newptr;
       return;
   }
   while(((key==2)&&(loc->key<2))||
     ((key==1)&&(loc->key<1))){
       loc=loc->previous;
       if(loc==0)  break;
   }
   if(loc==0){
       newptr->next=MyFront;
       newptr->previous=0;
       MyFront=newptr;
       newptr->next->previous=newptr;
   }
   else{
       newptr->next=loc->next;
       newptr->previous=loc;
       loc->next=newptr;
       newptr->next->previous=newptr;
   }
}

ElementType Queue::front() const
{
   if (!empty())
       return (MyFront->data);
   else
   {
       cerr << "*** Queue is empty "
       " -- returning garbage ***\n";
       ElementType* temp = new(ElementType);
       ElementType garbage = *temp;
       delete temp;
       return garbage;
   }
}

ElementType Queue::back() const
{
   if (!empty())
       return (MyBack->data);
   else
   {
       cerr << "*** Queue is empty "
       " -- returning garbage ***\n";
       ElementType* temp = new(ElementType);
       ElementType garbage = *temp;
       delete temp;
       return garbage;
   }
}
void Queue::dequeue()
{
    if (!empty())
    {
        Queue::NodePointer ptr = MyFront;
        MyFront = MyFront->next;
        delete ptr;
        if (MyFront == 0)
            MyBack = 0;
    }
    else
        cerr << "*** Queue is empty -- can't remove a value ***\n";
}
