#include <stdio.h>
#include <stdlib.h>
#define MAX 20
int front=-1;
int rear=-1;
struct node {
    int data;
    struct node *left,*right;
} ;
struct node *queue[MAX];
typedef struct node node1 ;
int is_empty()
{
    if( front== (rear+1) || front ==-1){
        return 1;
    }
    else {
        return 0;
    }
}
int is_full()
{
    if(rear == (MAX -1)){
        return 1;
    }
    else {
        return 0;
    }
}
void insert_queue(node1 *ptr)
{
    if( is_full() ){
        printf("Queue overflow in the queue\n");
        return ;
    }
    if(front==-1){
        front=0;
    }
    rear=rear+1;
    queue[rear]=ptr;
    return ;   
}
node1 *delete_queue()
{
    if( is_empty() ){
        printf("Queue underflow in the queue\n");
        return NULL;
    }
    struct node *p=queue[front];
    front=front+1;
    return p;
}


void level_order_traversal(node1 *rt)//rt->root
{
     if(rt == NULL){
         printf("tree is empty\n");
         return ;
     }
     node1 *p=rt;
     insert_queue(p);
     while ( !is_empty() )
     {
        p=delete_queue();
        printf("%d\t",p->data);
        if(p->left != NULL){
            insert_queue(p->left);
        }
        if(p->right != NULL){
            insert_queue(p->right);
        }    
     }
     printf("\n");
     return ;

}
 node1 *nonrec_insert(node1 *rt,int x)
{
    node1 *ptr=rt;
    node1 *parent= NULL;
    while(ptr != NULL)
    {   
        parent=ptr;
        if(x < ptr->data){
            ptr=ptr->left;
        }
        else if(x > ptr->data){
            ptr=ptr->right;
        }
        else {
            printf("duplicate key found \n");
            return rt;
        }
    }
    node1 *newnode =(node1 *)malloc(sizeof(node1 ));
    newnode->data=x;
    newnode->left=NULL;
    newnode->right=NULL;
    if(parent == NULL){
        rt=newnode;
    }
    else if(x < parent->data){
        parent->left=newnode;
    }
    else {
        parent->right=newnode;
    }
    return rt;
}
int main ()
{
    node1 *root=NULL;
    while(1){
        printf("1.insert the value\n");
        printf("2.level order traversal\n");
        printf("3.Quit\n");
        int choice,item ;
        printf("enter your choice \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("enter value to insert\n");
                scanf("%d",&item);
                root=nonrec_insert(root,item);
                break;
            case 2:
                level_order_traversal(root);
                break;
            case 3:
                printf("THANK YOU, HAVE A NICE DAY\n");
                return 0;
            default:
                printf("wrong choice entered\n");
        }
    }
}
