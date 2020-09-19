#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *front=NULL ;
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
    struct node *newnode =malloc(sizeof(struct node));
    if(newnode == NULL){
        printf("stack overflow\n");
        return ;
    }
    printf("enter the data to be inserted \n");
    int n;
    scanf("%d",&n);
    newnode->data=n;
    newnode->next=NULL;
    //when queue has one element, fornt and rear both are same .
    if(front == NULL){
        front =newnode ;
        rear =newnode;
        return ;
    }
    else {
        rear->next=newnode;
        rear =newnode ;
        return ;
    }
}
void delete()
{
    if(is_empty()){
        printf("queue underflow\n");
        return ;
    }
    int n=front->data;
    struct node *temp=front ;
    front =front->next;
    printf("deleted element =%d\n",n);
    free(temp);
}
//is empty returns 1 if queue is empty else 0.
int is_empty()
{
    if(front == NULL){
        return 1;
    }
    else {
        return 0;
    }
}
void peek()
{
    if( is_empty()  ){
        printf("queue underflow\n");
        return ;
    }
    printf("front element =%d\n ",front->data);
    return ;
}
void display()
{
    if( is_empty()){
        printf("queue underflow\n");
        return ;
    }
    struct node *p=front;
    while (p != NULL){
        printf("%d\t",p->data);
        p=p->next;
    }
    printf("\n");
    return ;
} 
