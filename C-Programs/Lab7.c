#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *in;
	char name[7];
	int type, type2, quantity;
	float cost, market;
	float cTot, mTot;
	float cAll, mAll, cLower;
	type2 = 0;
	cAll = 0;
	mAll = 0;
	if((in = fopen("blinn.dat", "r")) == NULL)
	{
		printf("Can't open file blinn.dat");   
		exit(1);
	}
	else
	{
		printf("\n\t\t\tBlinn Discount Apparel Company");
		printf("\n\t\t\t    Inventory Evaluation");
		printf("\n\t\t\t\t11/01/2001");
		printf("\n\n\t\t\tUnit Cost\t\tExtended");
		printf("\n\t  Quantity    Cost    Market\t    Cost     Market     Lower Cost\n");
		
		while(fscanf(in, "%d %s %d %f %f", &type,name,&quantity,&cost,&market) !=EOF)
		{	
			if(type2 != type)
			{
				if(cAll < mAll)
				{
					cLower += cAll;
				}
				else
				{
					cLower += mAll;
				}
				
				switch (type)
				{
					case 1: printf("\nMens Dept");
							break;
					case 2: printf("\n   Total\t\t\t       $%5.2f   $%5.2f     $%5.2f", cAll, mAll, cAll<mAll? cAll: mAll);
							printf("\nLadies Dept");
							cAll = 0;
							mAll = 0;
							break;
					case 3: printf("\n   Total\t\t\t       $%5.2f   $%5.2f     $%5.2f", cAll, mAll, cAll<mAll? cAll: mAll);
							printf("\nBoys Dept");
							cAll = 0;
							mAll = 0;
							break;
					case 4: printf("\n   Total\t\t\t       $%5.2f   $%5.2f     $%5.2f", cAll, mAll, cAll<mAll? cAll: mAll);
							printf("\nGirls Dept");
							cAll = 0;
							mAll = 0;
							break;
				}
			}
			cTot = quantity * cost;
			mTot = quantity * market;
			cAll += cTot;
			mAll += mTot;
			
			
			printf("\n  %s%9d\t%0.2f\t%5.2f\t%7.2f    %5.2f",name,quantity,cost,market,cTot,mTot);
			type2 = type;
		}
		if(cAll < mAll)
		{
			cLower += cAll;
		}
		else
		{
			cLower += mAll;
		}
		
		printf("\n   Total\t\t\t       $%5.2f   $%5.2f     $%5.2f", cAll, mAll, cAll<mAll? cAll: mAll);	
		printf("\n Total Inventory\t\t\t\t\t\t$%5.2f", cLower);
	}
}
