#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

void print_move (int from, int to)
{
    cout << "Move from: "<< from << ". To: " << to << "\n";
}

// from - start stick
// to - target stick
// ad - additional stick
void move (int from, int to, int ad, int n)
{
  	if ( n == 1 )
    {
      	print_move(from, to);
      	return;
    }

 	move(from, ad, to, n-1);
  	print_move(from, to);
  	move(ad, to, from, n-1);
}

int main ()
{
	int n;
	
  	cin >> n;
  	
    move(1, 3, 2, n);
}
