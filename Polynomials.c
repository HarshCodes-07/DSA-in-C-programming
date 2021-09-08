#include <stdio.h>
#include <conio.h>
#include <malloc.h>
struct node
{
    int num;
    int coeff;
    struct node *next;
};
struct node *start1 = NULL;
struct node *start2 = NULL;
struct node *start3 = NULL;
struct node *last3 = NULL;
struct node *create_poly(struct node *);
struct node *display_poly(struct node *);
struct node *add_poly(struct node *, struct node *, struct node *);
struct node *add_node(struct node *, int, int);
int main()
{
    int option;
    do
    {
        printf("\n******* MAIN MENU *******");
        printf("\n 1. Enter the first polynomial");
        printf("\n 2. Display the first polynomial");
        printf("\n 3. EXIT");
        printf("\n\n Enter your option : ");
        scanf("%d", &option);
        switch(option)
        {
        case 1:
            start1 = create_poly(start1);
            break;
        case 2:
            start1 = display_poly(start1);
            break;
        }
    }
    while(option!=3);
    getch();
    return 0;
}
struct node *create_poly(struct node *start)
{
    struct node *new_node, *ptr;
    int n, c;
    printf("\n Enter the number : ");
    scanf("%d", &n);
    printf("\t Enter its coefficient : ");
    scanf("%d", &c);
    while(n != -1)
    {
        if(start==NULL)
        {
            new_node = (struct node *)malloc(sizeof(struct node));
            new_node -> num = n;
            new_node -> coeff = c;
            new_node -> next = NULL;
            start = new_node;
        }
        else
        {
            ptr = start;
            while(ptr -> next != NULL)
                ptr = ptr -> next;
            new_node = (struct node *)malloc(sizeof(struct node));
            new_node -> num = n;
            new_node -> coeff = c;
            new_node -> next = NULL;
            ptr -> next = new_node;
        }
        printf("\n Enter the number : ");
        scanf("%d", &n);
        if(n == -1)
            break;
        printf("\t Enter its coefficient : ");
        scanf("%d", &c);
    }
    return start;
}
struct node *display_poly(struct node *start)
{
    struct node *ptr;
    ptr = start;
    while(ptr != NULL)
    {
        printf("\n%dx^%d\t", ptr -> num, ptr -> coeff);
        ptr = ptr -> next;
    }
    return start;
}
