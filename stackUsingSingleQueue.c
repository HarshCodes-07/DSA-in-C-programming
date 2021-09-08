#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*rear = NULL, *front = NULL;
void display();
int dequeue();
void enqueue();
int peek();
struct node* newnode(int );


void main()
{
 int val,option;


 do
 {
        printf("\n****MAIN MENU****");
        printf("\n 1. Push an element into stack");
        printf("\n 2. Pop an element from stack");
        printf("\n 3. Display the stack");
        printf("\n 4. EXIT");
        printf("\n Enter your option");
        scanf("%d",&option);

        switch(option)
        {

           case 1:


               Push();
               break;


           case 2:



               Pop();
               printf("\n The pop operation is done\n");
               break;


           case 3:

               display();
               break;


        }

    }while(option !=4);

}
struct node* newnode(int item)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));

    if(node != NULL){
        node->data = item;
        node->next = NULL;
        return node;
    }
    else{
        printf("\nHeap Underflow\n");

    }
}
void enqueue(int item)

{

    struct node* n_node = newnode(item);
    printf("Inserting : %d\n", item);

    if(front == NULL)
    {
        front = n_node;
        rear = n_node;
        rear->next=front;
    }

    else
    {
        rear->next = n_node;
        rear = n_node;

    }
}
int dequeue()
{
	struct node *temp;
	temp=front;
    int val;
    val=front->data;

	if(front==NULL && rear==NULL)
	{
		printf("the node is empty");
	}
	else
    if(front==rear)
	{
		front=rear=NULL;

		free(temp);
	}
	else
	{
		front=front->next;

		free(temp);
	}
    return val;
}
void Push()
{   int x;
     printf("Enter data:");
    scanf("%d",&x);
    enqueue(x);
}
void Pop()
{
struct node *temp;
temp=front;
int count=1,data;

if(front==rear)
{
    count=1;
}
else
{
    while (temp!=rear)
    {
        count++;
        temp=temp->next;
    }

}
printf("Number= %d",count);
for(int i=0;i<count-1;i++)
{
    data=dequeue();
    enqueue(data);
}
data=dequeue();

}
void display()
	{
		struct node *temp;

        temp=front;
		if(front==NULL && rear==NULL)
	    {
		printf("the node is empty");
	    }
	   else
	   {
		while (temp!=NULL)
            {
           printf("%d",temp->data);
			temp=temp->next;
            }
        }
    }
