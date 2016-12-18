#include <iostream>

using namespace std;
/*
struct student // обычно структуры только дл€ хранени€
{
	char *name;
	int mark;	
};
*/
class student
{
private:
	string name;
	vector <int> marks;	
public:	
	double avg  ();        // средн€€ оценка
	int exam    (int num); // оценка за num-тый экзамен
};

int main()
{
	
	
	return 0;
}
