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
struct node *insert(struct node *start,int key)
{
	struct node *newnode,*p,*temp;
	newnode =(struct node *)malloc(sizeof(struct node));
	newnode->data=key;
	newnode->next=NULL;
	if(start==NULL){
		printf("inserting in the empty list\n");
		start=newnode;
		printf("insertion successful\n");
		return start;
	}
	if(key<=(start->data)){
		newnode->next=start;
		start=newnode;
		return start ;
	}
	p=start;
	while(p->next !=NULL){
		temp=p->next;
		if(key <= temp->data){
			p->next=newnode;
			newnode->next=temp;
			return start;
		}
		p=p->next;
	}
	p->next=newnode;
	newnode->next=NULL;
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
struct node *merge(struct node *start1,struct node *start2)
{
    struct node *p1=start1,*p2=start2;
    struct node *start3=NULL;
    while (p1 !=NULL && p2 !=NULL){
        if(p1->data < p2->data){
            start3=insert(start3,p1->data);
            p1=p1->next;
        }
        else if(p2->data < p1->data){
            start3=insert(start3,p2->data);
            p2=p2->next;
        }
        else if(p1->data == p2->data){
            start3=insert(start3,p1->data);
            start3=insert(start3,p2->data);
            p1=p1->next;
            p2=p2->next;
        }
    }
    while(p1 != NULL){
        start3=insert(start3,p1->data);
        p1=p1->next;
    } 
    while(p2 != NULL){
        start3=insert(start3,p2->data);
        p2=p2->next;
    }
    return start3;
}  
int main ()
{
	struct node *head1=NULL,*head2=NULL,*head3=NULL;
    printf("for list1 :\n");
    head1=create_list();
    printf("for lis2 :\n");
    head2=create_list();
    head3=merge(head1,head2);
    display(head3);
}
 	

		
	
	
	
	
	