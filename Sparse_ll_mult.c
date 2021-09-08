#include<stdio.h>
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
struct node
{
    int row;
    int column;
    int num;
    struct node *next;
};
struct node *start1 = NULL;
struct node *start2 = NULL;
struct node *start3 = NULL;
struct node *create_sparse(struct node *);
struct node *display_sparse(struct node *);
struct node *add_sparse(struct node *start1, struct node *start2, struct node *start3);
struct node *add_node(struct node *start3, int n, int r,int c);
struct node *mult_sparse(struct node *start1, struct node *start2, struct node *start4);
int main()
{
    int option;
    do
    {
        printf("\n******* MAIN MENU *******");
        printf("\n 1. Enter the First Matrix");
        printf("\n 2. Display the first Sparse");
        printf("\n 3. Enter the second Matrix");
        printf("\n 4. Display the second Sparse");
        printf("\n 5. Multiply the two sparse Matrix");
        printf("\n 6. Display the result");
        printf("\n 9. EXIT");
        printf("\n\n Enter your option : ");
        scanf("%d", &option);
        switch(option)
        {
        case 1:
            start1 = create_sparse(start1);
            break;
        case 2:
            start1 = display_sparse(start1);
            break;
        case 3:
            start2 = create_sparse(start2);
            break;
        case 4:
            start2 = display_sparse(start2);
            break;
        case 5:
            start3 = mult_sparse(start1, start2, start3);
            break;
        case 6:
            start3 = display_sparse(start3);
            break;
        }
    }
    while(option!=9);
    getch();
    return 0;
}
struct node *create_sparse(struct node *start)
{
    struct node *new_node, *ptr;
    int r, c;
    printf("\n Enter the number of row and column : ");
    scanf("%d %d", &r,&c);
    int a[r][c];
    printf("\nEnter %d numbers : ",r*c);
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            printf("\nEnter %d %d Element : ",i,j);
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(a[i][j]!=0)
            {
                if(start==NULL)
                {
                    new_node = (struct node *)malloc(sizeof(struct node));
                    new_node -> num = a[i][j];
                    new_node -> row = i;
                    new_node -> column = j;
                    new_node->next=NULL;
                    start = new_node;
                }
                else
                {
                    ptr = start;
                    while(ptr -> next != NULL)
                        ptr = ptr -> next;
                    new_node = (struct node *)malloc(sizeof(struct node));
                    new_node -> num = a[i][j];
                    new_node -> row = i;
                    new_node -> column = j;
                    new_node -> next = NULL;
                    ptr -> next = new_node;
                }
            }
        }
    }
    return start;
}

struct node *display_sparse(struct node *start)
{
    struct node *ptr;
    ptr = start;
    while(ptr != NULL)
    {
        printf("\n\t%d\t%d\t%d", ptr -> row, ptr -> column,ptr->num);
        ptr = ptr -> next;
    }
    return start;
}
struct node *mult_sparse(struct node *start1, struct node *start2, struct node *start4)
{
    struct node *ptr1,*ptr2,*start5;
    ptr1=start1;
    while(ptr1!=NULL)
    {
        ptr2=start2;
        struct node *temp=NULL;
        start5=NULL;
        while(ptr2!=NULL)
        {
            if(ptr1->column==ptr2->row){
            temp=add_node(temp,ptr1->num*ptr2->num,ptr1->row,ptr2->column);
            }
            ptr2=ptr2->next;
        }
        start4=add_sparse(start4,temp,start5);
        ptr1=ptr1->next;
    }
    return start4;
}

struct node *add_sparse(struct node *start1, struct node *start2, struct node *start3)
{
    struct node *ptr1,*ptr2;
    ptr1=start1;
    ptr2=start2;
    int sum;
    while(ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1->row==ptr2->row && ptr1->column==ptr2->column){
            //direct Add
            sum=ptr1->num+ptr2->num;
            start3=add_node(start3,sum,ptr1->row,ptr2->column);
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }else if((ptr1->row==ptr2->row && ptr1->column < ptr2->column)||(ptr1->row<ptr2->row)){
            //add ptr1 and move
            start3=add_node(start3,ptr1->num,ptr1->row,ptr1->column);
            ptr1=ptr1->next;
        }else{
            //add ptr2 and move
            start3=add_node(start3,ptr2->num,ptr2->row,ptr2->column);
            ptr2=ptr2->next;
        }
    }
    if(ptr1!=NULL){
        while(ptr1!=NULL){
            start3=add_node(start3,ptr1->num,ptr1->row,ptr1->column);
            ptr1=ptr1->next;
        }
    }
    if(ptr2!=NULL){
        while(ptr2!=NULL){
            start3=add_node(start3,ptr2->num,ptr2->row,ptr2->column);
            ptr2=ptr2->next;
        }
    }
    return start3;
}
struct node *add_node(struct node *start3, int n, int r, int c)
{
    struct node *ptr, *new_node;
    if(start3 == NULL)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node -> num = n;
        new_node->row=r;
        new_node -> column = c;
        new_node -> next = NULL;
        start3 = new_node;
    }
    else
    {
        ptr = start3;
        while(ptr -> next != NULL)
            ptr = ptr -> next;
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node -> num = n;
        new_node->row=r;
        new_node -> column = c;
        new_node -> next = NULL;
        ptr -> next = new_node;
    }
    return start3;
};

