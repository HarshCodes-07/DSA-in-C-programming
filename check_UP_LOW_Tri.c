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

struct node *start = NULL;
struct node *create_sparse(struct node *);
struct node *display_sparse(struct node *);
struct node *check_Matrix(struct node *);
int *checkUp(struct node *);
int *checkLow(struct node *);
int *checkTri(struct node *);
int main()
{
    int option;
    do
    {
        printf("\n******* MAIN MENU *******");
        printf("\n 1. Enter the Matrix");
        printf("\n 2. Display the Sparse Matrix in Linked List Format");
        printf("\n 3. Check if Given Matrix is Lower Triagnol , Upper Triganol or TriDiagnol");
        printf("\n 4. EXIT");
        printf("\n\n Enter your option : ");
        scanf("%d", &option);
        switch(option)
        {
        case 1:
            start = create_sparse(start);
            break;
        case 2:
            start = display_sparse(start);
            break;
        case 3:
            start = check_Matrix(start);
            break;
        }
    }
    while(option!=4);
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
struct node *check_Matrix(struct node *start){
    struct node *ptr=start;
    if(checkUp(ptr)==1){
        printf("\n It is Upper Triagnol.");
    }else{
        printf("\n It is not Upper Triagnol.");
    }
    if(checkLow(ptr)==1){
        printf("\n It is Lower Triagnol.");
    }else{
        printf("\n It is not Lower Triagnol.");
    }
    if(checkTri(ptr)==1){
        printf("\n It is Tri Diagnol.");
    }else{
        printf("\n It is not Tri Diagnol.");
    }
    return start;
};
int *checkUp(struct node *start){
    struct node *ptr=start;
    while(ptr!=NULL){
        if(ptr->column<ptr->row){
            if(ptr->num!=0){
                return 0;
            }
        }
        ptr=ptr->next;
    }
    return 1;
}
int *checkLow(struct node *start){
    struct node *ptr=start;
    while(ptr!=NULL){
        if(ptr->column>ptr->row){
            if(ptr->num!=0){
                return 0;
            }
        }
        ptr=ptr->next;
    }
    return 1;
}
int *checkTri(struct node *start){
    struct node *ptr=start;
    while(ptr!=NULL){
        if(ptr->column==ptr->row || ptr->column==ptr->row-1 || ptr->column-1==ptr->row){
            if(ptr->num==0){
                return 0;
            }
        }else{
            if(ptr->num!=0){
                return 0;
            }
        }
        ptr=ptr->next;
    }
    return 1;
}

