#include <iostream>
#include "NodeVar.h"

using namespace std;

int operator +(const NodeVar &lhs, const NodeVar &rhs);

int main()
{

   NodeVar myNodeVar;

   myNodeVar.push_beginning(20);
   myNodeVar.push_beginning(22);
   myNodeVar.push_beginning(23);

   myNodeVar.push_end(40);

    myNodeVar.insert_at(3, 12);

    myNodeVar.swap_values(22,20);

    myNodeVar.display();

    myNodeVar.remove_from_position(myNodeVar, 0); // test if position is 0

    myNodeVar.display();

    myNodeVar.n_pop_front();

    myNodeVar.n_pop_back();


    //myNodeVar.reverseList();

    int searched_value = 12;

    if (myNodeVar.linear_search(searched_value) != nullptr)

        cout << "Value " << searched_value << " has been found at position: " << myNodeVar.linear_search(searched_value) << endl;
    else
        cout << "Searched value has not been found. " << endl;

    //myNodeVar.bubble_sort();

    //cout << "Minimum value is: " << myNodeVar.find_min() << endl;

    myNodeVar.display();

    return 0;
}

int operator +(const Node &lhs, const Node &rhs)
{
    return (lhs.data + rhs.data);
}

