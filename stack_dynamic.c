#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int *st;
int top=-1,size;
void push(int *st,int val);
int pop(int *st);
int peek(int *st);
void display(int *st);
int main()
{
    int val, option;
      printf("\nEnter the Base Size of the stack : ");
        scanf("%d",&size);
        st=(int *)malloc(sizeof(int)*size);
    do
    {
        printf("\n *****MAIN MENU*****");
        printf("\n 1. PUSH");
        printf("\n 2. POP");
        printf("\n 3. DISPLAY");
        printf("\n 4. EXIT");
        printf("\n Enter your option: ");
        scanf("%d", &option);
        switch(option)
        {
        case 1:
            printf("\n Enter the number to be pushed on stack: ");
            scanf("%d", &val);
            push(st, val);
            break;
        case 2:
            val = pop(st);
            if(val != -1)
                printf("\n The value deleted from stack is: %d", val);
            break;
        case 3:
            display(st);
            break;
        }
    }
    while(option != 4);
    return 0;
}
void push(int *st,int val)
{
    if(top==(size-1))
    {
        int choice;
        printf("\n The Stack is Full. Do you want to double the size ?\nEnter ->1 for yes or 2-> for no :");
        scanf("%d",&choice);
        if(choice==1){
        int *temp=(int *)malloc(sizeof(int)*(size*2));
        for(int i=0;i<=top;i++){
            temp[i]=st[i];
        }
        int *st=(int *)malloc(sizeof(int)*(size*2));
        free(st);
        st=temp;
        size*=2;
        }else{
            printf("\nStack Overflow..");
            return;
        }
    }
        st[++top]=val;
}
int pop(int *st)
{
    if(top==-1)
    {
        printf("\nStack Underflow.");
        return -1;
    }
    else
    {
        return st[top--];
    }
}
void display(int *st)
{
    if(top == -1)
        printf("\n STACK IS EMPTY");
    else
    {
        for(int i=top; i>=0; i--)
            printf("\n %d",st[i]);
        printf("\n");
    }
}
