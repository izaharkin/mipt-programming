#include "std_lib_facilities.h"
#include "ctime"

class Tree
{
private:
    int key;
    Tree *p, *left, *right;
    template<class Func> friend void apply_pre_order(Tree *root, Func &fn);
public:
    int getkey() {return key;};
    char value;
    Tree(int k, char v='w', Tree *pt=0, Tree *lt=0, Tree *rt=0)
        :key(k), value(v), p(pt), left(lt), right(rt) {}
    Tree* find(int k);
    int depth();
    Vector<Tree *> wfs();
    Tree* insert(Tree *n);
    Tree* erase();
    void clear();
};


