# pragma once
#include <iostream>

using namespace std;

template <class T>
class Node
{
    public:
        T  data;
        Node* next;
        Node* prev;

    Node()
    {

    }


    Node(const Node<T>& a)
    {
        data= a.data;
        next = a.next;
        prev = a.prev;
    }

    ~Node()
    {
        //dtor
    }

    Node<T>& operator=(const Node<T>& rhs)
    {
        if (&rhs!=this)
        {
         if (next)
            delete next;

         if(prev)
         delete prev;

       data = rhs.data;
       next = rhs.next;
       prev = rhs.prev;

        }

   return *this;
    }
};


