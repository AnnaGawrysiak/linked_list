#pragma once
#include "Node.h"
#include <iostream>

using namespace std;

class Red_Node : public Node
{
    public:
        Red_Node();
        virtual ~Red_Node();
        void testowa()
        {
            cout << "Jestem red node." << endl;
        }


    private:
};
