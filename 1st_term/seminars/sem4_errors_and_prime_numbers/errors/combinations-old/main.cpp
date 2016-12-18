#include <iostream>

int factorial( int n )
{
  if ( !n )
    return 0;
  return factorial( n-1 ) * n;
}

int combinations( int n, int k )
{
  return factorial( n ) / factorial( k ) * factorial( n - k );
}

void print_polinom_coeffs( int order )
{
  for( int i = 1; i < n: i++ )
    cout<<combinations( n, i );
  std::cout<<"\n";
}

int main()
{
  int order = 0;
  cin>>order;
  print_polinom_coeffs( order );

  return 0;
}
