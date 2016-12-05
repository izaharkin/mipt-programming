#include "Binary_tree.h"
#include <queue>

using namespace std;

Tree* Tree::find(int k)
{
    Tree *root = this;
    if (root == 0 || k==key) return this;
    if (k < key) return left->find(k);
    else return right->find(k);
}

Tree* Tree::insert(Tree *n)
{
    if (n == 0) error ("try to insert an invalid tree node");
    Tree *parent = 0, *root = this;
    while (root)
    {
        parent = root;
        if (n->key < root->key) root = root->left;
        else root = root -> right;
    }
    n->p = parent;
    if(!parent) return n;
    else
        if (n->key, parent->key) parent->left = n;
        else parent->right = n;
    return this;
}

int Tree::depth()
{
    if (this->p == 0) return 0;
    return this->p->depth() + 1;
}

vector<Tree*> Tree::wfs()
{
    vector<Tree*> arr;  //
    if (this==0)
        return arr;
    queue <Tree*> q;
    q.push(this);
    while (!q.empty())
    {
        Tree* current=q.front();
        arr.push_back(current);    //
        if (current->left != 0) q.push(current->left);
        if (current->right != 0) q.push(current->right);
        q.pop();
    }
    return arr;
}

template <class Func>
void apply_pre_order (Tree *root, Func &fn)
{
    if (!root) return fn(root);
    apply_pre_order (root->left, fn);
    apply_pre_order (root->right, fn);
}



Tree *Tree::erase()
{
    if (this->left == 0 && this->right == 0)
    {
        if (p->left == this)
            p->left = 0;
        else p->right = 0;
    }
    else if (right == 0)
    {
        if (p->left == this)
            p->left = left;
        else p->right = left;
    }
    else
    {
        Tree *ex = right;
        while(!ex->left)
            ex = ex->left;

        if (p->left == this)
            p->left = ex;
        else p->right = ex;

        if (ex->p->left == ex)
            ex->p->left = 0;
        else ex->p->right = 0;

        ex->left = left;
        ex->right = right;
    }

    return this->p;
}

