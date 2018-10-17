/*8. Design, Develop and Implement a menu driven Program in C for the following operations on
Doubly Linked List (DLL) of Employee Data with the fields: SSN, Name, Dept, Designation, Sal,
PhNo.
a. Create a DLL of N Employees Data by using end insertion.
b. Display the status of DLL and count the number of nodes in it
c. Perform Insertion and Deletion at End of DLL
d. Perform Insertion and Deletion at Front of DLL
emp. Demonstrate how this DLL can be used as Double Ended Queue
f. Exit
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 5
typedef struct employee
{
char ssn[20],name[20],dept[10],des[10],phno[15];
int sal;
struct employee *next;
struct employee *pre;
}emp;

emp *head=NULL,*tail=NULL;

int ch,c=0;

emp * createemp()
{
char u[20],n[20],b[10],d[10],p[20];
int s;
printf("Front Insert\n");
emp *newemp=malloc(sizeof( emp));
printf("enter emp ssn:");
scanf("%s",u);
printf("enter emp name:");
scanf("%s",n);
printf("enter emp dept:");
scanf("%s",b);
printf("enter emp designation:");
scanf("%s",d);
printf("enter emp sal:");
scanf("%d",&s);
printf("enter emp phno:");
scanf("%s",p);
strcpy(newemp->ssn,u);
strcpy(newemp->name,n);
strcpy(newemp->dept,b);
strcpy(newemp->des,d);
newemp->sal=s;
strcpy(newemp->phno,p);
return newemp;
}

void deleteemp(emp *temp)
{
printf("deleted emp record is:");
printf("ssn:%s\n",temp->ssn);
printf("name:%s\n",temp->name);
printf("dept:%s\n",temp->dept);
printf("dept:%s\n",temp->des);
printf("sal:%d\n",temp->sal);
printf("phno:%s\n",temp->phno);
}

void finsert()
{

if(c==max)
printf("emp record full\n");

else
{
emp *newemp=NULL;
newemp=createemp();
if(c==0)
tail=newemp;
else
{
head->pre=newemp;
newemp->next=head;
newemp->pre=NULL;
}
head=newemp;
c++;
}
}

void fdelete()
{
if(c==0)
printf("emp record empty\n");
else
{
printf("Front Delete\n");
emp *temp;
temp=head;
deleteemp(temp);

if(c==1)
head=tail=NULL;
else
{
head=head->next;
head->pre=NULL;
}
free(temp);
c--;
}
}

void rinsert()
{
if(c==max)
printf("emp record full\n");
else
{
emp *newemp=NULL;
newemp=createemp();

if(c==0)
head=newemp;

else
{
tail->next=newemp;
newemp->pre=tail;
newemp->next=NULL;
}

tail=newemp;
c++;
}
}

void rdelete()
{
if(c==0)
printf("emp record empty\n");
else
{
printf("Rear Delete\n");
 emp *temp;
temp=tail;
deleteemp(temp);
if(c==1)
head=tail=NULL;
else
{
tail=tail->pre;
tail->next=NULL;
}
free(temp);
c--;
}
}


void display()
{
emp * temp;
if(c==0)
{
printf("NO emp record to display\n");
return;
}
temp=head;
printf("number of emp records are:%d\n",c);
printf("ssn\tname\tdept\tdes\tsal\tphno\n");
while(temp!=NULL)
{
printf("%s\t",temp->ssn);
printf("%s\t",temp->name);
printf("%s\t",temp->dept);
printf("%s\t",temp->des);
printf("%d\t",temp->sal);
printf("%s\n",temp->phno);
temp=temp->next;
}
}

void create()
{
int n,i;
printf("enter how many emps records:\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("enter emp %d details:\n",i+1);
rinsert();
}
}
void main()
{
for(;;)
{
printf("\n1.create from rear\n2.finsert\n3.fdelete\n4.rinsert\n5.rdelete\n6.display\n7.exit\nenter your choice\n");
scanf("%d",&ch);
switch(ch)

{
case 1: create();
break;
case 2: finsert();
break;
case 3:fdelete();
break;
case 4: rinsert();
break;
case 5: rdelete();
break;
case 6: display();
break;
case 7: exit(0);
default: printf("Invalid choice\n");
}
}
}


/*OUTPUT

1.create from rear
2.finsert
3.fdelete
4.rinsert
5.rdelete
6.display
7.exit
enter your choice
1
enter how many emps records:
1
enter emp 1 details:
Front Insert
enter emp ssn:1
enter emp name:1
enter emp dept:1
enter emp designation:1
enter emp sal:1
enter emp phno:1

1.create from rear
2.finsert
3.fdelete
4.rinsert
5.rdelete
6.display
7.exit
enter your choice
6
number of emp records are:1
ssn	name	dept	des	sal	phno
1	1	1	1	1	1

1.create from rear
2.finsert
3.fdelete
4.rinsert
5.rdelete
6.display
7.exit
enter your choice
4
Front Insert
enter emp ssn:2
enter emp name:2
enter emp dept:2
enter emp designation:2
enter emp sal:2
enter emp phno:2

1.create from rear
2.finsert
3.fdelete
4.rinsert
5.rdelete
6.display
7.exit
enter your choice
6
number of emp records are:2
ssn	name	dept	des	sal	phno
1	1	1	1	1	1
2	2	2	2	2	2

1.create from rear
2.finsert
3.fdelete
4.rinsert
5.rdelete
6.display
7.exit
enter your choice
2
Front Insert
enter emp ssn:3
enter emp name:3
enter emp dept:3
enter emp designation:3
enter emp sal:3
enter emp phno:3

1.create from rear
2.finsert
3.fdelete
4.rinsert
5.rdelete
6.display
7.exit
enter your choice
6
number of emp records are:3
ssn	name	dept	des	sal	phno
3	3	3	3	3	3
1	1	1	1	1	1
2	2	2	2	2	2

1.create from rear
2.finsert
3.fdelete
4.rinsert
5.rdelete
6.display
7.exit
enter your choice
4
Front Insert
enter emp ssn:4
enter emp name:4
enter emp dept:4
enter emp designation:4
enter emp sal:4
enter emp phno:4

1.create from rear
2.finsert
3.fdelete
4.rinsert
5.rdelete
6.display
7.exit
enter your choice
6
number of emp records are:4
ssn	name	dept	des	sal	phno
3	3	3	3	3	3
1	1	1	1	1	1
2	2	2	2	2	2
4	4	4	4	4	4

1.create from rear
2.finsert
3.fdelete
4.rinsert
5.rdelete
6.display
7.exit
enter your choice
4
Front Insert
enter emp ssn:5
enter emp name:5
enter emp dept:5
enter emp designation:5
enter emp sal:5
enter emp phno:5

1.create from rear
2.finsert
3.fdelete
4.rinsert
5.rdelete
6.display
7.exit
enter your choice
6
number of emp records are:5
ssn	name	dept	des	sal	phno
3	3	3	3	3	3
1	1	1	1	1	1
2	2	2	2	2	2
4	4	4	4	4	4
5	5	5	5	5	5

1.create from rear
2.finsert
3.fdelete
4.rinsert
5.rdelete
6.display
7.exit
enter your choice
4
emp record full

1.create from rear
2.finsert
3.fdelete
4.rinsert
5.rdelete
6.display
7.exit
enter your choice
2
emp record full

1.create from rear
2.finsert
3.fdelete
4.rinsert
5.rdelete
6.display
7.exit
enter your choice
1
enter how many emps records:
1
enter emp 1 details:
emp record full

1.create from rear
2.finsert
3.fdelete
4.rinsert
5.rdelete
6.display
7.exit
enter your choice
6
number of emp records are:5
ssn	name	dept	des	sal	phno
3	3	3	3	3	3
1	1	1	1	1	1
2	2	2	2	2	2
4	4	4	4	4	4
5	5	5	5	5	5

1.create from rear
2.finsert
3.fdelete
4.rinsert
5.rdelete
6.display
7.exit
enter your choice
5
Rear Delete
deleted emp record is:ssn:5
name:5
dept:5
dept:5
sal:5
phno:5

1.create from rear
2.finsert
3.fdelete
4.rinsert
5.rdelete
6.display
7.exit
enter your choice
5
Rear Delete
deleted emp record is:ssn:4
name:4
dept:4
dept:4
sal:4
phno:4

1.create from rear
2.finsert
3.fdelete
4.rinsert
5.rdelete
6.display
7.exit
enter your choice
6
number of emp records are:3
ssn	name	dept	des	sal	phno
3	3	3	3	3	3
1	1	1	1	1	1
2	2	2	2	2	2

1.create from rear
2.finsert
3.fdelete
4.rinsert
5.rdelete
6.display
7.exit
enter your choice
3
Front Delete
deleted emp record is:ssn:3
name:3
dept:3
dept:3
sal:3
phno:3

1.create from rear
2.finsert
3.fdelete
4.rinsert
5.rdelete
6.display
7.exit
enter your choice
6
number of emp records are:2
ssn	name	dept	des	sal	phno
1	1	1	1	1	1
2	2	2	2	2	2

1.create from rear
2.finsert
3.fdelete
4.rinsert
5.rdelete
6.display
7.exit
enter your choice
3
Front Delete
deleted emp record is:ssn:1
name:1
dept:1
dept:1
sal:1
phno:1

1.create from rear
2.finsert
3.fdelete
4.rinsert
5.rdelete
6.display
7.exit
enter your choice
3
Front Delete
deleted emp record is:ssn:2
name:2
dept:2
dept:2
sal:2
phno:2

1.create from rear
2.finsert
3.fdelete
4.rinsert
5.rdelete
6.display
7.exit
enter your choice
3
emp record empty

1.create from rear
2.finsert
3.fdelete
4.rinsert
5.rdelete
6.display
7.exit
enter your choice
5
emp record empty

1.create from rear
2.finsert
3.fdelete
4.rinsert
5.rdelete
6.display
7.exit
enter your choice
6
NO emp record to display

1.create from rear
2.finsert
3.fdelete
4.rinsert
5.rdelete
6.display
7.exit
enter your choice


                                    
*/
