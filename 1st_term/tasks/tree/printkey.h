#include <iostream>
#include "tree.h"

class PrintKey
{
public:
    void operator()(Tree* n)const
    {
        cout << n->key << ' '<< n->value<< endl;
    }
};
