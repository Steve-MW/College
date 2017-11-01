// CS1 -57
// Sorting 

#include<stdio.h>
#include<malloc.h>
void main()
{
	int c, i=0,j=0,k=0,temp,small,pos,d;
	int *point;
	char choice = 'y';
	while(choice=='y'||choice=='Y')
	{
	printf("How many numbers do you want to enter ? :- ");
	scanf("%d",&i);
	point = (int *)malloc(i*sizeof(int ));
	printf("Enter %d numbers :- ",i);
	for(j=0;j<i;j++)
	{
		scanf("%d",(point+j));
	}	
	printf("What type of sorting do you want to do ? \n");
	printf("1.Bubble sort \n2.Selection sort \n3.Insertion sort\n");
	printf("Option :- ");
	scanf("%d",&c);
	switch(c)
	{
		case 1:
						for(j=0;j<i-1;j++)
						{
							for(k=0;k<i-1;k++)
							{
								if(*(point+k+1)<*(point+k))
								{
									temp=*(point+k+1);
									*(point+k+1)=*(point+k);
									*(point+k)=temp;
								}
							}
						}
						for(j=0;j<i;j++)
						{
							printf("%d ",*(point+j));
						}
						break;
		case 2:
						for(j=0;j<i-1;j++)
						{
							small=*(point+j);
							pos=j;
							for(k=j+1;k<i;k++)
							{
								if(*(point+k)<small)
								{small=*(point+k);
								 pos=k;
								}
							}
							if(pos!=j)
							{
								temp=*(point+pos);
								*(point+pos)=*(point+j);
								*(point+j)=temp;
							}
						}
						for(j=0;j<i;j++)
						{
							printf("%d ",*(point+j));
						}
						break;
		case 3:
						for(j=1;j<i;j++)
						{ temp=*(point+j);
							d=j-1;
							while(d>=0 && temp<*(point+d))
							{
								*(point+d+1)=*(point+d);
								d--;
							}
							*(point+d+1)=temp;
						}
						for(j=0;j<i;j++)
						{
							printf("%d ",*(point+j));
						}
						break;
							
							/*small=*(point+j);
							pos=j;
							for(k=j;k>=0;k--)
							{
								if(*(point+k)<small)
								{
									small=*(point+k);
									temp=*(point+pos);
									*(point+pos)=*(point+k);
									*(point+k)=temp;
								  pos=k;
								}
							}
						}
						for(j=0;j<i;j++)
						{
							printf("%d	",*(point+j));*/
							/*d=i;
							while(d>0&& *(point+d)<*(point+d-1))
							{
								temp=*(point+d-1);
								*(point+d-1)=*(point+d);
								*(point+d)=temp;
								d--;
							}
						}
						for(j=0;j<i;j++)
						{
							printf("%d ",*(point+j));
						}*/
						
						break;
		default:printf("Enter the right choice!");
		}
		printf("Do you want to re try ? (Y/N) :- ");
		getchar();
		scanf("%c",&choice);
	}
}
/*
How many numbers do you want to enter ? :- 3
Enter 3 numbers :- 15
1
3
What type of sorting do you want to do ? 
1.Bubble sort 
2.Selection sort 
3.Insertion sort
Option :- 1
1 3 15 Do you want to re try ? (Y/N) :- y
How many numbers do you want to enter ? :- 5
Enter 5 numbers :- 6
2
9
1
23
What type of sorting do you want to do ? 
1.Bubble sort 
2.Selection sort 
3.Insertion sort
Option :- 2
1 2 6 9 23 Do you want to re try ? (Y/N) :- y
How many numbers do you want to enter ? :- 4
Enter 4 numbers :- 1
8
3
6
What type of sorting do you want to do ? 
1.Bubble sort 
2.Selection sort 
3.Insertion sort
Option :- 3
1 3 6 8 Do you want to re try ? (Y/N) :- n
*/								
						
						
	
