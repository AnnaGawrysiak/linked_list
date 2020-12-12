#include "NodeVar.h"
#include "Node.h"

List::List()
{
    head = nullptr;
    tail = nullptr;
    count = 0;
}

List::~List()
{

}

Node* List::give_me_node(int index)
{
    if (index == 0)
        return head;

    Node* temp = head;

    for (int i = 0; i < index; i++)
    {
        temp = temp->next;
    }

    return temp;
}

void List::insert_after(Node* prev_node, int new_data)
{
   Node* newNode = new Node;

   newNode->data = new_data;

   newNode->next = prev_node->next;

   prev_node->next = newNode;

   newNode->prev = prev_node;

   if (newNode->next != NULL)
   newNode->next->prev = newNode;
   else tail = newNode;

    count++;
}

void List::insert_before(Node* next_node, int new_data)
{
   Node* newNode = new Node;

   newNode->data = new_data;

   next_node->prev = newNode;

   newNode->next = next_node;

   if (newNode->prev != nullptr)
   {
       newNode->prev = next_node->prev->prev;
       newNode->prev->next = newNode;
   }
   else head = newNode;

   count++;
}

void List::n_remove (Node* Node_to_remove)
{
    count--;

    if (Node_to_remove->prev != nullptr)
        Node_to_remove->prev->next = Node_to_remove->next;
    else
        {
        head = Node_to_remove->next;
        delete Node_to_remove;
        return;
        }


    if (Node_to_remove->next != nullptr)
        Node_to_remove->next->prev = Node_to_remove->prev;
    else
        tail = Node_to_remove->prev;

        cout << "Node to remove: " << Node_to_remove->data << endl;

         delete Node_to_remove;

}


int List::operator [](int index)
{
    Node* temp = head;

    for (int i = 0; i < index; i++)
    {
        temp = temp->next;
    }

    return temp->data;
}

void List::push_beginning(int new_data)
{
   Node* newNode = new Node;

   newNode->data = new_data;
   newNode->prev = nullptr;
   newNode->next = head;

   if(head != nullptr) //
   head->prev = newNode;

   else tail = newNode;

   head = newNode;

   count++;

}

void List::push_end(int new_data)
{
   Node* newNode = new Node;

   newNode->data = new_data;
   newNode->prev = tail;
   newNode->next = nullptr;

   if(tail != nullptr)
   tail->next = newNode;
   else
   head = newNode;

   tail = newNode;

   count++;

}

void List::remove_from_position (List myNodeVar_, int position)
{
    myNodeVar_.n_remove(myNodeVar_.give_me_node(position));
}

void List::n_pop_front()
{
    if (count != 0)
    {
        head->next->prev = nullptr;
        head = head -> next;
        head -> prev = nullptr;
    }
}

void List::n_pop_back()
{
    if (head == nullptr)
        return;

    else if (head->next == nullptr)
    {
        head = nullptr;
        count--;

        return;
    }

    else
    {
        tail = tail->prev;
        tail->next = nullptr;

        tail->next = nullptr;
        count--;
        return;
    }
}

void List::reverseList()
{
       Node *current = head;
       Node *prev = nullptr;

       tail = head;

        while (current != nullptr)
        {
            current->prev = current->next;
            current->next = prev;
            prev = current;
            current = current->prev;

        }

        head = prev;
    }

Node* List::linear_search(int value)
{
    if (head == nullptr)
        return nullptr;

    Node *temp = head;

    while(temp != tail && temp->data != value )
        {
            temp = temp->next;
        }

  if (temp->data == value)
    return temp;
  else
    return nullptr;

}


void List::bubble_sort()
{
    if (head == nullptr)
        return;

    Node *temp = head;

    do
    {
           if (temp->data > temp->next->data)
            {
                int tempNum = temp->data;
                temp->data = temp->next->data;
                temp->next->data = tempNum;
            }

        temp = temp->next;

    } while (temp->next!=nullptr);
}


int List::find_min()
{
    Node* ptr = head;

    int found_min = ptr->data;

    do
    {
      if (ptr->data > ptr->next->data)
      {
          found_min = ptr->next->data;
      }

       ptr = ptr->next;

       if(ptr->next == tail)
           return found_min;

    } while (ptr!=tail);

    return found_min;

}

void List::insert_at(int position, int value)
{
    if (count == 0)
        return;

    Node* newNode = new Node;

    newNode->data = value;

    Node* temp = head;

    for (int i = 0; i < position; i++)
    {
        temp = temp->next;
    }

    if (temp->prev != nullptr)
    {
       newNode->prev = temp->prev;
       newNode->prev->next = newNode;
    }
    else head = newNode;

   temp->prev = newNode;

   newNode->next = temp;

   count++;

}

void List::swap_value(List myNodeVar, int index1, int index2)
{
    int temp = 0;

    temp = myNodeVar.give_me_node(index1)->data;
    myNodeVar.give_me_node(index1)->data = myNodeVar.give_me_node(index2)->data;
    myNodeVar.give_me_node(index2)->data = temp;
}


void List::swap_(List myNodeVar, int index1, int index2)
{
    if (count == 0 || count ==1)
        return;

    if (index1 == index2)
        return;


    Node* A = myNodeVar.give_me_node(index1);
    Node* B = myNodeVar.give_me_node(index2);

    Node* temp1_prev = A->prev;
    Node* temp1_next = A->next;
    Node* temp2_prev = B->prev;
    Node* temp2_next = B->next;

    if (A->next == B)
    {
        A->next = temp1_next;
        B->prev = temp2_prev;
        A->prev = B;
        B->next = A;
        A->next->prev = B;
        B->prev->next = A;
    }

    else if (B->next == A)
    {
        B->next = temp2_next;
        A->prev = temp1_prev;
        B->prev = A;
        A->next = B;
        B->next->prev = A;
        A->prev->next = B;
    }
    else
    {
    A->prev = temp2_prev;
    A->next = temp2_next;

    B->prev = temp1_prev;
    B->next = temp1_next;

    if (A->prev != nullptr)
        A->prev->next = A;

    if (A->next != nullptr)
        A->next->prev = A;

    if (B->prev != nullptr)
        B->prev->next = B;

    if (B->next != nullptr)
        B->next->prev = B;

    }

     if(index1 == 0)
        head = B;

    if(index2 == 0)
        head = A;

    if(index1==myNodeVar.size_())
    {
        tail = A;
    }

    if(index2==myNodeVar.size_())
    {
        tail = B;
    }
}

int List::size_()
{
    Node* temp = head;
    int size_ = 1;

    while (temp->next != nullptr)
    {
        temp = temp ->next;
        size_++;
    }

return size_;
}


void List::display()
{
    if (head == nullptr)
    {
        cout << "List empty, nothing to display" << endl;
        return;
    }

   Node* ptr = head;

   cout << "Elements of the list: ";

   while (ptr != nullptr)
    {
      cout<< ptr->data <<" ";
      if (ptr->next != nullptr)
      {
          ptr = ptr->next;
      }
      else
          return;
    };
}
