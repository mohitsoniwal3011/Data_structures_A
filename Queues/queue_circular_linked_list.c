#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
// for circular linked list we l=only need rear pointer .
struct node *rear=NULL;
void display();
void peek ();
void delete();
void insert();
int  is_empty();
int main ()
{
    while(1){
        printf("1.insert\n");
        printf("2.delete\n");
        printf("3.display front element\n");
        printf("4.display all queue elemet\n ");
        printf("5.quit.\n");
        int choice,result ;
        printf("enter choice \n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                return 0;
            default:
                printf("wrong choice \n");
        }
    }
}
void insert()
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode== NULL){
        printf("queue overflow\n");
        return ;
    }
    printf("enter the element to be inserted  \n") ;
    int n;
    scanf("%d",&n);
    newnode->data=n;
    newnode->next=NULL;
    if(rear == NULL){
        rear=newnode ;
        rear->next=rear;
    }
    else{
        newnode->next=rear->next;
        rear->next=newnode;
        rear=newnode;
    }

}
void delete()
{
   if(is_empty()){
       printf("queue underflow\n");
       return ;
    }
    int n;
    struct node *p=rear->next;
    if(rear->next==rear){
        p=rear;
        rear=NULL;
        free(p);
        return;
    }
    n=p->data;
    do{
        p=p->next;
    }while(p != rear->next);
    rear->next=p->next;
    printf("deleted element =%d\n",n);
    free(p);
}
void peek()
{
    if( is_empty()){
        printf("stack underflow\n");
        return;
    }
    struct node *p=rear->next;
    printf("front element = %d \n",p->data );
    return ;
}
// return 1 if queue is empty else 0.
int is_empty()
{
    if(rear == NULL){
        return 1;
    }
    else {
        return 0;
    }
}
void display()
{
    struct node *p=rear->next;
    if(is_empty()){
        printf("stack underflow \n");
        return ;
    }
    do{
        printf("%d\t",p->data);
        p=p->next;
    }while(p != rear->next);
    printf("\n");
    return ;
}