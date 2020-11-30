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

    NodeVar(Node* head_, Node* tail_);

    ~NodeVar();

    void push_front(int new_data);

    void display();
    //private:
};
