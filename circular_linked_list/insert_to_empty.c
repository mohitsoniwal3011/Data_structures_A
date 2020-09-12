#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node *next;
} ;
struct node *insert_to_empty(struct node *last)
{
	if(last != NULL){
		printf("the list is not empty\n");
		return last;
	}
	struct node *newnode;	
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("enter the data to be inserted:\n");
	scanf("%d",&newnode->data);
	last=newnode;
	last->next=last;
	printf("inserted successfully \n");
	return last;
	
}
void display(struct node *last)
{
	struct node *p;//for traversing through the list
	int i=1;
	if(last == NULL){
		printf("the list is empty\n");
		return ;
	}
	p=last->next;
	do{
		printf("\ndata of the node %d :\n",i++);
		printf("%d",p->data);
		p=p->next;
	}while(p != last->next);
	//if we use while loop then in very first iteration codition of the while loop will be violated.
	//and nothing will be printed.
	return ;
}	

	
int main ()
{
	struct node *tail=NULL;
	struct node *new_tail=(struct node *)malloc(sizeof(struct node ) );
	new_tail=insert_to_empty(tail);
	display(new_tail);
	return 0;
}	
		