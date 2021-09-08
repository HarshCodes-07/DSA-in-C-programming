//DOUBLE LINKED list
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
struct node
{
    struct node *next;
    int data;
    struct node *prev;
};
struct node *start = NULL;
struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *insert_before(struct node *);
struct node *insert_after(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_before(struct node *);
struct node *delete_after(struct node *);
struct node *delete_list(struct node *);
struct node *del_dupl(struct node *start);
struct node *deleteNode(struct node* start, struct node* del);
int main()
{
    int option;
    do
    {
        printf("\n\n *****MAIN MENU *****");
        printf("\n 1: Create a list");
        printf("\n 2: Display the list");
        printf("\n 3: Add a node at the beginning");
        printf("\n 4: Add a node at the end");
        printf("\n 5: Add a node before a given node");
        printf("\n 6: Add a node after a given node");
        printf("\n 7: Delete a node from the beginning");
        printf("\n 8: Delete a node from the end");
        printf("\n 9: Delete a node before a given node");
        printf("\n 10: Delete a node after a given node");
        printf("\n 11: Delete the entire list");
        printf("\n 12: Delete the Duplicates of the list");
        printf("\n 13: EXIT");
        printf("\n\n Enter your option : ");
        scanf("%d", &option);
        switch(option)
        {
        case 1:
            start = create_ll(start);
            printf("\n DOUBLY LINKED LIST CREATED");
            break;
        case 2:
            start = display(start);
            break;
        case 3:
            start = insert_beg(start);
            break;
        case 4:
            start = insert_end(start);
            break;
        case 5:
            start = insert_before(start);
            break;
        case 6:
            start = insert_after(start);
            break;
        case 7:
            start = delete_beg(start);
            break;
        case 8:
            start = delete_end(start);
            break;
        case 9:
            start = delete_before(start);
            break;
        case 10:
            start = delete_after(start);
            break;
        case 11:
            start = delete_list(start);
            printf("\n DOUBLY LINKED LIST DELETED");
            break;
        case 12:
            start = del_dupl(start);
            printf("\n DOUBLY LINKED LIST DUPLICATES DELETED");
            break;
        }
    }
    while(option != 13);
    getch();
    return 0;
}
struct node *create_ll(struct node *start)
{
    struct node *new_node, *ptr;
    int num;
    printf("\n Enter -1 to end");
    printf("\n Enter the data : ");
    scanf("%d", &num);
    while(num != -1)
    {
        if(start == NULL)
        {
            new_node = (struct node*)malloc(sizeof(struct node));
            new_node -> prev = NULL;
            new_node -> data = num;
            new_node -> next = NULL;
            start = new_node;
        }
        else
        {
            ptr=start;
            new_node = (struct node*)malloc(sizeof(struct node));
            new_node->data=num;
            while(ptr->next!=NULL)
                ptr = ptr->next;
            ptr->next = new_node;
            new_node->prev=ptr;
            new_node->next=NULL;
        }
        printf("\n Enter the data : ");
        scanf("%d", &num);
    }
    return start;
}
struct node *display(struct node *start)
{
    struct node *ptr;
    ptr=start;
    while(ptr!=NULL)
    {
        printf("\t %d", ptr -> data);
        ptr = ptr -> next;
    }
    return start;
}
struct node *insert_beg(struct node *start)
{
    struct node *new_node;
    int num;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node -> data = num;
    start -> prev = new_node;
    new_node -> next = start;
    new_node -> prev = NULL;
    start = new_node;
    return start;
}
struct node *insert_end(struct node *start)
{
    struct node *ptr, *new_node;
    int num;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node -> data = num;
    ptr=start;
    while(ptr -> next != NULL)
        ptr = ptr -> next;
    ptr -> next = new_node;
    new_node -> prev = ptr;
    new_node -> next = NULL;
    return start;
}
struct node *insert_before(struct node *start)
{
    struct node *new_node, *ptr;
    int num, val;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    printf("\n Enter the value before which the data has to be inserted:");
    scanf("%d", &val);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node -> data = num;
    ptr = start;
    while(ptr -> data != val)
        ptr = ptr -> next;
    new_node -> next = ptr;
    new_node -> prev = ptr-> prev;
    ptr -> prev -> next = new_node;
    ptr -> prev = new_node;
    return start;
}
struct node *insert_after(struct node *start)
{
    struct node *new_node, *ptr;
    int num, val;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    printf("\n Enter the value after which the data has to be inserted:");
    scanf("%d", &val);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node -> data = num;
    ptr = start;
    while(ptr -> data != val)
        ptr = ptr -> next;
    new_node -> prev = ptr;
    new_node -> next = ptr -> next;
    ptr -> next -> prev = new_node;
    ptr -> next = new_node;
    return start;
}
struct node *delete_beg(struct node *start)
{
    struct node *ptr;
    ptr = start;
    start = start -> next;
    start -> prev = NULL;
    free(ptr);
    return start;
}
struct node *delete_end(struct node *start)
{
    struct node *ptr;
    ptr = start;
    while(ptr -> next != NULL)
        ptr = ptr -> next;
    ptr -> prev -> next = NULL;
    free(ptr);
    return start;
}
struct node *delete_after(struct node *start)
{
    struct node *ptr, *temp;
    int val;
    printf("\n Enter the value after which the node has to deleted : ");
    scanf("%d", &val);
    ptr = start;
    while(ptr -> data != val)
        ptr = ptr -> next;
    temp = ptr -> next;
    ptr -> next = temp -> next;
    temp -> next -> prev = ptr;
    free(temp);
    return start;
}
struct node *delete_before(struct node *start)
{
    struct node *ptr, *temp;
    int val;
    printf("\n Enter the value before which the node has to deleted:");
    scanf("%d", &val);
    ptr = start;
    while(ptr -> data != val)
        ptr = ptr -> next;
    temp = ptr -> prev;
    if(temp == start)
        start = delete_beg(start);
    else
    {
        ptr -> prev = temp -> prev;
        temp -> prev -> next = ptr;
    }
    free(temp);
    return start;
}
struct node *delete_list(struct node *start)
{
    while(start != NULL)
        start = delete_beg(start);
    return start;
}
struct node *del_dupl(struct node *start)
{
    if(start==NULL)
        return;
    struct node *ptr=start;
    while(ptr->next!=NULL){
        if(ptr->data==ptr->next->data)
            start=deleteNode(start,ptr->next);
        ptr=ptr->next;
    }
    return start;
};
struct node *deleteNode(struct node* start, struct node* del)
{
    if (start == NULL || del == NULL)
        return;
    if (start == del)
        start = del->next;
    if (del->next != NULL)
        del->next->prev = del->prev;
    if (del->prev != NULL)
        del->prev->next = del->next;
    free(del);
    return start;
} ;
