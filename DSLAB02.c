/*
2 Design, Develop and Implement a Program in C for the following operations
on Strings
a. Read a main String (STR), a Pattern String (PAT) and a Replace String
(REP)
b. Perform Pattern Matching Operation: Find and Replace all occurrences of
PAT in STR with REP if PAT exists in STR. Report suitable messages in
case PAT does not exist in STR.
Support the program with functions for each of the above operations. Don't
use Built-in functions.
*/

#include<stdio.h>
#include<stdlib.h>
char str[100],pat[20],rep[20];
int i,j,found=0,k,pos;
int slen=0,plen=0,rlen=0;
void read()
{
printf("enter main string :");
gets(str);
for(slen=0;str[slen]!='\0';slen++);
printf("enter pattern string:");
gets(pat);
for(plen=0;pat[plen]!='\0';plen++);
printf("enter replace string:");
gets(rep);
for(rlen=0;rep[rlen]!='\0';rlen++);
if(slen<plen || slen<plen)
{
printf("\nstring length is lesser matching cannot be done\n");
exit(0);
}
if(plen!=rlen)
{
printf("\npattern and replace string lengths are not equal, matching cannot be done\n");
exit(0);
}
printf("\nmain string is:%s",str);
printf("\npattern string is:%s",pat);
printf("\nreplace string is:%s",rep);
}
void matching()
{
i=j=0;
while(str[i]!='\0')
{
	j=0;
	pos=i;
	while(pat[j]!='\0')
		{
		if(str[i]==pat[j])
			{
				i++;
				j++;
			}
		else
			{
				if(str[i]==pat[0])
				break;

				else
				{		
				i++;
				break;
				}
			}
		}	
	
	if(pat[j]=='\0')
		{
			for(k=pos,j=0;rep[j]!='\0';j++,k++)
				str[k]=rep[j];
			found=1;
		}
}
}
void main()
{
read();
matching();
if(found==1)
{
printf("\npattern string found\n");
printf("\nString after replacement= %s\n",str);
}
else
printf("\npattern string not found\n");
}


/* OUTPUT1:

enter main string :mit is in mysore, mit is good  
enter pattern string:mit
enter replace string:MIT

main string is:mit is in mysore, mit is good
pattern string is:mit
replace string is:MIT
pattern string found

String after replacement= MIT is in mysore, MIT is good
-----------------------------------------------------------
OUTPUT2:

enter main string :ABCDABCDEF ABC ABC ABC ABABC AABC AAAABCCCC
enter pattern string:ABC
enter replace string:xyz

main string is:ABCDABCDEF ABC ABC ABC ABABC AABC AAAABCCCC
pattern string is:ABC
replace string is:xyz
pattern string found

String after replacement= xyzDxyzDEF xyz xyz xyz ABxyz Axyz AAAxyzCCC
*/
