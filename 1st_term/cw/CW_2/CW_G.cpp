#include <iostream>

using namespace std;

class Bin_Tree
{
private:
	Bin_Tree *left, *right, *p;
public:
	const int key;
	
	Bin_Tree *insert();
};

Bin_Tree *Bin_Tree:: insert (Bin_Tree* n)
{
	if ( n == 0 ) 
		cerr << "Try to insert an invalid tree node!";	
		
	Bin_Tree* parent = 0, *root = this;
	
	while ( root )
	{
		parent = root;
		if ( n->key < root->key )
			root = root->left;
		else
			root = root->right;
	}
	
	n->p = parent;
	if ( !parent )
		return n;
	else if ( n->key < parent->key )
		parent->left = n;
	else
		parent->right = n;
		
	return this;
}

void pre_order (Bin_Tree *t)
{
	if ( t->left != 0 && t->right != 0 )
		cout << t->key << " ";
	if ( t->left != 0 )
		pre_order(t->left);
	if ( t->left != 0 )
		pre_order(t->right);
}

Bin_Tree* get_p (Bin_Tree* t)
{
	Bin_Tree* tt = t;
	
	while ( tt->p )
		tt = tt->p;
	
	return tt;
}

int main ()
{
	int x;
	Bin_Tree *tp = 0;
	
	while ( cin >> x )
		tp = tp->insert(new Bin_Tree(x));
	
	tp = get_p(tp);
	
	pre_order(tp);
	
	return 0;
}

    /*
    void DeleteNode(int n)
    {
        PNode pointer = Head;
        PNode parent  = NULL;
 
        while((pointer != NULL) && (pointer->data != n))
        {
            parent = pointer;
            if(n < (pointer->data))
                pointer = pointer->left;
            else
                pointer = pointer->right;
        }
 
        if(pointer != NULL)
        {
            PNode removed = NULL;
 
            if ((pointer->left == NULL) || (pointer->right == NULL))
            {   
                PNode child = NULL;
                removed = pointer;
 
                if((pointer->left) != NULL)
                    child = pointer->left;
                else 
                    if((pointer->right) != NULL)
                        child = pointer->right;
 
                if(parent == NULL)
                    Head = child;
                else
                {
                    if((parent->left) == pointer)
                        parent->left = child;
                    else
                        parent->right = child;
                }
            }
            else // (pointer->left != NULL && pointer->right != NULL)
            {
                PNode mostLeft = pointer->right;
                PNode mostLeftParent = pointer;
            
                while ((mostLeft->left) != NULL)
                {
                    mostLeftParent = mostLeft;
                    mostLeft = mostLeft->left;
                }
 
                pointer->data = mostLeft->data;
                removed = mostLeft;
 
                if((mostLeftParent->left) == mostLeft)
                    mostLeftParent->left = NULL;
                else
                    mostLeftParent->right = mostLeft->right;
            }
            delete removed;
        }
    }
    void DeleteTree(PNode x)
    {
        if(x == NULL)
            return;
        DeleteTree(x->left);
        DeleteNode(x->data);
        DeleteTree(x->right);
    }
    
        PNode GetHead()
    {
        return Head;
    }
    
    PNode TreeMin(PNode x)
    {
        while ( (x->left) != NULL )
            x = x->left;
        return x;
    }
    
    PNode TreeMax(PNode x)
    {
        while ( (x->right) != NULL )
            x = x->right;
        return x;
    }*/
