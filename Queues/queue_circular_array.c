//deletion only on front end and addition only on last.
#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int queue_array[MAX];
int front=-1 ;
int rear=-1;
void display();
void peek ();
void delete();
void insert();
int is_full();
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
    if ( is_full() ){
        printf("queue overflow \n");
        return ;
    }
    int n;
    printf("enter the  number to be inserted \n");
    scanf("%d",&n);
    if(front == -1){
        front =0;
        rear=0;
        queue_array[rear]=n;
        return ;
    }
    if(rear==MAX-1){
        rear=0;
        queue_array[rear]=n;
        return ;
    }
    else {
        rear=rear+1;
        queue_array[rear]=n;
        return ;
    }
}

void delete()
{
    if( is_empty() ){
        printf("queue underflow\n");
        return ;
    }
    int n=queue_array[front];
    if(front == rear){
        front =rear= -1;
    }
    else if(front ==MAX-1){
        front =0;
    }
    else {
        front ++;
    }
    printf("deleted element =%d\n",n);
    return ;
}
void display()
{
    if( is_empty() ){
        printf("queue underflow\n");
        return ;
    }
    int i=front ;
    if(  front <=rear){
        while(i<=rear){
            printf("%d\t",queue_array[i]);
            i++;
        }
    }
    else {
        while(i<=MAX-1){
            printf("%d\t",queue_array[i]);
            i++;
        }
        i=0 ;
        while (i<=rear){
            printf("%d\t",queue_array[i]);
            i++;
        }
    }
    printf("\n");
    return ;
}
//is empty returns 1 if queue is empty else 0.
int is_empty()
{
    if(front == -1){
        return 1;
    }
    else {
        return 0;
    }
}
//is full returns 1 if queue is full else 0
int is_full()
{
    if( (front ==0 && rear==MAX-1) || front==rear+1 ){
        return 1;
    }
    else {
        return 0;
    }
}
void peek ()
{
    if( is_empty() )  {
        printf("stack underflow\n");
        return;
    }
    else {
        printf("front element =%d\n",queue_array[front]);
        return ;
    }
}
