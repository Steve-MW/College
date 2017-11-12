#include<stdio.h>
#include<stdlib.h>
int binaryTree[50];
void displayTree(int , int []);
void postOrderLRN(int , int , int []);
void inOrderLNR(int , int, int []);
void preOrderNLR(int, int, int []);
void main()
{   
    int i = 0;
    char ch = 'y';
    printf("\nEnter the root node: ");
    scanf("%d",&binaryTree[i]);//i gets incremented to 2 after this 
    while(ch== 'y')
    {   
        ++i;
        if(i%2==0)
        {
            printf("\nEnter the Right child: ");
            scanf("%d",&binaryTree[i]);

        }
        else
        {
            printf("\nEnter the Left child: ");
            scanf("%d",&binaryTree[i]);

        }
        printf("Do you want to enter more nodes into the tree (y/n)?\nOption: ");
        getchar();
        scanf("%c",&ch);

    }
    i++; // To get the number of elements in the tree i.e. n
    displayTree(i,binaryTree);
    printf("\nThe tree using post order traversal (LRN): ");
    postOrderLRN(0,i,binaryTree);
    printf("\nThe tree using in order traversal (LNR): ");
    inOrderLNR(0,i,binaryTree);
    printf("\nThe tree using pre order traversal (NLR): ");
    preOrderNLR(0,i,binaryTree);
    printf("\n");
}
void postOrderLRN(int i, int n, int binaryTree [])
{
    if(i<n)
    {
        postOrderLRN(2*i+1,n,binaryTree);
        if(2*i+2<n)
            postOrderLRN(2*i+2,n,binaryTree);
        printf("%d  ",binaryTree[i]);
    }

}
void inOrderLNR(int i, int n, int binaryTree [])
{
    if(i<n)
    {
        inOrderLNR(2*i+1,n,binaryTree);
        printf("%d  ",binaryTree[i]);
        if(2*i+2<n)
            inOrderLNR(2*i+2,n,binaryTree);
    }
}
void preOrderNLR(int i, int n, int binaryTree[])
{
    if(i<n)
    {
        printf("%d  ",binaryTree[i]);
        preOrderNLR(2*i+1,n,binaryTree);
        if(2*i+2<n)
            preOrderNLR(2*i+2,n,binaryTree);
    }
}
void displayTree(int n, int binaryTree [])
{
    int i;
    printf("The tree in linear form : ");
    for(i = 0;i<n;i++)
    {
        printf("%d  ",binaryTree[i]);
    }
}