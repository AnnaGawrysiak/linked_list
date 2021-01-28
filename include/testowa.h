#pragma once
#include "NodeVar.h"
#include "Node.h"

class testowa
{
private:
    testowa();
    static testowa* wsk;

public:
void operator = (const testowa&) = delete;
testowa (const testowa&) = delete;

static testowa* get_instance();

bool test_push_beginning();

bool test_push_end();

bool test_n_pop_front();

bool test_n_pop_back();

bool test_reverseList();

bool test_linear_search();

bool test_bubble_sort();

bool test_find_min();

bool test_insert_at();

bool test_swap_value();

bool test_swap_();

bool test_size_();

bool test_remove_from_position();

void run(); // obiekt testowy mamy tylko jeden i mozemy go sobie wywolywac ile chcemy

};

/*
bool test_n_pop_back()
{
    List<int> obiekttestowy;

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
     List<int> obiekttestowy;

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
     List<int> obiekttestowy;

    obiekttestowy.push_beginning(1);
    obiekttestowy.push_beginning(2);
    obiekttestowy.push_beginning(3);

   int solution = obiekttestowy.linear_search(2)->data;

    if(solution == 2)
        return true;

    return false;

}

bool test_bubble_sort()
{
     List<int> obiekttestowy;

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
    List<int> obiekttestowy;

    obiekttestowy.push_beginning(4);
    obiekttestowy.push_beginning(1);
    obiekttestowy.push_beginning(5);

    int min = obiekttestowy.find_min();

    if((min == 1))
        return true;

    return false;

}

bool test_insert_at()
{
    List<int> obiekttestowy;

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
    List<int> obiekttestowy;
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
    List<int> obiekttestowy;

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
    List<int> obiekttestowy;

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
    List<int> obiekttestowy;

    obiekttestowy.push_beginning(4);
    obiekttestowy.push_beginning(1);
    obiekttestowy.push_beginning(3); // 3 1 4

    obiekttestowy.remove_from_position(0);

    obiekttestowy.display();

    if(obiekttestowy[0] == 1) // 3 1 4 - nic nie zostalo usuniete
        return true;

    return false;
}
*/
