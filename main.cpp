#include <iostream>
#include "NodeVar.h"

using namespace std;

int operator +(const Node &lhs, const Node &rhs);

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

int main()
{

   List myNodeVar;

   myNodeVar.push_beginning(20);
   myNodeVar.push_beginning(22);
   myNodeVar.push_beginning(23);
   myNodeVar.push_beginning(25);
   myNodeVar.push_beginning(26);
   myNodeVar.push_beginning(21);

    cout << "test_push_beginning: " << (test_push_beginning() ? " Success! " : " Failure") << endl;

    myNodeVar.push_end(40);
    myNodeVar.push_end(43);
    myNodeVar.push_end(4);
    myNodeVar.push_end(49);

    cout << "test_push_end: " << (test_push_end() ? " Success! " : " Failure") << endl;

    myNodeVar.n_pop_front();

    cout << "test_n_pop_front: " << (test_n_pop_front() ? " Success! " : " Failure") << endl;

     myNodeVar.n_pop_back();

    cout << "test_n_pop_back: " << (test_n_pop_back() ? " Success! " : " Failure") << endl;

    myNodeVar.reverseList();

     cout << "test_reverse_list: " << (test_reverseList() ? " Success! " : " Failure") << endl;

     int searched_value = 25;

    if (myNodeVar.linear_search(searched_value) != nullptr)

        cout << "Value " << searched_value << " has been found at position: " << myNodeVar.linear_search(searched_value) << endl;
    else
        cout << "Searched value has not been found. " << endl;

     cout << "test_linear_search: " << (test_linear_search() ? " Success! " : " Failure") << endl;

      myNodeVar.bubble_sort();

    cout << "test_bubble_sort: " << (test_bubble_sort() ? " Success! " : " Failure") << endl;

    myNodeVar.bubble_sort();

    cout << "Minimum value is: " << myNodeVar.find_min() << endl;

    cout << "test_find_min: " << (test_find_min() ? " Success! " : " Failure") << endl;

     myNodeVar.insert_at(3, 12);

     cout << "test_insert_at: " << (test_insert_at() ? " Success! " : " Failure") << endl;

    cout << "test_swap_value: " << (test_swap_value() ? " Success! " : " Failure") << endl;

     cout << "test_swap_: " << (test_swap_() ? " Success! " : " Failure") << endl;

     myNodeVar.swap_(myNodeVar, 1, 2);

    cout << "test_size_: " << (test_size_() ? " Success! " : " Failure") << endl;

    cout << "test_remove_from_position: " << (test_remove_from_position() ? " Success! " : " Failure") << endl;

    myNodeVar.display();

    return 0;
}

int operator +(const Node &lhs, const Node &rhs)
{
    return (lhs.data + rhs.data);
}

bool test_push_beginning()
{
    List obiekttestowy;

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
    List obiekttestowy;

    obiekttestowy.push_end(4);
    obiekttestowy.push_end(5);

    if(obiekttestowy[1]==5)
        return true;

    return false;
}

bool test_n_pop_front()
{
    List obiekttestowy;

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
    List obiekttestowy;

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
     List obiekttestowy;

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
     List obiekttestowy;

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
     List obiekttestowy;

    obiekttestowy.push_beginning(4);
    obiekttestowy.push_beginning(1);
    obiekttestowy.push_beginning(5);

    obiekttestowy.bubble_sort();

    if((obiekttestowy[0] < obiekttestowy[1]) && (obiekttestowy[1] < obiekttestowy[2]))
        return true;

    return false;

}

bool test_find_min()
{
    List obiekttestowy;

    obiekttestowy.push_beginning(4);
    obiekttestowy.push_beginning(1);
    obiekttestowy.push_beginning(5);

    int min = obiekttestowy.find_min();

    if((min == obiekttestowy[1]))
        return true;

    return false;

}

bool test_insert_at()
{
    List obiekttestowy;

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
    List obiekttestowy;

    obiekttestowy.push_beginning(4);
    obiekttestowy.push_beginning(1);
    obiekttestowy.push_beginning(4); // 4 1 4

   obiekttestowy.swap_value(obiekttestowy, 1, 0);

    if(obiekttestowy[0] ==1 && obiekttestowy[1] == 4)
        return true;

    return false;
}

bool test_swap_()
{
    List obiekttestowy;

    obiekttestowy.push_beginning(4);
    obiekttestowy.push_beginning(1);
    obiekttestowy.push_beginning(4);

   obiekttestowy.swap_value(obiekttestowy, 1, 0);

    if(obiekttestowy[0] ==1 && obiekttestowy[1] == 4)
        return true;

    return false;
}

bool test_size_()
{
    List obiekttestowy;

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
    List obiekttestowy;

    obiekttestowy.push_beginning(4);
    obiekttestowy.push_beginning(1);
    obiekttestowy.push_beginning(3); // 3 1 4

    cout << "obiekttestowy[0]"  << obiekttestowy[0] << endl;

    obiekttestowy.remove_from_position(obiekttestowy, 0);

    cout << "obiekttestowy[0]"  << obiekttestowy[0] << endl;

    obiekttestowy.display();

    if(obiekttestowy[0] == 1) // 3 1 4 - nic nie zostalo usuniete
        return true;

    return false;
}


