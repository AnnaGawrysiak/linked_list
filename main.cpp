#include <iostream>
#include "NodeVar.h"
#include "testowa.h"

using namespace std;

int main()
{
   testowa* test = testowa::get_instance();
   test->run(); // testy maja sie same tworzyc, sprawdzac i wyczyscic. jest enkapsulacja.

    return 0;
}
