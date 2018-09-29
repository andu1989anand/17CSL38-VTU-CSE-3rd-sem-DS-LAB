/*Design, Develop and Implement a Program in C for the following Stack Applications 
a. Evaluation of Suffix expression with single digit operands and operators: +, -, *, /, %, ^ 
b. Solving Tower of Hanoi problem with n disks*/

#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#define MAX 50            /* Size of Stack */

char post[50];
int s[MAX],op1,op2,res;
int top=-1;       /* Global declarations */
 
void push(int num)
{                       /* Function for PUSH operation */
    s[++top]=num;
}
 
int pop()
{                      /* Function for POP operation */
    return(s[top--]);
}
 
int eva(char ch,int op1,int op2)
{                 /* Function for precedence */
    switch(ch)
    {
    
    case '+': return op1+op2;
		
    case '-': return op1-op2;
		
    case '*': return op1*op2;
		
    case '/': if(op2==0)
                { 
                   printf("arthimatic error, result cannot be computed\n\n");
                   exit(0);
                } 
               else
                return op1/op2;
		
    case '%': 
            if(op2==0)
                { 
                   printf("modulus error, result cannot be computed\n\n");
                   exit(0);
                } 
            return op1%op2;
		
    case '^': return pow(op1,op2);

    default: printf("Invalid operator\n\n");
             exit(0);
		
    }
}

void main()
{                         /* Main Program */
   
    int i=0;
    char ch;
    printf("\n\nEnter the Postfix Expression:");
    scanf("%s",post);
   
    while( (ch=post[i++]) != '\0')
    {
        if(isalpha(ch))
        {
        printf("invalid expression\n");
        exit(0);
        }        

        if(isdigit(ch))
	    push(ch-'0');
	
	  else
	{
	op2=pop();	
	op1=pop();
	res=eva(ch,op1,op2);
	s[++top]=res;
}
}
        
printf("\n\n Postfix Expression: %s\n",post);
printf("\n\n Result: %d\n",s[top]);
}


/*OUTPUT1:
Enter the Postfix Expression:1234+-*


 Postfix Expression: 1234+-*


 Result: -5
------------------------------------------
OUTPUT2:
Enter the Postfix Expression:1234+++


 Postfix Expression: 1234+++


 Result: 10
------------------------------------------
OUTPUT3:
Enter the Postfix Expression:13*563%-/45/+


 Postfix Expression: 13*563%-/45/+


 Result: 0
------------------------------------------
OUTPUT4:
Enter the Postfix Expression:10/
arthimatic error, result cannot be computed
------------------------------------------
Enter the Postfix Expression:123*&
Invalid operator
-------------------------------------------
Enter the Postfix Expression:123+-bc+
invalid expression
-------------------------------------------
Enter the Postfix Expression:95%


 Postfix Expression: 95%


 Result: 4
-------------------------------------------*/
