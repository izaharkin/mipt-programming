#include <iostream>
using namespace std;

int main()
{
  int order = 0; // binomial order
  cin>>order;

  for( int n = 0; n <= order; n++)
  {

    for( int k = 0; k <= n; k++ )
    { // calculations of binomial coefficient ( C(n,k) )
      int n1 = 1; // n!
      for( int i = n; 1 < i; i-- )
        n1 *= i;

      int k1 = 1; // k!
      for( int i = k; 1 < i; i-- )
        k1 *= i;

      int nk1 = 1; // (n-k)!
      for( int i = n-k; 1 < i; i-- )
        nk1 *= i;

      cout<< n1 / k1 / nk1 << " ";
    }
    cout<<"\n";

  }

  return 0;
}
