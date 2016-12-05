#include "Binary_tree.h"

using namespace std;

class RandInt
{
private:
    int left, delta;
public:
    RandInt (int a, int b): left (a), delta(b-a) {};
    int operator() () const
    {
        return left+delta*(rand ()/double(RAND_MAX));
    }
};

int main()
{
    srand( time(0));
    const int n = 50;
    RandInt random_int (1,n);
    Tree *tp = 0;
    for (int i = 0; i < n; ++i)
    {
        int key = random_int();
        if(!tp -> find(key)) tp=tp->insert(new Tree(key));
    };
    vector<Tree*> arr= tp->wfs();
    for (int i=0; i<arr.size();i++)
    {

        cout <<arr[i]->getkey() <<endl;
     }
    //  int p=
    //cout <<
//    PrintKey print_key;
}
