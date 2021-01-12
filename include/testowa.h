#pragma once
#include "NodeVar.h"
#include "Node.h"


template<typename T>
class testowa
{
public:

bool test_push_beginning()
{
    List<T> obiekttestowy;

    obiekttestowy.push_beginning(41);
    obiekttestowy.push_beginning(42);
    obiekttestowy.push_beginning(35);
    obiekttestowy.push_beginning(9);
    obiekttestowy.push_beginning(4);
    obiekttestowy.push_beginning(3);

    if (obiekttestowy[0]==3)
       return true;

    return false;

}

bool test_push_end()
{
    List<T> obiekttestowy;

    obiekttestowy.push_end(4);
    obiekttestowy.push_end(5);

    if(obiekttestowy[1]==5)
        return true;

    return false;
}

bool test_n_pop_front()
{
    List<T> obiekttestowy;

    obiekttestowy.push_beginning(4);
    obiekttestowy.push_beginning(3);
    obiekttestowy.push_beginning(2);

    obiekttestowy.n_pop_front();

    if (obiekttestowy[0]==3)
        return true;

    return false;

}

bool test_n_pop_back()
{
    List<T> obiekttestowy;

    obiekttestowy.push_beginning(4);
    obiekttestowy.push_beginning(3);
    obiekttestowy.push_beginning(2);

    obiekttestowy.n_pop_back();

    if (obiekttestowy[1]==3)
        return true;

    return false;

}

bool test_reverseList()
{
     List<T> obiekttestowy;

    obiekttestowy.push_beginning(1);
    obiekttestowy.push_beginning(2);
    obiekttestowy.push_beginning(3);

    obiekttestowy.reverseList();

    if (obiekttestowy[0] == 1 && obiekttestowy[1] == 2 && obiekttestowy[2] == 3)
        return true;

    return false;

}

bool test_linear_search()
{
     List<T> obiekttestowy;

    obiekttestowy.push_beginning(1);
    obiekttestowy.push_beginning(2);
    obiekttestowy.push_beginning(3);

   T solution = obiekttestowy.linear_search(2)->data;

    if(solution == 2)
        return true;

    return false;

}

bool test_bubble_sort()
{
     List<T> obiekttestowy;

    obiekttestowy.push_beginning(4);
    obiekttestowy.push_beginning(1);
    obiekttestowy.push_beginning(5);

    obiekttestowy.bubble_sort();

    if(obiekttestowy[0] == 1 && obiekttestowy[1] == 4 && obiekttestowy[2] == 5)
        return true;

    return false;

}

bool test_find_min()
{
    List<T> obiekttestowy;

    obiekttestowy.push_beginning(4);
    obiekttestowy.push_beginning(1);
    obiekttestowy.push_beginning(5);

    T min = obiekttestowy.find_min();

    if((min == 1))
        return true;

    return false;

}


bool test_insert_at()
{
    List<T> obiekttestowy;

    obiekttestowy.push_beginning(4);
    obiekttestowy.push_beginning(1);
    obiekttestowy.push_beginning(5);

    obiekttestowy.insert_at(2, 3);

    if((obiekttestowy[2]==3))
        return true;

    return false;

}


bool test_swap_value()
{
    List<T> obiekttestowy;
    obiekttestowy.push_beginning(4);
    obiekttestowy.push_beginning(1);
    obiekttestowy.push_beginning(4); // 4 1 4

   obiekttestowy.swap_value(1, 0);

    if(obiekttestowy[0] ==1 && obiekttestowy[1] == 4)
        return true;

    return false;
}


bool test_swap_()
{
    List<T> obiekttestowy;

    obiekttestowy.push_beginning(4);
    obiekttestowy.push_beginning(1);
    obiekttestowy.push_beginning(4);

   obiekttestowy.swap_value(1, 0);

    if(obiekttestowy[0] ==1 && obiekttestowy[1] == 4)
        return true;

    return false;
}


bool test_size_()
{
    List<T> obiekttestowy;

    obiekttestowy.push_beginning(4);
    obiekttestowy.push_beginning(1);
    obiekttestowy.push_beginning(4);

    int size = obiekttestowy.size_();

    if(size ==3)
        return true;

    return false;
}

bool test_remove_from_position()
{
    List<T> obiekttestowy;

    obiekttestowy.push_beginning(4);
    obiekttestowy.push_beginning(1);
    obiekttestowy.push_beginning(3); // 3 1 4

    obiekttestowy.remove_from_position(0);

    obiekttestowy.display();

    if(obiekttestowy[0] == 1) // 3 1 4 - nic nie zostalo usuniete
        return true;

    return false;
}
};
