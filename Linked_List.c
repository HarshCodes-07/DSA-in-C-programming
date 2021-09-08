#include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    struct node *next;
};

struct node *start=NULL;
struct node *traverse(struct node *);
struct node *isEmpty(struct node *);
struct node *insert(struct node *);
struct node *del(struct node *);
struct node *del_key(struct node *);
struct node *count_Nodes(struct node *);
struct node *search(struct node *);
struct node *insert_beg(struct node *head);
struct node *insert_end(struct node *head);
struct node *insert_any(struct node *head);
struct node *del_beg(struct node *head);
struct node *del_end(struct node *head);
struct node *del_any(struct node *head);
void rearrange(struct node *head);

int main(){
    int option;
    do{
        printf("\n*****MAIN MENU*****\n");
        printf("\n1) TRAVERSE");
        printf("\n2) CHECK FOR EMPTY");
        printf("\n3) INSERT");
        printf("\n4) DELETE");
        printf("\n5) DELETE BY KEY");
        printf("\n6) COUNT NODES");
        printf("\n7) SEARCH");
        printf("\n8) EXIT");
        printf("\nEnter your Option : ");
        scanf("%d",&option);
        switch(option){
        case 1:
            {start=traverse(start);
            break;}
        case 2:
            {start=isEmpty(start);
            break;}
        case 3:
            {start=insert(start);
            break;}
        case 4:
            {start=del(start);
            break;}
        case 5:
            {start=del_key(start);
            break;}
        case 6:
            {start=count_Nodes(start);
            break;}
        case 7:
            {start=search(start);
            break;}
        }
    }while(option!=8);
}

struct node *traverse(struct node *head){
    struct node *ptr;
    ptr=head;
    if(ptr==NULL)
        printf("\nThe List is Empty");
    else{
        printf("\nPrinting the Linked List : ");
        while(ptr!=NULL){
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
        printf("\n");
    }
    return start;
}
struct node *isEmpty(struct node *head){
    struct node *ptr;
    ptr=head;
    if(ptr==NULL)
        printf("\nThe List is Empty");
    else
        printf("\nThe List is Not Empty");
}

struct node *insert(struct node *start){
    int option;
    printf("\n***INSERT MENU***\n");
    printf("\n1)At Beginning");
    printf("\n2)At End");
    printf("\n3)At Position");
    printf("\nEnter the option : ");
    scanf("%d",&option);
    switch(option){
        case 1:
            start=insert_beg(start);
            break;
        case 2:
            start=insert_end(start);
            break;
        case 3:
            start=insert_any(start);
            break;
    }
    return start;
}
struct node *insert_beg(struct node *start){
    int new_data;
    printf("\nEnter the Element to Insert : ");
    scanf("%d",&new_data);
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data  = new_data;
    new_node->next = start;
    start = new_node;
    return start;
}
struct node *insert_end(struct node *start){
    int new_data;
    printf("\nEnter the Element to Insert : ");
    scanf("%d",&new_data);
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    struct node* ptr=start;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    new_node->data=new_data;
    ptr->next=new_node;
    new_node->next=NULL;
    return start;
}
struct node *insert_any(struct node *start) {
    int data,position;
    printf("\nEnter Element : ");
    scanf("%d",&data);
    printf("\nEnter Position : ");
    scanf("%d",&position);
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    struct node *prev, *cur;
    prev = NULL;
    cur = start;
    while(position)
    {
        prev = cur;
        cur = cur->next;
        --position;
    }
    if(prev){
        prev->next = temp;
        temp->next = cur;
    }
    else{
       temp->next = cur;
       start = temp;
    }
    return start;
}



struct node *del(struct node *start){
 int option;
    printf("\n***DELETE MENU***\n");
    printf("\n1)At Beginning");
    printf("\n2)At End");
    printf("\n3)At Position");
    printf("\nEnter the option : ");
    scanf("%d",&option);
    switch(option){
        case 1:
            start=del_beg(start);
            break;
        case 2:
            start=del_end(start);
            break;
        case 3:
            start=del_any(start);
            break;
    }
    return start;
}
struct node *del_beg(struct node *start){
    return start->next;
}
struct node *del_end(struct node *start){
    struct node *ptr;
    ptr=start;
    struct node *curr;
    while(ptr->next!=NULL){
            curr=ptr;
        ptr=ptr->next;
    }
    curr->next=NULL;
    return start;
}
struct node *del_any(struct node *start){

}
struct node *del_key(struct node *start){

}
struct node *count_Nodes(struct node *start){
    struct node *ptr;
    ptr=start;
    int c=0;
    while(ptr!=NULL){
            c++;
            ptr=ptr->next;
    }
    printf("NO OF NODE : %d",c);
    return start;
}
struct node *search(struct node *start){
    int n;
    printf("\nEnter the Element to be searched : ");
    scanf("%d",&n);
    struct node *ptr;
    ptr=start;
    if(ptr==NULL)
        printf("\nThe List is Empty");
    else{
        printf("\nPrinting the Linked List : ");
        while(ptr!=NULL){
            if(ptr->data==n)
            {
                printf("\nElement is Present");
                break;
            }
            ptr=ptr->next;
        }
    }
    return start;
}
