//CS1 - 57
//Program 6 : Stack and queue using array

#include<stdio.h>
#include<string.h>
#include<malloc.h>
int top = -1;
int front = -1;
int rear = -1;

void pop ( int **);
void push(int **, int, int );
void enqueue(int **, int, int );
void dequeue(int **);
void displayStack(int **, int);
void displayQueue(int **, int);
void main()
{
	int maxStack, maxQueue, item;
	int *stack, *queue;
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
			case 1:printf("\nHow many elements do you want in the stack ?");
						 printf("\nNumber of elements: ");
						 scanf("%d",&maxStack);
						 stack=(int *)malloc(maxStack*sizeof(int ));
						 while(choice3=='y'||choice3=='Y')
						 {
						 	printf("\nOperation to be done :\n 1.push\n 2.pop\n 3.Display\n 4.Exit\n Choice: ");
						 	scanf("%d", &choice2);
						 	switch(choice2)
						 	{
						 		case 1:printf("\nEnter the element to be pushed: ");
						 					 scanf("%d",&item);
						 					 push(&stack,item,maxStack);
						 					 break;
						 		case 2:pop(&stack);
						 					 break;
						 		case 3:displayStack(&stack, maxStack);
						 					 break;
						 		case 4:choice3='N';
						 					 break;
						 		default: printf("Wrong choice !");
						 	}
						 }
						 printf("->");
						 free(stack);
						 //If you want to make another stack!
						 break;
			case 2:printf("\nHow many elements do you want in the Queue ?");
						 printf("\nNumber of elements: ");
						 scanf("%d",&maxQueue);
						 queue=(int *)malloc(maxQueue*sizeof(int ));
						 while(choice3=='y'||choice3=='Y')
						 {
						 	printf("\nOperation to be done :\n 1.Enqueue\n 2.Dequeue\n 3.Display\n 4.Exit\n Choice: ");
						 	scanf("%d", &choice2);
						 	switch(choice2)
						 	{
						 		case 1:printf("\nEnter the element to be inserted: ");
						 					 scanf("%d",&item);
						 					 enqueue(&queue,item,maxQueue);
						 					 break;
						 		case 2:dequeue(&queue);
						 					 break;
						 		case 3:displayQueue(&queue, maxQueue);
						 					 break;
						 		case 4:choice3='N';
						 					 break;
						 		default: printf("Wrong choice !");
						 	}
						 }
						 free(queue);
						 //If you want to make another Queue!
						 break;
			default: printf("Wrong Choice !");	
						 
	  }
	  printf("Do you want to make more ?(Y/N) : ");
	  getchar();
	  scanf("%c",&choice4);
	  //printf("Terminating..");
  }while(choice4=='y'||choice4=='Y');
}
void pop ( int ** stack)
{
	if(top==-1)
	{
		printf("\nUnderflow!");
	}
	else 
	{
		printf("\n%d Was Deleted",*(*stack+top));
		top--;
	}
}
void push(int **stack, int item, int max)
{
	if(top==max-1)
	{
		printf("\nOverFlow!");
	}
	else
	{
		top++;
		*(*stack+top)=item;
	}
}
void enqueue(int **queue, int item, int max)
{
	if(rear==max-1)
	{
		printf("\nOverFlow!");
	}
	else if(front==-1&&rear==-1)
	{
	 front = 0;
	 rear = 0;
	 *(*queue+rear)=item;
	}
	else
	{
		rear++;
		*(*queue+rear)=item;
	}
}
void dequeue(int **queue)
{
	if(front==-1)
	{
		printf("\nUnderFlow!");
	}
	else if(front == rear)
	{
		printf("\n%d was deleted",*(*queue+front));
		front = -1;
		rear = -1;
	}
	else
	{
		printf("\n%d was deleted",*(*queue+front));
		front++;
  }
}
void displayStack(int **stack, int max)
{ int i;
	if(top == -1)
	{
	 printf("UnderFlow!");
	}
	else
	{
	 for(i=top;i>=0;i--)
	 {
	 	printf("%d	",*(*stack+i));
	 }
	}
}
void displayQueue(int **queue, int max)
{ int i;
	if(front==-1)
	{
		printf("UnderFlow!");
	}
	else
	{
		for(i=front;i<=rear;i++)
		{
			printf("%d	",*(*queue+i));
		}
	}
}

/*
Output :
What do you want to create ?
 1.Stack
 2.Queue
 Option: 1

How many elements do you want in the stack ?
Number of elements: 3

Operation to be done :
 1.push
 2.pop
 3.Display
 4.Exit
 Choice: 1

Enter the element to be pushed: 43

Operation to be done :
 1.push
 2.pop
 3.Display
 4.Exit
 Choice: 1

Enter the element to be pushed: 56

Operation to be done :
 1.push
 2.pop
 3.Display
 4.Exit
 Choice: 1

Enter the element to be pushed: 78

Operation to be done :
 1.push
 2.pop
 3.Display
 4.Exit
 Choice: 1

Enter the element to be pushed: 23

OverFlow!
Operation to be done :
 1.push
 2.pop
 3.Display
 4.Exit
 Choice: 2

78 Was Deleted
Operation to be done :
 1.push
 2.pop
 3.Display
 4.Exit
 Choice: 3
56	43	
Operation to be done :
 1.push
 2.pop
 3.Display
 4.Exit
 Choice: 4
->Do you want to make more ?(Y/N) : y
here
What do you want to create ?
 1.Stack
 2.Queue
 Option: 2

How many elements do you want in the Queue ?
Number of elements: 3

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

Enter the element to be inserted: 34

Operation to be done :
 1.Enqueue
 2.Dequeue
 3.Display
 4.Exit
 Choice: 1

Enter the element to be inserted: 65

Operation to be done :
 1.Enqueue
 2.Dequeue
 3.Display
 4.Exit
 Choice: 3
21	34	65	
Operation to be done :
 1.Enqueue
 2.Dequeue
 3.Display
 4.Exit
 Choice: 2

21 was deleted
Operation to be done :
 1.Enqueue
 2.Dequeue
 3.Display
 4.Exit
 Choice: 3
34	65	
Operation to be done :
 1.Enqueue
 2.Dequeue
 3.Display
 4.Exit
 Choice: 1

Enter the element to be inserted: 21

OverFlow!
Operation to be done :
 1.Enqueue
 2.Dequeue
 3.Display
 4.Exit
 Choice: 1

Enter the element to be inserted: 23

OverFlow!
Operation to be done :
 1.Enqueue
 2.Dequeue
 3.Display
 4.Exit
 Choice: 4
Do you want to make more ?(Y/N) : n
*/
