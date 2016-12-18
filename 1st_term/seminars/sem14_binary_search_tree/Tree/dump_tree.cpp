#include "dump_tree.h"
#include <iostream>
#include <fstream>

using namespace std;

const char *color_name(char color)
{
    switch(color)
    {
        case 'b': return "blue";
        case 'c': return "cyan";
        case 'g': return "green";
        case 'm': return "magenta2";
        case 'o': return "orange";
        case 'r': return "red2";
    }
    return "white";
}

class DumpNode
{
    ostream &os;
    int k; // null counter

    public:
    DumpNode(ostream &out): os(out), k(0) {}


    void operator() (Tree *n)
    {
        const char *nil_style=" [label=NIL shape=plaintext style =\"filled,rounded\" width=0.5 height=0.3 fontsize=16]\n";
        os << "  " << n->readkey() << " [fillcolor=" << color_name(n->value) << "]";
        if (n->hasleft())
            os << "; " << n->readkey() << " -> " << n->getleft()->readkey() << " [color=blue]";
        else
        {
            os << "; n" << k << nil_style << "; " << n->readkey() << " -> n" << k << " [color=orange]";
            k++;
        }

        if (n->hasright())
            os << "; " << n->readkey() << " -> " << n->getright()->readkey() << " [color=cyan]";
        else
        {
            os << "; n" << k << nil_style << "; " << n->readkey() << " -> n" << k << " [color=orange]";
            k++;
        }

        if (n->getparent() != 0)
            os << "; " << n->readkey() << " -> " << n->getparent()->readkey() << " [color=black]";
    }
};

void dump(Tree *root, const string &filename)
{
    ofstream ofs(filename.c_str());
    ofs << "digraph Tree {\n";
    ofs << "  node [style=filled shape=circle width=0.45 fixedsize=true fontsize=20]\n";
    DumpNode dump(ofs);
    if (!root)
        ofs << "n0 [label=\"Empty tree\" shape=plaintext fixedsize=false]\n";
    else
        apply_in_order(root, dump);
    ofs << "}\n";
    ofs.close();
}
