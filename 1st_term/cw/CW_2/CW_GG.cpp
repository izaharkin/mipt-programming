#include <iostream>
 
using namespace std;
 
struct Node
{
    int data;
    Node *p, *left, *right;
};
 
typedef Node *PNode;
 
class FBTree
{
private:
    PNode Head;
public:
    FBTree() : Head(NULL) {}
    
    void insert(int n)
    {
        PNode z = new Node;
        PNode y = NULL;
        PNode x = Head;
 
        z->data = n;
 
        while ( x != NULL )
        {
            y = x;
            if ( (z->data) < (x->data) )
                x = x->left;
            else
                x = x->right;
        }
        
        z->p = y;
        if ( y == NULL )
            Head = z;
        else
        {
            if ( (z->data) < (y->data) )
                y->left = z;
            else
                y->right = z;
        }
        
        z->left = NULL;
        z->right = NULL;
 
        delete x;
        delete y;
    }
    
    FBTree(int n)
    {
        insert(n);
    }
    //Итеративный поиск
    PNode FindNode(int n)
    {
        PNode x = Head;
 
        while ( (x != NULL) && (x->data != n) )
            if ( n < (x->data) )
                x = x->left;
            else
                x = x->right;
        return x;
    }
    
    void in_order (PNode x)
    {
        if (x == NULL)
            return;
        in_order(x->left);
        if ( (x->left != NULL) && (x->right != NULL) )
			cout << (x->data);
        in_order(x->right);
	}
	
	PNode GetHead()
    {
        return Head;
    }
};

int main()
{
	int x;
	FBTree tp(7);
	/*
	while ( cin >> x )
		tp.insert(x);
	*/
	cout << tp.GetHead()->data;
	
	//tp.in_order(tp.GetHead());
	
	return 0;
}
