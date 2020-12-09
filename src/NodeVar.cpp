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
    //dtor
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

//insert a new node at the beginning of the list
void List::push_beginning(int new_data)
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

void List::push_end(int new_data)
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

void List::insert_before(Node* next_node, int new_data)
{
    //allocate memory for new node
   Node* newNode = new Node;

   //assign data to new node
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

void List::insert_after(Node* prev_node, int new_data)
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

void List::n_remove (Node* Node_to_remove)
{
    count--;

    //Jeœli istnieje poprzednik usuwanego elementu, to w jego polu next
    //umieszczamy zawartoœæ pola next usuwanego elementu, czyli adres nastêpnika.
    //W przeciwnym razie wybrany element jest pierwszym elementem listy. W takim przypadku w head  umieszczamy zawartoœæ pola next
    //usuwanego elementu, czyli adres nastêpnika. W przypadku listy jednoelementowej do pola head  trafi adres zerowy.

    if (Node_to_remove->prev != nullptr)
        Node_to_remove->prev->next = Node_to_remove->next;
    else
    {
        head = Node_to_remove->next;
    }

    if (Node_to_remove->next != nullptr)
        Node_to_remove->next->prev = Node_to_remove->prev;
    else
        tail = Node_to_remove->prev;

         delete Node_to_remove;

}

//void List::remove_from_position (List myNodeVar_, int position)
//{
 //    myNodeVar_.n_remove(myNodeVar_[position]); // otrzebna jest metoda do pozyskiwania position
//}

void List::n_pop_front()
{
    if (count != 0)
    {
        head->next->prev = nullptr;
        head = head -> next;
        delete head -> prev;
    }
}

void List::n_pop_back()
{
    if (head == nullptr)
        return;

    else if (head->next == nullptr)
    {
        delete head;
        count--;

        return;
    }

    else
    {
        tail = tail->prev;
        tail->next = nullptr;

        delete tail->next;
        count--;
        return;
    }
}

void List::reverseList()
{
        // Initialize current, previous and
        // next pointers
        Node *current = head;
        Node *prev = nullptr;
        Node *next = nullptr;

        while (current != nullptr)
        {
            // Store next
            next = current->next;

            // Reverse current node's pointer
            current->next = prev;

            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        head = prev;
    }

Node* List::linear_search(int value)
{
    if (head == nullptr)
        return nullptr;

    Node *temp = head;// ustaw wskaznik na pierwszy element listy

    while(temp != tail && temp->data != value )
        {
            temp = temp->next;
        }

  if (temp->data == value)
    return temp;
  else
    return nullptr;
   //zwracana wartosc: adres elementu listy, który zawiera v  lub adres zerowy, jeśli lista takiego elementu nie posiada
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
                //swap(temp->data, temp->next->data);
                int tempNum = temp->data;
                temp->data = temp->next->data;
                temp->next->data = tempNum;
            }

        temp = temp->next;

    } while (temp->next!=tail);
}


int List::find_min()
{
    Node* ptr = head;

    int found_min = ptr->data;

    cout << "head" << ptr->data << endl;

    do
    {
      if (ptr->data > ptr->next->data)
      {
          found_min = ptr->next->data;
      }

       ptr = ptr->next;

       if(ptr->next == tail)
           return found_min;

           cout << "found_min" << found_min << endl;

    } while (ptr!=tail);

    return found_min;

}

void List::insert_at(int position, int value)
{
    if (count == 0)
        return;

    //allocate memory for new node
    Node* newNode = new Node;

    //assign data to new node
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

    //newNode->next = temp;
    //temp->prev = newNode;

    //if (newNode->prev != nullptr)
    //{
      //  newNode->prev = temp->prev;
       // newNode->prev->next = newNode;
    //}

    //else
      //  head = newNode;

}

void List::swap_values(int val1, int val2)
{
     if (val1== val2) return;

    //Node* node1     = myNodeVar_.linear_search(val1);
    //Node* node2     = myNodeVar_.linear_search(val2);

    Node* temp = head;

    do
    {
        if (temp->data == val1)
            temp->data = val2;

        else if (temp->data == val2)
            temp->data = val1;

         temp = temp->next;
    } while(temp->next!=nullptr);

}

//dopisanie do tej listy metody swap(), która zamieni miejscami dwa nody o danych indeksach.

/*void List::swap_value(List myNodeVar, int index1, int index2)
{
    int temp = 0;

    temp = myNodeVar[index1]->data;
    myNodeVar[index1]->data = myNodeVar[index2]->data;
    myNodeVar[index2]->data = temp;
}
*/
/*void List::swap_(List myNodeVar, int index1, int index2)
{
    if (index1 == index2)
        return;

    Node* temp1 = myNodeVar[index1]; //0
    Node* temp2 = myNodeVar[index2];//1

    myNodeVar[index1]->prev = temp2->prev;
    cout << myNodeVar[index1]->prev -> data << endl;
    myNodeVar[index1]->next = temp2->next;
    cout << myNodeVar[index1]->next -> data << endl;
    myNodeVar[index1]->data = temp2->data;
    cout << myNodeVar[index1]-> data << endl;

    myNodeVar[index2]->prev = temp1->prev;
    myNodeVar[index2]->next = temp1->next;
    myNodeVar[index2]->data = temp1->data;

    if(index1==0)
    {
        head = myNodeVar[index1];
    }

    if(index2==0)
    {
        head = myNodeVar[index2];
    }

    if(myNodeVar[index2]->next == nullptr)
    {
        tail = myNodeVar[index2];
    }

     if(myNodeVar[index1]->next == nullptr)
    {
        tail = myNodeVar[index1];

        delete temp1;
        delete temp2;
    }
}
*/

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
