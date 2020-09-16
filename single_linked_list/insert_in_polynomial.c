#include <stdio.h>
#include <stdlib.h>
struct node {
	float cofficient;
	int exponent;
	struct  node *next;
};	
struct node *create_list()
{
	struct node *head,*newnode,*temp;
	printf("enter the number of terms:\n");
	int n;
	scanf("%d",&n);
	if(n==0){
		printf("creating empty list\n");
		struct node *head=NULL;
		return head;
	}	
	//scanf("%d",&n);
	int i=1;
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("enter the cofficient and expression of term %d:\n",i);
	scanf("%f%d",&newnode->cofficient,&newnode->exponent);
	newnode->next=NULL;
	head=newnode;
	temp=head;
	for(i=2;i<=n;i++){
		newnode=(struct node *)malloc(sizeof(struct node));
		printf("enter the cofficient and expression of term %d:\n",i);
		scanf("%f%d",&newnode->cofficient,&newnode->exponent);
		newnode->next=NULL;
		temp->next=newnode;
		temp=newnode;
	}
	return head;
}
void display(struct node *start)
{
	if(start==NULL){
		printf("nothing to display\n");
	}
	struct node *p=start;
	int i=1;
	while(p != NULL){
		//printf("for term %d:\n",i++);
		printf("%.1fx^(%d)  ",p->cofficient,p->exponent);
		if(p->next != NULL)
		if(p->next->cofficient  >0)
		printf("+");
		p=p->next;
	}
}
struct node *insert(struct node *start,float coff,int expo)
{
	struct node *newnode=(struct node *)malloc(sizeof(struct node ));
	//printf("enter the cofficient and exponent of the term to be inserted:\n");
	//scanf("%f%d",&newnode->cofficient,&newnode->exponent);
	newnode->cofficient=coff;
	newnode->exponent=expo;
	newnode->next=NULL;
	if(start ==NULL){
		printf("inserting in the empty list...\n");
		start=newnode;
		//newnode->next=NULL;
		return start;
	}
	if(newnode->exponent > start->exponent){
		newnode->next=start;
		start=newnode;
		return start;
	}
	struct node *temp,*p=start;
	while(p->next != NULL){
		temp=p->next;
		if(temp->exponent <= newnode->exponent){
		newnode->next=temp;
		p->next=newnode;
		
		return start;
		}
		p=p->next;
		
		//printf("inside the loop :coff=%f  expo=%d \n",p->cofficient,p->exponent);
	}
	if(newnode->exponent < p->exponent){
		p->next=newnode;
		newnode->next=NULL;
		return start;
	}
}	
int main () 
{
	
	struct node *head=(struct node *)malloc(sizeof(struct node));
	head=create_list();
	struct node *new_head=(struct node *)malloc(sizeof(struct node));
	printf("enter the cofficient and exponent of the termo to be inserted :\n");
	float coff;
	int expo;
	scanf("%f%d",&coff,&expo);
	new_head=insert(head,coff,expo);
	display(new_head);
	return 0;
}	

	
		
	
	
	