#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node * next;
};
struct node *insert_in_empty_list(struct node *start,int key)
{
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=key;
	newnode->next=NULL;
	start=newnode;
	printf("successfully inserted the node ");
	return start;
}
void display(struct node *start)
{
	struct node *p;//for traversing through the list
	p=start;
	int i=1;
	if(start ==NULL){
		printf("list is empty");
		return ;
	}	
	while(p != NULL){
		printf("\ndata of the node %d :\n",i++);
		printf("%d",p->data);
		p=p->next;
	}	

	return ;
}	
int main ()
{
	struct node *head=NULL;
	printf("enter the key you want to insert in the empty list:\n");
	int n;
	scanf("%d",&n);
	head=insert_in_empty_list(head,n);
	//struct node *new_head=(struct node *)malloc(sizeof(struct node ) );
	//new_head=insert_at_beggining(head,n);
	display(head);
	return 0;
}
	