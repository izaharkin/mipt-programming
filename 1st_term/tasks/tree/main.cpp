#include <ctime>
#include "std_lib_facilities.h"
#include "tree.h"
#include "printkey.h"
#include <queue>


using namespace std;

void wfs(queue<Tree*> a)
{
    Tree *tree;
    tree = a.front();
    a.pop();
    if(tree->show_left()!= 0) a.push(tree->show_left());
    if(tree->show_right()!= 0) a.push(tree->show_right());
    int d = tree->depth();
    cout<< tree->key<< ' ';
    while(a.size()!= 0)
    {
        tree = a.front();
        a.pop();
        if( d != tree->depth())
        {
            d = tree->depth();
            cout << endl<< tree->key<< ' ';
        }
        else cout << tree->key<< ' ';

        if(tree->show_left()!= 0) a.push(tree->show_left());
        if(tree->show_right()!= 0) a.push(tree->show_right());

    }



}


int main()
{
    queue<Tree*> a;
    PrintKey print_key;
    srand(time(0));
    const int n = 50;
    RandInt random_int(1,n);
    Tree *tp = 0;
    for(int i = 0; i < n; ++i)
    {
        int key = random_int();
        if(!tp->find(key))
                     tp = tp->insert(new Tree(key));
    }

    a.push(tp);
    wfs(a);

    tp = tp->clear();


    return 0;
}
