#include "Heroes of Dungeons and Classes.h"

int main()
{

	ifstream in("in.txt");   // input file
	ofstream out("out.txt"); // output file

	string s;

	string _map = "map",
		_create = "create",
		_show = "show",
		_dump = "dump",
		_move = "move",
		_help = "help",
		_quit = "quit";

	bool flag = false;

	World Map;
	while (true)
	{
		in >> s;
		to_lower(s);

		if (_map.find(s) == 0)
		{
			if (flag)
				cerr << "Sorry, but you can`t create another map now!";
			else
				flag = true;

			int width, height;
			in >> width >> height;

			Map.SetSize(width, height);
		}
		else if (_create.find(s) == 0)
		{
			string cr;
			in >> cr;
			to_lower(cr);                    // my own function
			if (cr == "hero")
			{
				string name, str;
				int x, y, hp;

				in >> name >> str >> x >> y >> str >> hp;

				Hero H(name, name, point(x, y), 1, hp);
				Map.add_object(&H);
			}
			else if (cr == "monster")
			{
				string str;
				int x, y, hp;

				in >> str >> x >> y >> str >> hp;

				Monster M(point(x, y), 1, hp);
				Map.add_object(&M);
			}
			else if (cr == "lake")
			{
				string str;
				int x, y, size, depth;

				in >> str >> depth >> str >> x >> y >> str >> size;

				Lake L(point(x, y), size, depth);
				Map.add_object(&L);
			}
			else if (cr == "forest")
			{
				string str;
				int x, y, size;

				in >> str >> x >> y >> str >> size;

				Forest F(point(x, y), size);
				Map.add_object(&F);
			}
			else if (cr == "mountain")
			{
				string str;
				int x, y, size, height;

				in >> str >> height >> str >> x >> y >> str >> size;

				Mountain M(point(x, y), size, height);
				Map.add_object(&M);
			}
		}
		else if (_show.find(s) == 0)
		{
			Map.show(out);
		}
		else if (_dump.find(s) == 0)
		{
			out << "Dumping " << Map.GetQuan() << " objects:\n";
			Map.dump(out);
		}
		else if (_move.find(s) == 0)
		{
			string str;
			int ind, nx, ny;

			in >> str >> ind >> nx >> ny;
			Map.move(ind, nx, ny);
		}
		else if (_help.find(s) == 0)
		{
			cout << "map - create new map - map <width> <height>\n"
				<< "show  - show current status of our map\n"
				<< "create - create a new game object - create <type> at <x> <y> [size] [depth] [with hp]\n"
				<< "dump - show descriptions of all objects that are on our map for now\n"
				<< "move - move object to the new pisition - move <index> <new_x> <new_y>\n"
				<< "help - show commands instructions\n"
				<< "quit - turn off the programm\n";
		}
		else if (_quit.find(s) == 0)
			break;
	}

	out << "Goodbye!";

	return 0;
}