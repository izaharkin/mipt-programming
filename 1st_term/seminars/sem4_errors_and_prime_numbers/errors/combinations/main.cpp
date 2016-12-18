#include <iostream>
using namespace std;

int main()
{
int order=0;
cin>>order;
const int n=order;
for(int k=0;k<=n;k++){
int n1=1;
for(int i=n;1<i;i--)
n1*=i;
int k1=1;
for(unsigned i=k;-1<i;i--)
k1*=i;
int nk1=1;
for(int i=n-k;-1<i;i--)
nk1*=i;
cout<<n1/k1*nk1<<" ";
}
cout<<"\n";
return 0;
}
