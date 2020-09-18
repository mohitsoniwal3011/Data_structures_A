#include <stdio.h>
#include <stdlib.h>
#define MAX 3
int top=-1;
int stack_arr[MAX];
void push();
void pop();
int peek();
void display();
int is_empty();
int is_full();
int main ()
{   
    again:
    printf("1.push\n");
    printf("2.pop\n");
    printf("3.display all stack elememts \n");
    printf("4.display top element\n");
    printf("5.check if the stack is empty\n");
    printf("6.check if the stack full\n ");
    int choice,item,result;
    printf("enter your choice \n");
    scanf("%d",&choice);
    getchar();
    switch(choice)
    {
        case 1:
            push();
            printf("top = %d stack_arr[top] =%d \n",top,stack_arr[top]);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            item=peek();
            printf("item at top is %d\n",item);
        case 5:
            result=is_empty();
            if(result == 1){
                printf("stack underflow\n");
            }        
            else {
                printf("list is  not empty");
            }\
            break;
        case 6: 
            result=is_full();
            if(result == 1){
                printf("stack is full ");
            }        
            else {
                printf("stack is  not full");
            }
            break;
        default:
            printf("wrong choice\n"); 
    }
    printf("do you want to perform any operation again(Y/N)\n");
    char c=getchar();
    if(c== 'Y' || c== 'y'){
        goto again ;
    }
    else if(c=='N' || c== 'n' ){
        return 0;
    }
}
void push() 
{
   if( is_full() ){
       printf("stack overflow\n");
       return ;
   }
    printf("enter item to be pushed \n");
    int item ;
    scanf("%d",&item);
    getchar();
    top++;
    stack_arr[top]=item ;
    return ;
}
void  pop()
{   
    if( is_empty() ){
        printf("stack underflow\n");
        return;
    }
    int item=stack_arr[top];
    printf("popped item is %d\n ",item);
    top--;
    return ;
}
//peek displays the top element.
int peek()
{   
    if(  is_empty() ){
        printf("stack under flow");
    }
    return stack_arr[top];
}
// is_empty will return 1 if stack is empty else 0
int is_empty()
{
    if(top == -1){
        return 1;
    }
    else {
        return 0;
    }
}
// is_full will return 1 if stack is full else 0
int is_full()
{
    if(top==MAX-1){
        return 1;
    }
    else {
        return 0;
    }
}
void display()
{
    int i;
    //test condition
    for(i=top;i>=0;i--){
        printf("%d\t",stack_arr[i]) ;
    }
    return ;
}