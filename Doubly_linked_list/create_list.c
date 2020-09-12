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
	display(head);
	return 0;
}	
	
	
		