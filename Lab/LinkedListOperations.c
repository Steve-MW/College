// CS1 57
// Program 4
#include<stdio.h>
#include<malloc.h>
#include<string.h>
struct node
{
	struct node *link;
	int info;
}*start=NULL;
void create(int);
int insert(int, int);
void delete(int);
void display();
int main()
{	
	char c;
	int item,pos,choice,num,i;
	printf("Do you want to create a linked list ? (y/n) :- ");
	scanf("%c",&c);
	while(c=='y'||c=='Y')
	{ printf("How many items do you want to create ? ");
		scanf("%d",&num);
		printf("Enter an item to be stored :- ");
		scanf("%d",&item);
		create(item);
		for(i=1;i<num;i++)
		{
			printf("Enter the item to be stored:- ");
			scanf("%d",&item);
			insert(item,-1);
		}
		
		break;
	}
	while(c=='y'||c=='Y')
	{
	printf("What do you want to do ?\n");
	do
	{
		printf("1.Insert a node\n2.Delete a node\n3.Display a node\n4.Exit\n");
		printf("Option:-");
		
		scanf("%d",&choice);
	
		switch(choice)
		{
		 case 1:
		 				printf("Enter the data to be stored :- ");
						scanf("%d",&item);
						printf("Enter the position to insert (1...n):- ");
						scanf("%d",&pos);
						insert(item,pos);
						break;
		case 2:
						 printf("Enter the position of the node to delete (1...n) :- ");
						 scanf("%d",&pos);
						 delete(pos);
						 break;
		case 3:
						 display();
						 break;
		case 4:
					 goto label;
					 break;
		default: printf("Enter the right choice! ");
		
		}
		printf("Go back to the option menu (Y/N)");
		getchar();
		scanf("%c",&c);
		}while(c=='y'||c=='Y');
		
		}
	label:
	return 0;
	}
void create(int item)
{
	struct node *newNode;
	newNode=(struct node *)malloc(sizeof(struct node));
	start = newNode;
	newNode->info=item;
	newNode->link=NULL;
}
int insert(int item, int pos)
{ 
	struct node *newNode,*temp;
	int num=1,i=0;
	/*Num = 1 to count the number of nodes. So that if we enter a position
	greater the total number of nodes, it will display an error
	*/
	temp=start;
	newNode=(struct node *)malloc(sizeof(struct node ));
	newNode->info=item;
	while(temp->link!=NULL)
	{
		temp=temp->link;
		num++;
	}
	//Counting the number of nodes in the list
	temp=start;
	if(pos>num)
	{// If the position entered exeeds the amount of nodes present
	 printf("There are only %d nodes, try again.\n",num);
	 return 0;
	}
	if(pos==-1)
	{ /* -1 will be passed if we just want to append to the last position */
		while(temp->link!=NULL)
		{
			temp=temp->link;
		}
		temp->link=newNode;
		newNode->link=NULL;
		return 0;
	}y
	else if(pos==1)
	{//If the first position was entered
	 temp=start; //Storing the previous start here
	 create(item); 
	 //Create a new node at the start 
	 /* so now the start is pointing to the new node, and newNode is 
	   disconnected to nohting, i.e it is de railed. so just change the link 
	   of the new node to Start, i.e the old starting point. 
	 */
	 start->link=temp;
	  
	 
	}
	else
	{
		temp=start;
		for(i=1;i<pos-1;i++)
		{
			temp=temp->link;
		}
		newNode->link=temp->link;
		temp->link=newNode;
		return 0;
	}
	
	
}
void delete(int pos)
{
 int i = 1;
 struct node *delNode, *temp;
 temp=start;
 while(temp->link!=NULL)
 {
 	temp=temp->link;
 	i++;
 }
 if(pos<=i)
 {
 	temp=start;
 	for(i=1;i<pos-1;i++)
 	{
 		temp=temp->link;
 	}
 	delNode=temp->link;
 	temp->link=delNode->link;
 	free(delNode);
 }
}
void display()
{
	struct node *temp;
	temp=start;
	while(temp!=NULL)
	{
		printf("%d  ",temp->info);
		temp=temp->link;
	}
	printf("\n");
}
/*

Do you want to create a linked list ? (y/n) :- y
How many items do you want to create ? 3
Enter an item to be stored :- 10
Enter the item to be stored:- 20
Enter the item to be stored:- 30
What do you want to do ?
1.Insert a node
2.Delete a node
3.Display a node
4.Exit
Option:-3
10  20  30  
Go back to the option menu (Y/N)y
1.Insert a node
2.Delete a node
3.Display a node
4.Exit
Option:-1
Enter the data to be stored :- 40
Enter the position to insert :- 2
Go back to the option menu (Y/N)y
1.Insert a node
2.Delete a node
3.Display a node
4.Exit
Option:-3
10  40  20  30  
Go back to the option menu (Y/N)y
1.Insert a node
2.Delete a node
3.Display a node
4.Exit
Option:-2
Enter the position of the node to delete :- 3
Go back to the option menu (Y/N)y
1.Insert a node
2.Delete a node
3.Display a node
4.Exit
Option:-3
10  40  30  
Go back to the option menu (Y/N)y
1.Insert a node
2.Delete a node
3.Display a node
4.Exit
Option:-3
10  40  30  
Go back to the option menu (Y/N)n


*/
 
 
 
			
			
		
	 
