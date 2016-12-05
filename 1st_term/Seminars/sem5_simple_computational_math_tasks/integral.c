#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*----integrand definition---*/
double function(double x)
{
	return log(x);
}

/*----rectangle method definition---*/
double rectangles(double left, double right, double step)
{
	double sum = 0;
	double runner;
	
	/* rectangular formula */
	for(runner = left + step * 0.5; runner < right; runner += step)
		sum += function(runner);
	sum *= step;
	
	return sum;
}

/*----trapezium method definition---*/
double trapezium(double left, double right, double step)
{
	double sum = 0;
	double runner;

	/* trapezium formula */
	for(runner = left + step; runner < right; runner += step)
		sum += function(runner);
	sum = (sum + 0.5*(function(left) + function(right))) * step;
	
	return sum;
}

int main(int argc, char ** argv)
{
	char c;
	double a, b;
	double step;
	
	printf("Enter lower limit of integration : ");
	scanf("%lf",&a);
	printf("Enter upper limit of integration : ");
	scanf("%lf",&b);
	printf("Enter integration step : ");
	scanf("%lf",&step);
	
	double rect = rectangles(a, b, step);
	double trap = trapezium(a, b, step);
	
	double divrect = rectangles(a, b, step/2);
	double divtrap = trapezium(a, b, step/2);
	
	double errrect = (rect - divrect) / 7;
	double errtrap = (trap - divtrap) / 7;
		
	printf("Answer by rectangles method is %10.10f.\n", divrect);
	printf("Error by rectangles method is %10.10f.\n", errrect);
	printf("Answer by trapezium method is  %10.10f.\n", divtrap);
	printf("Error by trapezium method is %10.10f.\n", errtrap);
	scanf("%c",&c);scanf("%c",&c);
	return 0;
}
