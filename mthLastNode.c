#include<stdio.h>
#include<stdlib.h>
//structure of a node
struct node{
   int data;
   struct node *next;
};
struct node *start=NULL;
struct node *temp=NULL;
int count=0;
void last(int m){
    temp=start;
    for(int i=0;i<count-m;i++){
        temp=temp->next;
    }
    printf("\nThe %d Last Element is : %d ",m,temp->data);
}
void insert(int val){
   struct node* newnode = (struct node*)malloc(sizeof(struct node));
   newnode->data = val;
   newnode->next = NULL;
   if(start == NULL){
      start = newnode;
      temp = start;
      count++;
   } else {
      temp->next=newnode;
      temp=temp->next;
      count++;
   }
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
   int m;
   printf("\nEnter m : ");
   scanf("%d",&m);
   last(m);
   return 0;
}
