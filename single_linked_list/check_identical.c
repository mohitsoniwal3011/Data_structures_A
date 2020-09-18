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
void check_identical(struct node *start1,struct node *start2)
{
    struct node *p1=start1,*p2=start2;
    while(p1 !=NULL && p2 != NULL){
        if(p1->data != p2->data){
            printf("lists are not identical \n");
            return ;
        }
        p1=p1->next;
        p2=p2->next;
    }
    if(p1 != NULL ){
        printf("lists are not identical\n");
        return ;
    }
    if(p2 != NULL ){
        printf("lists are not identical\n");
        return ;
    }
    printf("lists are identical\n");
    return ;
}

int main ()
{
    struct node *head1=NULL,*head2=NULL;
    printf("for list 1:\n");
	head1=create_list();
    printf("for list 2:\n");
	head2=create_list();
    check_identical(head1,head2);
	return 0;
}
 	

		
	
	
	
	
	