#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node *prev;
	struct node *next;
} ;
struct node *create_list()
{
	int n,i=1;
	printf("enter the number of nodes you want to create:\n");
	scanf("%d",&n);
	if(n==0){
		struct node *head=NULL;
		printf("created an empty list\n");
		return head;
	}
	struct node *start,*temp,*newnode;
	//temp for traversing throiugh the list ,newnode for creating any newnode and 
	//start to store the address of the first node  
	//creating the head node ;
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("enter the data for the node %d:\n",i);
	scanf("%d",&newnode->data);
	newnode->prev=NULL;
	newnode->next=NULL;
	start=newnode;
	temp=start;
	//creating other nodes ;
	for(i=2;i<=n;i++){
		newnode=(struct node *)malloc(sizeof(struct node) );
		printf("enter data for the node %d:\n",i);
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		newnode->prev=temp;
		temp->next=newnode;
		temp=temp->next;
	}
	return start;
}
struct node *insert_at_position(struct node *start)
{	
	struct node *newnode,*p,*temp;
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("enter the element you want to insert:\n");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	newnode->prev=NULL;
	int position;
	printf("enter the position at which you want to insert the data\n");
	scanf("%d",&position);
	int i=1;
	if(position == 1){
		newnode->next=start;
		start->prev=newnode;
		start=newnode;
		return start;
	}
	i=2;
	p=start->next;
	while(p != NULL){
		if(i == position){
			temp=p->prev;
			temp->next=newnode;
			newnode->prev=temp;
			newnode->next=p;
			p->prev=newnode;
			return start;
		}
		if(p->next== NULL){
			p=p->next;
		}
		else{
			p=p->next;
			i++;
		}
	}
	printf("ERROR: there are only %d loops in the  list\n",i);
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
	struct node *head=(struct node *)malloc(sizeof(struct node));
	head=create_list();
	struct node *new_head=(struct node *)malloc(sizeof(struct node));
	new_head=insert_at_position(head);
	display(new_head);
	return 0;
}	
	
	
		