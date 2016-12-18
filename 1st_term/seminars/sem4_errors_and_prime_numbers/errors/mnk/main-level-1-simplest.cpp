#include <iostream>
#include <vector>

using namespace std;

double avg (vector <double> data)
{
	double sum = 0;
	
	for (unsigned int i = 1; i < data.size(); i++)
		sum += data[i];
	
	return ( sum / double(data.size()) );
}

void mnk_calc (double& a, double& b)
{
	int n;
	vector <double> var_x, var_y;
	
	cout << "Input values of xi and then input values of yi: \n";
	for (;cin;)
	{	
		cin >> n;
		var_x.push_back(n);
			
		if ( !cin )
			throw int(56);
			
		cin >> n;	
		var_y.push_back(n);
	}
	
	if ( var_x.size() != var_y.size() ) // Если не равны размеры
		throw int();
		
	vector <double> var_x2(var_x.size(), 0), var_xy(var_x.size(), 0);
	
	for (int i = 0; i < var_x.size(); i++)
	{
		var_x2[i] = var_x[i]*var_x[i]; 
		var_xy[i] = var_x[i]*var_y[i];
	}
	
	double avg_x = avg( var_x ), avg_y = avg( var_y ); 
	double avg_x2 = avg( var_x2 ), avg_xy = avg( var_xy );
	
	b = (avg_y * avg_x - avg_xy) / (avg_x*avg_x - avg_x2);
	a = avg_y - b * avg_x;
}

int main()
{
	double a, b;
	
	try
	{
		mnk_calc(a, b);
	}
	catch (int err)
	{
		cout << "The quantity of x and y must be equal!";	
	}
	catch (...)
	{
		cout << "TEXT";
	}
	cout << a << ' ' << b;
	
	return 0;
}
