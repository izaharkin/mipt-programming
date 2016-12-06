#include "Heroes of Dungeons and Classes.h"

void Hero::info(ofstream& out) const
{
	out << "Great hero " << name << " with hp " << hp << " at ";
	place.print(out);
	out << "\n";
}

char Hero::symbol() const
{
	return name[0];
}

point Hero::GetPlace() const
{
	return place;
}

int Hero::GetSize() const
{
	return size;
}

void Monster::info(ofstream& out) const
{
	out << "Some monster with hp " << hp << " at ";
	place.print(out);
	out << "\n";
}

char Monster::symbol() const
{
	return 'm';
}

point Monster::GetPlace() const
{
	return place;
}

int Monster::GetSize() const
{
	return size;
}

int Lake::GetDepth() const
{
	return depth;
}

void Lake::info(ofstream& out) const
{
	out << "Clean lake of depth " << depth << " at ";
	place.print(out);
	out << " size " << size;
	out << "\n";
}

char Lake::symbol() const
{
	return '~';
}

point Lake::GetPlace() const
{
	return place;
}

int Lake::GetSize() const
{
	return size;
}

void Forest::info(ofstream& out) const
{
	out << "Forest at ";
	place.print(out);
	out << " size " << size;
	out << "\n";
}

char Forest::symbol() const
{
	return '*';
}

point Forest::GetPlace() const
{
	return place;
}

int Forest::GetSize() const
{
	return size;
}

int Mountain::GetHeight() const
{
	return height;
}

void Mountain::info(ofstream& out) const
{
	out << "Big mountain " << height << " feet high at ";
	place.print(out);
	out << " size " << size;
	out << "\n";
}

char Mountain::symbol() const
{
	return '^';
}

point Mountain::GetPlace() const
{
	return place;
}

int Mountain::GetSize() const
{
	return size;
}

World::World(int width, int height)
{
	map.resize(height + 1);
	for (int i = 0; i < height + 1; ++i)
	{
		map[i].resize(width + 1);
		for (int j = 0; j < width + 1; ++j)
			map[i][j] = '.';
	}
}

World::~World()
{
	while (objects.size())
		objects.pop_back();
}

void World::SetSize(int _width, int _height)
{
	width = _width;
	height = _height;
	map.resize(height + 1);
	for (int i = 0; i < height + 1; ++i)
	{
		map[i].resize(width + 1);
		for (int j = 0; j < width + 1; ++j)
			map[i][j] = '.';
	}
}

void World::render()
{
	GameObject *GO = objects[objects.size() - 1];

	point place = GO->GetPlace();
	int size = GO->GetSize();
	char c = GO->symbol();

	for (int i = place.y; i < place.y + size; ++i)
	{
		for (int j = place.x; j < place.x + size; ++j)
			map[i][j] = c;
	}
}

void World::add_object(GameObject *new_object)
{
	objects.push_back(new_object);
	render();
}

int World::GetQuan() const
{
	return objects.size();
}

void World::dump(ofstream& out) const
{
	for (size_t i = 0; i < objects.size(); ++i)
	{
		out << i + 1 << ". ";
		objects[i]->info(out);
	}
	out << "\n";
}

GameObject *World::GetObj(int i) const
{
	return objects[i];
}

void World::show(ostream& out) const
{
	for (size_t i = 1; i < map.size(); ++i)
	{
		for (size_t j = 1; j < map[i].size(); ++j)
			out << map[i][j] << ' ';
		out << "\n";
	}
	out << "\n";
}

void World::move(int id, int nx, int ny)
{
	GameObject *GO = GetObj(id);

}

void to_lower(string &s)
{
	int len = s.length();

	for (int i = 0; i < len; ++i)
	if ('A' <= s[i] && s[i] <= 'Z')
		s[i] += 'a' - 'A';
}