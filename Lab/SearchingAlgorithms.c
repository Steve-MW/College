// CS1 - 57
// Program 3
#include<stdio.h>
#include<malloc.h>
void sort(int *,int );
void main()
{
 int first, last, mid, i, j, item,k,temp,o,error=1;
 int *array;
 printf("How many numbers do want to store ? ");
 scanf("%d",&i);
 array=(int *)malloc(i*sizeof(int));
 printf("Enter the numbers :- \n");
 for(j=0;j<i;j++)
 {
 	scanf("%d",(array+j));
 }
 printf("What type of searching do you want to do ?");
 printf("\n1.Binary Search\n2.Linear Search\nOption:- ");
 scanf("%d",&o);
 switch(o)
 {
 	case 1:
 	        sort(array,i);
 					for(j=0;j<i;j++)
 					{
 						printf("%d  ",*(array+j));
 					}
 					printf("\nEnter the number you want to search for :- ");
 					scanf("%d",&item);
 					first=0;
				  last=i-1;
				  
				  while(first<=last)
 					{
 						mid=(first+last)/2;
 					if(*(array+mid)==item)
 					{
 						printf("The item was found at position %d\n",mid+1);
 						error = 0;
 						break;
 					}
 					else if(item>*(array+mid))
 					{
 						first=mid+1;
 					}
 					else if(item<*(array+mid))
 					{
 						last=mid-1;
 					}
 					}
 					if(error==1)
 					{
 						printf("The item was not found!\n");
 					}
 					break;
	case 2:
				 for(j=0;j<i;j++)
 					{
 						printf("%d  ",*(array+j));
 					}
 					printf("Enter the number you want to search for :- ");
 					scanf("%d",&item);
 					for(j=0;j<i;j++)
 					{
 						if(item==*(array+j))
 						{
 						 printf("Enter the number was found at position %d \n",j+1);
 						 error=0;
 						}
 					}
 					if(error==1)
 					{
 						printf("The item was not found!\n");
 					}
 					break;
 	default:printf("Enter the right choice!");
 }
 
 					
 					
				 
		
}
void sort(int *array, int i)
{ int j,k,temp;
	for(j=0;j<i-1;j++)
						{
							for(k=0;k<i-1;k++)
							{
								if(*(array+k+1)<*(array+k))
								{
									temp=*(array+k+1);
									*(array+k+1)=*(array+k);
									*(array+k)=temp;
								}
							}
						}
						
 }
/*

How many numbers do want to store ? 5
Enter the numbers :- 
1
7
3
5
2
What type of searching do you want to do ?
1.Binary Search
2.Linear Search
Option:- 1
1  2  3  5  7  
Enter the number you want to search for :- 3
The item was found at position 3

How many numbers do want to store ? 5
Enter the numbers :- 
1
7
3
5
2
What type of searching do you want to do ?
1.Binary Search
2.Linear Search
Option:- 1
1  2  3  5  7  
Enter the number you want to search for :- 8
The item was not found!

*/


	
