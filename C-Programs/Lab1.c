#include <stdio.h> 
#include <stdlib.h>

struct date {
       int mm, dd, yy;
};

int main()
{
     char name[20], phone[15], line[81];
     float weight;
     struct date birth;
     char more = 'y';
     FILE *inF, *outF, *outP;
     
     outF = fopen ("e:\\data1", "w");
     if (outF == NULL) {
        printf("\n\t\tCan't create file f:\data1");
        exit(1);
     }
     
     while (more == 'y' || more == 'Y') {
           printf ("\n\t\tInput your personal information: ");
           printf ("\n\t\t\tName: ");
           gets(name);
           printf ("\n\t\t\tBirth (mm/dd/yyyy): ");
           scanf ("%d/%d/%d", &birth.mm, &birth.dd, &birth.yy);
           printf ("\n\t\t\tWeight: ");
           scanf ("%f", &weight);
           getchar();
           printf ("\n\t\t\tPhone: ");
           gets(phone);
           fprintf (outF, "\n\t%-20s %2d/%2d/%4d\t\t%7.2f lb.\t%s",
                                   name, birth.mm, birth.dd, birth.yy, weight, phone);
           printf ("\n\t\t\tDo more (Y/N) ? ");
           scanf ("%s%c", &more);
     }
     fclose (outF);
     
     inF = fopen ("e:\\data1", "r");
     outP = fopen ("lpt1", "w");
     if (inF == NULL) {
             printf ("\nCan't open the input file");
             exit(1);
     }
     
     fprintf (outP, "\n\n\n\n\n\t\t     This is lab 1, made by Nathan L. Perkins");
     fprintf (outP, "\n\n\t  Name\t\t\tB-date\t\t   Weight\t     Phone");
     while (fgets(line, 80, inF) != NULL)
           fprintf (outP, "%s", line);
     
     fclose (inF);
     fclose (outP);
}
