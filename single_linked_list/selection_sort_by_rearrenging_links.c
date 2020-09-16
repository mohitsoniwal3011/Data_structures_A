#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node * next;
};
struct node * create_list()
{
	int i,n;
	printf("enter the number of nodes you want to create \n");
	scanf("%d",&n);
	if(n==0){
		struct node *head=NULL;
		return head;
	}	
	struct node *head,*newnode,*temp;
	/*we will use newnode for creating any new node in the list.
	head to store the address of the first node so that we can return it to the main function
	temp to traverse through the list so that any other links in the list do not get Damaged. */
	//creating  the head node
	newnode=(struct node *)malloc(sizeof(struct node));
	i=1;
	head=NULL;
	printf("enter the data for node %d :\n",i);
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	head=newnode;
	temp=head; 
	//creating other nodes 
	for(i=2;i<=n;i++){
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("enter the data for node %d:\n",i);
		scanf("%d",&newnode->data);
		newnode->next=NULL;
		temp->next=newnode;
		temp=newnode;
	}
	return head;
}
struct node *selection_sort(struct node *start)
{
	if(start ==NULL){
		printf("list is empty");
		return start ;
	}
	struct node *p,*q,*r,*s,*temp;
	for(r=p=start; p->next !=NULL;r=p,p=p->next){
		for(s=q=p->next; q !=NULL;s=q,q=q->next){
			if(p->data > q->data){
				temp=p->next;
				p->next=q->next;
				q->next=temp;
				if(p != start){
					r->next=q;
				}
				s->next=p;
				if(p==start){
					start=q;
				}
				temp=p;
				p=q;
				q=temp;
			}
		}
	}
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
	struct node *head=(struct node *)malloc(sizeof(struct node));
	head=create_list();
	struct node *new_head=(struct node *)malloc(sizeof(struct node));
	new_head=selection_sort(head);
	
	display(new_head);
	return 0;
}
 	

		
	
	
	
	
	