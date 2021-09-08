#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define MAX 5

int st[MAX],top=-1;
int st1[MAX],sorted[MAX];
void push(int st[],int val);
int pop(int st[]);
int peek(int st[]);
void display(int st[]);
void sort();
void insert(int);
int main()
{
    int val, option;
    do
    {
        printf("\n *****MAIN MENU*****");
        printf("\n 1. PUSH");
        printf("\n 2. POP");
        printf("\n 3. PEEK");
        printf("\n 4. DISPLAY");
        printf("\n 5. SORT AND DISPLAY");
        printf("\n 6. EXIT");
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
            val = peek(st);
            if(val != -1)
                printf("\n The value stored at top of stack is: %d", val);
            break;
        case 4:
            display(st);
            break;
        case 5:
            sort(st);
            display(st);
            break;
        }
    }
    while(option != 6);
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
void insert(int item) {
    if (top==-1||item>peek(st)) {
        push(st,item);
    } else {
        int top = pop(st);
        insert(item);
        push(st,top);
    }
}
void sort(){
    if(top!=-1){
        int x=pop(st);
        sort();
        insert(x);
    }
}

