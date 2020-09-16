#include <stdio.h>
#include <stdlib.h>
struct node {
	int data;
	struct node * next;
};
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
}
struct node *concat(struct node *last1,struct node *last2)
{
    if(last1 == NULL){
        last1=last2;
        return last1;
    }
    if(last2 == NULL){
        return last1;
    }
    struct node *p1;
    p1=last1->next;
    last1->next=last2->next;
    last2->next=p1;
    last1=last2;
    return last1;

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
	struct node *tail1=NULL,*tail2=NULL;
    printf("for list 1:\n");
    tail1=create_list();
    printf("for list 2:\n");
    tail2=create_list();
    tail1=concat(tail1,tail2);
    display(tail1);
	return 0;
}