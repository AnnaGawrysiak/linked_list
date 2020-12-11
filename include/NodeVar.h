#pragma once
#include "Node.h"

using namespace std;

class List
{
private:

    Node* give_me_node(int index);

    void insert_after(Node* prev_node, int new_data);

    void insert_before(Node* next_node, int new_data);

    void n_remove (Node* Node_to_remove);

public:
       Node* head;
       Node* tail;
       unsigned count;

    List();

    ~List();

    int operator [](int index);

    void push_beginning(int new_data);

    void push_end (int new_data);

    void remove_from_position(List myNodeVar_, int position);

    void n_pop_front();

    void n_pop_back();

    void reverseList();

    Node* linear_search(int value);

    void bubble_sort();

    int find_min();

    void insert_at(int position, int value);

    void swap_value(List myNodeVar, int index1, int index2);

    void swap_(List myNodeVar, int index1, int index2);

    int size_();

    void display();
};
