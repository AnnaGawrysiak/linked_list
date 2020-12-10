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

Node* List::give_me_node(int index)
{
    Node* temp = head;

    for (int i = 0; i < index; i++)
    {
        temp = temp->next;
    }

    return temp;
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

void List::swap_(List myNodeVar, int index1, int index2)
{
    if (index1 == index2)
        return;

    //Przypisujemy Node do tymczasowych zmiennych, żeby w trakcie przepisywania połaczeń nie korzystać z operatora []
    //Operator [] aby znaleźć kolejny Node sprawdza pole Next - gdy przy połowie przepisywania połaczeń wywołamy gdzieś ten operator, to
    //Next zacznie wskazywać na samych siebie lub nullptr
    Node* A = myNodeVar.give_me_node(index1);
    Node* B = myNodeVar.give_me_node(index2);

    //Przepisujemy poniższe parametry do tymczasowych zmiennych, aby było czytelniej
    Node* temp1_prev = A->prev;
    Node* temp1_next = A->next;
    Node* temp2_prev = B->prev;
    Node* temp2_next = B->next;

    //Zamieniamy pola Node'ów, czyli przepinamy je do nowych miejsc
    A->prev = temp2_prev;
    A->next = temp2_next;

    B->prev = temp1_prev;
    B->next = temp1_next;

    //To, czego nie zrobiłyśmy na spotkaniu - oprócz tego, że przepinamy Node'y, które przychodzą na indeksach 1 oraz 2, to jeszcze musimy
    //zadbać o ich sąsiadów, aby in Next i Prev wskazywały na nowe Nody. Jeżeli tego nie zrobimy, lista zaczyna się kręcić w kółko.
    if (A->prev != nullptr)
        A->prev->next = A;

    if (A->next != nullptr)
        A->next->prev = A;

    if (B->prev != nullptr)
        B->prev->next = B;

    if (B->next != nullptr)
        B->next->prev = B;

    //I na koniec oczywiście zmieniamy Head w List jeżeli jest taka potrzeba
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
    int size_ = 0;

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
