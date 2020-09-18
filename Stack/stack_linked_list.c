#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *top=NULL;
void pop();
void push();
int is_empty();
void display();
void peek();

int main ()
{
    again:
    printf("1.push\n");
    printf("2.pop\n");
    printf("3.display top element\n");
    printf("4.display all elements\n");
    printf("5.check if stack is empty\n");
    printf("6.quit\n");
    int choice,result ;
    printf("enter choice \n");
    scanf("%d",&choice);
    getchar();//just to store the newline entered after scaning item otherwise \n will get stored 
    //as buffer and will create problem when we will scan next charecter .
    switch(choice)
    {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            result=is_empty();
            if(result == 1){
                printf("stack underflow\n");
            }
            else if(result == 0){
                printf("stack is not empty\n");
            }
            break;
        case 6:
            return 0;
        default:
            printf("wrong choice \n");
            return 0;                       
    }
    printf("do you want to perform any operation again(Y/N)\n ");
    char c=getchar();
    if(c== 'Y' || c=='y'){
        goto again ;
    }
    if(c== 'N' || c=='n'){
        return 0;
    }
}
void push()
{
    printf("enter the item to be pushed \n");
    int item;
    scanf("%d",&item);
    getchar() ;
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    if(newnode == NULL){
        printf("stack overflow\n ");
        return ;
    }
    else {
        newnode->data=item;
        newnode->next=top;
        top=newnode;
    }

}
void pop()
{
    if(top == NULL){
        printf("stack underflow\n");
        return ;
    }
    struct node *temp=top;
    int item=top->data;
    top=top->next;
    free(temp);
    printf("popped element= %d\n",item);
    return ;
}
void peek()
{
    if(is_empty() ){
        printf("stack underflow\n");
        return ;
    }

    printf("top element =%d\n",top->data);\
    return ;
}
void display()
{
    struct node *p=top;
    if(top==NULL){
        printf("Nothing to display\n");
        return ;
    }
    while(p != NULL){
        printf("%d\t",p->data);
        p=p->next;
    }
    printf("\n");
    return ;
}
// is_empty returns 1 if list is empty and 0 if not empty
int  is_empty()
{
    if(top == NULL){
        return 1;
    }
    else {
        return 0;
    }
}