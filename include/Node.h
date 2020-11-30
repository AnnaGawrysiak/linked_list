#include <iostream>
# pragma once

using namespace std;

// A doubly linked list node
class Node // element listy dwukierunkowej
{
    public:
        int data;
        struct Node* next;
        struct Node* prev;
        Node();
        virtual ~Node();

    //private:
};


