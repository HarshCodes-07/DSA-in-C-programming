#include<stdio.h>
#include<malloc.h>
#include<stddef.h>

struct node
{
    int data;
    struct node *next;
};

struct node *createlist(struct node *head);
struct node *display(struct node *head);
int count(struct node *head);
struct node *insertbeg(struct node *head);
struct node *insertend(struct node *head);
struct node *insertpos(struct node *head);

int main()
{
    struct node *head;
    int opt;
    int choicee;

    do
    {
        printf("Enter your choice for performing an operation on single linked list:\n\n1. Creation\n2. Traversal (Display)\n3. Insertion at beginning\n4. Insertion at end\n5. Insertion at a specific location\n");
        scanf("%d",&opt);

        printf("\n");
        switch(opt)
        {
        case 1:
            head=createlist(head);
            break;

        case 2:
            head=display(head);
            break;

        case 3:
            head=insertbeg(head);
            break;

        case 4:
            head=insertend(head);
            break;

        case 5:
            head=insertpos(head);
            break;

        default:
            printf("INVALID OPTION !\n");
            break;
        }

        printf("Do you want to continue the program (1/0) ?: ");
        scanf("%d",&choicee);
    }
    while(choicee);

    return 0;
}

struct node *createlist(struct node *head)
{
    struct node *newnode, *temp;
    head=NULL;
    int i=1;
    int choice;
    do
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data in the node %d : ",i);
        scanf("%d",&newnode->data);
        newnode->next=NULL;

        if(head==NULL)
            head=temp=newnode;
        else
        {
            temp->next=newnode;
            temp=newnode;
        }

        i++;

        printf("Do you want to continue (0/1) ?  ");
        scanf("%d",&choice);
        printf("\n");
    }
    while(choice);
    return head;
}
struct node *display(struct node *head)
{
    struct node *temp;
    printf("The data in the linked list is: ");
    temp=head;
    while(temp!=NULL)
    {
        printf("%d  ",temp->data);
        temp=temp->next;
    }
    printf("\n");
    return head;
}

int count(struct node *head)
{
    struct node *temp;
    int countt=0;
    temp=head;
    while(temp!=NULL)
    {
        temp=temp->next;
        countt++;
    }
    return countt;
}

struct node *insertbeg(struct node *head)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data you want to insert in the beginning: ");
    scanf("%d",&newnode->data);
    newnode->next=head;
    head=newnode;

    head=display(head);
    return head;
}

struct node *insertend(struct node *head)
{
    struct node *newnode, *temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter data you want to insert in the end: ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=newnode;

    head=display(head);
    return head;
}
struct node *insertpos(struct node *head)
{
    struct node *newnode, *temp;
    int pos;
    int j=1;
    int count1=count(head);
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nNOTE: The default position starts from 0.\n");
    printf("Enter the position at which you want to insert: ");
    scanf("%d",&pos);
    if(pos>count1)
        printf("INVALID POSITION !");
    else
    {
        temp=head;
        while(j<pos)
        {
            temp=temp->next;
            j++;
        }
        printf("Enter data: ");
        scanf("%d",&newnode->data);
        newnode->next=temp->next;
        temp->next=newnode;
    }

    head=display(head);
    return head;
}
