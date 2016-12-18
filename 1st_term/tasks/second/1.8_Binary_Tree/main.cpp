#include "binary_tree.h"

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
    srand( time(0) );
    const int n = 50;
    Tree *tp = 0;
    
    for (int i = 0; i < n; ++i)
    {
        int key = rand() % 30;
        if ( !tp->find(key) ) 
			tp = tp->insert(new Tree(key));
    };

    while ( true )
    {
        vector<Tree*> arr = tp->wfs();
        
        for (int i = 0; i < arr.size(); i++)
            cout << arr[i]->getkey() << endl;
        cout << endl;
        
        int rm; 
		cin >> rm;
		
        tp->find(rm)->erase();
    }
}
