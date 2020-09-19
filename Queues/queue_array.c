//deletion only on front end and addition only on last.
#include <stdio.h>
#include <stdlib.h>
#define MAX 10
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
void  insert()
{
    int n;
     if ( is_full() ){
         printf("queue overflow\n");
         return ;
     }
    printf("enter the element to be inserted \n");
    scanf("%d",&n);
    rear++;
    queue_array[rear] = n;
    if(front == -1){
        front=0;
        return ;
    }
    else{
        return ;
    } 
}
void delete()
{
    if( is_empty() ){
        printf("queue underflow\n");
        return ;
    }
    printf("deleted element = %d \n",queue_array[front]);
    front ++;
}
//is_full returns 1 if queue is full  else 0;
int is_full()
{
    if(rear== MAX -1){
        return 1;
    }
    else {
        return 0;
    }
}
//is empty returns 1 if queue if empty else 0.
int is_empty()
{
    if(front == -1 || front ==rear+1){
        return 1;
    }
    else {
        return 0;
    }
}
void peek()
{
    if( is_empty() ){
        printf("queue underflow\n");
        return ;
    }
    printf("front element = %d\n",queue_array[front]);
    return ;
}
void display()
{
    if(is_empty()){
        printf("queue underflow\n");
        return ;
    }
    int i;
    for (i=front ; i<rear+1;i++){
        printf("%d\t",queue_array[i]);
    }
    printf("\n");
    return ;
}