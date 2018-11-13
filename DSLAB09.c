/*Design, Develop and Implement a Program in C for the following operations on Singly Circular
Linked List (SCLL) with header POLYs
a. Represent and Evaluate a Polynomial P(x,y,z) = 6x2y2z-4yz5+3x3yz+2xy5z-2xyz3
b. Find the sum of two polynomials POLY1(x,y,z) and POLY2(x,y,z) and store the result in POLYSUM(x,y,z)
Support the program with appropriate functions for each of the above operations
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct polynomial
{
int pcoff,px,py,pz,flag;
struct polynomial *next;
}POLY;


POLY* getnode()
{
POLY *x;
x=(POLY*)malloc(sizeof(POLY));
if(x==NULL)
{
printf("Insufficient memory\n"); exit(0);
}
return x;
}

POLY* rinsert(int cf,int x,int y,int z,POLY * head)
{
POLY *cur;

POLY * newterm=malloc(sizeof(POLY));
newterm->pcoff=cf;
newterm->px=x;
newterm->py=y;
newterm->pz=z;

cur=head->next;
while(cur->next!=head)
cur=cur->next;

cur->next=newterm;
newterm->next=head;

return head;
}


POLY* read_poly(POLY *head)
{
int x,y,z,cf,i,nterm;
printf("\nEnter no. of terms in polynomial: ");
scanf("%d",&nterm);
for(i=0;i<nterm;i++)
{
printf("\nEnter cof,x, y, z powers(0-indiacate NO term): ");
scanf("%d%d%d%d",&cf,&x,&y,&z);
head=rinsert(cf,x,y,z,head);
}
return head;
}



void display(POLY *head)
{
POLY *temp;


if(head->next==head)
{
printf("Polynomial does not exist\n"); 
return;
}

temp=head->next;

printf("\nPolynomial is:\n");
while(temp!=head)
{
printf("%d x^%d y^%d z^%d",temp->pcoff,temp->px,temp->py,temp->pz);
if(temp->next != head)
printf(" + ");
temp=temp->next;
}
printf("\n");
}

void evaluate(POLY *h1)
{
POLY *temp; 
int x=0, y=0, z=0,c=0;
float result=0;
temp=h1->next;
printf("\nEnter x, y, z, terms to evaluate:\n");
scanf("%d%d%d", &x, &y, &z);

while(temp!=h1)
{
result = result + (temp->pcoff * pow(x,temp->px) * pow(y,temp->py) * pow(z,temp->pz));
temp=temp->next;
c++;
}
printf("\nPolynomial result is: %f", result);
}



POLY * add_poly(POLY *h1,POLY *h2,POLY *h3)
{
POLY *p1,*p2;
int x1,x2,y1,y2,z1,z2,cf1,cf2,cf;
p1=h1->next;
while(p1!=h1)
{
x1=p1->px;
y1=p1->py;
z1=p1->pz;
cf1=p1->pcoff;
p2=h2->next;
while(p2!=h2)
{
x2=p2->px;
y2=p2->py;
z2=p2->pz;
cf2=p2->pcoff;
if(x1==x2 && y1==y2 && z1==z2)
break;
p2=p2->next;
}
if(p2!=h2)
{
cf=cf1+cf2;
p2->flag=1;
if(cf!=0)
h3=rinsert(cf,x1,y1,z1,h3);
}
else
h3=rinsert(cf1,x1,y1,z1,h3);
p1=p1->next;
}
p2=h2->next;
while(p2!=h2)
{
if(p2->flag==0)
h3=rinsert(p2->pcoff,p2->px,p2->py,p2->pz,h3);
p2=p2->next;
}
return h3;
}



void main()
{
int ch;
POLY *h1,*h2,*h3,*res;
h1=getnode();
h2=getnode();
h3=getnode();
res=getnode();
h1->next=h1;
h2->next=h2;
h3->next=h3;
res->next=res;

for(;;)
{
printf("\n1.Evaluate poly\n2.add 2 polynomials\n3.exit\nenter your choice\n");
scanf("%d",&ch);
switch(ch)

{
case 1: 
printf("\nEnter polynomial to evaluate:\n");
h1=read_poly(h1);
display(h1);
evaluate(h1);
break;

case 2:
printf("\nEnter the first polynomial:");
h2=read_poly(h2);
printf("\nEnter the second polynomial:");
h3=read_poly(h3);
res=add_poly(h2,h3,res);
printf("\nFirst polynomial is: ");
display(h2);
printf("\nSecond polynomial is: ");
display(h3);
printf("\nThe sum of 2 polynomials is: ");
display(res);
break;

case 3: exit(0);
default: printf("Invalid choice\n");
}
}
}

/*
OUTPUT

1.Evaluate poly
2.add 2 polynomials
3.exit
enter your choice
1

Enter polynomial to evaluate:

Enter no. of terms in polynomial: 3

Enter cof,x, y, z powers(0-indiacate NO term): 4
1
2
3

Enter cof,x, y, z powers(0-indiacate NO term): 5
4
3
2

Enter cof,x, y, z powers(0-indiacate NO term): -4
3
3
3

Polynomial is:
4 x^1 y^2 z^3 + 5 x^4 y^3 z^2 + -4 x^3 y^3 z^3

Enter x, y, z, terms to evaluate:
1
2
1

Polynomial result is: 24.000000


-------------------------------------------------------------------


1.Evaluate poly
2.add 2 polynomials
3.exit
enter your choice
2

Enter the first polynomial:
Enter no. of terms in polynomial: 3

Enter cof,x, y, z powers(0-indiacate NO term): 5
4
3
2

Enter cof,x, y, z powers(0-indiacate NO term): 7
6
5
4

Enter cof,x, y, z powers(0-indiacate NO term): -9
3
2
1

Enter the second polynomial:
Enter no. of terms in polynomial: 4

Enter cof,x, y, z powers(0-indiacate NO term): 4
4
3
2

Enter cof,x, y, z powers(0-indiacate NO term): 2
6
5
4

Enter cof,x, y, z powers(0-indiacate NO term): 8
5
5
5

Enter cof,x, y, z powers(0-indiacate NO term): 2
3
2
1

First polynomial is: 
Polynomial is:
5 x^4 y^3 z^2 + 7 x^6 y^5 z^4 + -9 x^3 y^2 z^1

Second polynomial is: 
Polynomial is:
4 x^4 y^3 z^2 + 2 x^6 y^5 z^4 + 8 x^5 y^5 z^5 + 2 x^3 y^2 z^1

The sum of 2 polynomials is: 
Polynomial is:
9 x^4 y^3 z^2 + 9 x^6 y^5 z^4 + -7 x^3 y^2 z^1 + 8 x^5 y^5 z^5



*/
