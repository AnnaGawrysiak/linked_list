#include "NodeVar.h"
#include "Node.h"

template <typename T>
Node<T>::Node()
{
    //ctor
}

template <typename T>
Node<T>::Node(const Node& a)
{
    data= a.data;
    next = a.next;
    prev = a.prev;
}

template <typename T>
Node<T>::~Node()
{
    //dtor
}

template <typename T>
Node<T>& Node<T>::operator=(const Node &rhs)
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
   //this->other_data = n.other_data;
}

template class Node<int>;

