#include<stdio.h>
#include<malloc.h>
struct node
{
	int constant, power;
	struct node *link;
}*start1=NULL,*start2=NULL,*start3,*start4;                                                                
void create(int ,int , struct node*);
void add(struct node *, struct node *);
void multiply(struct node *, struct node *);       
void disp(struct node*);
void main()
{
	int constant , power, totalNode1, totalNode2, choice;
	int i;
	struct node *temp1, *temp2;
	         
	printf("Enter the number of elements of the first list :- ");
	scanf("%d", &totalNode1);
	printf("Enter the elements of the first list :- \n");
	
	for (i=0;i<totalNode1;i++)  
	{
		printf("%d. \n",i+1);
		printf("Constant :- ");
		scanf("%d", &constant);
		printf("Power :- ");
		scanf("%d",&power);
		create(constant,power,start1);
	}
	disp(start1);
	printf("Enter the number of elements of the second list :- ");
	scanf("%d", &totalNode2);
	printf("Enter the elements of the second list :- \n");
	
	for (i=0;i<totalNode2;i++)
	{
		printf("%d. \n",i+1);
		printf("Constant :- ");
		scanf("%d", &constant);
		printf("Power :- ");
		scanf("%d",&power);
		create(constant,power,start2);
	}
	
	printf("What do you want to do ? \n");
	printf("1.ADD\n2.MULTIPLAY\n");
	printf("Choice :- ");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1: add(start1,start2);
						//disp(start3);
						break;
		case 2: multiply(start1,start2);
						//disp(start4);
						break;
		default: printf("Enter the correct choice !");
	}
	
}
void create(int constant, int power, struct node *start)
{ printf("here");
	struct node *temp,*newNode;
	int exit = 0;
	newNode = (struct node*)malloc(sizeof(struct node));
	newNode->constant=constant;
	newNode->power=power;
	temp=start;
	if(temp==NULL)
	{ printf("here1");
		start=newNode;
		newNode->link=NULL;
	}
	else
	{ 
	while(temp!=NULL&&exit==0)
		{
		  printf("here2");
			if(newNode->power==temp->power)
			{ printf("here3");
				temp->constant+=newNode->constant;
				free(newNode);
				exit=1;
				break;
			}
			else if(newNode->power>temp->power)
			{ printf("here4");
				start=newNode;
				newNode->link=temp;
				exit=1;
				break; 
			}
			else if(temp->link==NULL)
			{ /*If we reach the last element and still, the power is not added 
					then we just add the element to the last position 
				*/
				printf("here5");
				newNode->link=NULL;
				temp->link=newNode;
				exit=1;
				break;
			}
			else
			{ /*If we reach a postion where the last elements power is lesser
					and the current elements power is larger then we just add the 
					element is added in between */
					printf("here6");
				if((temp->link)->power<newNode->power)
				{ printf("here7");
					newNode->link=temp->link;
					temp->link=newNode;
					exit=1;
					break;
				}
				/*Or else just point to the next element */
				else
				{ printf("here8");
					temp=temp->link;
				}
			}
			
		}
	}
	
}
void add(struct node *start1, struct node *start2)
{
	struct node *temp1, *temp2, *temp3, *newNode;
	temp1 = start1;
	temp2 = start2;
	temp3 = start3;
	newNode = (struct node*)malloc(sizeof(struct node));
	while(temp1!=NULL&&temp2!=NULL)
	{
		
		if(temp1->power==temp2->power)
		{
			newNode->constant = temp1->constant + temp2->constant;
			newNode->power = temp1->power;
			temp1=temp1->link;
			temp2=temp2->link;
		}
		else if(temp1->power>temp2->power)
		{
			newNode->constant = temp1->constant;
			newNode->power = temp1->power;
			temp1=temp1->link;
		}
		else if(temp1->power<temp2->power)
		{
			newNode->constant=temp2->constant;
			newNode->power=temp2->power;
			temp2=temp2->link;
		}
		temp3->link=newNode;
		newNode->link=NULL;
		newNode = (struct node *)malloc(sizeof(struct node));
		/* Here we are leaving the node idle i.e. Without linking it
		   to the previous node so that if at all the next while 
		   condition is not satisfied, we can just delete it. 
		*/
		}
		if(temp1==NULL&&temp2==NULL)
		{
			free(newNode);
		}
		else if(temp1==NULL)
		{
			while(temp2!=NULL)	
			{
				newNode->constant = temp2->constant;
				newNode->power = temp2->power;
				temp2=temp2->link;
				temp3->link=newNode;
				newNode->link=NULL;
				newNode=(struct node*)malloc(sizeof(struct node ));
			}
		}
		else if(temp2==NULL)
		{
			while(temp1!=NULL)
			{
				newNode->constant = temp1->constant;
				newNode->power = temp1->power;
				temp1=temp1->link;
				temp3->link=newNode;
				newNode->link=NULL;
				newNode=(struct node*)malloc(sizeof(struct node ));
			}
		}
}
void multiply(struct node *start1, struct node *start2)
{
	struct node *temp1, *temp2, *temp4, *delNode, *newNode;
	temp1=start1;
	temp4=start4;
	while(temp1!=NULL)
	{	temp2=start2;
		while(temp2!=NULL)
		{
			newNode = (struct node *)malloc(sizeof(struct node));
			newNode->constant=temp1->constant*temp2->constant;
			newNode->power=temp1->power+temp2->power;
			newNode->link=NULL;
			temp4->link=newNode;
			temp4=newNode;
			temp2=temp2->link;
		}
		temp1=temp1->link;
	}
	temp1=start4;
	
	//adding after multiplication 
	while(temp1!=NULL)
	{
		
		temp2=temp1; // Start checking from the very next position i.e temp2-link; 
		//Note:- temp1 = checking pointer
		//Note:- temp2 = Moving pointer
		while(temp2!=NULL)
		{ delNode =(struct node *)malloc(sizeof(struct node));
			if(temp2->link==NULL)
			{/*A condition seperately for the last node
				 i.e. not to check temp->link->power but
				 check temp->power .
			 */
				if(temp1->power==temp2->power)
				{
					temp1->constant+=temp2->constant;
					delNode=temp2;
					temp2->link=NULL;
					free(delNode);
				}
			}
			else
			{	/*The condition to check for all cases except for the last node */		
				if(temp1->power==temp2->link->power)
				{
					temp1->constant+=temp2->link->constant;
					delNode=temp2->link;
					temp2->link=delNode->link;
					free(delNode);
				}
			}
			temp2=temp2->link;
		}
		temp1=temp1->link;
	}							
}
void disp(struct node *start)
{
	struct node* temp;
	temp=start;
	printf("%dx^%d",temp->constant,temp->power);
	temp=temp->link;
	while(temp!=NULL)
	{
		printf(" + %dx^%d",temp->constant,temp->power);
		temp=temp->link;
	}
		
}
 

