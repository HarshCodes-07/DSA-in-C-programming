//WAP TO ROTATE COUNTER CLOCKWISE BY K TO A LINKED LIST
#include<stdio.h>
#include<malloc.h>
struct node{
   int data;
   struct node *next;
};
struct node *start=NULL;
struct node *temp=NULL;
void insert(int val){
   struct node* newnode = (struct node*)malloc(sizeof(struct node));
   newnode->data = val;
   newnode->next = NULL;
   if(start == NULL){
      start = newnode;
      temp = start;
   } else {
      temp->next=newnode;
      temp=temp->next;
   }
}
int countNodes(){
    int count =0;
    struct node *temp=start;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}
void display(){
   if(start==NULL)
      printf("\nThe List Is Empty");
   else {
      temp=start;
      while(temp!=NULL) {
         printf("%d ",temp->data);
         temp=temp->next;
      }
   }
}
void dd(struct node *start){
   if(start==NULL)
      printf("\nThe List Is Empty");
   else {
      temp=start;
      while(temp!=NULL) {
         printf("%d ",temp->data);
         temp=temp->next;
      }
   }
}
void reverseK(int k){
    struct node *beg = start;
    int count = 1;
    while (count < k) {
        beg = beg->next;
        count++;
    }
    struct node *end = beg->next;
    beg->next = NULL;
    struct node *temp=end;
    while(end->next!=NULL)
        end=end->next;
    end->next=start;
    start=temp;
}
int main(){
   struct node* head = NULL;
   int n;
   printf("\nEnter no of elements to insert : ");
   scanf("%d",&n);
   printf("\nEnter %d Elements : ",n);
   for(int i=0;i<n;i++){
        int x;
   scanf("%d",&x);
    insert(x);
   }
   printf("\nLinked list is : ");
   display();
   int k;
   printf("\nEnter the index K to rotate : ");
   scanf("%d",&k);
   reverseK(k);
   display();
   return 0;
}
