#include <iostream>
#include "NodeVar.h"
#include "Node.h"

using namespace std;

int main()
{

   NodeVar myNodeVar;

   myNodeVar.push_beginning(20);
   myNodeVar.push_beginning(22);
   myNodeVar.push_beginning(23);

   myNodeVar.push_end(40);

    myNodeVar.insert_after(myNodeVar.head, 11);

    myNodeVar.insert_after(myNodeVar.head->next->next, 12);

    myNodeVar.insert_before(myNodeVar.tail->prev, 13);

    myNodeVar.n_remove(myNodeVar.tail);

    myNodeVar.n_pop_front();

    myNodeVar.n_pop_back();

    //11 22 12 20

    myNodeVar.reverseList();

    int searched_value = 12;

    if (myNodeVar.linear_search(searched_value) != nullptr)

        cout << "Wartosc " << searched_value << " zostala znaleziona na pozycji: " << myNodeVar.linear_search(searched_value) << endl;
    else
        cout << "Szukana wartosc nie zostala znaleziona. " << endl;

    //myNodeVar.bubble_sort();

    //cout << "Minimum value is: " << myNodeVar.find_min() << endl;

    myNodeVar.display();

    return 0;
}
