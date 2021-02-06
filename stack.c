/*
this program is wrtten to make a stack using structure array
*/

#include <stdio.h>
#include <stdlib.h>

struct stack  //this structure is used to create an array
{

   int size; //size of the array
   int top; //Top pointer 
   int *S; //array pointer pointing to the array

};

void createStack(struct stack *st) //this function will create the stack
{
   //struct stack *st is call by reference and it will allow us to make changes in the elements present inside the stack  
   printf("Enter the size of the stack\n");
   scanf("%d",&st->size);
   st->top=-1; //initializing the top pointer to -1
   st->S=(int *)malloc(st->size*sizeof(int));

}

void DisplayStack(struct stack st) //this struct stack st is call by value it is used when we read the data from the stack and not actually modify its elements
{
    int i; //loop variable
    for(i=st.top;i>=0;i--)
    {
    	 printf("%d \n",st.S[i]); 
    }
}

void PushStack(struct stack *st, int x) //push function accepts stack *S because we are actually making changes inside the stack and int X which is the value that we want to insert inside the stack
{
     if(st->top==st->size-1)
     {
     	printf("stack overflow!!!....\n");
     }
     else
     {
     	st->top++; //incrementing top pointer
     	st->S[st->top]=x;  //inserting the element inside the stack
     }
}

int POPStack(struct stack *st) //this function will delete an element from the stack
{
    int x=-1;
    if (st->top==-1)
    {
    	printf("Stack underflow!!!!....\n");
    }
    else
    {
    	x=st->S[st->top--];
    }
    return x;
}

int main()
{
	struct stack st; //initializing stack in the main function
	int choiceStack; //choice variable for stack menue
	int StackCounter=0; //menue loop variable
	int y; //new value that is to be pushed inside  the stack
	do
	{
		printf("---------------------STACK MENUE--------------------------\n");
		printf("Press 1 to create a stack\n");
		printf("Press 2 to Display the elements inside the stack\n");
		printf("Press 3 to push an element inside the stack\n");
		printf("Press 4 to pop an element from the stack\n");
		printf("Press 5 to terminate the program\n");
		scanf("%d",&choiceStack);
		printf("\n");
      
        switch(choiceStack)
        {
        	case 1:
        	 createStack(&st);
        	 printf("\n");
        	break;
        	case 2:
              DisplayStack(st);
        	break;
        	case 3:
        	 printf("Enter the element you want to push inside the stack\n");
        	 scanf("%d",&y);
             PushStack(&st, y);
             printf("\n");
        	break;
        	case 4:
        	  y = POPStack(&st);
        	  printf("The %d is poped out of the stack\n", y);
        	break;
        	case 5:
        	StackCounter = 5000;
        	printf("Program terminated by the user!!!!....\n");
        	break;
        	default :
        	printf("Wrong choice....!\n");
        	printf("\n");
        	break;
        }

	}while(StackCounter<4000);
	return 0;
}

