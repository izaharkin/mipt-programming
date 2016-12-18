#include <iostream>
#include <vector>

int avg(vector<int> data)
{int sum=0;
for(unsigned int i=data.size();
-1<i;i--)sum+=data[i];
return sum/data.size();}
int mnk_calc()
{vector x,y;
for(;;){x.push_back(0);
if(cin)
cin>>x[x.size()];
else break;
if(cin)cin>>y[y.size()];
else
break;
}vector<int> x2, y2;
for(int i=0;i<x.size();i++)x.push_back(0);
for(int i=0;i<x.size();i++)y2.push_back(0);
for(unsigned int i=x.size();0<i;i++){x2[i]=x*x,xy[i]=x*y;}
int ax=avg(x),ay(y);ax2=avg(x),ay2=avg(y2);
int b=ay*ax-yx/ax^2-ax2;
int a=ay-b*ax;
return a,b;}
int main(){cout<<mnk_calc;return 0;}

