#include <iostream>

using namespace std;
/*
struct student // ������ ��������� ������ ��� ��������
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
	double avg  ();        // ������� ������
	int exam    (int num); // ������ �� num-��� �������
};

int main()
{
	
	
	return 0;
}
