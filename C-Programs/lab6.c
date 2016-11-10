#include <stdio.h>
#include <stdlib.h> 

daysPassed(int m, int d, int y)
{
	int i = 0;
	int day = 0;
	int mArray[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	for(i = m - 1; i > 0; i--)
	{	
		day = day + mArray[i];

		if(i == 1)
		{
			if(y % 400 == 0)
			{
				if(y % 100 == 0)
				{
					if(y % 4 == 0)
					{
						day = day + 1;
					}
				}
			}
			else if(y % 100 != 0 && y % 4 == 0)
			{
				day = day + 1;
			}
		}
	}
	if(m == 2)
	{
		day = day + d + 2;
	}
	else
	{
		day = day + d;
	}

	printf("\n\n\t\tThere are %d days passed in the year %d", day, y);
}

date(int d,int y)
{
	int i;
	int mArray[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	for(i = 0; d > 0; i++)
	{
		d = d - mArray[i];
		
		if(i == 1)
		{
			if(y % 400 == 0)
			{
				if(y % 100 == 0)
				{
					if(y % 4 == 0)
					{
						d = d - 1;
					}
				}
			}
			else if(y % 100 != 0 && y % 4 == 0)
			{
				d = d - 1;
			}
		}
		
		if(d <= 0)
		{
			if(i == 1)
			{
				if(y % 400 == 0)
				{
					if(y % 100 == 0)
					{
						if(y % 4 == 0)
						{
							d = d + mArray[i] + 1;
							
							break;
						}
					}
				}
				else if(y % 100 != 0 && y % 4 == 0)
				{
					d = d + mArray[i] + 1;
					
					break;
				}
			}
			else
			{
				d = d + mArray[i];
			
				break;
			}
		}
	}
	printf("\n\n\t\tThe date is %d-%d-%d", i + 1, d, y);
}

int main()
{
	char more = 'y';
	int choice, month, day, year,date(int, int);
	int mArray[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	while(more == 'y' || more == 'Y')
	{
		printf("\n\n\tThis program will find days passed or date in the year");
		printf("\n\t\t\t1)  Input date (mm/dd/yyyy) to find days passed");
		printf("\n\t\t\t2)  Input passed days to find date in the year");
		printf("\n\n\t\t\tYour choice (1/2): ");
		scanf("%d", &choice);
	
		if(choice == 1)
		{
			printf("\n\n\t\tPlease input date (mm-dd-yy): ");
			scanf("%d %d %d", &month, &day, &year);
			day *= -1;
			year *= -1;
			
			if(day <= 0 || day >= 366)
			{
				printf("\n\n\t\tDate input error");
			}
			else if(mArray[month - 1] - day < 0)
			{
				printf("\n\n\t\tDate input error");
			}
			else if(year <= 0)
			{
				printf("\n\n\t\tDate input error");
			}
			else if(year % 400 == 0)
			{
				if(year % 100 == 0)
				{
					if(year % 4 == 0)
					{
						if(month == 2)
						{
							if(29 - day >= 0)
							{
								daysPassed(month, day, year);
							}
							else
							{
								printf("\n\n\t\tDate input error");
							}	
						}
						else if(mArray[month - 1] - day >= 0)
						{
							daysPassed(month, day, year);
						}
						else
						{
							printf("\n\n\t\tDate input error");
						}
					}
				}
			}
			else if(year % 100 != 0 && year % 4 == 0)
			{
				if(month == 2)
				{
					if(29 - day >= 0)
					{
						daysPassed(month, day, year);
					}
					else
					{
						printf("\n\n\t\tDate input error");
					}	
				}
				else if(mArray[month - 1] - day >= 0)
				{
					daysPassed(month, day, year);
				}
				else
				{
					printf("\n\n\t\tDate input error");
				}
			}
			else if(month == 2)
			{
				if(28 - day >= 0)
				{
					daysPassed(month, day, year);
				}
				else
				{
					printf("\n\n\t\tDate input error");
				}	
			}
			else
			{
				daysPassed(month, day, year);
			}		
			

		}
		else if(choice == 2)
		{	
			printf("\n\t\tInput days: ");
			scanf("%d", &day);
			printf("\n\t\t     Years: ");
			scanf("%d", &year);
			
			if(day <= 0 || day >= 366)
			{
				printf("\n\n\t\tDate input error");
			}
			else if(year <= 0)
			{
				printf("\n\n\t\tDate input error");
			}
			else if(year % 400 == 0)
			{
				if(year % 100 == 0)
				{
					if(year % 4 == 0)
					{
						if(day <= 0 || day >= 367)
						{
							printf("\n\n\t\tDate input error");
						}
						else
						{
							date(day, year);
						}
					}
				}
			}
			else if(year % 100 != 0 && year % 4 == 0)
			{
				if(day <= 0 || day >= 367)
				{
					printf("\n\n\t\tDate input error");
				}
				else
				{
					date(day, year);
				}
			}
			else
			{
				date(day, year);
			}			
		}
		printf("\n\n\t\tDo more (Y/N) ? ");
		scanf ("%s", &more);	 
	}
}
