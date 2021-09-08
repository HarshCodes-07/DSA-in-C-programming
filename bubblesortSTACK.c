#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define MAX 5

int st[MAX],top=-1;
void push(int st[],int val);
int pop(int st[]);
int peek(int st[]);
void display(int st[]);
void bubbleSort(int st[],int n);
int main()
{
    int n;
    printf("\nEnter size : ");
    scanf("%d",&n);
    int a[n];
    printf("\nEnter %d Elements : ",n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
        push(st,a[i]);
    }
    bubbleSort(st,n);
    for(int i=n-1;i>=0;i--){
        a[i]=pop(st);
    }
    printf("\nAFTER SORTING : ");
    for(int i=0;i<n;i++){
        printf("\t%d",a[i]);
    }
}
void bubbleSort(int st[],int n)
{
    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (st[j] > st[j+1])
            {
                int temp=st[j];
                st[j]=st[j+1];
                st[j+1]=temp;
            }
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
