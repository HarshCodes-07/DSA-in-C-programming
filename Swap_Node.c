//WAP TO SWAP KTH NODE FROM BEGINNING WITH KTH NODE FROM END IN A LINKED LIST
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
void swapKth(int k){
    struct node *x, *y, *prev_x = NULL, *prev_y = start;
	struct node *curr = start;
	for (int i = 1; i < k && curr!=NULL; i++) {
		prev_x = curr;
		curr = curr->next;
	}
	x = curr;
	if (curr == NULL)
		return;
	struct node *ptr = start;
	while (curr->next) {
		prev_y = ptr;
		ptr = ptr->next;
		curr = curr->next;
	}
	y = ptr;
	if (x->next == y){
		x->next = y->next;
		y->next = x;
		prev_x->next = y;
	}
	else if (y->next == x){
		y->next = x->next;
		x->next = y;
		prev_y->next = x;
	}
	else if (x == start){
		start= y;
		y->next = x->next;
		prev_y->next = x;
		x->next = NULL;
	}
	else if (y == start){
		start = x;
		x->next = y->next;
		prev_x->next = y;
		y->next = NULL;
	}
	else {
		ptr = y->next;
		y->next = x->next;
		x->next = ptr;
		prev_x->next = y;
		prev_y->next = x;
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
   display();
   int k;
   printf("\nEnter the index K : ");
   scanf("%d",&k);
   swapKth(k);
   display();
   return 0;
}
