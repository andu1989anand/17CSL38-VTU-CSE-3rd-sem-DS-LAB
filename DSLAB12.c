#include <stdio.h>
#include <stdlib.h>
#define MAX 20

typedef struct employee {
int id;
char name[15];
int k; 
}EMP;


EMP emp[MAX];

int HT[MAX],count=0,key;

int reademp(EMP emp[],int htindex)
{
printf("\nEnter emp id: ");
scanf("%d",&emp[htindex].id);
printf("\nEnter emp name: ");
getchar();
gets(emp[htindex].name);
emp[htindex].k=key;
count++;
return htindex;
}




void display() 
{
int i;
printf("\nThe hash table is:\n");
printf("----------------------------\n");
printf("\nHTIndex\tKEY\tEmpID\tEmpName");
for(i=0; i<MAX; i++)
printf("\n%d\t%d\t%d\t%s", i,emp[i].k, emp[i].id, emp[i].name);
printf("\n----------------------------\n");
}




void hashing()
{
int htindex, i;
if(count == MAX)
{
printf("\n Hash table is full");
return;
}

printf("\nEnter the KEY (4-digit) information: ");
scanf("%d", &key);
htindex=key%MAX;

if(HT[htindex] == -1)
{
HT[htindex]=reademp(emp, htindex);
}
else
{
printf("\nCollision Detected...!!!\n");

i=htindex;
while(HT[i] != -1)
i=(i+1)%MAX;
htindex=i;
HT[htindex]=reademp(emp, htindex);
printf("\nCollision avoided successfully using LINEAR PROBING\n");
}
}

void main()
{
int num, htindex, i;
int ch;
printf("\nCollision handling by linear probing: ");
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
}

/*

Collision handling by linear probing: 
1.Create Employee record
2.Display Hash Table
3.exit
enter your choice
1

Enter the KEY information: 1234

Enter emp id: 111

Enter emp name: anand

1.Create Employee record
2.Display Hash Table
3.exit
enter your choice
2

The hash table is:
----------------------------

HTIndex	KEY	EmpID	EmpName
0	0	0	
1	0	0	
2	0	0	
3	0	0	
4	0	0	
5	0	0	
6	0	0	
7	0	0	
8	0	0	
9	0	0	
10	0	0	
11	0	0	
12	0	0	
13	0	0	
14	1234	111	anand
15	0	0	
16	0	0	
17	0	0	
18	0	0	
19	0	0	
----------------------------

1.Create Employee record
2.Display Hash Table
3.exit
enter your choice
1

Enter the KEY information: 5655

Enter emp id: 878

Enter emp name: raju

1.Create Employee record
2.Display Hash Table
3.exit
enter your choice
2

The hash table is:
----------------------------

HTIndex	KEY	EmpID	EmpName
0	0	0	
1	0	0	
2	0	0	
3	0	0	
4	0	0	
5	0	0	
6	0	0	
7	0	0	
8	0	0	
9	0	0	
10	0	0	
11	0	0	
12	0	0	
13	0	0	
14	1234	111	anand
15	5655	878	raju
16	0	0	
17	0	0	
18	0	0	
19	0	0	
----------------------------

1.Create Employee record
2.Display Hash Table
3.exit
enter your choice
1

Enter the KEY information: 9877

Enter emp id: 333

Enter emp name: manu

1.Create Employee record
2.Display Hash Table
3.exit
enter your choice
2

The hash table is:
----------------------------

HTIndex	KEY	EmpID	EmpName
0	0	0	
1	0	0	
2	0	0	
3	0	0	
4	0	0	
5	0	0	
6	0	0	
7	0	0	
8	0	0	
9	0	0	
10	0	0	
11	0	0	
12	0	0	
13	0	0	
14	1234	111	anand
15	5655	878	raju
16	0	0	
17	9877	333	manu
18	0	0	
19	0	0	
----------------------------

1.Create Employee record
2.Display Hash Table
3.exit
enter your choice
1

Enter the KEY information: 9882

Enter emp id: 777

Enter emp name: uday

1.Create Employee record
2.Display Hash Table
3.exit
enter your choice
2

The hash table is:
----------------------------

HTIndex	KEY	EmpID	EmpName
0	0	0	
1	0	0	
2	9882	777	uday
3	0	0	
4	0	0	
5	0	0	
6	0	0	
7	0	0	
8	0	0	
9	0	0	
10	0	0	
11	0	0	
12	0	0	
13	0	0	
14	1234	111	anand
15	5655	878	raju
16	0	0	
17	9877	333	manu
18	0	0	
19	0	0	
----------------------------

1.Create Employee record
2.Display Hash Table
3.exit
enter your choice
1

Enter the KEY information: 8222

Collision Detected...!!!

Enter emp id: 888

Enter emp name: kumar

Collision avoided successfully using LINEAR PROBING

1.Create Employee record
2.Display Hash Table
3.exit
enter your choice
2

The hash table is:
----------------------------

HTIndex	KEY	EmpID	EmpName
0	0	0	
1	0	0	
2	9882	777	uday
3	8222	888	kumar
4	0	0	
5	0	0	
6	0	0	
7	0	0	
8	0	0	
9	0	0	
10	0	0	
11	0	0	
12	0	0	
13	0	0	
14	1234	111	anand
15	5655	878	raju
16	0	0	
17	9877	333	manu
18	0	0	
19	0	0	
----------------------------

1.Create Employee record
2.Display Hash Table
3.exit
enter your choice
1

Enter the KEY information: 3286

Enter emp id: 188

Enter emp name: kushal

1.Create Employee record
2.Display Hash Table
3.exit
enter your choice
2

The hash table is:
----------------------------

HTIndex	KEY	EmpID	EmpName
0	0	0	
1	0	0	
2	9882	777	uday
3	8222	888	kumar
4	0	0	
5	0	0	
6	3286	188	kushal
7	0	0	
8	0	0	
9	0	0	
10	0	0	
11	0	0	
12	0	0	
13	0	0	
14	1234	111	anand
15	5655	878	raju
16	0	0	
17	9877	333	manu
18	0	0	
19	0	0	
----------------------------

1.Create Employee record
2.Display Hash Table
3.exit
enter your choice
1

Enter the KEY information: 7654

Collision Detected...!!!

Enter emp id: 666

Enter emp name: lavanya

Collision avoided successfully using LINEAR PROBING

1.Create Employee record
2.Display Hash Table
3.exit
enter your choice
2

The hash table is:
----------------------------

HTIndex	KEY	EmpID	EmpName
0	0	0	
1	0	0	
2	9882	777	uday
3	8222	888	kumar
4	0	0	
5	0	0	
6	3286	188	kushal
7	0	0	
8	0	0	
9	0	0	
10	0	0	
11	0	0	
12	0	0	
13	0	0	
14	1234	111	anand
15	5655	878	raju
16	7654	666	lavanya
17	9877	333	manu
18	0	0	
19	0	0	
----------------------------

1.Create Employee record
2.Display Hash Table
3.exit
enter your choice
1

Enter the KEY information: 4574

Collision Detected...!!!

Enter emp id: 767

Enter emp name: harish

Collision avoided successfully using LINEAR PROBING

1.Create Employee record
2.Display Hash Table
3.exit
enter your choice
2

The hash table is:
----------------------------

HTIndex	KEY	EmpID	EmpName
0	0	0	
1	0	0	
2	9882	777	uday
3	8222	888	kumar
4	0	0	
5	0	0	
6	3286	188	kushal
7	0	0	
8	0	0	
9	0	0	
10	0	0	
11	0	0	
12	0	0	
13	0	0	
14	1234	111	anand
15	5655	878	raju
16	7654	666	lavanya
17	9877	333	manu
18	4574	767	harish
19	0	0	
----------------------------

*/
