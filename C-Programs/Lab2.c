#include <stdio.h>

int main()
{
	float c;
	float f;
	char more = 'y';
	int choice = 1;
	
	while(more == 'y' || more == 'Y')
	{
        printf("\n\t\tRelationship between Fahrenheit and Celsius\n\n");
       	printf("\t\t\t    1 )    F  - >  C\n");
        printf("\t\t\t    2 )    C  - >  F");
        printf("\n\n\t\t\tChoice (1/2) ? ");
        scanf ("%d", &choice);              
 
		if (choice == 1 || choice == 2)
		{
			if (choice == 1)
			{
				printf("\n\n\t\t\tInput F: ");
				scanf ("%f", &f);
			
				c = 5.0/9.0 * (f - 32);
			
				printf("\n\n\t\t\t%5.2fF = %5.2fC", f, c);
			}
			if (choice == 2)
			{
				printf("\n\n\t\t\tInput C: ");
				scanf ("%f", &c);
			
				f = c * 9.0/5.0 + 32;
			
				printf("\n\n\t\t\t%5.2fC = %5.2fF", c, f);
			}
			
		}
		else
		{
			printf("\n\n\t\t\tYour input was not a 1 or a 2! Please try again.\n");
		}
		printf("\n\n\t\t\tDo more (Y/N) ? ");
		scanf ("%s", &more);
	}
	return (0);
}
