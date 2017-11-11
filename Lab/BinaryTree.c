#include<stdio.h>
int binaryTree[50];
void displayTree(int );
void main()
{
    int i = 1;
    char ch = 'y';
    printf("\nEnter the root node: ");
    scanf("%d",&binaryTree[i]);//i gets incremented to 2 after this 
    while(ch== 'y')
    {   
        ++i;
        if(i%2==0)
        {
            printf("\nEnter the left child: ");
            scanf("%d",&binaryTree[i]);

        }
        else
        {
            printf("\nEnter the right child: ");
            scanf("%d",&binaryTree[i]);

        }
        printf("Do you want to enter more nodes into the tree (y/n)?\nOption: ");
        getchar();
        scanf("%c",&ch);

    }
    displayTree(i);
}
void displayTree(int n)
{
    int i;
    printf("The tree in linear form : ");
    for(i = 1;i<=n;i++)
    {
        printf("%d  ",binaryTree[i]);
    }
}