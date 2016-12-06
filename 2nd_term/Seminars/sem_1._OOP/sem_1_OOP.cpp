#include <iostream>
#include <vector>

using namespace std;

// cout - console output
// cin - console input

int main()
{
	size_t size = 10;
	vector <int> arr(size);
	
	for (int i = 0; i < size; ++i)
	{
			arr[i] = i*i;
			
	}	
	
	return 0;
}
