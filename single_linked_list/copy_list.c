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
struct node *copy_list(struct node *start)
{   
    printf("copying...\n");
    struct node *p1=NULL,*copy_head=NULL;
    if(start == NULL){
        copy_head=NULL;
        return copy_head;
    }
    p1=start;
    struct node *newnode=NULL,*temp=NULL;
    newnode=(struct node *)malloc(sizeof(struct node));
        newnode->data=start->data;
        newnode->next=NULL;
        copy_head=newnode;
        temp=copy_head;
        p1=p1->next;  
    while(p1 != NULL){
        newnode=(struct node *)malloc(sizeof(struct node));
        newnode->data=p1->data;
        newnode->next=NULL;
        temp->next=newnode;
        temp=newnode;
        p1=p1->next;
    }
    temp->next=NULL;
    return copy_head;
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
	struct node *head=create_list();
    struct node *head2=copy_list(head);
    printf("the copied list is \n");
	display(head2);
	return 0;
}
 	

		
	
	
	
	
	