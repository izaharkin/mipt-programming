#include <algorithm>
#include <iostream>
#include <sstream> // stringstream
#include <vector>
#include <string>
#include <list>

using namespace std;

class node
{
public:
	string key;  // name
  	string phone;

  	int   height;
  	node* parent;
  	node* left;
  	node* right;
  	node (string k) { key = k; left = right = 0; height = 0; }
 
  	node *insert (node *n)
  	{
    	node *parent;
    	node *r = this;
    	while ( r )
      	{
			parent = r;
			if ( r->key > n->key ) 
				r = r->left;
			else 
				r = r->right;
      	}
    	if ( !parent )
      		n->height = 0;
    	else
      	{
			n->height = parent->height + 1;
			if ( parent->key > n->key ) 
				parent->left = n;
			else 
				parent->right = n;
      	}
    	return n;
  	}
  	
  	node *find (string k)
  	{
    	if (this == 0 || k == key)
      		return this;
    	if ( k < key ) 
			return left->find(k);
    	if ( k > key ) 
			return right->find(k);
  	}
};

vector<string> split (const string &s, char delim = ' ')
{
  	stringstream ss(s);
  	string item;
  	vector<string> elems;
  	
  	while (getline(ss, item, delim))
    {
      	//cout << "Item: " << item << endl;
      	elems.push_back(item);
    }
    
  	return elems;
}

string &tolower (string &s)
{
  	for (int i = 0; i < s.length(); i++)
    	if (s[i] >= 'A' && s[i] <= 'Z')
      		s[i] -= 'A' - 'a';
      
  	return s; 
} 

void clear(node *root)
{
}

void print(node *root)
{
    if ( !root ) return;
    
    if ( root->height != 1 )
      cout << "Name: " << root->key << ". Phone: " << root->phone << endl;

    print(root->left);
    print(root->right);
}

void insert (node *root, string name, string phone)
{
  	node *c = root->find(name);
  	if (c != 0)
    {
      	cout << "Record already contains phone: " << c->phone << endl;
      	c->phone = phone;
      	cout << "Record updated: " << c->phone << endl;
    }
  	else
    {
      	root->insert(new node(name))->phone = phone;
      	cout << "New record added" << endl;
    }
}

void find (node *root, string name)
{
  	node *c = root->find(name);
  	
  	if ( !c )
    	cout << "Record not found" << endl;
  	else 
	  	cout << "Phone: " << c->phone << endl;
}

int main(int argc, char *argv[])
{
  	cout << "Notepad" << endl;
  	string cmd;
  	node root("0");
  	while (true)
    {
      	cout << "Enter command: " << endl;
      	getline(cin, cmd);
      	if (cmd == "exit" || !cin.good())
			break;

      	//if (strlen(cmd) == 0)
      	//continue;

      	vector<string> args = split(cmd);
      	if (!(args.size() >= 1 && args.size() <= 3))
		{
	  		cout << "Wrong args" << endl;
	  		continue;
		}

      	tolower(args[0]);
     	if (args[0] == "insert")
			insert(&root, args[1], args[2]);
      	else if (args[0] == "find")
			find(&root, args[1]);
      	else if (args[0] == "print")
			print(&root);
      	else 
		  	cout << "Wrong command" << endl;
		  	
      	cout << endl;
    }
  
  	clear(&root);
  	
  	return 0;
}
