#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define MAX 5

int st[MAX],top=-1;
void push(int st[],int val);
int pop(int st[]);
int peek(int st[]);
void display(int st[]);
void peekHighestElement(int st[]);
void peekLowestElement(int st[]);
void peekMiddleElement(int st[]);

int main()
{
    int val, option;
    do
    {
        printf("\n *****MAIN MENU*****");
        printf("\n 0. Check for Empty");
        printf("\n 1. PUSH");
        printf("\n 2. POP");
        printf("\n 3. PEEK");
        printf("\n 4. DISPLAY");
        printf("\n 5. Print highest Element");
        printf("\n 6. Print lowest Element");
        printf("\n 7. Print middle Element");
        printf("\n 8. EXIT");
        printf("\n Enter your option: ");
        scanf("%d", &option);
        switch(option)
        {
        case 0:
            if(top==-1)
                printf("\nYES EMPTY");
            else
                printf("\nNOT EMPTY");
            break;
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
            val = peek(st);
            if(val != -1)
                printf("\n The value stored at top of stack is: %d", val);
            break;
        case 4:
            display(st);
            break;
        case 5:
            peekHighestElement(st);
            break;
        case 6:
            peekLowestElement(st);
            break;
        case 7:
            peekMiddleElement(st);
            break;
        }
    }
    while(option != 8);
    return 0;
}
void push(int st[],int val)
{
    if(top==(MAX-1))
    {
        printf("\nSTACK OVERFLOW.");
        return;
    }
    else
    {
        st[++top]=val;
    }
}
int pop(int st[])
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
int peek(int st[])
{
    if(top==-1)
    {
        printf("\nStack Underflow.");
        return -1;
    }
    else
    {
        return st[top];
    }
}
void display(int st[])
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
void peekHighestElement(int st[])
{
    if(top==-1)
    {
        printf("\nStack is Empty");
    }
    else
    {
        printf("\n Highest Element is  : %d",st[top]);
    }
}
void peekLowestElement(int st[])
{
    if(top==-1)
    {
        printf("\nStack is Empty");
    }
    else
    {
        printf("\n Lowest Element is  : %d",st[0]);
    }
}
void peekMiddleElement(int st[])
{
    if(top==-1)
    {
        printf("\nStack is Empty");
    }
    else
    {
        printf("\n Middle Element is  : %d",st[top/2 + 1]);
    }
}
