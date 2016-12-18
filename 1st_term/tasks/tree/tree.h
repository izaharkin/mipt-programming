#ifndef RANDINT
#define RANDINT

#include <iostream>


class RandInt
{
    int left, delta;
public:
    RandInt(int a, int b)
        :left(a),delta(b-a){}
    int operator()()const
    {
        return left+delta*(rand()/double(RAND_MAX));
    }
};

class Tree
{
public:
    const int key;
    char value;
    Tree(int k, char v = 'w')
        :key(k), value(v),
          p(0), left(0),right(0){}
    Tree * find(int k);//ищет, выдает ссылку на элемент с таким же значением
    int depth()const;// находит глубину древа
    Tree * insert(Tree* n);//вставляет новый элемент
    Tree *erase();//удаляем элемент, выдаем ссылку на элемент, которым нужно заменить
    Tree *clear();//возвращает 0
    friend void clear1(Tree *a);
    Tree *show_parent();
    Tree *show_left();
    Tree *show_right();
    Tree *show_tree();

private:
    Tree *p, *left, *right;
    template <class Func>
    friend void apply_pre_order(Tree *root, Func &fn);//обход дерева с наименьшего ключа


};


template <class Func>
void apply_pre_order(Tree *root, Func &fn)
{
    fn(root);
    if(root->left != 0) apply_pre_order(root->left, fn);
    if(root->right != 0) apply_pre_order(root->right, fn);
}


#endif
