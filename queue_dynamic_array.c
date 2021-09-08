#include<stdio.h>
int *queue;
int front=-1,rear=-1;
void enqueue(void);
int dequeue(void);
int peek(void);
void display(void);
void isFull();
void isEmpty();
int size;
void main()
{
    printf("\nEnter the Base Size of the stack : ");
        scanf("%d",&size);
        queue=(int *)malloc(sizeof(int)*size);
    int val,option;
    do
    {
        printf("\n***MAIN MENU***");
        printf("\n 1. Enqueue an element");
        printf("\n 2. Dequeue an element");
        printf("\n 3. PEEK");
        printf("\n 4. Display the queue");
        printf("\n 5. Check if Queue is Full");
        printf("\n 6. Check if Queue is Empty");
        printf("\n 7. EXIT");
        printf("\n Enter your option : ");
        scanf("%d",&option);
        switch(option)
        {
        case 1:
            enqueue();
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
        }

    }
    while(option !=7);
}
void enqueue()
{
    int num;
    printf("\n Enter the number to be inserted in queue :");
    scanf("%d",&num);
    if(rear==(size-1)){
            int choice;
        printf("\n The Queue is Full. Do you want to double the size ?\nEnter ->1 for yes or 2-> for no :");
        scanf("%d",&choice);
        if(choice==1){
        int *temp=(int *)malloc(sizeof(int)*(size*2));
        for(int i=front;i<=rear;i++){
            temp[i]=queue[i];
        }
        int *queue=(int *)malloc(sizeof(int)*(size*2));
        free(queue);
        queue=temp;
        size*=2;
    queue[++rear]=num;
        }else{
            printf("\nStack Overflow..");
            return;
        }
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
        printf("\nQueue underflow");
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
    if(rear==(size-1))
    {
        printf("\nIS FULL");
    }
    else
    {
        printf("\nNOT FULL");
    }
}
void isEmpty()
{
    if((front==rear)&&(front!=0))
    {
        printf("\nIS EMPTY");
    }
    else
    {
        printf("\nNOT EMPTY");
    }
}
