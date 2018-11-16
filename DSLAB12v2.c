/*
12 Given a File of N employee records with a set K of Keys(4-digit) which
uniquely determine the records in file F. Assume that file F is maintained in
memory by a Hash Table(HT) of m memory locations with L as the set of
memory addresses (2-digit) of locations in HT. Let the keys in K and
addresses in L are Integers. Design and develop a Program in C that uses
Hash function H: K →L as H(K)=K mod m (remainder method), and
implement hashing technique to map a given key K to the address space L.
Resolve the collision (if any) using linear probing.
*/

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX 10

struct employee 
{
int id;
char name[15];
int k; 
int flag;
}EMP;


struct employee emp[MAX];

int HT[MAX];
FILE *fptr;



void display() 
{
int i;
printf("\nThe hash table is:\n");
printf("\n-------------------------------------------------------");
printf("\nHTIndex\t KEY\t EmpID\t EmpName\tCollision_Status");
printf("\n-------------------------------------------------------\n");
for(i=0; i<MAX; i++)
printf("\n%d\t %d\t %d\t %10s\t %d",i,emp[i].k, emp[i].id, emp[i].name,emp[i].flag);
printf("\n-------------------------------------------------------\n");
}


void hashing()
{
int key,eid;
char ename[20];
int htindex,count=0;

while(fscanf(fptr,"%d%d%s",&key,&eid,ename)!=EOF)
{
if(count == MAX)
{
printf("\n Hash table is full\na");
return;
}

htindex=key%MAX;

if(HT[htindex] == -1)
{
emp[htindex].id=eid;
strcpy(emp[htindex].name,ename);
emp[htindex].k=key;
emp[htindex].flag=0;
HT[htindex]=htindex;
}

else
{
printf("\nCollision Detected...!!!\n");

while(HT[htindex] != -1)
htindex=(htindex+1)%MAX;

emp[htindex].id=eid;
strcpy(emp[htindex].name,ename);
emp[htindex].k=key;
emp[htindex].flag=1;
HT[htindex]=htindex;

printf("\nCollision avoided successfully for key=%d\n",key);
}
count++;
}
}
void main()
{
int i;
int ch;
fptr = fopen("a.txt","r");
printf("\nCollision handling by using LINEAR PROBING: ");
for (i=0; i < MAX; i++)
HT[i] = -1;

for(;;)
{
printf("\n1.Create Employee record\n2.Display Hash Table\n3.exit\nenter your choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1: 
hashing();
break;

case 2:
display(emp);
break;

case 3: exit(0);

default: printf("invalid choice\n");
}
}
fclose(fptr);
}

/*

FILE CONTENT

1234 111	anand
2345 222	kumar
3422 333    arun
5655 444    nayana
1112 555    eshwar
7876 666    rani
9988 777    manju
6544 888    thanu

----------------------------------

Collision handling by using LINEAR PROBING: 
1.Create Employee record
2.Display Hash Table
3.exit
enter your choice
1

Collision Detected...!!!

Collision avoided successfully for key=5655

Collision Detected...!!!

Collision avoided successfully for key=1112

Collision Detected...!!!

Collision avoided successfully for key=7876

Collision Detected...!!!

Collision avoided successfully for key=6544

1.Create Employee record
2.Display Hash Table
3.exit
enter your choice
2

The hash table is:

-------------------------------------------------------
HTIndex	 KEY	 EmpID	 EmpName	Collision_Status
-------------------------------------------------------

0	 0	 0	           	 0
1	 0	 0	           	 0
2	 3422	 333	       arun	 0
3	 1112	 555	     eshwar	 1
4	 1234	 111	      anand	 0
5	 2345	 222	      kumar	 0
6	 5655	 444	     nayana	 1
7	 7876	 666	       rani	 1
8	 9988	 777	      manju	 0
9	 6544	 888	      thanu	 1
-------------------------------------------------------


*/
