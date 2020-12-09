# pragma once
#include <iostream>

using namespace std;

// A doubly linked list node
class Node // element listy dwukierunkowej
{
    public:
        int data;
        Node* next;
        Node* prev;
        Node();
        Node (const Node& a);
        virtual ~Node();
        Node& operator=(const Node& r);

    //private:
};


