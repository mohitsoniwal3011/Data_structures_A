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
	temp->next=NULL;//changing here
	return head;
}
void display(struct node *start)
{
	if(start==NULL){
		printf("nothing to display\n");
	}
	struct node *p=start;
	int i=1;
	struct node *temp=NULL;
	while(p != NULL){
		temp=NULL;
		//printf("for term %d:\n",i++);
		printf("%.1fx^(%d)  ",p->cofficient,p->exponent);
		if(p->next != NULL){
			temp=p->next;
			if(temp->cofficient  >0){
				printf("+");
			}
			else{
				printf("\n");
			}
				
		}



		p=p->next;
	}
}
int main () 
{
	
	struct node *head=(struct node *)malloc(sizeof(struct node));
	head=create_list();
	display(head);
	return 0;
}	

	
		
	
	
	