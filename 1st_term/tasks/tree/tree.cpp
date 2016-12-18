#include "std_lib_facilities.h"
#include "tree.h"

Tree *Tree::find(int k)
{
    Tree *root = this;
    if (root == 0 || k == key)
        return this;
    if(k < key) return left->find(k);
    return right->find(k);
}

Tree *Tree::insert(Tree *n)
{
    if(n == 0) error("Try to insert an invalid tree node!");
    Tree *parent = 0, *root = this;
    while(root)
    {
        parent = root;
        if(n->key < root->key) root = root->left;
        else root = root->right;
    }
    n->p = parent;
    if(!parent) return n;
    else if(n->key < parent->key) parent->left = n;
    else if(n->key > parent->key) parent->right = n;
    return this;
}



Tree *Tree::clear()
{
    if(this == 0) return 0;

    (left)->clear();

    (right)->clear();

    delete this;
    return 0;
}


Tree *Tree::show_parent()
{
    return p;
}

Tree *Tree::show_left()
{
    return left;
}

Tree *Tree::show_right()
{
    return right;
}

Tree *Tree::show_tree()
{
    return this;
}


int Tree::depth() const
{
    if(p == 0) return 1;
    return (p->depth()+1);
}






