/*1. Design, Develop and Implement a menu driven program in C for the following Array operations
a. Creating Array of N Integer elements.
b. Display of Array elements with suitable headings.
c. Inserting an element (ELEM) at a given valid position (POS).
d. Deleting an element at a given valid position (POS).
e. Exit.
Support the program with functions for each of the above operations.
*/

#include<stdio.h>
#include<stdlib.h>

int a[20], n, elem, i, pos;

void create()

{
printf("\nEnter the size of the array elements: ");
scanf("%d", &n);
printf("\nEnter the elements for the array:\n");
for(i=0; i<n; i++)
scanf("%d", &a[i]);
}


void display()
{
int i;
if(n>0)
{
printf("\nThe array elements are:\n");
for(i=0; i<n; i++)
printf("%d\t", a[i]);
}
else
printf("\n Array is empty\n");
}

void insert() 
{

printf("\nEnter the position for the new element: ");
scanf("%d", &pos);
pos=pos-1;
if(pos<=n)
{
printf("\nEnter the element to be inserted: ");
scanf("%d", &elem);
for(i=n-1; i>=pos; i--)
a[i+1] = a[i];

a[pos] = elem;
n = n+1;
}
else
printf("\nEnter valid position\n");
}

void del()
{

printf("\nEnter the position of the element to be deleted: ");
scanf("%d", &pos);
pos=pos-1;
if(pos<n && pos>=0)
{
elem = a[pos];
for(i=pos; i<n-1; i++)
{
a[i] = a[i+1];
}
n = n-1;
printf("\nThe deleted element is = %d", elem);
}
else
printf("\nEnter valid position\n");
}

void main()
{
int ch;
for(;;)
{
printf("\n\n--------Menu-----------\n");
printf("1.Create\n 2.Display\n 3.Insert\n 4.Delete\n 5.Exit\n");
printf("-------------------------------");
printf("\nEnter your choice: ");
scanf("%d", &ch);
switch(ch)
{
case 1: create();
break;
case 2: display();
break;
case 3: insert();
break;
case 4: del();
break;
case 5: exit(0);
break;
default: printf("\nInvalid choice:\n");
break;
}
}
}


/*
OUTPUT:

--------Menu-----------
1.Create
 2.Display
 3.Insert
 4.Delete
 5.Exit
-------------------------------
Enter your choice: 1

Enter the size of the array elements: 3

Enter the elements for the array:
1
2
3


--------Menu-----------
1.Create
 2.Display
 3.Insert
 4.Delete
 5.Exit
-------------------------------
Enter your choice: 2

The array elements are:
1	2	3	

--------Menu-----------
1.Create
 2.Display
 3.Insert
 4.Delete
 5.Exit
-------------------------------
Enter your choice: 3

Enter the position for the new element: 2

Enter the element to be inserted: 22


--------Menu-----------
1.Create
 2.Display
 3.Insert
 4.Delete
 5.Exit
-------------------------------
Enter your choice: 2

The array elements are:
1	22	2	3	

--------Menu-----------
1.Create
 2.Display
 3.Insert
 4.Delete
 5.Exit
-------------------------------
Enter your choice: 3

Enter the position for the new element: 1

Enter the element to be inserted: 11


--------Menu-----------
1.Create
 2.Display
 3.Insert
 4.Delete
 5.Exit
-------------------------------
Enter your choice: 2

The array elements are:
11	1	22	2	3	

--------Menu-----------
1.Create
 2.Display
 3.Insert
 4.Delete
 5.Exit
-------------------------------
Enter your choice: 3

Enter the position for the new element: 5

Enter the element to be inserted: 55


--------Menu-----------
1.Create
 2.Display
 3.Insert
 4.Delete
 5.Exit
-------------------------------
Enter your choice: 2

The array elements are:
11	1	22	2	55	3	

--------Menu-----------
1.Create
 2.Display
 3.Insert
 4.Delete
 5.Exit
-------------------------------
Enter your choice: 3

Enter the position for the new element: 7

Enter the element to be inserted: 77


--------Menu-----------
1.Create
 2.Display
 3.Insert
 4.Delete
 5.Exit
-------------------------------
Enter your choice: 2

The array elements are:
11	1	22	2	55	3	77	

--------Menu-----------
1.Create
 2.Display
 3.Insert
 4.Delete
 5.Exit
-------------------------------
Enter your choice: 3

Enter the position for the new element: 9

Enter valid position


--------Menu-----------
1.Create
 2.Display
 3.Insert
 4.Delete
 5.Exit
-------------------------------
Enter your choice: 3

Enter the position for the new element: 15

Enter valid position


--------Menu-----------
1.Create
 2.Display
 3.Insert
 4.Delete
 5.Exit
-------------------------------
Enter your choice: 2

The array elements are:
11	1	22	2	55	3	77	

--------Menu-----------
1.Create
 2.Display
 3.Insert
 4.Delete
 5.Exit
-------------------------------
Enter your choice: 4

Enter the position of the element to be deleted: 1

The deleted element is = 11

--------Menu-----------
1.Create
 2.Display
 3.Insert
 4.Delete
 5.Exit
-------------------------------
Enter your choice: 2

The array elements are:
1	22	2	55	3	77	

--------Menu-----------
1.Create
 2.Display
 3.Insert
 4.Delete
 5.Exit
-------------------------------
Enter your choice: 3

Enter the position for the new element: 4

Enter the element to be inserted: 44


--------Menu-----------
1.Create
 2.Display
 3.Insert
 4.Delete
 5.Exit
-------------------------------
Enter your choice: 2

The array elements are:
1	22	2	44	55	3	77	

--------Menu-----------
1.Create
 2.Display
 3.Insert
 4.Delete
 5.Exit
-------------------------------
Enter your choice: 4

Enter the position of the element to be deleted: 4

The deleted element is = 44

--------Menu-----------
1.Create
 2.Display
 3.Insert
 4.Delete
 5.Exit
-------------------------------
Enter your choice: 2

The array elements are:
1	22	2	55	3	77	

--------Menu-----------
1.Create
 2.Display
 3.Insert
 4.Delete
 5.Exit
-------------------------------
Enter your choice: 4

Enter the position of the element to be deleted: 4

The deleted element is = 55

--------Menu-----------
1.Create
 2.Display
 3.Insert
 4.Delete
 5.Exit
-------------------------------
Enter your choice: 2

The array elements are:
1	22	2	3	77	

--------Menu-----------
1.Create
 2.Display
 3.Insert
 4.Delete
 5.Exit
-------------------------------
Enter your choice: 4

Enter the position of the element to be deleted: 5

The deleted element is = 77

--------Menu-----------
1.Create
 2.Display
 3.Insert
 4.Delete
 5.Exit
-------------------------------
Enter your choice: 2

The array elements are:
1	22	2	3	

--------Menu-----------
1.Create
 2.Display
 3.Insert
 4.Delete
 5.Exit
-------------------------------
Enter your choice: 3

Enter the position for the new element: 6

Enter valid position


--------Menu-----------
1.Create
 2.Display
 3.Insert
 4.Delete
 5.Exit
-------------------------------
Enter your choice: 4

Enter the position of the element to be deleted: 9

Enter valid position


--------Menu-----------
1.Create
 2.Display
 3.Insert
 4.Delete
 5.Exit
-------------------------------
Enter your choice: 2

The array elements are:
1	22	2	3	

--------Menu-----------
1.Create
 2.Display
 3.Insert
 4.Delete
 5.Exit
-------------------------------
Enter your choice: 4

Enter the position of the element to be deleted: 2

The deleted element is = 22

--------Menu-----------
1.Create
 2.Display
 3.Insert
 4.Delete
 5.Exit
-------------------------------
Enter your choice: 2

The array elements are:
1	2	3	


--------Menu-----------
1.Create
 2.Display
 3.Insert
 4.Delete
 5.Exit
-------------------------------
Enter your choice: 4

Enter the position of the element to be deleted: 1

The deleted element is = 1

--------Menu-----------
1.Create
 2.Display
 3.Insert
 4.Delete
 5.Exit
-------------------------------
Enter your choice: 4

Enter the position of the element to be deleted: 1

The deleted element is = 2

--------Menu-----------
1.Create
 2.Display
 3.Insert
 4.Delete
 5.Exit
-------------------------------
Enter your choice: 2

The array elements are:
3	

--------Menu-----------
1.Create
 2.Display
 3.Insert
 4.Delete
 5.Exit
-------------------------------
Enter your choice: 4

Enter the position of the element to be deleted: 1

The deleted element is = 3

--------Menu-----------
1.Create
 2.Display
 3.Insert
 4.Delete
 5.Exit
-------------------------------
Enter your choice: 2

 Array is empty

--------Menu-----------
1.Create
 2.Display
 3.Insert
 4.Delete
 5.Exit
-------------------------------
Enter your choice: 1

Enter the size of the array elements: 3

Enter the elements for the array:
1
2
3


--------Menu-----------
1.Create
 2.Display
 3.Insert
 4.Delete
 5.Exit
-------------------------------
Enter your choice: 2

The array elements are:
1	2	3	

--------Menu-----------
1.Create
 2.Display
 3.Insert
 4.Delete
 5.Exit
-------------------------------
Enter your choice: 4

Enter the position of the element to be deleted: 7

Enter valid position


--------Menu-----------
1.Create
 2.Display
 3.Insert
 4.Delete
 5.Exit
-------------------------------
Enter your choice: 4

Enter the position of the element to be deleted: 0

Enter valid position


--------Menu-----------
1.Create
 2.Display
 3.Insert
 4.Delete
 5.Exit
-------------------------------
Enter your choice: 4

Enter the position of the element to be deleted: -9

Enter valid position


--------Menu-----------
1.Create
 2.Display
 3.Insert
 4.Delete
 5.Exit
-------------------------------
Enter your choice: 4

Enter the position of the element to be deleted: 0

Enter valid position


--------Menu-----------
1.Create
 2.Display
 3.Insert
 4.Delete
 5.Exit
-------------------------------
Enter your choice: 4

Enter the position of the element to be deleted: 1

The deleted element is = 1

--------Menu-----------
1.Create
 2.Display
 3.Insert
 4.Delete
 5.Exit
-------------------------------
Enter your choice: 2

The array elements are:
2	3	

--------Menu-----------
1.Create
 2.Display
 3.Insert
 4.Delete
 5.Exit
-------------------------------
Enter your choice: 4

Enter the position of the element to be deleted: 1

The deleted element is = 2

--------Menu-----------
1.Create
 2.Display
 3.Insert
 4.Delete
 5.Exit
-------------------------------
Enter your choice: 4

Enter the position of the element to be deleted: 1

The deleted element is = 3

--------Menu-----------
1.Create
 2.Display
 3.Insert
 4.Delete
 5.Exit
-------------------------------
Enter your choice: 4

Enter the position of the element to be deleted: 1

Enter valid position


--------Menu-----------
1.Create
 2.Display
 3.Insert
 4.Delete
 5.Exit
-------------------------------
Enter your choice: 4

Enter the position of the element to be deleted: 1

Enter valid position


--------Menu-----------
1.Create
 2.Display
 3.Insert
 4.Delete
 5.Exit
-------------------------------
Enter your choice: 4

Enter the position of the element to be deleted: 5

Enter valid position




*/
