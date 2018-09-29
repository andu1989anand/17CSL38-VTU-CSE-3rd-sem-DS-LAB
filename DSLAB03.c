/*Design, Develop and Implement a menu driven program in C for the following operations on
STACK of integers (Array implementation of stack with maximum size MAX)
a. Push an element on to stack
b. Pop an element from stack.
c. Demonstrate how stack can be used to check palindrome.
d. Demonstrate Overflow and Underflow situations on stack.
e. Display the status of stack.
f. Exit.
Support the program with appropriate functions for each of the above operations.

*/

#include<stdio.h>
#include<stdlib.h>
#define max 5
int ele,del,ch,top=-1,i;
int stack[max];

void push()
{

if(top==max-1)
printf("stack OVERFLOW\n");

else
{
printf("enter a element\n");
scanf("%d",&ele);
stack[++top]=ele;
}
}

void pop()
{
del=stack[top--];
}

void palindrome()
{
int pal=0,temp;
temp=top;
for(i=0;i<=top/2;i++)
{
pop();
if(stack[i]==del)
pal=1;
else
pal=0;
}
top=temp;
if(pal==1)
printf("STACK content is a palindrome\n");
else
printf("STACK content is NOT a palindrome\n");
}
void display()
{
if(top==-1)
{
printf("stack EMPTY\n");
return;
}
printf("stack ELEMENTS are:\n");
for(i=top;i>=0;i--)
printf("%d\n",stack[i]);
}


void main()
{

for(;;)
{
printf("\n1.push\n2.pop\n3.Palindrome\n4.display\n5.exit\nenter your choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1: push();break;
case 2: if(top==-1)
        printf("stack UNDERFLOW\n");
        else
        {
        pop(); 
        printf("popped =%d\n",del);
        }        
        break;
case 3: if(top==-1)
        printf("stack EMPTY, Palindrome cannot be checked\n");
        else
        palindrome();
        break;
case 4: display(); break;
case 5: exit(0);
default: printf("invalid choice\n");
}
}
}

/*
OUTPUT1:
1.push
2.pop
3.Palindrome
4.display
5.exit
enter your choice
3
stack EMPTY, Palindrome cannot be checked

1.push
2.pop
3.Palindrome
4.display
5.exit
enter your choice
4
stack EMPTY

1.push
2.pop
3.Palindrome
4.display
5.exit
enter your choice
-----------------------------
OUTPUT2:
1.push
2.pop
3.Palindrome
4.display
5.exit
enter your choice
1   
enter a element
1

1.push
2.pop
3.Palindrome
4.display
5.exit
enter your choice
1
enter a element
2

1.push
2.pop
3.Palindrome
4.display
5.exit
enter your choice
1
enter a element
3

1.push
2.pop
3.Palindrome
4.display
5.exit
enter your choice
4
stack ELEMENTS are:
3
2
1

1.push
2.pop
3.Palindrome
4.display
5.exit
enter your choice
1
enter a element
4

1.push
2.pop
3.Palindrome
4.display
5.exit
enter your choice
1
enter a element
5

1.push
2.pop
3.Palindrome
4.display
5.exit
enter your choice
1
stack OVERFLOW

1.push
2.pop
3.Palindrome
4.display
5.exit
enter your choice
4
stack ELEMENTS are:
5
4
3
2
1

1.push
2.pop
3.Palindrome
4.display
5.exit
enter your choice
3
STACK content is NOT a palindrome

1.push
2.pop
3.Palindrome
4.display
5.exit
enter your choice
2
popped =5

1.push
2.pop
3.Palindrome
4.display
5.exit
enter your choice
2
popped =4

1.push
2.pop
3.Palindrome
4.display
5.exit
enter your choice
2
popped =3

1.push
2.pop
3.Palindrome
4.display
5.exit
enter your choice
4
stack ELEMENTS are:
2
1

1.push
2.pop
3.Palindrome
4.display
5.exit
enter your choice
1
enter a element
1

1.push
2.pop
3.Palindrome
4.display
5.exit
enter your choice
3
STACK content is a palindrome

1.push
2.pop
3.Palindrome
4.display
5.exit
enter your choice
4
stack ELEMENTS are:
1
2
1

1.push
2.pop
3.Palindrome
4.display
5.exit
enter your choice
--------------------------
*/
