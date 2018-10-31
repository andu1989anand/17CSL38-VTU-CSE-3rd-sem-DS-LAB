/*
10.  Design, Develop and Implement a menu driven Program in C for the following operations on Binary
Search Tree (node) of Integers
a. Create a node of N Integers: 6, 9, 5, 2, 8, 15, 24, 14, 7, 8, 5, 2
b. Traverse the node in Inorder, Preorder and Post Order
c. Search the node for a given element (KEY) and report the appropriate message
d. Exit
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
int data;
struct node *left;
struct node *right;
};
typedef struct node BST;
BST *root=NULL;

BST* createtree(BST *root, int data)
{
if (root == NULL)
{
BST *newnode=malloc(sizeof(BST));
newnode->data = data;
newnode->left = newnode->right = NULL;
return newnode;
}

if (data < (root->data))
root->left = createtree(root->left, data);

else if (data > root->data)
root -> right = createtree(root->right, data);

return root;
}

BST* search(BST *root, int data)
{
if(root == NULL)
printf("\nElement not found");
else if(data < root->data)
root->left=search(root->left, data);

else if(data > root->data)
root->right=search(root->right, data);

else
printf("\nElement found is: %d", root->data);

return root;
}

void inorder(BST *root)
{
if(root != NULL)
{
inorder(root->left);
printf("%d\t", root->data);
inorder(root->right);
}
}


void preorder(BST *root)
{
if(root != NULL)
{
printf("%d\t", root->data);
preorder(root->left);
preorder(root->right);
}
}



void postorder(BST *root)
{
if(root != NULL)
{
postorder(root->left);
postorder(root->right);
printf("%d\t", root->data);
}
}

BST* findMin(BST *root)
{
if(root==NULL)
{
return NULL;
}
if(root->left)
return findMin(root->left);
else
return root;
}


void main()
{
int data, ch, i, n;

//BST *root=NULL;

while (1)
{
printf("\n1.Insertion in Binary Search Tree");
printf("\n2.Search Element in Binary Search Tree");
printf("\n3.Inorder\n4.Preorder\n5.Postorder\n6.Exit");
printf("\nEnter your choice: ");
scanf("%d", &ch);
switch (ch)
{
case 1: printf("\nEnter N value: " );
scanf("%d", &n);
printf("\nEnter the values to create BST like(6,9,5,2,8,15,24,14,7,8,5,2)\n");
for(i=0; i<n; i++)
{
scanf("%d", &data);
root=createtree(root, data);
}
break;

case 2: printf("\nEnter the element to search: ");
scanf("%d", &data);
root=search(root, data);
break;

case 3: printf("\nInorder Traversal: \n");
inorder(root);
break;
case 4: printf("\nPreorder Traversal: \n");
preorder(root);
break;
case 5: printf("\nPostorder Traversal: \n");
postorder(root);
break;
case 6: exit(0);
default:printf("\nWrong option");
break;
}
}
}

/* OUTPUT

1.Insertion in Binary Search Tree
2.Search Element in Binary Search Tree
3.Inorder
4.Preorder
5.Postorder
6.Exit
Enter your choice: 1

Enter N value: 8

Enter the values to create BST like(6,9,5,2,8,15,24,14,7,8,5,2)
6 9 5 2 8 15 24 14

1.Insertion in Binary Search Tree
2.Search Element in Binary Search Tree
3.Inorder
4.Preorder
5.Postorder
6.Exit
Enter your choice: 3

Inorder Traversal: 
2	5	6	8	9	14	15	24	
1.Insertion in Binary Search Tree
2.Search Element in Binary Search Tree
3.Inorder
4.Preorder
5.Postorder
6.Exit
Enter your choice: 4

Preorder Traversal: 
6	5	2	9	8	15	14	24	
1.Insertion in Binary Search Tree
2.Search Element in Binary Search Tree
3.Inorder
4.Preorder
5.Postorder
6.Exit
Enter your choice: 5

Postorder Traversal: 
2	5	8	14	24	15	9	6	
1.Insertion in Binary Search Tree
2.Search Element in Binary Search Tree
3.Inorder
4.Preorder
5.Postorder
6.Exit
Enter your choice: 2

Enter the element to search: 8

Element found is: 8
1.Insertion in Binary Search Tree
2.Search Element in Binary Search Tree
3.Inorder
4.Preorder
5.Postorder
6.Exit
Enter your choice: 2

Enter the element to search: 5

Element found is: 5
1.Insertion in Binary Search Tree
2.Search Element in Binary Search Tree
3.Inorder
4.Preorder
5.Postorder
6.Exit
Enter your choice: 2

Enter the element to search: 25

Element not found
1.Insertion in Binary Search Tree
2.Search Element in Binary Search Tree
3.Inorder
4.Preorder
5.Postorder
6.Exit
Enter your choice: 2

Enter the element to search: 24

Element found is: 24
1.Insertion in Binary Search Tree
2.Search Element in Binary Search Tree
3.Inorder
4.Preorder
5.Postorder
6.Exit
Enter your choice: 2

Enter the element to search: 14

Element found is: 14
1.Insertion in Binary Search Tree
2.Search Element in Binary Search Tree
3.Inorder
4.Preorder
5.Postorder
6.Exit
Enter your choice: 3

Inorder Traversal: 
2	5	6	8	9	14	15	24	
1.Insertion in Binary Search Tree
2.Search Element in Binary Search Tree
3.Inorder
4.Preorder
5.Postorder
6.Exit
Enter your choice: 4

Preorder Traversal: 
6	5	2	9	8	15	14	24	
1.Insertion in Binary Search Tree
2.Search Element in Binary Search Tree
3.Inorder
4.Preorder
5.Postorder
6.Exit
Enter your choice: 5

Postorder Traversal: 
2	5	8	14	24	15	9	6	
1.Insertion in Binary Search Tree
2.Search Element in Binary Search Tree
3.Inorder
4.Preorder
5.Postorder
6.Exit
Enter your choice: 



*/
