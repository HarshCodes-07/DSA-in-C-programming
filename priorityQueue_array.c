#include<stdio.h>
#define MAX 20
int queue[MAX],priority[MAX];
int front =-1,rear=-1;
void enqueue(int data,int p);
int dequeue();
void print();
int main()
{
    int opt,n,i,data,p;
    printf("Enter Your Choice:-");
    do
    {
        printf("\n\n1 for Insert the Data in Queue\n2 for show the Data in Queue \n3 for Delete the data from the Queue\n0 for Exit");
        scanf("%d",&opt);
        switch(opt)
        {
        case 1:
            printf("\nEnter the number of data");
            scanf("%d",&n);
            printf("\nEnter your data and Priority of data");
            i=0;
            while(i<n)
            {
                scanf("%d %d",&data,&p);
                enqueue(data,p);
                i++;
            }
            break;
        case 2:
            print();
            break;
        case 3:
            dequeue();
            break;
        case 0:
            break;
        default:
            printf("\nIncorrect Choice");

        }
    }
    while(opt!=0);
    return 0;
}
void enqueue(int data,int p)
{
    int i;
    if(front==0&&rear==MAX-1)
    {
        printf("\nQueue OVERFLOW");
    }
    else
    {
        if(front==-1)
        {
            front=rear=0;
            queue[rear]=data;
            priority[rear]=p;
        }
        else if(rear==MAX-1)
        {
            for(i=front; i<=rear; i++)
            {
                queue[i-front] = queue[i];
                priority[i-front] = priority[i];
                rear=rear-front;
                front = 0;
                for(i = rear; i>front; i--)
                {
                    if(p>priority[i])
                    {
                        queue[i+1] = queue[i];
                        priority[i+1] = priority[i];
                    }
                    else
                        break;
                    queue[i+1] = data;
                    priority[i+1] = p;
                    rear++;
                }
            }
        }
        else
        {
            for(i = rear; i>=front; i--)
            {
                if(p>priority[i])
                {
                    queue[i+1] = queue[i];
                    priority[i+1] = priority[i];
                }
                else
                    break;
            }
            queue[i+1] = data;
            priority[i+1] = p;
            rear++;
        }
    }
}
int dequeue()
{
	if(front == -1)
	{
		printf("Queue is Empty");
	}
	else
	{
		printf("Deleted Element = %d\t Its Priority = %d",queue[front],priority[front]);
		if(front==rear)
			front = rear = -1;
		else
			front ++;
	}
}

void print(){
    int i;
    for(i=front;i<=rear;i++){
        printf("\nElement = %d\tPriority = %d",queue[i],priority[i]);
    }
}
