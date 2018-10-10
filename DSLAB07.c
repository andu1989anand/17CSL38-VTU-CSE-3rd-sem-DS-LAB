/*7. Design, Develop and Implement a menu driven Program in C for the following operations
on Singly Linked List (SLL) of Student Data with the fields: USN, Name, Branch, Sem,
PhNo
a. Create a SLL of N Students Data by using front insertion.
b. Display the status of SLL and count the number of nodes in it
c. Perform Insertion / Deletion at End of SLL
d. Perform Insertion / Deletion at Front of SLL(Demonstration of stack)
e. Exit
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 10
typedef struct students
{
char usn[20],name[20],branch[10],phno[15];
int sem;
struct student *next;
}student;
student *head=NULL,*tail=NULL;

int ch,c=0;

void finsert()
{
char u[20],n[20],b[10],p[20];
int s;
if(c==max)
printf("student record full\n");

else
{
student *newstu=malloc(sizeof(student));
printf("enter student usn:");
scanf("%s",u);
printf("enter student name:");
scanf("%s",n);
printf("enter student branch:");
scanf("%s",b);
printf("enter student sem:");
scanf("%d",&s);
printf("enter student phno:");
scanf("%s",p);
strcpy(newstu->usn,u);
strcpy(newstu->name,n);
strcpy(newstu->branch,b);
newstu->sem=s;
strcpy(newstu->phno,p);
newstu->next=head;
head=newstu;
c++;
if(c==1)
tail=newstu;
}
}

void fdelete()
{
if(c==0)
printf("student record empty\n");
else
{
student *temp;
temp=head;
printf("deleted student record is:");
printf("usn:%s\n",temp->usn);
printf("name:%s\n",temp->name);
printf("branch:%s\n",temp->branch);
printf("sem:%d\n",temp->sem);
printf("phno:%s\n",temp->phno);
if(c==1)
head=tail=NULL;
else
head=head->next;
free(temp);
c--;
}
}

void rinsert()
{
char u[20],n[20],b[10],p[20];
int s;
if(c==max)
printf("student record full\n");
else
{
student *newstu=malloc(sizeof(student));
printf("enter student usn:");
scanf("%s",u);
printf("enter student name:");
scanf("%s",n);
printf("enter student branch:");
scanf("%s",b);
printf("enter student sem:");
scanf("%d",&s);
printf("enter student phno:");
scanf("%s",p);
strcpy(newstu->usn,u);
strcpy(newstu->name,n);
strcpy(newstu->branch,b);
newstu->sem=s;
strcpy(newstu->phno,p);
tail->next=newstu;
newstu->next=NULL;
tail=newstu;
c++;
}
}

void rdelete()
{
if(c==0)
printf("student record empty\n");
else
{
student *temp,*temp1;
temp=head;
temp1=tail;
printf("deleted student record is:\n");
printf("usn:%s\n",temp1->usn);
printf("name:%s\n",temp1->name);
printf("branch:%s\n",temp1->branch);
printf("sem:%d\n",temp1->sem);
printf("phno:%s\n",temp1->phno);
if(c==1)
head=tail=NULL;
else
{
while(temp->next!=tail)
temp=temp->next;
tail=temp;
tail->next=NULL;
}
free(temp1);
c--;
}
}


void display()
{
student * temp;
if(c==0)
{
printf("NO studentrecord to display\n");
return;
}
temp=head;
printf("number of student records are:%d\n",c);
printf("usn\tname\tbranch\tsem\tphno\n");
while(temp!=NULL)
{
printf("%s\t",temp->usn);
printf("%s\t",temp->name);
printf("%s\t",temp->branch);
printf("%d\t",temp->sem);
printf("%s\n",temp->phno);
temp=temp->next;
}
}

void create()
{
int n,i;
printf("enter how many students records:\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("enter student %d details:\n",i+1);
finsert();
}
}
void main()
{
for(;;)
{
printf("\n1.create from front\n2.finsert\n3.fdelete\n4.rinsert\n5.rdelete\n6.display\n7.exit\nenter your choice\n");
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


/*
OUTPUT:


1.create from front
2.finsert
3.fdelete
4.rinsert
5.rdelete
6.display
7.exit
enter your choice
1
enter how many students records:
3
enter student 1 details:
enter student usn:1
enter student name:Q
enter student branch:Q
enter student sem:1
enter student phno:1
enter student 2 details:
enter student usn:2
enter student name:W
enter student branch:W
enter student sem:2
enter student phno:2
enter student 3 details:
enter student usn:3
enter student name:E
enter student branch:E
enter student sem:3
enter student phno:3

1.create from front
2.finsert
3.fdelete
4.rinsert
5.rdelete
6.display
7.exit
enter your choice
6
number of student records are:3
usn	name	branch	sem	phno
3	E	E	3	3
2	W	W	2	2
1	Q	Q	1	1

1.create from front
2.finsert
3.fdelete
4.rinsert
5.rdelete
6.display
7.exit
enter your choice
5
deleted student record is:
usn:1
name:Q
branch:Q
sem:1
phno:1

1.create from front
2.finsert
3.fdelete
4.rinsert
5.rdelete
6.display
7.exit
enter your choice
6
number of student records are:2
usn	name	branch	sem	phno
3	E	E	3	3
2	W	W	2	2

1.create from front
2.finsert
3.fdelete
4.rinsert
5.rdelete
6.display
7.exit
enter your choice
3
deleted student record is:usn:3
name:E
branch:E
sem:3
phno:3

1.create from front
2.finsert
3.fdelete
4.rinsert
5.rdelete
6.display
7.exit
enter your choice
6
number of student records are:1
usn	name	branch	sem	phno
2	W	W	2	2

1.create from front
2.finsert
3.fdelete
4.rinsert
5.rdelete
6.display
7.exit
enter your choice
4
enter student usn:5
enter student name:t
enter student branch:t
enter student sem:5
enter student phno:5

1.create from front
2.finsert
3.fdelete
4.rinsert
5.rdelete
6.display
7.exit
enter your choice
6
number of student records are:2
usn	name	branch	sem	phno
2	W	W	2	2
5	t	t	5	5

1.create from front
2.finsert
3.fdelete
4.rinsert
5.rdelete
6.display
7.exit
enter your choice
5
deleted student record is:
usn:5
name:t
branch:t
sem:5
phno:5

1.create from front
2.finsert
3.fdelete
4.rinsert
5.rdelete
6.display
7.exit
enter your choice
5
deleted student record is:
usn:2
name:W
branch:W
sem:2
phno:2

1.create from front
2.finsert
3.fdelete
4.rinsert
5.rdelete
6.display
7.exit
enter your choice
5
student record empty

1.create from front
2.finsert
3.fdelete
4.rinsert
5.rdelete
6.display
7.exit
enter your choice
3
student record empty

1.create from front
2.finsert
3.fdelete
4.rinsert
5.rdelete
6.display
7.exit
enter your choice
6
NO studentrecord to display

1.create from front
2.finsert
3.fdelete
4.rinsert
5.rdelete
6.display
7.exit
enter your choice
6
NO studentrecord to display

1.create from front
2.finsert
3.fdelete
4.rinsert
5.rdelete
6.display
7.exit
enter your choice

*/
