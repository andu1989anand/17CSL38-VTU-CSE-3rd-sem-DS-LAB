/*
11.
Design, Develop and Implement a Program in C for the following operations on Graph(G) of Cities
a. Create a Graph of N cities using Adjacency Matrix.
b. Print all the nodes reachable from a given starting node in a digraph using BFS method
c. Check whether a given graph is connected or not using DFS method.
*/

#include<stdio.h>
#include<stdlib.h>

int a[10][10], n, source, b[10]={0};

void create()
{
int i,j;
printf("\nEnter the number of vertices of the digraph: ");
scanf("%d", &n);
printf("\nEnter the adjacency matrix of the graph:\n");
for(i=0; i<n; i++)
for(j=0; j<n; j++)
scanf("%d", &a[i][j]);

printf("\nthe adjacency matrix of the graph:\n");
for(i=0; i<n; i++)
{
for(j=0; j<n; j++)
printf("%d  ", a[i][j]);
printf("\n");
}
}


void bfs()
{
int q[10], u, front=0, rear=-1,i;
int visited[10]={0};
printf("\nEnter the source vertex to find other nodes reachable or not: ");
scanf("%d", &source);
q[++rear] = source;
visited[source] = 1;

printf("\nThe reachable vertices are: ");
while(front<=rear)
{
u = q[front++];
for(i=0; i<n; i++)
{
if(a[u][i] == 1 && visited[i] == 0)
{
q[++rear] = i;
visited[i] = 1;
printf("\n%d-->%d",u,i);
}
}
}

for(i=0;i<n;i++)
{
if(i==source)
continue;
if(visited[i]==1)
printf("\nThe vertex %d is reachable from source node %d\n",i,source);
else
printf("\nThe vertex %d is  not reachable from source node %d\n",i,source);
}
}

void dfs(int source)
{
int i, top = -1;
b[source] = 1;
for(i=0; i<n; i++)
{
if(a[source][i] == 1 && b[i] == 0)
{
printf("\n%d -> %d", source, i);
dfs(i);
}
}
}
void main()
{
int ch,i;
while(1)
{
printf("\n1.Create Graph\n2.BFS\n3.DFS\n4.Exit");
printf("\nEnter your choice: ");
scanf("%d", &ch);
switch(ch)
{
case 1: create(); break;

case 2: bfs();  break;

case 3: printf("\nEnter the source vertex: ");
scanf("%d",&source);
for(i=0;i<n;i++)
b[i]=0;

dfs(source);

for(i=0;i<n;i++)
{
if(i==source)
continue;
if(b[i]==1)
printf("\nThe vertex %d is reachable from source node %d\n",i,source);
else
printf("\nThe vertex %d is  not reachable from source node %d\n",i,source);
}

break;
case 4:exit(0);

default: printf("enter a valid choice\n");
}
}
}


/*OUTPUT

1.Create Graph
2.BFS
3.DFS
4.Exit
Enter your choice: 1

Enter the number of vertices of the digraph: 6

Enter the adjacency matrix of the graph:
0  1  0  0  0  0  
0  0  1  0  0  0  
0  0  0  0  1  0  
0  0  1  0  0  1  
0  1  0  1  0  0  
1  0  0  0  0  0  

the adjacency matrix of the graph:
0  1  0  0  0  0  
0  0  1  0  0  0  
0  0  0  0  1  0  
0  0  1  0  0  1  
0  1  0  1  0  0  
1  0  0  0  0  0  

1.Create Graph
2.BFS
3.DFS
4.Exit
Enter your choice: 2

Enter the source vertex to find other nodes reachable or not: 0

The reachable vertices are: 
0-->1
1-->2
2-->4
4-->3
3-->5
The vertex 1 is reachable from source node 0

The vertex 2 is reachable from source node 0

The vertex 3 is reachable from source node 0

The vertex 4 is reachable from source node 0

The vertex 5 is reachable from source node 0

1.Create Graph
2.BFS
3.DFS
4.Exit
Enter your choice: 2

Enter the source vertex to find other nodes reachable or not: 4

The reachable vertices are: 
4-->1
4-->3
1-->2
3-->5
5-->0
The vertex 0 is reachable from source node 4

The vertex 1 is reachable from source node 4

The vertex 2 is reachable from source node 4

The vertex 3 is reachable from source node 4

The vertex 5 is reachable from source node 4

1.Create Graph
2.BFS
3.DFS
4.Exit
Enter your choice: 3

Enter the source vertex: 5

5 -> 0
0 -> 1
1 -> 2
2 -> 4
4 -> 3
The vertex 0 is reachable from source node 5

The vertex 1 is reachable from source node 5

The vertex 2 is reachable from source node 5

The vertex 3 is reachable from source node 5

The vertex 4 is reachable from source node 5

1.Create Graph
2.BFS
3.DFS
4.Exit
Enter your choice: 3

Enter the source vertex: 3

3 -> 2
2 -> 4
4 -> 1
3 -> 5
5 -> 0
The vertex 0 is reachable from source node 3

The vertex 1 is reachable from source node 3

The vertex 2 is reachable from source node 3

The vertex 4 is reachable from source node 3

The vertex 5 is reachable from source node 3

1.Create Graph
2.BFS
3.DFS
4.Exit
Enter your choice: 
------------------------------------------------------
1.Create Graph
2.BFS
3.DFS
4.Exit
Enter your choice: 1       

Enter the number of vertices of the digraph: 5

Enter the adjacency matrix of the graph:
0 1 0 0 1
0 0 0 0 1
0 1 0 0 0
0 0 1 0 1
0 0 1 0 0

the adjacency matrix of the graph:
0  1  0  0  1  
0  0  0  0  1  
0  1  0  0  0  
0  0  1  0  1  
0  0  1  0  0  

1.Create Graph
2.BFS
3.DFS
4.Exit
Enter your choice: 2

Enter the source vertex to find other nodes reachable or not: 0

The reachable vertices are: 
0-->1
0-->4
4-->2
The vertex 1 is reachable from source node 0

The vertex 2 is reachable from source node 0

The vertex 3 is  not reachable from source node 0

The vertex 4 is reachable from source node 0

1.Create Graph
2.BFS
3.DFS
4.Exit
Enter your choice: 2

Enter the source vertex to find other nodes reachable or not: 1

The reachable vertices are: 
1-->4
4-->2
The vertex 0 is  not reachable from source node 1

The vertex 2 is reachable from source node 1

The vertex 3 is  not reachable from source node 1

The vertex 4 is reachable from source node 1

1.Create Graph
2.BFS
3.DFS
4.Exit
Enter your choice: 3

Enter the source vertex: 0

0 -> 1
1 -> 4
4 -> 2
The vertex 1 is reachable from source node 0

The vertex 2 is reachable from source node 0

The vertex 3 is  not reachable from source node 0

The vertex 4 is reachable from source node 0

1.Create Graph
2.BFS
3.DFS
4.Exit
Enter your choice: 3

Enter the source vertex: 1

1 -> 4
4 -> 2
The vertex 0 is  not reachable from source node 1

The vertex 2 is reachable from source node 1

The vertex 3 is  not reachable from source node 1

The vertex 4 is reachable from source node 1

1.Create Graph
2.BFS
3.DFS
4.Exit
Enter your choice: 3

Enter the source vertex: 3

3 -> 2
2 -> 1
1 -> 4
The vertex 0 is  not reachable from source node 3

The vertex 1 is reachable from source node 3

The vertex 2 is reachable from source node 3

The vertex 4 is reachable from source node 3

*/
