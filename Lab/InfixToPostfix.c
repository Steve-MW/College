#include<stdio.h>
#include<math.h>
#include<ctype.h>
int topExp = -1,topStack = -1;
float product;
char initString[20], postExp[20], postStack[20];
/*
postStack -> To hold all the operators ( *, /....) during convertion 
postExp   -> Holds the final postfix Expression 
*/
void pushExp(char);
char popExp();
void pushStack(char );
char popStack();
void processUpdate(char [], int );
void display();
int priorityGenerate(char );
void postFixConvertor();
float result (char , char , char );
void postfixEvaluator();


void main()
{  
    postFixConvertor();
    display();
    postfixEvaluator();
}



/*
One push and pop function for both arrays.
Error:- while popping, the concept of pass
by reference is followed. Hence we have to 
pass back a charecter pointer which is not 
possible since we are also passing the popped
element.
*/
/*
void  * push(char *stack, char item, int *top)
{
    stack[++top] = item;
    return stack;
}
char * pop (char *stack, int *top)
{
  return stack[top--];
}
*/
//To push into the finall post fix expression
void pushExp(char item)
{
    postExp[++topExp] = item;

}
//pop out of the postfix expression
char popExp()
{   //Could include checking for -1
    return(postExp[topExp--]);
}
//Push into the Stack i.e the one which holds the operators
void pushStack(char item)
{
    postStack[++topStack] = item;
}
// Pop out of Stack preferably to push into the postfix expression
char popStack()
{
    return(postStack[topStack--]);
}
void processUpdate(char stack[], int top)
{
    int i = 0,j;
    while(i<=top)
    {
        printf("%c",stack[i++]);
    }
    for(j = 1;j <= (13-i); j++)
    {
        printf(" ");
    }
    /*What this basically does is that, it prints out the 
    correct amount of spacing.A total of 13 spaces, if there
    are no elements in the stack, 12 spaces (13-1) if there 
    is one element within the stack and so on.This will help
    to maintain spacing between the output of the postfix
    expression and ':' which will be printed after this 
    function is called.
    */

}
void display()
{   
    int i = 0;
    printf("\nThe post Fix expression in : ");
    while(i<=topExp)
    {
        printf("%c",postExp[i++] );
    }

}

int priorityGenerate(char symbol)
{
    if(symbol == '^')
        return 3;
    else if(symbol == '*'|| symbol == '/'||symbol =='%')
        return 2;
    else if(symbol == '+'||symbol =='-')
        return 1;
    else return -1;
}
void postFixConvertor()
{
 int i,j,k;
 //Pusing '(' initially in order to create a proper order 
 pushStack('(');
 //After accepting the string from user add ')' to the end of the string 
 printf("Enter an infix expression : ");
 scanf("%s",initString);
 printf("\nThe infix Expression is : ");
 printf("%s",initString);
 k = 0;
 while(*(initString+k)!='\0')
 {
    k++;
 }
 *(initString+k) = ')';
 *(initString + ++k) = '\0';
 printf("\nStack         Postfix Expression\n");
 for(i = 0; initString[i]!='\0'; i++)
    {
      if(isalpha(initString[i]))
      {
          pushExp(initString[i]);
      }
      else 
      {
        if (initString[i] == '(')
            pushStack(initString[i]);
        else if(initString[i] == ')')
        {
            for(j = topStack; postStack[j] !='(';j--)
                pushExp(popStack());
            popStack();
        }
        else if(initString[i] == '^' && postStack[topStack]=='^')
            pushStack(initString[i]);
        else if(priorityGenerate(initString[i])>priorityGenerate(postStack[topStack]))
        {
            pushStack(initString[i]);
        }
        else if(priorityGenerate(initString[i])<=priorityGenerate(postStack[topStack]))
        {
            /*
            priorityGenerate(initString[i])>priorityGenerate(postStack[topStack])
            this will keep generating a false value since the operator that we 
            are inserting is having a lesser priority. But the Not of that will 
            generate TRUE which will keep the while statement running.     
            As soon as we pop the operators and push into the post fix expression 
            i.e when priority will be high, it will generate a true and hence 
            the NOT of that will be FALSE due to which the loop will terminate */
            while(!(priorityGenerate(initString[i])>priorityGenerate(postStack[topStack])))
            {
                pushExp(popStack());
            }
            pushStack(initString[i]);
        }


    }
    processUpdate(postStack,topStack);
    printf(":");
    processUpdate(postExp,topExp);
    printf("\n");
}
}
float result (char a, char b, char symbol)
{
    float x,y;
    if (a == '`')
    {
        x = product;
    }
    else
    {
        printf("\nValue of %c : ",a);
        scanf("%f",&x);
    }
    if(b == '`')
    {
        y = product;
    }
    else
    {
        printf("\nValue of %c : ",b);
        scanf("%f",&y);
    }

    switch(symbol)
    {
        case '^':return pow(x,y);
                break;
        case '*':return y*x;
                break; 
        case '/':return y/x;
                break;       
        case '%':return (int)y%(int)x;
                break;
        case '+':return y+x;
                break;
        case '-':return y-x;
                break;            
    }
}
void postfixEvaluator()
{
    printf("\n\nEvaluation :\n");
    int i;
    for(i = 0;i<=topExp;i++)
    {
        if(isalpha(postExp[i]))
        {
            pushStack(postExp[i]);
        }
        else
        {
            product = result(popStack(),popStack(),postExp[i]);
            pushStack('`');

        }
    }
    printf("\nThe Evaluated result of the post fix expression is : %f\n\n",product);
}
