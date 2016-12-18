#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include <math.h>
#include <random>
#include <time.h>

#include "binnary_tree.h"
#include "dump_tree.h"

using namespace std;

// Функтор
class RandInt
{
    private:
        int left, delta;
    public:
        RandInt(int a, int b) : left(a), delta(b-a) { }
    int operator() () const // operator() - имя функции, перегрузка вызова функции
    {
        return left + delta*(rand() / RAND_MAX); // RAND_MAX = 32767
    };
};

class PrintKey
{
public:
    int operator() (Tree *root) const
    {
        int depth = root->getdepth();
        for (int i = 0; i < depth; i++)
            cout << "-";
        cout << root->readkey() << endl;
    }
};

int main()
{
    srand(time(0)); // seed = tick

    const int n = 50;
    RandInt rn(1, n);

    vector<int> keylist;
    Tree *tp = 0; // пустое новое дерево
    for (int i = 0; i < n; i++)
    {
        int key = rand() % 30;
        keylist.push_back(key);
        if (!tp->find(key)) // если такого ключа еще нет, создадим узел с ним
            tp = tp->insert(new Tree(key));
    }

    // PrintKey - functor
    PrintKey print_key;
    apply_pre_order(tp, print_key); // обход с выводом
    cout << endl;

    /*
    for(int i = 0; i < keylist.size(); i++)
        if (tp->readkey() != keylist[i])
            tp->find(keylist[i])->erase();

    apply_pre_order(tp, print_key); // обход с выводом
    cout << endl;
    */

    // dump graph file
    dump(tp, "file");

    tp = tp->clear();
    return 0;
}
