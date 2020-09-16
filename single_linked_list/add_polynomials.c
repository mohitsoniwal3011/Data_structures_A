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
	struct node *p=NULL;
	
	int i=1;
	struct node *temp=NULL;
	p=start;
	printf("the resultant polynomial is :\n");
	while(p != NULL){
		temp=NULL;
		printf("%.1fx^(%d)\t",p->cofficient,p->exponent);
		if(p->next != NULL){
			temp=p->next;
			if ((temp->cofficient )>0){
				printf("+");
			}
		}
		else{
			printf("\n");
			return ;
		}
		p=p->next;
	}
	return ;
}
struct node *insert(struct node *start,float coff,int expo)
{
	struct node *newnode=(struct node *)malloc(sizeof(struct node ));
	newnode->cofficient=coff;
	newnode->exponent=expo;
	newnode->next=NULL;
	if(start ==NULL){
		printf("inserting in the empty list...\n");
		start=newnode;
		return start;
	}
	if(newnode->exponent > start->exponent){
		newnode->next=start;
		start=newnode;
		return start;
	}
	struct node *temp,*p=start;
	while(p->next != NULL){
		if(p->next != NULL)
			temp=p->next;
		if(temp->exponent <= newnode->exponent){
		p->next=newnode;
		newnode->next=temp;
		return start;
		}
		p=p->next;
	}
	if(newnode->exponent < p->exponent){
		p->next=newnode;
		newnode->next=NULL;
		return start;
	}
}
struct node *add_polynomials(struct node *start1,struct node *start2)
{
	struct node *p1,*p2;
	p1=start1;
	p2=start2;
	struct node *p3_start=NULL;
	while(p1 != NULL && p2 != NULL){
		if(p1->exponent > p2->exponent){
			p3_start=insert(p3_start,p1->cofficient,p1->exponent);
			p1=p1->next;
		}
		else if(p1->exponent < p2->exponent){
			p3_start=insert(p3_start,p2->cofficient,p2->exponent);
			p2=p2->next;
			
		}
		else if(p1->exponent == p2->exponent){
			p3_start=insert(p3_start,p1->cofficient +p2->cofficient,p1->exponent);
			p1=p1->next;
			p2=p2->next;
		}
	}
	while(p1 != NULL){
		p3_start=insert(p3_start,p1->cofficient,p1->exponent);
		p1=p1->next;
	}
	while(p2 != NULL){
		
		p3_start=insert(p3_start,p2->cofficient,p2->exponent);
		p2=p2->next;
	}
	return p3_start;
}	
int main () 
{
	struct node *p1_head,*p2_head,*p3_head;
	p1_head=(struct node *)malloc(sizeof(struct node ));
	p1_head=create_list();
	p2_head=(struct node *)malloc(sizeof(struct node ));
	p2_head=create_list();
	p3_head=(struct node *)malloc(sizeof(struct node ));
	p3_head=add_polynomials(p1_head,p2_head);
	display(p3_head);
	return 0;	
}	

	
		
	
	
	