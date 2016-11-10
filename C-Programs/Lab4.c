#include <stdio.h>
#include <math.h>

int main()
{
	double x, mySin(double), myCos(double), myExp(double);
	char more = 'y';
	
		while(more == 'y' || more == 'Y')
	{
		printf("\n\t\t\tInput X: ");
		scanf ("%lf", &x);
		printf("\n\n\t\t\t\tLibraryResult\tMyResult");
		
		printf("\n\t\tsin(%6.2f)	%9.6f\t%9.6f", x,sin(x),mySin(x));
		printf("\n\t\tcos(%6.2f)	%9.6f\t%9.6f", x,cos(x),myCos(x));
		printf("\n\t\texp(%6.2f)	%9.6f\t%9.6f", x,exp(x),myExp(x));
		
		printf("\n\t\t\tDo more (Y/N) ? ");
		scanf ("%s", &more);
	}
}


//Sin Function
double mySin(double x)
{
	int i, sign;
	double sum, Prod(double, int);
	
	for (i = 0, sign = 1, sum = 0.; i <20; i++, sign = -sign)
	{
		sum = sum + sign * Prod(x, 2 * i + 1);
	}
	
	return sum;
}


//Cos Function
double myCos(double x)
{
	int i, sign, n;
	double sum, Prod(double, int);
	
	for (i = 0, sign = 1, sum = 0; i < 20; i++, sign = -sign)
	{
		sum = sum + sign * Prod(x, 2 * i);
	}

	return sum;
}


//Exp Function
double myExp(double x)
{
	int i;
	double sum, Prod(double, int);
	
	for (i = 1, sum = 1.; i <20; i++)
	{
		sum = sum + Prod(x, i);
	}
	
	return sum;
}


//Product Function
double Prod(double x, int n)
{
	int i = 1;
	double prod;

	for (i = 1, prod = 1; i <=n; i++)
	{
		prod = prod * x/i;
	}

	return prod;
}
