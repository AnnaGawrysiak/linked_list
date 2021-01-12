#pragma once
#include "Node.h"

using namespace std;

template<typename T>
class List
{
private:

      Node<T>* head;

      Node<T>* tail;

      unsigned count;

     Node<T>* give_me_node(int index)
     {
        if (index == 0)
            return head;

        Node<T>* temp = head;

        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }

        return temp;
    }

    void insert_after( Node<T>* prev_node, T new_data)
    {
       Node<T>* newNode = new Node<T>;

       newNode->data = new_data;

       newNode->next = prev_node->next;

       prev_node->next = newNode;

       newNode->prev = prev_node;

       if (newNode->next != nullptr)
       newNode->next->prev = newNode;
       else tail = newNode;

        count++;
    }

    void insert_before( Node<T>* next_node, T new_data)
    {
       Node<T>* newNode = new Node<T>;

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

    void n_remove ( Node<T>* Node_to_remove)
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

public:

    List()
    {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }

    ~List()
    {

    }

    int operator [](int index)
    {
        Node<T>* temp = head;

        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }

        return temp->data;
    }

    void push_beginning(T new_data)
    {
       Node<T>* newNode = new Node<T>;

       newNode->data = new_data;
       newNode->prev = nullptr;
       newNode->next = head;

       if(head != nullptr) //
       head->prev = newNode;

       else tail = newNode;

       head = newNode;

       count++;

    }

    void push_end (T new_data)
    {
       Node<T>* newNode = new Node<T>;

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

    void remove_from_position(int position)
    {
        n_remove(give_me_node(position));
    }

    void n_pop_front()
    {
       if (head == nullptr)
            return;

        else if (head->next == nullptr)
            {
                delete head;
                head = nullptr;
                tail = nullptr;

                count--;

                return;
            }

        else
            {
                Node<T>* temp = head->next;
                temp->prev = nullptr;
                delete head;
                head = temp;

                count--;

                return;
            }
    }

    void n_pop_back()
    {
        if (head == nullptr)
            return;

        else if (head->next == nullptr)
        {
            Node<T>* delNode = tail; // Save address of node to delete in a pointer
            tail = tail->prev;
            head = nullptr;
            delete delNode;
            count--;

            return;
        }

        else
        {
            Node<T>* delNode = tail; // Save address of node to delete in a pointer
            tail = tail->prev;
            tail->next = nullptr;
            delete delNode;

            count--;

            return;
        }
    }

    void reverseList()
    {
       Node<T> *current = head;
       Node<T> *prev = nullptr;

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


    Node<T>* linear_search(T value)
    {
    if (head == nullptr)
        return nullptr;

    Node<T> *temp = head;

    while(temp != tail && temp->data != value )
        {
            temp = temp->next;
        }

  if (temp->data == value)
    return temp;
  else
    return nullptr;

    }

    void bubble_sort()
    {
        if (head == nullptr)
            return;

        Node<T> *temp = head;

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


    int find_min()
    {
        Node<T>* ptr = head;

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

    void insert_at(int position, T value)
    {
        if (position > size_())
        {
           cout << "Warning: position exceeds size of the list" << endl;

           return;
        }

        Node<T>* newNode = new Node<T>;

        newNode->data = value;

        Node<T>* temp = head;

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

    void swap_value(int index1, int index2)
    {
        int temp = 0;

        temp = give_me_node(index1)->data;
       give_me_node(index1)->data = give_me_node(index2)->data;
       give_me_node(index2)->data = temp;
    }

    void swap_(int index1, int index2)
    {
        if (count == 0 || count ==1)
            return;

        if (index1 == index2)
            return;


        Node<T>* A = give_me_node(index1);
        Node<T>* B = give_me_node(index2);

        Node<T>* temp1_prev = A->prev;
        Node<T>* temp1_next = A->next;
        Node<T>* temp2_prev = B->prev;
        Node<T>* temp2_next = B->next;

        if (A->next == B)
        {
            A->next = temp2_next;
            A->prev = B;
            A->next->prev = A;

            B->prev = temp1_prev;
            B->next = A;
            B->prev->next = B;
        }

        else if (B->next == A)
        {
            B->next = temp1_next;
            B->prev = A;
            B->next->prev = B;

            A->prev = temp2_prev;
            A->next = B;
            A->prev->next = A;
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

        if(A->prev == nullptr)
        {
            head = A;
        }

        if(B->prev == nullptr)
        {
            head = B;
        }

        if(A->next == nullptr)
        {
            tail = A;
        }

        if(B->next == nullptr)
        {
            tail = B;
        }

    }

    int size_()
    {
        int size_ = 0;

        if(head==nullptr)
        {
            return size_;
        }

        Node<T>* temp = head;

        while (temp->next != nullptr)
        {
            temp = temp ->next;
            size_++;
        }

        return (size_+1);
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "List empty, nothing to display" << endl;
            return;
        }

       Node<T>* ptr = head;

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
};
