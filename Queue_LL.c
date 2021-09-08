#include <stdio.h>
#include <malloc.h>
struct node
{
    int data;
    struct node *next;
};
struct queue
{
    struct node *front;
    struct node *rear;
};
struct stack
{
    struct node *next;
    int data;
};
struct stack *s;
struct queue *q;
struct stack *push(struct stack *s,int val);
struct stack *pop(struct stack *s);
struct queue *create_queue(struct queue *);
struct queue *insert(struct queue *,int);
struct queue *delete_element(struct queue *);
struct queue *display(struct stack *);
int main()
{
    int val, option;
    q=create_queue(q);
    do
    {
        printf("\n *****MAIN MENU*****");
        printf("\n 1. PUSH");
        printf("\n 2. POP");
        printf("\n 3. DISPLAY");
        printf("\n 4. EXIT");
        printf("\n Enter your option : ");
        scanf("%d", &option);
        switch(option)
        {
        case 1:
            printf("\n Enter the number to insert in the queue:");
            scanf("%d", &val);
            s = push(s,val);
            break;
        case 2:
            s=pop(s);
            break;
        case 3:
            s = display(s);
            break;
        }
    }
    while(option != 5);
    getch();
    return 0;
}
struct queue *create_queue(struct queue *q)
{
    q = (struct queue*)malloc(sizeof(struct queue));
    q -> rear = NULL;
    q -> front = NULL;
    return q;
}
struct queue *insert(struct queue *q,int val)
{
    struct node *ptr;
    ptr = (struct node*)malloc(sizeof(struct node));
    ptr -> data = val;
    if(q -> front == NULL)
    {
        q -> front = ptr;
        q -> rear = ptr;
        q -> front -> next = q -> rear -> next = NULL;
    }
    else
    {
        q -> rear -> next = ptr;
        q -> rear = ptr;
        q -> rear -> next = NULL;
    }
    return q;
}
struct queue *display(struct queue *q)
{
    struct node *ptr;
    ptr = q -> front;
    if(ptr == NULL)
        printf("\n QUEUE IS EMPTY");
    else
    {
        printf("\n");
        while(ptr!=q -> rear)
        {
            printf("%d\t", ptr -> data);
            ptr = ptr -> next;
        }
        printf("%d\t", ptr -> data);
    }
    return q;
}
struct queue *delete_element(struct queue *q)
{
    struct node *ptr;
    ptr = q -> front;
    if(q -> front == NULL)
        printf("\n UNDERFLOW");
    else
    {
        q -> front = q -> front -> next;
        printf("\n The value being deleted is : %d", ptr -> data);
        free(ptr);
    }
    return q;
}

