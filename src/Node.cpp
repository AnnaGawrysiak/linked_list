#include "NodeVar.h"
#include "Node.h"


Node::Node()
{
    //ctor
}

Node::Node(const Node& a)
{
    data= a.data;
    next = a.next;
    prev = a.prev;
}

Node::~Node()
{
    //dtor
}

Node* Node::operator=(const Node& rhs)
{
    if (&rhs==this)
		return this;

   data = rhs.data;
   next = rhs.next;
   prev = rhs.prev;
   //this->other_data = n.other_data;

    return this;
}
