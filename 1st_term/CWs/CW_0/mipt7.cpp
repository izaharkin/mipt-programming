#include <iostream>

using namespace std;

int main()
{
	int n;
	
	cin >> n;
	
	int cnt = 1;
	for (int i = 1; i < n; i++)
		for (int j = i+1; j < n; j++)
			if ( i + j == n )
				cnt++;
	
	for (int i = 1; i < n; i++)
		for (int j = i+1; j < n; j++)
			for (int k = j+1; k < n; k++)
				if ( i + j + k == n )
					cnt++;
	
	for (int i = 1; i < n; i++)
		for (int j = i+1; j < n; j++)
			for (int k = j+1; k < n; k++)
				for (int l = k+1; l < n; l++)
					if ( i + j + k + l == n )
					cnt++;
	
	for (int i = 1; i < n; i++)
		for (int j = i+1; j < n; j++)
			for (int k = j+1; k < n; k++)
				for (int l = k+1; l < n; l++)
					for (int m = l + 1; m < n; m++)
						if ( i + j + k + l + m == n )
							cnt++;
							
	for (int i = 1; i < n; i++)
		for (int j = i+1; j < n; j++)
			for (int k = j+1; k < n; k++)
				for (int l = k+1; l < n; l++)
					for (int m = l + 1; m < n; m++)
						for (int h = m+1; h < n; h++)
							if ( i + j + k + l + m + h == n )
								cnt++;
	
	for (int i = 1; i < n; i++)
		for (int j = i+1; j < n; j++)
			for (int k = j+1; k < n; k++)
				for (int l = k+1; l < n; l++)
					for (int m = l + 1; m < n; m++)
						for (int h = m+1; h < n; h++)
							for (int p = h+1; p < n; p++)
								if ( i + j + k + l + m + h + p == n )
									cnt++;							
					
	cout << cnt;
	
	return 0;
}
