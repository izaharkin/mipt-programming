// ГЛАВА 12. Пункты 12.1 и 12.3
// ДЕРЕВЬЯ (Двоиные деревья поиска)
#include "Bin_Tree.h"

Bin_Tree *Bin_Tree:: find (int k)
{
	Bin_Tree* root = this;
	
	if ( root == 0 || k == key )
		return root;
		
	if ( k < key )
		return left->find(k);
	else
		return right->find(k);
}
 
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

Bin_Tree* Bin_Tree:: bt_max (Bin_Tree* x)
{
	while ( x->right )
		x = x->right;
	return x;
} 

Bin_Tree* Bin_Tree:: bt_min (Bin_Tree* x)
{
	while ( x->left )
		x = x->left;
	return x;
} 

Bin_Tree* Bin_Tree:: trans (Bin_Tree* u, Bin_Tree* v)
{
	if ( !u->p )
		return v;
	else if ( u == u->p->left )
		u->p->left = v;
	else
		u->p->right = v;
	if ( v )
		v->p = u->p;
}

Bin_Tree *Bin_Tree:: erase (Bin_Tree *n)
{
	if ( !n->left )
		trans(n, n->right);
	else if ( !n->right )
		trans(n, n->left);
	else
	{
		Bin_Tree *y = bt_min(this);
		if ( y->p != n )
		{
			trans(y, y->right);
			y->right = n->right;
			y->right->p = y;
		}
		trans(n, y);
		y->left = n->left;
		y->left->p = y;
	}
} 

int Bin_Tree:: depth ()
{
	if ( this )
		return (1 + (this->left ? this->left->depth() : 0) + (this->right ? this->right->depth() : 0));
	else
		return 0;
}

void Bin_Tree:: clear ()
{
	
}

void pre_order_ (Bin_Tree *t)
{
	if ( t->left != 0 && t->right != 0 )
		cout << t->key << " ";
	if ( t->left != 0 )
		pre_order(t->left);
	if ( t->left != 0 )
		pre_order(t->right);
}

template <class Func>
void pre_order (Bin_Tree* root, Func& fn)
{
	fn(root);
	apply_pre_order(root->left, fn);
	apply_pre_order(root->right, fn);
}

template <class Func>
void in_order (Bin_Tree* root, Func& fn)
{
	apply_pre_order(root->left, fn);
	fn(root);
	apply_pre_order(root->right, fn);
}

template <class Func>
void post_order (Bin_Tree* root, Func& fn)
{
	apply_pre_order(root->left, fn);
	apply_pre_order(root->right, fn);
	fn(root);
}
