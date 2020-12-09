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

Node& Node::operator=(const Node &rhs)
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
