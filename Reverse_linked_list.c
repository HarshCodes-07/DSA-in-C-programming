//Reverse a linked List
#include<stdio.h>
#include<malloc.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node *add(struct Node *start,int x){
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data=x;
    new_node->next=start;
    start=new_node;
    return start;
}
struct Node *printing(struct Node* start){
    struct Node *ptr=start;
    while(ptr!=NULL){
        printf("%d  ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
    return start;
}
struct Node *reverse(struct Node* start){
    struct Node *ptr;
    ptr = start;
    struct Node *prev=NULL;
    struct Node *temp;
    while(ptr!=NULL){
        temp=ptr->next;
        ptr->next=prev;
        prev=ptr;
        ptr=temp;
    }
    start=prev;
    return start;
}
int main(){
    struct Node* start=NULL;
    int n;
    printf("\nEnter the Number of elements to add : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        start = add(start,x);
    }
    printf("Given List : ");
    start = printing(start);
    printf("After Reversing the List : ");
    start=reverse(start);
    start = printing(start);
}
