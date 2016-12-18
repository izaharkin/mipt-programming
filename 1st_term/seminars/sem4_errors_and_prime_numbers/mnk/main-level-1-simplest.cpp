#include <iostream>
#include <vector>

int avg( std::vector<int> data )
{
int sum = 0;
for( unsigned int i = data.size(); -1 < i; i-- )
sum += data[i];
return sum / data.size();
}

int mnk_calc()
{
std::vector<int> var_x, var_y;
for(;;){
var_x.push_back( 0 );
if(cin)
cin>>var_x[var_x.size()];
else break;
if(cin)cin>>var_y[var_y.size()];
else
break;
}
vector<int> var_x2, var_xy;
for( int i = 0; i < var_x.size(); i++ )var_x.push_back( 0 );
for( int i = 0; i < var_x.size(); i++ )var_xy.push_back( 0 );
for( int i = 0; i < var_x.size(); i++ ){var_x2[i] = x*x, var_xy[i] = x*y;}
int avg_x = avg( var_x ), avg_y( var_y ); avg_x2 = avg( var_x ), avg_xy = avg( var_xy );
int b = avg_y * avg_x - avg_yx / avg_x ^ 2 - avg_x2;
int a = avg_y - b * avg_x;
return a, b;
}

int main()
{
cout<<mnk_calc;
return 0;
}
