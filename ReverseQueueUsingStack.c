#include<stdio.h>
#define MAX 10
int queue[MAX];
int front=-1,rear=-1;
void enqueue(int num);
int dequeue(void);
int peek(void);
void display(void);
void isFull();
int isEmpty();
void reverse();
int st[MAX],top=-1;
void push(int st[],int val);
int pop(int st[]);
void main()
{
    int val,option,num;
    do
    {
        printf("\n***MAIN MENU***");
        printf("\n 1. Enqueue an element");
        printf("\n 2. Dequeue an element");
        printf("\n 3. PEEK");
        printf("\n 4. Display the queue");
        printf("\n 5. Check if Queue is Full");
        printf("\n 6. Check if Queue is Empty");
        printf("\n 7. Reverse the Queue");
        printf("\n 8. EXIT");
        printf("\n Enter your option : ");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
            num;
            printf("\n Enter the number to be inserted in queue :");
            scanf("%d",&num);
            enqueue(num);
            break;
        case 2:
            val=dequeue();
            if(val!=-1)
                printf("\n The deleted element from queue is : %d",val);
            break;
        case 3:
            val=peek();

            if(val!=-1)
                printf("\n The first value in queue is : %d",val);
            break;
        case 4:
            display();
            break;
        case 5:
            isFull();
            break;
        case 6:
            isEmpty();
            break;
        case 7:
            reverse();
            break;
        }

    }
    while(option !=8);
}
void enqueue(int num)
{
    if(rear==(MAX-1)){
            printf("\n Queue overflow");
            return;
        }
    else if(front==-1 && rear==-1)
        front=rear=0;
    else
        rear++;
    queue[rear]=num;
}
int dequeue()
{
    int val;
    if(front==-1 || front>rear)
    {
     //   printf("\nQueue underflow");
        return -1;
    }
    else
    {
        val=queue[front];
        front++;
        if(front>rear)
            front=rear=-1;
        return val;
    }
}

int peek()
{
    if(front==-1 || front>rear)
    {
        printf("\nQueue is empty");
        return -1;
    }
    else
        return(queue[front]);
}

void display()
{
    int i;
    if(front==-1 || front>rear)
    {
        printf("\nQueue is empty");
    }
    else
    {
        for(i=front; i<=rear; i++)
            printf("\t%d",queue[i]);
    }
}
void isFull()
{
    if(rear==(MAX-1))
    {
        printf("\nIS FULL");
    }
    else
    {
        printf("\nNOT FULL");
    }
}
int isEmpty()
{
    if((front==rear)&&(front!=0))
    {
        return 1;
    }
    else
    {
       return 0;
    }
}
void reverse(){
    int x=dequeue();
    int i=1;
    while(x!=-1){
        i++;
        push(st,x);
        x=dequeue();
    }
    while(i-->1)
        enqueue(pop(st));
  /*  x=pop(st);
    printf("%d",x);
    while(x!=-1){
        enqueue(x);
        x=pop(st);
    }*/
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
    //    printf("\nStack Underflow.");
        return -1;
    }
    else
    {
        return st[top--];
    }
}
