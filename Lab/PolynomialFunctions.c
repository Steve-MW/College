#include<stdio.h>
#include<malloc.h>
struct node 
{
    int constant;
    int power;
    struct node *link;
};
void * create(int consant, int power, struct node * start)
{
    struct node *temp, *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->constant = constant;
    newNode->power = power;
    newNode->link=NULL;
    
    if(start==NULL)
    {
        start = newNode;
    }
    else 
    {
        if (start->power < power)
        {
            newNode->link=start;
            start = newNode;
            return start;
        }
        else if(start->power == power )
        {
            start->constant+=constant;
            free(newNode);
            return start;
        }

        int last = 1;
        for (temp=start;temp->link!=NULL;temp=temp->link)
        {
            if(temp->link->power<power)
            {
                newNode->link=temp->link;
                temp->link=newNode;
                last = 0;
                break;
            }
            else if(temp->link->power==power)
            {
                temp->link->constant+=constant;
                free(newNode);
                last = 0;
                break;

            }
        }
        if(last == 1)
        {
            temp->link=newNode;

        }

    }
    return start;
}
void main()
{
    int ch;
    struct node *start1, *start2, *start3;
    

}