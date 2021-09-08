#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
};

struct node* start=NULL;
struct node* createNode()
{
    start=(struct node*)malloc(sizeof(struct node));
    return start;
}
void insertNode_atEnd(struct node **start)
{
    struct node *temp,*t;
    temp=createNode();
    printf("Enter a number");
    scanf("%d",&temp->info);
    temp->link=NULL; //since it is last node
    if(*start==NULL)
        *start =temp;
    else
    {
        t=*start;
        while(t->link!=NULL)
            t=t->link;
        t->link=temp;
    }
}

void swap(struct node **start,int loc)
{
    int c=0;
    struct node *t,*p,*q,*r;
    if(*start==NULL)
        printf("List is empty");
    else
    {
        t=*start;
        while(t!=NULL)
        {
            c++;
            if(c==loc-1)
            {
                p=t;
                q=p->link;
                r=q->link;
                break;
            }
            t=t->link;
        }
        p->link=r;
        q->link=r->link;
        r->link=q;
    }
}
int length(struct node **start)
{
    int c=0;
    struct node *t;
    if(*start==NULL)
        return 0;
    else
    {
        t=*start;
        while(t!=NULL)
        {
            c++;
            t=t->link;
        }
        return c;
    }
}
void viewList(struct node **start)
{
    struct node *t;
    if(*start==NULL)
        printf("List is empty");
    else
    {
        t=*start;
        while(t!=NULL)
        {
            printf("%d\t",t->info);
            t=t->link;
        }
    }
}
void main()
{
    struct node *start=NULL;
    while(1)
    {
        int ch;
        printf("\n1.Add value to end of SLL");
        //printf("\n2.Swap 2 adjacent nodes of SLL");
        printf("\n2.Pairwise swap SLL");
        printf("\n3.View List");
        printf("\n4.Length of linked list");
        printf("\n5.Exit");
        printf("\n\nEnter your choice");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            insertNode_atEnd(&start);
            break;
       // case 2: { int loc; printf("Position to swap");
        //scanf("%d",&loc);
    //     swap(&start,0); }
        case 2:
        {
            for(int i=2; i<length(&start); i++){
                if(i%2==1) swap(&start,i);
            }
            break;
        }
        case 3:
            viewList(&start);
            break;
        case 4:
            printf("%d",length(&start));
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Invalid Choice");
        }
    }
}
