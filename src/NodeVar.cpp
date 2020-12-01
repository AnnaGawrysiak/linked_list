#include "NodeVar.h"
#include "Node.h"

NodeVar::NodeVar()
{
    head = nullptr;
    tail = nullptr;
    count = 0;
}

NodeVar::~NodeVar()
{
    //dtor
}

//insert a new node at the beginning of the list
void NodeVar::push_beginning(int new_data)
{
   //allocate memory for node
   Node* newNode = new Node;

   newNode->data = new_data;
   newNode->prev = nullptr;
   newNode->next = head;

   //Jeœli istnieje nastêpnik dodanego elementu, to w polu prev  nastêpnika umieszczamy adres nowego elementu.
   //Pozwoli to przejœæ z nastêpnika do pierwszego elementu. Lista staje siê kompletna.
   if(head != nullptr) //
   head->prev = newNode;
   //Jeœli nastêpnik nie istnieje, to dodawaliœmy element do pustej listy.
   //W takim przypadku w polu tail  nale¿y równie¿ wprowadziæ adres nowego elementu – lista stanie siê list¹ jednoelementow¹.
   else tail = newNode;

   head = newNode;

   count++;
} // co powinna zwracac taka funkcja? iterator wskazujacy na

void NodeVar::push_end(int new_data)
{
   //allocate memory for node
   Node* newNode = new Node;

   newNode->data = new_data;
   newNode->prev = tail;
   newNode->next = nullptr;

   if(tail != nullptr) //
   tail->next = newNode;
   else
   head = newNode;

   tail = newNode;

   count++;

}

void NodeVar::insert_before(Node* next_node, int new_data)
{
    //allocate memory for new node
   Node* newNode = new Node;

   //assign data to new node
   newNode->data = new_data;

   next_node->prev = newNode;

   newNode->next = next_node;

   newNode->prev = next_node->prev;

   if (newNode->prev != NULL)
   newNode->prev->next = newNode;
   else head = newNode;

   count++;
}

void NodeVar::insert_after(Node* prev_node, int new_data)
{
    //allocate memory for new node
   Node* newNode = new Node;

   //assign data to new node
   newNode->data = new_data;

   //set next of newnode to next of prev node
   newNode->next = prev_node->next;

   prev_node->next = newNode;

   newNode->prev = prev_node;

  //set prev of new node's next to newnode
   if (newNode->next != NULL)
   newNode->next->prev = newNode;
   else tail = newNode;

    count++;
}

void NodeVar::n_remove (Node* Node_to_remove)
{
    count--;

    //Jeœli istnieje poprzednik usuwanego elementu, to w jego polu next
    //umieszczamy zawartoœæ pola next usuwanego elementu, czyli adres nastêpnika.
    //W przeciwnym razie wybrany element jest pierwszym elementem listy. W takim przypadku w head  umieszczamy zawartoœæ pola next
    //usuwanego elementu, czyli adres nastêpnika. Zwróæ uwagê, ¿e w przypadku listy jednoelementowej do pola head  trafi adres zerowy.

    if (Node_to_remove->prev != nullptr)
        Node_to_remove->prev->next = Node_to_remove->next;
    else
        head = Node_to_remove->next;

    if (Node_to_remove->next != nullptr)
        Node_to_remove->next->prev = Node_to_remove->prev;
    else
        tail = Node_to_remove->prev;

         delete Node_to_remove;

}

void NodeVar::n_pop_front()
{
    if (count != 0)
    {
        head->next->prev = nullptr;
        head = head -> next;
        delete head -> prev;
    }
}

void NodeVar::n_pop_back()
{
    if (count != 0)
    {
        tail->prev->next = nullptr;
        tail = tail->prev;
        delete tail->next;
    }
}

void NodeVar::reverseList()
{
    if (head != nullptr)
    {
        Node *p = nullptr;

        Node* pc = head;

            while (pc -> next)
            {
                p = pc->next;
                pc->next = p->next;
                p->next = head;
                p->next->prev = pc;
                pc->prev = p;
                head = p;
        }
    }

}

Node* NodeVar::linear_search(int value)
{
    if (head == nullptr)
        return nullptr;

    Node * temp = head;// ustaw wskaznik na pierwszy element listy

    while(temp != tail && (*temp)->data != value )
        {
            temp = temp->next;
        }

  if ((*temp)->data == value)
    return temp;
  else
    return nullptr;
   //zwracana wartosc: adres elementu listy, który zawiera v  lub adres zerowy, jeśli lista takiego elementu nie posiada
}

void NodeVar::display()
{
   Node* ptr = head;
   while(ptr != nullptr)
    {
      cout<< ptr->data <<" ";
      ptr = ptr->next;
    }
}
