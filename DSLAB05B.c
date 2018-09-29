//Solving Tower of Hanoi problem with n disks.

#include<stdio.h>
#include<math.h>
void toh(int n, char s,char t, char d)
{
if(n==0)
return;
else
{
toh(n-1, s, d, t);
printf("\nMove disc %d from %c to %c\n", n, s, d);
toh(n-1, t, s, d);
}
}

void main()
{
int n;
printf("\nEnter the number of discs: \n");
scanf("%d", &n);
toh(n, 'S', 'T', 'D');
printf("\n\nTotal Number of moves are: %d\n\n", (int)pow(2,n)-1);
}


/*
OUTPUT:

Enter the number of discs: 
3

Move disc 1 from S to D

Move disc 2 from S to T

Move disc 1 from D to T

Move disc 3 from S to D

Move disc 1 from T to S

Move disc 2 from T to D

Move disc 1 from S to D


Total Number of moves are: 7
*/
