#include<stdio.h>
#include<math.h>
#include<ctype.h>
int topExp = -1,topStack = -1;
char initString[20], postExp[20], postStack[20];
/*
postStack -> To hold all the operators ( *, /....) during convertion 
postExp   -> Holds the final postfix Expression 
*/
/*
One push and pop function for both arrays.
Error:- while popping, the concept of pass
by reference is followed. Hence we have to 
pass back a charector pointer which is not 
possible since we are also passing the popped
element.
*/
/*
void  * push(char *stack, char item, int *top)
{
    stack[++top] = item;
    return stack;
}
char pop (char *stack, int *top)
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

void display()
{   int i = topExp;
    while(topExp>=0)
    {
        printf("%c",postExp[i--] );
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
 char *i;
 int j;
 for(i = initString; *i!='\0'; i++)
 {
      if(isalpha(*i))
      {
          pushExp(*i);
      }
      else 
      {
        if (*i == '(')
            pushStack(*i);
        else if(*i == ')')
        {
            for(j = topStack; postStack[j] !='(';j--)
                pushExp(popStack());
            popStack();
        }
        else if(priorityGenerate(*i)>priorityGenerate(postStack[topStack]))
        {
            pushStack(*i);
        }
        else if(priorityGenerate(*i)<=priorityGenerate(postStack[topStack]))
        {
            /*
            priorityGenerate(*i)>priorityGenerate(postStack[topStack])
            this will keep generating a false value since the operator that we 
            are inserting is having a lesser priority. But the Not of that will 
            generate TRUE which will keep the while statement running.
            As soon as we pop the operatiors and push into the post fix expression 
            i.e when priority will be high, it will generate a true and hence 
            the NOT of that will be FALSE due to which the loop will terminate */
            while(!(priorityGenerate(*i)>priorityGenerate(postStack[topStack])))
            {
                pushExp(popStack());
            }
            pushExp(*i);
        }


      }
 }
}
void main()
{   int i;
    //Pusing '(' initially inorder to create a proper order 
    pushStack('(');
    //After accepting the string from user add ')' to the end of the string 
    printf("Enter an infix expression : ");
    scanf("%s",initString);
    i = 0;
    while(*(initString+i)!='\0')
    {
        i++;
    }
    *(initString+i) = ')';
    *(initString + ++i) = '\0';
    postFixConvertor();
    display();
    
}