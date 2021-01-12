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

     Node<T>* give_me_node(int index);

    void insert_after( Node<T>* prev_node, T new_data);

    void insert_before( Node<T>* next_node, T new_data);

    void n_remove ( Node<T>* Node_to_remove);

public:

    List();

    ~List();

    int operator [](int index);

    void push_beginning(T new_data);

    void push_end (T new_data);

    void remove_from_position(int position);

    void n_pop_front();

    void n_pop_back();

    void reverseList();

    Node<T>* linear_search(T value);

    void bubble_sort();

    int find_min();

    void insert_at(int position, T value);

    void swap_value(int index1, int index2);

    void swap_(int index1, int index2);

    int size_();

    void display();
};
