#include <iostream>
#include <math.h>
using namespace std;


int main()
{
	double a, b, c, x1, x2;
	double xba, xi;
	char more = 'y';
	
	cout << "Solve quadratic equation by giving A,B,C coefficients" << endl;
	
	while(more == 'y' || more == 'Y')
	{
		cout << "Please input" << endl <<  "A: ";
		cin >> a;
		cout <<"B: ";
		cin >> b;
		cout << "C: ";
		cin >> c;
		cout << endl;
		
		if (a != 0)
		{
              x1 = (-b + sqrt((b*b) - 4*(a)*(c)))/(2*a);
              x2 = (-b - sqrt((b*b) - 4*(a)*(c)))/(2*a);
              
              if (x1 == x2)
              {
                    cout << "Repeated root, X = " << x1 << endl;
              }
              else if ( (b*b - 4*a*c) < 0)
              {
                   xi = sqrt((b*b - 4*a*c) * -1)/(2*a);
                   xba = (-b)/(2*a);
                   
                   cout << "Two Complex roots, X1 = " << xba << " + " << xi << "i, X2 = " << xba << " - " << xi << "i" << endl;
              }
              else
              {
                   x1 = (-b + sqrt((b*b) - 4*(a)*(c)))/(2*a);
                   x2 = (-b - sqrt((b*b) - 4*(a)*(c)))/(2*a);
            
                   cout << "Two real roots, X1 = " << x1 << ", X2 = " << x2 << endl; 
              }
        }
		else if (a == 0)
		{
			if (b == 0)
			{
				if (c == 0)
				{
					cout << "Infinite Solutions." << endl;
				}
				else if (c != 0)
				{
					cout << "Contradict equation" << endl;
				}
			}
			else
			{
                 x1 = (-c)/b;
                 cout << "Single root, X = " << x1 << endl;
            }
		}
		
		cout << "Do more (Y/N) ?  ";
		cin >> more;
		cout << endl << endl;
	}
}
