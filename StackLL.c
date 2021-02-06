/*
this program implements stack using linked list
*/

#include<stdlib.h>
#include <stdio.h>

struct node
{
        int info;
        struct node *next;
};

struct node *start=NULL;

void PushStackLL()
{
        struct node *temp,*ptr;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("\nStack overflow!!!!!.....\n");
                exit(0);
        }
        printf("\nPush an element inside the stack....\n");
        scanf("%d",&temp->info);
        temp->next=NULL;
        if(start==NULL)
        {
                start=temp;
        }
        else
        {
                temp->next=start;
                start=temp;
        }
}

void displayStackLL()
{
        struct node *ptr;
        if(start==NULL)
        {
                printf("\nStack underflow!!!!!.....\n");
                return;
        }
        else
        {
                ptr=start;
                printf("\nElements in the stack is :-\n");
                while(ptr!=NULL)
                {
                        printf("%d\n",ptr->info );
                        ptr=ptr->next ;
                }
        }
}

void popStackLL()
{
	struct node *ptr;
        if(start==NULL)
        {
                printf("\nStack underflow!!!!.....\n");
                return;
        }
        else
        {
                ptr=start;
                start=start->next ;
                printf("\nPopping elements from the stack!!!!!!.....%d\n",ptr->info);
                free(ptr);
        }
}

int main()     
{
        int choice;
        while(1){
               
                printf("\n                MENU                             \n");
                printf("\n 1.Push the element in stack   \n");
                printf("\n 2.Display elements in stack    \n");
                printf("\n 3.Pop the element in stack   \n");
                printf("\n 4.Exit       \n");
                printf("\n--------------------------------------\n");
                printf("\nEnter your choice:\n");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:
                                        PushStackLL();
                                        break;
                        case 2:
                                        displayStackLL();
                                        break; 
                        case 3:
                                        popStackLL();
                                        break;    
                        
                        case 4:
                                        printf("This piece of program was written by\n");
                                        printf("Name : Aditya Kumar\n");
                                        printf("Roll number : 1901230100001\n");
                                        printf("College code: 123\n");
                                        printf("College Name : SITM\n");
                                        printf("Course: B.Tech\n");
                                        printf("Branch : Computer science\n");
                                        printf("Year : 2nd Year\n");
                                        printf("Thank you for using my program ....Bye\n");
                                        exit(0);
                                        break;
                             
                        default:
                                        printf("\n Wrong Choice:\n");
                                        break;
                }
        }
        return 0;
}