#include "NodeVar.h"
#include "Node.h"

NodeVar::NodeVar()
{
    head = NULL;
    tail = NULL;
    count = 0;
}

NodeVar::NodeVar(Node* head_, Node* tail_)
{
    head = head_;
    tail = tail_;
    count = 0;
}

NodeVar::~NodeVar()
{
    //dtor
}

//insert a new node at the beginning of the list
void NodeVar::push_front(int new_data)
{
   //allocate memory for node
   Node* newNode = new Node;

   newNode->data = new_data;
   newNode->prev = NULL;
   newNode->next = head;

   head->prev = newNode ;

   head = newNode;

   count++;
} // co powinna zwracac taka funkcja? iterator wskazujacy na

void NodeVar::display()
{
   Node* ptr = head;
   while(ptr != NULL)
    {
      cout<< ptr->data <<" ";
      ptr = ptr->next;
    }
}
