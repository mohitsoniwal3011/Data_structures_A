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
	return last	;
	
}
struct node *delete_after(struct node *last)
{
	
	if(last ==NULL){
		printf("the list is empty \n");
	}
	printf("enter the element you want to delete from the list:\n");
	int element ;
	
		
	scanf("%d",&element);
	struct node *p,*temp;
	if(last->next==last && last->data ==element){
		temp=last;
		last=NULL;
		free(temp);
		printf("successfully deleted and freed memory \n");
		return last;
	}	
		
	p=last->next;
	if(p->data==element){
		last->next=p->next;
		p->next=NULL;
		free(p);
		printf("successfully deleted and freed memory \n");
		return last;
	}
	int visit=1;
	while(p->next != last){
		//printf("number of visite :    %d \n",visit++);
		temp=p->next;
		if(temp->data==element && temp !=last){
			p->next=temp->next;
			temp->next=NULL;
			free(temp);
			printf("successfully deleted and freed memory \n");
			return last;
		}	
		p=p->next;
	}
	if(p->next->data ==element){
			temp=p->next;
			p->next=last->next;
			temp->next=NULL;
			last=p;
			free(temp);
			printf("successfully deleted and freed memory \n");
			return last;
	}
	printf("the element is not present in  the list\n");
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
	struct node *tail=(struct node *)malloc(sizeof(struct node ));
	tail=create_list();
	struct node *new_tail=(struct node *)malloc(sizeof(struct node ));
	new_tail=delete_after(tail);
	display(new_tail);
	return 0;
}	