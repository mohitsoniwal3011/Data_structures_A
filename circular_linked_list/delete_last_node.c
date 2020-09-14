#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node *next;
} ;
struct node *create_list()
{
	printf("enter the number of nodes you want to create:\n");
	int n,i=1;
	scanf("%d",&n);
	if(n==0){
		struct node *last=NULL;
		printf("created an empty list \n");
		return last;
	}		
	struct node *newnode,*last,*temp;
	struct node *head=NULL;
	if(n==1){
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("enter the data for node %d:\n",i);
		scanf("%d",&newnode->data);
		last=newnode;
		last->next=last;
		return last;
	}
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("enter the data for node %d:\n",i);
	scanf("%d",&newnode->data);
	head=newnode;
	temp=head;
	for(i=2;i<=n;i++){
		if(i == n){
			newnode=(struct node *)malloc(sizeof(struct node ));
			printf("enter the data for node %d:\n",i);
			scanf("%d",&newnode->data);
			newnode->next=head;
			temp->next=newnode;
			last=newnode;
			return last;
		}		
		newnode=(struct node *)malloc(sizeof(struct node ));
		printf("enter the data for node %d:\n",i);
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		temp->next=newnode;
		temp=newnode;
	}
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
struct node * delete_last_node(struct node *last)
{
	if(last ==NULL){
		printf("list is empty\n");
		return last;
	}
	if(last->next==last){
		last->next=NULL;
		free(last);
		last=NULL;
		printf("successfully deleted the  node \n");
		return last;
	}
	struct node *temp,*p;
	p=last;
	temp=last->next;
	while(p->next != last){
		p=p->next;
	}	
			temp=p->next;
			p->next=last->next;
			temp->next=NULL;
			last=p;
			free(temp);
			printf("successfully deleted and freed memory \n");
			return last;
	printf("successfully deleted last node and freed memory\n");
	return p;
}			
int main ()
{
	struct node *tail=(struct node *)malloc(sizeof(struct node ));
	tail=create_list();
	//printf("enter the key you want to insert at the last of the list:\n");
	//int n;
	//scanf("%d",&n);
	struct node *new_tail=(struct node *)malloc(sizeof(struct node ) );
	new_tail=delete_last_node(tail);
	display(new_tail);
	return 0;
}	
		