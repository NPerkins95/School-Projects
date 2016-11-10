#include <stdio.h>
#include <stdlib.h> 

void printIt(int bOne[10], int bTwo[10])
{
	int i, frame, tot = 0, both = 0, score = 0;
	
	printf("\n\n\n\t  Frame  -");
	for(i = 0; i < 10; i++)
	{
		printf("%4d", i + 1);
	}
	printf("  Xtr-1  Xtr-2");
	
	printf("\n\tBall - 1 :");
	for(i = 0; i < 10; i++)
	{
		printf("%4d", bOne[i]);
	}
		
	if(bOne[9] == 10)
	{
		printf("%5d%7d", bOne[10], bTwo[10]);
	}
	else if(bOne[9] + bTwo[9] == 10)
	{
		printf("%5d", bOne[10]);
	}	
	
	printf("\n\tBall - 2 :");
	for(i = 0; i < 10; i++)
	{
		printf("%4d", bTwo[i]);
	}
	
	printf("\n\t  Score  :");
	for(i = 0; i < 10; i++)
	{
		frame = i + 1;
		
		if(bOne[i] == 10)
		{
			if(bOne[i+1] == 10)
			{
				if(frame == 10)
				{
					tot+= bOne[10] + bTwo[10];
				}
				else
				{
					tot += bOne[i+1] + bOne[i+2];
				}
			}
			else
			{
				tot += bOne[i+1] + bTwo[i+1];
			}
		}
		else if(bOne[i] + bTwo[i] == 10)
		{
			tot += bOne[i+1];
		}
		
		tot += bOne[i] + bTwo[i];
		
		printf("%4d", tot);
	}
}

int main()
{
	char more = 'y';
	int i;

	while(more =='y' || more == 'Y')
	{
		int ballOne[] = {0,0,0,0,0,0,0,0,0,0,0};
		int ballTwo[] = {0,0,0,0,0,0,0,0,0,0,0};
		
		printf("\n\n\t\tWelcome to Blinn Bowling Center");
		
		for(i = 0; i < 10; i++)
		{
			printf("\n\t  Frame - %d", i + 1);
			printf("\n\t\tBall - 1: ");
			scanf ("%d", &ballOne[i]);
		
			while(ballOne[i] < 0 || ballOne[i] > 10)
			{
				printf("\n\t\t\t\tIllegal score, do one more time...");
				printf("\n\t\tBall - 1: ");
				scanf ("%d", &ballOne[i]);
			}
			
			if(ballOne[i] == 10)
			{
				printf("\t\t\t\tCongratulation!   It is STRIKE...");
			}
			else
			{
				printf("\n\t\tBall - 2: ");
				scanf ("%d", &ballTwo[i]);
				
				while(ballTwo[i] < 0 || ballTwo[i] > 10 || ballOne[i] + ballTwo[i] > 10)
				{
					printf("\n\t\t\t\tIllegal score, do one more time...");
					printf("\n\t\tBall - 2: ");
					scanf ("%d", &ballTwo[i]);
				}
				
				if(ballOne[i] + ballTwo[i] == 10)
				{
					printf("\t\t\t\tNot bad, it is SPARE...");
				}
				else if(ballOne[i] + ballTwo[i] >= 0 && ballOne[i] + ballTwo[i] < 10)
				{
					printf("\t\t\t\tNeed work harder, Dude!");
				}
			}
		}
		
		if(ballOne[9] == 10)
		{
			printf("\n\t\tExtra - 1: ");
			scanf ("%d", &ballOne[10]);
			
			while(ballOne[10] < 0 || ballOne[10] > 10)
			{
				printf("\n\t\t\t\tIllegal score, do one more time...");
				printf("\n\t\tExtra - 1: ");
				scanf ("%d", &ballOne[10]);
			}
			
			printf("\n\t\tExtra - 2: ");
			scanf ("%d", &ballTwo[10]);
			
			if(ballOne[10] == 10)
			{
				while(ballTwo[10] < 0 || ballTwo[10] > 10)
				{
					printf("\n\t\t\t\tIllegal score, do one more time...");
					printf("\n\t\tExtra - 2: ");
					scanf ("%d", &ballTwo[10]);
				}
			}
			else
			{
				while(ballTwo[10] < 0 || ballTwo[10] > 10 || ballOne[10] + ballTwo[10] > 10)
				{
					printf("\n\t\t\t\tIllegal score, do one more time...");
					printf("\n\t\tExtra - 2: ");
					scanf ("%d", &ballTwo[10]);
				}
			}
		}
		else if(ballOne[9] + ballTwo[9] == 10)
		{
			printf("\n\t\tExtra - 1: ");
			scanf ("%d", &ballOne[10]);
			
			while(ballOne[10] < 0 || ballOne[10] > 10)
			{
				printf("\n\t\t\t\tIllegal score, do one more time...");
				printf("\n\t\tExtra - 1: ");
				scanf ("%d", &ballOne[10]);
			}
		}
		
		printIt(ballOne,ballTwo);
			
		printf("\n\n\t\tDo more (Y/N) ? ");
		scanf ("%s", &more);
		if(more =='y' || more == 'Y')
		{
			printf("\n\t\t\t\tLife goes on, never stop");
		}
	}
}
