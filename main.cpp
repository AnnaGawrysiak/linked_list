#include <iostream>
#include "NodeVar.h"
#include "testowa.h"

using namespace std;
/*
template <typename T>
int operator +(const  Node<T> &lhs, const  Node<T> &rhs);

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
*/
int main()
{
   testowa* test = testowa::get_instance();
   test->run(); // testy maja sie same tworzyc, sprawdzac i wyczyscic. jest enkapsulacja.
/*
    cout << "test_push_end: " << (test->test_push_end() ? " Success! " : " Failure") << endl;

    myNodeVar.n_pop_front();

    cout << "test_n_pop_front: " << (test->test_n_pop_front() ? " Success! " : " Failure") << endl;

     myNodeVar.n_pop_back();

    cout << "test_n_pop_back: " << (test->test_n_pop_back() ? " Success! " : " Failure") << endl;

    myNodeVar.reverseList();

     cout << "test_reverse_list: " << (test->test_reverseList() ? " Success! " : " Failure") << endl;

     int searched_value = 25;

    if (myNodeVar.linear_search(searched_value) != nullptr)

        cout << "Value " << searched_value << " has been found at position: " << myNodeVar.linear_search(searched_value) << endl;
    else
        cout << "Searched value has not been found. " << endl;

     cout << "test_linear_search: " << (test->test_linear_search() ? " Success! " : " Failure") << endl;

      myNodeVar.bubble_sort();

    cout << "test_bubble_sort: " << (test->test_bubble_sort() ? " Success! " : " Failure") << endl;

    myNodeVar.bubble_sort();

    cout << "Minimum value is: " << myNodeVar.find_min() << endl;

    cout << "test_find_min: " << (test->test_find_min() ? " Success! " : " Failure") << endl;

     myNodeVar.insert_at(3, 12);

     cout << "test_insert_at: " << (test->test_insert_at() ? " Success! " : " Failure") << endl;

    cout << "test_swap_value: " << (test->test_swap_value() ? " Success! " : " Failure") << endl;

     cout << "test_swap_: " << (test->test_swap_() ? " Success! " : " Failure") << endl;

     myNodeVar.swap_(1, 2);

    cout << "test_size_: " << (test->test_size_() ? " Success! " : " Failure") << endl;

    cout << "test_remove_from_position: " << (test->test_remove_from_position() ? " Success! " : " Failure") << endl;

    myNodeVar.display();
*/
    return 0;
}
/*
template<typename T>
int operator +(const Node<T> &lhs, const Node<T> &rhs)
{
    return (lhs.data + rhs.data);
}

template<typename T>
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

template<typename T>
bool test_push_end()
{
    List<T> obiekttestowy;

    obiekttestowy.push_end(4);
    obiekttestowy.push_end(5);

    if(obiekttestowy[1]==5)
        return true;

    return false;
}

template<typename T>
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

template<typename T>
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

template<typename T>
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

template<typename T>
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

template<typename T>
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

template<typename T>
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

template<typename T>
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

template<typename T>
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

template<typename T>
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

template<typename T>
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

template<typename T>
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
*/
