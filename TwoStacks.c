#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define MAX 5

int st[MAX],top1=-1,top2=MAX;
void push(int st[],int val);
int pop(int st[]);
int peek(int st[]);
void display(int st[]);
int main()
{
    int val, option;
    do
    {
        printf("\n *****MAIN MENU*****");
        printf("\n 1. PUSH to 1st stack");
        printf("\n 2. POP from 1st stack");
        printf("\n 3. PEEK from 1st stack");
        printf("\n 4. DISPLAY STACK 1");
        printf("\n 5. PUSH to 2nd stack");
        printf("\n 6. POP from 2nd stack");
        printf("\n 7. PEEK from 2nd stack");
        printf("\n 8. DISPLAY STACK 2");
        printf("\n 9. EXIT");
        printf("\n Enter your option: ");
        scanf("%d", &option);
        switch(option)
        {
        case 1:
            printf("\n Enter the number to be pushed on stack 1: ");
            scanf("%d", &val);
            push1(st, val);
            break;
        case 2:
            val = pop1(st);
            if(val != -1)
                printf("\n The value deleted from stack 1 is: %d", val);
            break;
        case 3:
            val = peek1(st);
            if(val != -1)
                printf("\n The value stored at top of stack 1 is: %d", val);
            break;
        case 4:
            display1(st);
            break;
        case 5:
            printf("\n Enter the number to be pushed on stack 2: ");
            scanf("%d", &val);
            push2(st, val);
            break;
        case 6:
            val = pop2(st);
            if(val != -1)
                printf("\n The value deleted from stack 2 is: %d", val);
            break;
        case 7:
            val = peek2(st);
            if(val != -1)
                printf("\n The value stored at top of stack 2 is: %d", val);
            break;
        case 8:
            display2(st);
            break;
        }
    }
    while(option != 9);
    return 0;
}
void push1(int st[],int val)
{
    if(top1>=top2-1)
    {
        printf("\nSTACK OVERFLOW.");
        return;
    }
    else
    {
        st[++top1]=val;
    }
}
void push2(int st[],int val)
{
    if(top1>=top2-1)
    {
        printf("\nSTACK OVERFLOW.");
        return;
    }
    else
    {
        st[--top2]=val;
    }
}
int pop1(int st[])
{
    if(top1==-1)
    {
        printf("\nStack Underflow.");
        return -1;
    }
    else
    {
        return st[top1--];
    }
}
int pop2(int st[])
{
    if(top2==MAX)
    {
        printf("\nStack Underflow.");
        return -1;
    }
    else
    {
        return st[top2++];
    }
}

int peek1(int st[])
{
    if(top1==-1)
    {
        printf("\nStack Underflow.");
        return -1;
    }
    else
    {
        return st[top1];
    }
}
int peek2(int st[])
{
    if(top2==MAX)
    {
        printf("\nStack Underflow.");
        return -1;
    }
    else
    {
        return st[top2];
    }
}
void display1(int st[])
{
    if(top1 == -1)
        printf("\n STACK IS EMPTY");
    else
    {
        for(int i=top1; i>=0; i--)
            printf("\n %d",st[i]);
        printf("\n");
    }
}
void display2(int st[])
{
    if(top2 == MAX)
        printf("\n STACK IS EMPTY");
    else
    {
        for(int i=top2; i<MAX; i++)
            printf("\n %d",st[i]);
        printf("\n");
    }
}
