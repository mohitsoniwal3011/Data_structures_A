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
	struct node *header=(struct node *)malloc(sizeof(struct node ));
	header->data=n;
	header->next=NULL;
	if(n==0){
		struct node *head=NULL;
		return header;
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
	header->next=head;
	return header;
}
void display(struct node *header)
{
	struct node *p;//for traversing through the list
	p=header;
	printf("number of nodes in the list = %d \n",header->data);
	p=p->next;
	int i=1;
	if(p ==NULL){
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
	struct node *header;
	header=create_list();
	display(header);
	return 0;
}
 	

		
	
	
	
	
	