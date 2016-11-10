#include <stdio.h>

void printIt(int a[])
{
	int i;
	
	for (i = 0; i < 15; i++)
	{
		printf("%2d,", a[i]);
	}
}

void shellSort(int x[15], int m)
{
	int i, temp, j, swap, k;
	int jump = 15;
	int flag = 1;
		for(i = m; i = i / jump;	)
		{
			for(swap = i; swap < m; swap++)
			{
			
				k = x[swap];
			
				for(j = swap; j >= i && k < x[j - i]; j -= i)
				{
					x[j] = x[j-i];
				}
				x[j] = k;
				flag = 0;
			}
		}
}

int binarySearch(int x[], int tgt)
{
    int low = 0, high = 16, mid;
    while(low <= high)
    {
        mid = (low + high)/2;
        if(x[mid] < tgt)
        {
	        low = mid + 1; 
        }
        else if(x[mid] > tgt)
        {
            high = mid - 1;
        }
        else if(x[mid] == tgt)
        {
            return mid + 1;
        }

    }
    return 0;
}
int main()
{
	int x[] = {25, 16, 92, 81, 65, 59, 48, 31, 67, 27, 14, 9, 52, 38, 61};
	int loc, temp;
	int m = sizeof x / sizeof x[0];
	char more = 'y';
	
	printf("\n\t\tUnsorted Seq: ");
	printIt(x);
	shellSort(x,m);
	printf("\n\t\t  Sorted Seq: ");
	printIt(x);
	
	while(more == 'y' || more == 'Y')
	{
		printf("\n\t\t\tInput a Number: ");
		scanf ("%d", &temp);
		loc = binarySearch (x, temp);
		
		if (loc > 0)
		{
			printf ("\n\t\t\t%d is found at position %d", temp, loc);
		}
		else
		{
			printf ("\n\t\t\t%d is not found", temp);
		}
		
		printf("\n\t\t\t\tDo more (Y/N) ? ");
		scanf ("%s", &more);
	}
}
