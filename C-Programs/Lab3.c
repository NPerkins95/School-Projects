#include <stdio.h>
#include <math.h>

int main()
{
	float a, b, c, x1, x2;
	float xba, xi;
	char more = 'y';
	
	printf("\t\tSolve quadratic equation for givine A,B,C coefficient");
	
	while(more == 'y' || more == 'Y')
	{
		printf("\n\n\t\t\tPlease input A:");
		scanf ("%f", &a);
		printf("\n\n\t\t\t\t     B:");
		scanf ("%f", &b);
		printf("\n\n\t\t\t\t     C:");
		scanf ("%f", &c);
		
		if (a != 0)
		{
              x1 = (-b + sqrt((b*b) - 4*(a)*(c)))/(2*a);
              x2 = (-b - sqrt((b*b) - 4*(a)*(c)))/(2*a);
              
              if (x1 == x2)
              {
                     printf("\n\n\t\t\tRepeated root, X = %5.2f", x1);
              }
              else if ( (b*b - 4*a*c) < 0)
              {
                   xi = sqrt((b*b - 4*a*c) * -1)/(2*a);
                   xba = (-b)/(2*a);
                   
                   printf("\n\n\t\tTwo Complex roots, X1 = %5.3f + %5.3fi, X2 = %5.3f - %5.3fi", xba, xi, xba, xi);
              }
              else
              {
                   x1 = (-b + sqrt((b*b) - 4*(a)*(c)))/(2*a);
                   x2 = (-b - sqrt((b*b) - 4*(a)*(c)))/(2*a);
            
                   printf("\n\n\t\t\tTwo real roots, X1 = %5.2f, X2 = %5.2f",x1,x2); 
              }
        }
		else if (a == 0)
		{
			if (b == 0)
			{
				if (c == 0)
				{
					printf("\n\n\t\t\tInfinite Solutions.");
				}
				else if (c != 0)
				{
					printf("\n\n\t\t\tContradict equation");
				}
			}
			else
			{
                 x1 = (-c)/b;
                 printf("\n\n\t\t\tSingle root, X = %5.2f", x1);
            }
		}
		
		printf("\n\n\t\t\tDo more (Y/N) ? ");
		scanf ("%s", &more);
	}
}
