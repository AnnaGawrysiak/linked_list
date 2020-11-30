#include <iostream>
#include <new>
#include "NodeVar.h"
#include "Node.h"

using namespace std;

int main()
{
    /*Start with the empty list */
   Node* head = NULL;

   // insert 20 at the head
   push_front(20);

   display();

    return 0;
}
