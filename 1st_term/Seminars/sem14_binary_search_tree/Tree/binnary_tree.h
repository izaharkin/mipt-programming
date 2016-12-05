#ifndef binnary_tree_h
#define binnary_tree_h

#include <stdlib.h>
#include <stdio.h>
#include <iostream>

#include <math.h>
#include <random>
#include <stdexcept>

class Tree
{
    int key;
    Tree *p;
    Tree *left;
    Tree *right;
    int depth;

    template<class Func> friend void apply_pre_order (Tree *root, Func &fn);
    public:
    char value;

    // key, value, parent, left, right
    Tree (int k, char v = 'W', Tree *pt = 0, Tree *lt = 0, Tree *rt = 0)
        : key(k), value(v), p(pt), left(lt), right(rt) { }

    Tree *find (int k);
    Tree *insert(Tree *n); // pointer to "new" node or tree
    Tree *erase();
    Tree *clear();
    int getdepth() const { return depth; };
    int readkey() const;

    bool hasleft() const { return left != 0; }
    bool hasright() const { return right != 0; }
    Tree *getleft() const { return left; }
    Tree *getright() const { return right; }
    Tree *getparent() const { return p; };
};

template <class Func> // functor
void apply_pre_order(Tree *root, Func &fn)
{
    if (!root) return;
    fn(root);
    apply_pre_order(root->getleft(), fn);
    apply_pre_order(root->getright(), fn);
}
template <class Func> // functor
void apply_post_order(Tree *root, Func &fn)
{
    if (!root) return;
    apply_post_order(root->getleft(), fn);
    apply_post_order(root->getright(), fn);
    fn(root);
}
template <class Func>
void apply_in_order(Tree *root, Func &fn)
{
    if (!root) return;
    apply_in_order(root->getleft(), fn);
    fn(root);
    apply_in_order(root->getright(), fn);
}

#endif binnary_tree_h
