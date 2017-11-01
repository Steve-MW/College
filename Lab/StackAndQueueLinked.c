//CS1 - 57
//Program 7: implementing stack and queue using linked list 
#include<stdio.h>
#include<malloc.h>
struct stack 
{
	int item;
	struct stack *link;
}*top=NULL;
struct queue
{
	int item;
	struct queue *link;
}*front=NULL,*rear=NULL;
void pop ();
void push(int );
void enqueue(int );   
void dequeue();
void displayStack();
void displayQueue();
void main()
{
	int item;
	int choice1, choice2;
	char choice3, choice4;
	
	choice4 = 'y';
	do
	{ 
		choice3 = 'y';
		printf("\nWhat do you want to create ?");
		printf("\n 1.Stack\n 2.Queue\n Option: ");
		scanf("%d",&choice1);
		switch(choice1)
		{
			case 1:while(choice3=='y'||choice3=='Y')
						 {
						 	printf("\nOperation to be done :\n 1.push\n 2.pop\n 3.Display\n 4.Exit\n Choice: ");
						 	scanf("%d", &choice2);
						 	switch(choice2)
						 	{
						 		case 1:printf("\nEnter the element to be pushed: ");
						 					 scanf("%d",&item);
						 					 push(item);
						 					 break;
						 		case 2:pop();
						 					 break;
						 		case 3:displayStack();
						 					 break;
						 		case 4:choice3='N';
						 					 break;
						 		default: printf("Wrong choice !");
						 	}
						 }
						 printf("->");
						 break;
			case 2:while(choice3=='y'||choice3=='Y')
						 {
						 	printf("\nOperation to be done :\n 1.Enqueue\n 2.Dequeue\n 3.Display\n 4.Exit\n Choice: ");
						 	scanf("%d", &choice2);
						 	switch(choice2)
						 	{
						 		case 1:printf("\nEnter the element to be inserted: ");
						 					 scanf("%d",&item);
						 					 enqueue(item);
						 					 break;
						 		case 2:dequeue();
						 					 break;
						 		case 3:displayQueue();
						 					 break;
						 		case 4:choice3='N';
						 					 break;
						 		default: printf("Wrong choice !");
						 	}
						 }
						 
						 
						 break;
			default: printf("Wrong Choice !");	
						 
	  }
	  printf("Do you want to make more ?(Y/N) : ");
	  getchar();
	  scanf("%c",&choice4);
	  //printf("Terminating..");
  }while(choice4=='y'||choice4=='Y');
}
void pop ()
{ struct stack* delNode;
	if(top==NULL)
	{
		printf("UnderFlow!");
	}
	else if(top->link==NULL)
	{ 
		printf("%d was deleted!",top->item);
		delNode=top;
		top=NULL;
		free(delNode);
	}
	
	else
	{
		printf("%d was deleted ",top->item);
		delNode=top;
		top=top->link;
		free(delNode);
	}
}
void push(int item)
{
	struct stack *newNode;
	newNode = (struct stack *)malloc(sizeof(struct stack));
	newNode->item=item;
	newNode->link=top;
	top=newNode;

}
void enqueue(int item)
{	struct queue *newNode;
	newNode=(struct queue *)malloc(sizeof(struct queue));
	newNode->item=item;
	newNode->link=NULL;

	if(front==NULL&&rear==NULL)
	{
		front=newNode;
		rear=newNode;
	}
	else
	{
		rear->link=newNode;
		rear=newNode;
	}
}

			
void dequeue()
{ struct queue *delNode;	

	if(front==NULL)
	{
		printf("UnderFlow!");
	}
	else if(front==rear)
	{
		printf("%d was Deleted",front->item);
		delNode=front;
		front=NULL;
		rear=NULL;
		free(delNode);
	}
	else
	{
		printf("%d was deleted!",front->item);
		delNode=front;
		front=front->link;
	}
}
void displayStack()
{ 
	struct stack *temp;
	temp=top;
	if(temp==NULL)
	{
		printf("UnderFlow!");
	}
	else 
	{
	
		while(temp!=NULL)
		{
			printf("%d	",temp->item);
			temp=temp->link;
		}
	}
}
void displayQueue()
{
	struct queue *temp;
	temp=front;
	if(temp==NULL)
	{
		printf("UnderFlow!");
	}
	else
	{
		while(temp!=NULL)
		{
			printf("%d	",temp->item);
			temp=temp->link;
		}
	}
}
/*
What do you want to create ?
 1.Stack
 2.Queue
 Option: 1

Operation to be done :
 1.push
 2.pop
 3.Display
 4.Exit
 Choice: 1

Enter the element to be pushed: 21

Operation to be done :
 1.push
 2.pop
 3.Display
 4.Exit
 Choice: 1

Enter the element to be pushed: 32

Operation to be done :
 1.push
 2.pop
 3.Display
 4.Exit
 Choice: 1

Enter the element to be pushed: 45

Operation to be done :
 1.push
 2.pop
 3.Display
 4.Exit
 Choice: 3
45	32	21	
Operation to be done :
 1.push
 2.pop
 3.Display
 4.Exit
 Choice: 2
45 was deleted 
Operation to be done :
 1.push
 2.pop
 3.Display
 4.Exit
 Choice: 2
32 was deleted 
Operation to be done :
 1.push
 2.pop
 3.Display
 4.Exit
 Choice: 2
21 was deleted!
Operation to be done :
 1.push
 2.pop
 3.Display
 4.Exit
 Choice: 2
UnderFlow!
Operation to be done :
 1.push
 2.pop
 3.Display
 4.Exit
 Choice: 2
UnderFlow!
Operation to be done :
 1.push
 2.pop
 3.Display
 4.Exit
 Choice: 3
UnderFlow!
Operation to be done :
 1.push
 2.pop
 3.Display
 4.Exit
 Choice: 4
->Do you want to make more ?(Y/N) : y

What do you want to create ?
 1.Stack
 2.Queue
 Option: 2

Operation to be done :
 1.Enqueue
 2.Dequeue
 3.Display
 4.Exit
 Choice: 1

Enter the element to be inserted: 21

Operation to be done :
 1.Enqueue
 2.Dequeue
 3.Display
 4.Exit
 Choice: 1

Enter the element to be inserted: 243

Operation to be done :
 1.Enqueue
 2.Dequeue
 3.Display
 4.Exit
 Choice: 1

Enter the element to be inserted: 45

Operation to be done :
 1.Enqueue
 2.Dequeue
 3.Display
 4.Exit
 Choice: 3
21	243	45	
Operation to be done :
 1.Enqueue
 2.Dequeue
 3.Display
 4.Exit
 Choice: 2
21 was deleted!
Operation to be done :
 1.Enqueue
 2.Dequeue
 3.Display
 4.Exit
 Choice: 2
243 was deleted!
Operation to be done :
 1.Enqueue
 2.Dequeue
 3.Display
 4.Exit
 Choice: 2
45 was Deleted
Operation to be done :
 1.Enqueue
 2.Dequeue
 3.Display
 4.Exit
 Choice: 2
UnderFlow!
Operation to be done :
 1.Enqueue
 2.Dequeue
 3.Display
 4.Exit
 Choice: 2
UnderFlow!
Operation to be done :
 1.Enqueue
 2.Dequeue
 3.Display
 4.Exit
 Choice: 3
UnderFlow!
Operation to be done :
 1.Enqueue
 2.Dequeue
 3.Display
 4.Exit
 Choice: 4
Do you want to make more ?(Y/N) : n

*/		


