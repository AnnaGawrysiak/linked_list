#pragma once
#include "Node.h"

using namespace std;

class NodeVar // zmienna obslugujaca liste dwukierunkowa
{
    public:
       Node* head; // wskazuje na 1. element listy
       Node* tail; // wskazuje na ostatnie element listy
       unsigned count; // zawiera liczbe elementow przechowywanych na liscie

// Unless a value is assigned, a pointer will point to some garbage address by default.
// Besides memory addresses, there is one additional value that a pointer can hold: a null value.
//  A null value is a special value that means the pointer is not pointing at anything. A pointer holding a null value is called a null pointer.

    NodeVar();

    ~NodeVar();

    void push_beginning(int new_data);

    void push_end (int new_data);

    /* Given a node as prev_node, insert a new node after the given node */
    void insert_after(Node* prev_node, int new_data);

    void insert_before(Node* next_node, int new_data);

    // usuwanie wybranego elementu listy

    void n_remove (Node* Node_to_remove);

    //Usuwanie elementu z pocz¹tku listy

    void n_pop_front();

    void n_pop_back();

    void reverseList();

    int linear_search(int value);

    void display();
    //private:
};
