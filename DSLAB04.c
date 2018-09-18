/*Lab Program 04: 
Design, Develop and Implement a Program in C for converting an Infix Expression to Postfix
Expression. Program should support for both parenthesized and free parenthesized expressions with the
operators: +, -, *, /, %( Remainder), ^ (Power) and alphanumeric operands.*/


#include<stdio.h>
#define SIZE 50            /* Size of Stack */
#include <ctype.h>
char s[SIZE];
int top=-1;       /* Global declarations */
 
void push(char elem)
{                       /* Function for PUSH operation */
    s[++top]=elem;
}
 
char pop()
{                      /* Function for POP operation */
    return(s[top--]);
}
 
int pr(char elem)
{                 /* Function for precedence */
    switch(elem)
    {
    case '#': return 0;
    case '(': return 1;
    case '+':
    case '-': return 2;
    case '*':
    case '/': return 3;
    case '$':
    case '^': return 4;
    }
}
 
void main()
{                         /* Main Program */
    char infx[50],pofx[50],ch,elem;
    int i=0,k=0;
    printf("\n\nEnter the Infix Expression:");
    scanf("%s",infx);
    push('#');
    while( (ch=infx[i++]) != '\0')
    {
        if( ch == '(') push(ch);
        else if(isalnum(ch)) pofx[k++]=ch;
        else if( ch == ')')
                {
                    while( s[top] != '(')
                        pofx[k++]=pop();
                    elem=pop(); /* Remove ( */
                }
                else
                {       /* Operator */
                    while( pr(s[top]) >= pr(ch) )
                        pofx[k++]=pop();
                    push(ch);
                }
    }
    while( s[top] != '#')     /* Pop from stack till empty */
        pofx[k++]=pop();
    pofx[k]='\0';          /* Make pofx as valid string */
    printf("\n\nGiven Infix Expression: %s  \n Postfix Expression: %s\n",infx,pofx);
}


/*
OUTPUT1:

Enter the Infix Expression:a+b*(c/d)^e-f


Given Infix Expression: a+b*(c/d)^e-f  
 Postfix Expression: abcd/e^*+f-


OUTPUT2:
Enter the Infix Expression:1*3/(5-6%3)+4/5


Given Infix Expression: 1*3/(5-6%3)+4/5  
 Postfix Expression: 13*563%-/45/+
*/
