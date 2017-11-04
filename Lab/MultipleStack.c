#include<stdio.h>
int mainStack[50],maxList[50],minList[50];
int mainMax,stackCount,elementCount,topList[50];
void multipleCreate()
{
    int i=0,k=0;
    for (k=0;k<=stackCount-1;k++)
    {
        topList[k] = i-1; /* top will always be next stacks max - 1
                         but in the first stacks case, it will be 
                         -1, hence top[0] = 0 - 1.
                         top[1] = 0 + 3 - 1 (if 3 is element count)
                       */ 
        minList[k] = topList[k];
        i = i+elementCount;
        if(k==stackCount-1)
        {
            /*For the last stack the max will be the same as the main
              stacks max i.e including the excess elements also. */
            maxList[k] = mainMax; 
        }
        else
        {
            maxList[k] = i-1;
        }
    }
}
void multiplePush(int stack, int item)
{
    if(topList[stack]==maxList[stack])
    {
        printf("OverFlow !");
    }
    else
    {
        topList[stack]++;
        mainStack[topList[stack]] = item;
    }
}
void multiplePop(int stack)
{
    if(topList[stack]==minList[stack])
    {
        printf("UnderFlow !");
    }
    else
    {
        printf("%d was deleted", mainStack[topList[stack]]);
        topList[stack]--;

    }
}
void display(int all, int stack)
{
    if (all == 1)
    {
        
    }
}
int main()
{
    mainMax = 10;
    stackCount = 3;
    elementCount = 3;
    multipleCreate();
    return 0;

}