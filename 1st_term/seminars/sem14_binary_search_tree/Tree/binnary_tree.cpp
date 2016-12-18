#include "binnary_tree.h"
using namespace std;

/*
int Tree::depth() const
{
    if (this->p == 0)
        return 0;
    return this->p->depth() + 1;
}
*/

int Tree::readkey() const
{
    return this->key;
}

// TODO: fix
Tree *Tree::erase()
{
    if (this->left == 0 && this->right == 0) // случай без потомков
    {
        if (p->left == this)
            p->left = 0;
        else p->right = 0;
    }
    else if (right == 0) // один потомок
    {
        if (p->left == this)
            p->left = left;
        else p->right = left;
    }
    else // два потомка
    {
        Tree *exchange = right;
        while(!exchange->left)
            exchange = exchange->left;

        if (p->left == this) // Разрываем связь между родителем и удаляемым объектом
            p->left = exchange;
        else p->right = exchange;

        if (exchange->p->left == exchange) // Рвем связь родителя и обменного объекта
            exchange->p->left = 0;
        else exchange->p->right = 0;

        exchange->left = left;
        exchange->right = right;
    }

    return this->p;
}

// TODO: implemenation
Tree *Tree::clear()
{

}

Tree *Tree::find(int k)
{
    Tree *root = this;
    if (root == 0 || k == key) return this;
    if (k < key) return left->find(k);
    if (k > key) return right->find(k); // or else
}

Tree *Tree::insert(Tree *newtree)
{
    if (newtree == 0) throw runtime_error("Tree::insert newtree == 0");
    Tree *parent = 0;
    Tree *root = this;
    while (root)
    {
        parent = root;
        if (newtree->key < root->key) root = root->left;
        else root = root->right;
    }
    if (parent == 0)
        newtree->depth = 0;
    else
    {
        newtree->p = parent;
        newtree->depth = parent->depth + 1;
    }

    // tree was empty before
    if (parent == 0) // !parent
        return newtree;
    else if (newtree->key < parent->key)
        parent->left = newtree;
    else parent->right = newtree;

    return this;
}
