#include "binary_tree.h"
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
        if (n->key < parent->key) parent->left = n;
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
        cout << "Dep: " << q.size() << endl;
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
    if (left == 0 && right == 0)
    {
        if (p->left == this)
            p->left = 0;
        else p->right = 0;
    }
    else if ((left == 0 && right != 0) || (left != 0 && right == 0))
    {
        cout << "One son" << endl;
        Tree *son;

        son = left ? left : right;
        cout << "Key: " << son->key << endl;
        if (p->left == this)
            p->left = son;
        else p->right = son;

        son->p = p;
    }
    else
    {
        cout << "Two sons" << endl;
        if (right->left == 0)
        {
            cout << "???" << endl;
            right->p = p;
            right->left = left;
            left->p = right;

            if (p->left == this)
                p->left = right;
            else p->right = right;

        }
        else
        {

            cout << "!!!" << endl;
            Tree *exchange = right;
            while(exchange->left != 0)
                exchange = exchange->left;

            exchange->p->left = 0;
            exchange->p = p;

            exchange->left = left;
            left->p = exchange;

            exchange->right = right;
            right->p = exchange;


           
            if (p->left == this)
                p->left = exchange;
            else p->right = exchange;
        }

    }
    delete this;
    return this->p;
}
