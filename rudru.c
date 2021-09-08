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
void delete_node(struct node *,int);
struct node *deleteK(struct node *,int);
struct node *delete_beg(struct node *start)
{
    struct node *ptr;
    struct node *temp;
    ptr = start;
    while(ptr -> next != start)
        ptr = ptr -> next;
    ptr -> next = start -> next;
    temp = start;
    start=start->next;
    start->prev=ptr;
    free(temp);
    return start;
}
int main()
{
    int option,k;
    do
    {
        printf("\n\n *****MAIN MENU *****");
        printf("\n 1: Create a list");
        printf("\n 2: Display the list");
        printf("\n 3: Add a node at the beginning");
        printf("\n 4: Add a node at the end");
        printf("\n 5: Delete a given node");
        printf("\n 6: EXIT");
        printf("\n\n Enter your option : ");
        scanf("%d", &option);
        switch(option)
        {
        case 1:
            start = create_ll(start);
            printf("\n CIRCULAR DOUBLY LINKED LIST CREATED");
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
            printf("\nEnter K : ");
            scanf("%d",&k);
            start = deleteK(start,k);
            break;
        }
    }
    while(option != 6);
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
while(num!=-1)
{
 new_node = (struct node*)malloc(sizeof(struct node));
 new_node -> data = num;
 if(start == NULL)
 {
 new_node -> next = new_node;
 start = new_node;
 }
 else
 { ptr = start;
 while(ptr -> next != start)
 ptr = ptr -> next;
 ptr -> next = new_node;
 new_node -> next = start;
 }
 printf("\n Enter the data : ");
 scanf("%d", &num);
}
return start;
}
struct node *display(struct node *start)
{
    struct node *ptr;
    ptr = start;
    while(ptr -> next != start)
    {
        printf("\t %d", ptr -> data);
        ptr = ptr -> next;
    }
    printf("\t %d", ptr -> data);
    return start;
}
struct node *insert_beg(struct node *start)
{
    struct node *new_node, *ptr;
    int num;
    printf("\n Enter the data : ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node-> data = num;
    ptr = start;
    while(ptr -> next != start)
        ptr = ptr -> next;
    new_node -> prev = ptr;
    ptr -> next = new_node;
    new_node -> next = start;
    start -> prev = new_node;
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
    ptr = start;
    while(ptr -> next != start)
        ptr = ptr -> next;
    ptr -> next = new_node;
    new_node -> prev = ptr;
    new_node -> next = start;
    start-> prev = new_node;
    return start;
}
void delete_node(struct node* head, int key)
{
    if (head == NULL)
        return;
    struct node *curr = head, *prev;
    while (curr->data != key) {
        if (curr->next == head) {
                return;
            break;
        }
        prev = curr;
        curr = curr->next;
    }
    if (curr->next == head) {
        head = NULL;
        free(curr);
        return;
    }
    if (curr == head) {
        prev = head;
        while (prev->next != head)
            prev = prev->next;
        head = curr->next;
        prev->next = head;
        free(curr);
    }
    else if (curr->next == head) {
        prev->next = head;
        free(curr);
    }
    else {
        prev->next = curr->next;
        free(curr);
    }
}
struct node *deleteK(struct node *start,int k){
    struct node *ptr;
    ptr = start;
    while(ptr -> next != start)
    {
        if(ptr->data%k==0){
            delete_node(start,ptr->data);
        }
        ptr = ptr -> next;
    }
    printf("\t %d", ptr -> data);
    return start;
};
