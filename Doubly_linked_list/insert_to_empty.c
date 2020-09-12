#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node *prev;
	struct node *next;
} ;
struct node *insert_to_empty(struct node *start)
{	
	if(start != NULL){
		printf("the list is not empty \n");
		return start ;
	}
	start=malloc(sizeof(struct node ));
	printf("enter the data you want to insert:\n");
	scanf("%d",&start->data);
	start->next=NULL;
	start->prev=NULL;
	return start;
}
void display(struct node * start)
{
	struct node *p;
	p=start;
	int i=1;
	if(start==NULL){
		printf("the list is empty \n");
		return ;
	}
	while(p !=NULL ){
		printf("data of te node %d:\n",i++);
		printf("%d\n",p->data);
		p=p->next;
	}
	return ;
}	
int main ()
{
	struct node *head=NULL;
	struct node *new_head=(struct node *)malloc(sizeof(struct node));
	new_head=insert_to_empty(head);
	display(new_head);
	return 0;
}	
	
	
	
	
		
		