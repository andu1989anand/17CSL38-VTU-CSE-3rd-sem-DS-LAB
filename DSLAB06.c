/*
6. Design, Develop and Implement a menu driven Program in C for the following operations
on Circular QUEUE of Characters (Array Implementation of Queue with maximum size
MAX)
a. Insert an Element on to Circular QUEUE
b. Delete an Element from Circular QUEUE
c. Demonstrate Overflow and Underflow situations on Circular QUEUE
d. Display the status of Circular QUEUE
e. Exit
Support the program with appropriate functions for each of the above operations
*/

#include<stdio.h>
#include<stdlib.h>
#define max 5
char cq[max];
int f=-1,r=-1,ch;
char ele,del;

void insert()
{

if((f==0 && r==max-1)||(f==r+1))
printf("CIRCULAR-queue overflow\n");
else
{
getchar();
printf("enter a element:\n");
scanf("%c",&ele);

if(r==-1)
f=0;

r=(r+1)%max;
cq[r]=ele;
}
}

void delete()
{
if(f==-1&&r==-1)
printf("CIRCULAR-queue UNDERFLOW\n");

else
{
del=cq[f];
printf("deleted element:%c\n",del);
if(f==r)
f=r=-1;
else
f=(f+1)%max;
}
}

void display()
{
int i;
if(f==-1)
printf("CIRCULAR-queue EMPTY\n");
else
{
i=f;
printf("CIRCULAR-queue elements are:\n");
for(;i!=r;i=(i+1)%max)
printf("%d-->%c\n",i,cq[i]);
printf("%d-->%c\n",i,cq[r]);
}

}

void main()
{
for(;;)
{
printf("\n1.insert\n2.delete\n3.display\n4.exit\nenter your choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1: insert();break;
case 2: delete(); break;
case 3: display(); break;
case 4: exit(0);
}
}
}


/*
OUTPUT:


1.insert
2.delete
3.display
4.exit
enter your choice
1
enter a element:
A

1.insert
2.delete
3.display
4.exit
enter your choice
1
enter a element:
B

1.insert
2.delete
3.display
4.exit
enter your choice
1
enter a element:
C

1.insert
2.delete
3.display
4.exit
enter your choice
1
enter a element:
D

1.insert
2.delete
3.display
4.exit
enter your choice
1
enter a element:
E

1.insert
2.delete
3.display
4.exit
enter your choice
1
CIRCULAR-queue overflow

1.insert
2.delete
3.display
4.exit
enter your choice
3
CIRCULAR-queue elements are:
0-->A
1-->B
2-->C
3-->D
4-->E

1.insert
2.delete
3.display
4.exit
enter your choice
2
deleted element:A

1.insert
2.delete
3.display
4.exit
enter your choice
2
deleted element:B

1.insert
2.delete
3.display
4.exit
enter your choice
3
CIRCULAR-queue elements are:
2-->C
3-->D
4-->E

1.insert
2.delete
3.display
4.exit
enter your choice
1
enter a element:
W

1.insert
2.delete
3.display
4.exit
enter your choice
1
enter a element:
T

1.insert
2.delete
3.display
4.exit
enter your choice
3
CIRCULAR-queue elements are:
2-->C
3-->D
4-->E
0-->W
1-->T

1.insert
2.delete
3.display
4.exit
enter your choice
2
deleted element:C

1.insert
2.delete
3.display
4.exit
enter your choice
2
deleted element:D

1.insert
2.delete
3.display
4.exit
enter your choice
2
deleted element:E

1.insert
2.delete
3.display
4.exit
enter your choice
2
deleted element:W

1.insert
2.delete
3.display
4.exit
enter your choice
2
deleted element:T

1.insert
2.delete
3.display
4.exit
enter your choice
2
CIRCULAR-queue UNDERFLOW

1.insert
2.delete
3.display
4.exit
enter your choice
3
CIRCULAR-queue EMPTY

1.insert
2.delete
3.display
4.exit
enter your choice
     

*/
