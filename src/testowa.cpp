#include "testowa.h"

testowa::testowa()
{
}

testowa* testowa::wsk = nullptr;

testowa* testowa::get_instance()
{
    if(!wsk)
    wsk = new testowa(); // przez new nalezy explicite konstruktor wywolac

    return wsk;

}

bool testowa::test_push_beginning()
{
    List<int> obiekttestowy;

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

bool testowa::test_push_end()
{
    List<int > obiekttestowy;

    obiekttestowy.push_end(4);
    obiekttestowy.push_end(5);

    if(obiekttestowy[1]==5)
        return true;

    return false;
}

bool testowa::test_n_pop_front()
{
    List<int> obiekttestowy;

    obiekttestowy.push_beginning(4);
    obiekttestowy.push_beginning(3);
    obiekttestowy.push_beginning(2);

    obiekttestowy.n_pop_front();

    if (obiekttestowy[0]==3)
        return true;

    return false;

}

bool testowa::test_n_pop_back()
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

bool testowa::test_reverseList()
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

bool testowa::test_linear_search()
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

bool testowa::test_bubble_sort()
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

bool testowa::test_find_min()
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


bool testowa::test_insert_at()
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


bool testowa::test_swap_value()
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


bool testowa::test_swap_()
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


bool testowa::test_size_()
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

bool testowa::test_remove_from_position()
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

void testowa::testowa::run()
{
    cout << "test_push_beginning: " << (test_push_beginning() ? " Success! " : " Failure") << endl;

    cout << "test_push_end: " << (test_push_end() ? " Success! " : " Failure") << endl;

    cout << "test_n_pop_front: " << (test_n_pop_front() ? " Success! " : " Failure") << endl;

    cout << "test_n_pop_back: " << (test_n_pop_back() ? " Success! " : " Failure") << endl;

    cout << "test_reverse_list: " << (test_reverseList() ? " Success! " : " Failure") << endl;

    cout << "test_linear_search: " << (test_linear_search() ? " Success! " : " Failure") << endl;

    cout << "test_bubble_sort: " << (test_bubble_sort() ? " Success! " : " Failure") << endl;

    cout << "test_find_min: " << (test_find_min() ? " Success! " : " Failure") << endl;

    cout << "test_insert_at: " << (test_insert_at() ? " Success! " : " Failure") << endl;

    cout << "test_swap_value: " << (test_swap_value() ? " Success! " : " Failure") << endl;

    cout << "test_swap_: " << (test_swap_() ? " Success! " : " Failure") << endl;

    cout << "test_size_: " << (test_size_() ? " Success! " : " Failure") << endl;

    cout << "test_remove_from_position: " << (test_remove_from_position() ? " Success! " : " Failure") << endl;

}

