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
void insert_after(struct node *start)
{	
	struct node *newnode;
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("enter the data to want to insert:\n");
	scanf("%d",&newnode->data);
	int element;
	printf("enter the element after which you want to insert \n");
	scanf("%d",&element);
	struct node *p,*temp;
	p=start;
	while(p->next != NULL){
		temp=p->next;
		if(p->data == element){
			p->next=newnode;
			newnode->prev=p;
			temp->prev=newnode;
			newnode->next=temp;
			printf("inserted successfully\n");
			return ;
			
		}
		p=p->next;
	}
	if(p->data==element){
		p->next=newnode;
		newnode->prev=p;
		newnode->next=NULL;
	}
	printf("element is not present in the list\n");
	return ;
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
	//struct node *new_head=(struct node *)malloc(sizeof(struct node));
	insert_after(head);
	display(head);
	return 0;
}	
	
	
		