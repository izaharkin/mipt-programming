#ifndef _HEROES_OF_DUNGEONS_AND_DRAGONS_H_

#define _HEROES_OF_DUNGEONS_AND_DRAGONS_H_

#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

/*  Commands:

map - creates new map - map <width> <height>
show  - shows current status of our map
create - creates a new game object - create <type> at <w> <h> <additional params>
dump - shows descriptions of all objects that are on our map for now (uses GameObject::print())
move - moves object to the new pisition - move <index> <new_w> <new_h>
help - shows commands instructions
quit - turns off our programme

*/

void to_lower(string&);

struct point
{
	int x;
	int y;
	point(int _x, int _y) : x(_x), y(_y) {}
	void print(ofstream& o) const { o << "(" << x << ", " << y << ")"; }
};

class GameObject
{
protected:
	point place;
	int size;
public:
	GameObject(point _place, int _size) : place(_place), size(_size) {}

	virtual point GetPlace() const = 0;     // prints coordinates of this object
	virtual int GetSize() const = 0;        // returns size of this object

	void move(int new_x, int new_y);        // moves object to the new position

	virtual void info(ofstream&) const = 0;     // shows us the discription of this object
	virtual char symbol() const = 0;            // symbol, that will be associated with this object (for painting)
};

class Creature: public GameObject
{
protected:
	int hp;
public:
	Creature(point _place, int _size, int _hp) : GameObject(_place, _size), hp(_hp) {}

	virtual point GetPlace() const = 0;
	virtual int GetSize() const = 0;
};

class Hero: public Creature
{
private:
	string name;
public:
	Hero(const string& _name, const string& _sur, point _place, int _size, int _hp) : Creature(_place, _size, _hp), name(_name) {}

	point GetPlace() const;
	int GetSize() const;

	void info(ofstream&) const override;
	char symbol() const override;
};

class Monster: public Creature
{
public:
	Monster(point _place, int _size, int _hp) : Creature(_place, _size, _hp) {}

	point GetPlace() const;
	int GetSize() const;

	void info(ofstream&) const override;
	char symbol() const override;       // 'm'
};

class Terrain: public GameObject
{
public:
	Terrain(point _place, int _size) : GameObject(_place, _size) {}
};

class Lake: public Terrain
{
private:
	int depth;
public:
	Lake(point _place, int _size, int _depth) : Terrain(_place, _size), depth(_depth) {}

	point GetPlace() const;
	int GetSize() const;
	int GetDepth() const;

	void info(ofstream&) const override;
	char symbol() const override;       // '~'
};

class Forest: public Terrain
{
public:
	Forest(point _place, int _size) : Terrain(_place, _size) {}

	point GetPlace() const;
	int GetSize() const;

	void info(ofstream&) const override;
	char symbol() const override;       // '*'
};

class Mountain: public Terrain
{
private:
	int height;
public:
	Mountain(point _place, int _size, int _height) : Terrain(_place, _size), height(_height) {}

	point GetPlace() const;
	int GetSize() const;
	int GetHeight() const;

	void info(ofstream&) const override;
	char symbol() const override;       // '^'
};

class World
{
private:
	void render();     // makes changings, but doesn`t paint it, use every time when call "add_object()"
	int width, height; // width and height of our map

	vector <GameObject*> objects;  // vector of pointers on objects
	vector < vector<char> > map;   // map itself

	World(const World&) = delete;           // copying is banned
	void operator= (const World&) = delete; // is banned too
public:
	World() : width(0), height(0) {}
	World(int, int);                // initialize all params, calls "render()" in order to make an empty map 
	~World();                       // deletes map and all objects 
	void SetSize(int, int);			// sets size of our map (nessessary function, because our World must exit not only in if/else block)

	void add_object(GameObject* new_object); // adds pointer on new created object in vector "objects" and calls "render()"
	int GetQuan() const;					 // returns the quantity of objects ( objects.size() )
	void show(ostream& out) const;			 // shows us current world status
	void dump(ofstream&) const;				 // to dump all objects
	GameObject *GetObj(int) const;			 // returns object having index, that is in argument lists, from "objects"
	void move(int, int, int);
};

#endif /* _HEROES_OF_DUNGEONS_AND_DRAGONS_ */