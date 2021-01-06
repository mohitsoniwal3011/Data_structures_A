#include <stdio.h>
#include <stdlib.h>
#define MAX 20
struct node {
    int data;
    struct node *left_child;
    struct node *right_child;
};
typedef struct node node1;
void init_stack(int *t)
{
    *t=-1;
    return ;
}
int is_empty(int *t)
{
    if( *t == -1){
        return 1;
    }
    else {
        return 0;
    }
}
int is_full(int *t)
{
    if(*t == MAX-1){
        return 1;
    }
    else {
        return 0;
    }
}
node1 *create_tree()
{
    static int num=1;
    if(num ==1 ){
        printf("enter the data of the root node\n");\
        num++;
    }
    node1 *newnode=(node1 *)malloc(sizeof(node1));
    int x;
    scanf("%d",&x);
    if(x== -1){
        return NULL;
    }
    else {
        newnode->data=x;
        printf("enter data of left child of %d\n",x);
        newnode->left_child=create_tree();
        printf("enter data of right node of %d\n",x);
        newnode->right_child=create_tree();
    }
    return newnode;
}
void push(node1 *A[],int *t,node1 *item)
{
   //int *temp=t
    if( is_full(t) ){
        printf("stack overflow\n");
    }
    *t=*t+1;
    A[*t]=item;
    return ;
}
node1 *pop(node1 *A[],int *t)
{
    //int *temp=t;
    if( is_empty(t) ){
        printf("stack underflow\n");
        return  NULL;
    }
    node1 *item=A[*t];
    *t=*t-1;
    return item;

}
void preorder_traverse(node1 *A[],node1 *rt,int *t)
{
    
    if(rt ==  NULL){
        printf("tree is empty\n");
        return ;
    }
    node1 *temp=rt;
    push(A,t,temp);
    while( !is_empty(t) ){
        temp=pop(A,t);
        printf("%d\t",temp->data);
        if(temp->right_child != NULL){
            push(A,t,temp->right_child);
        }
        if(temp->left_child != NULL){
            push(A,t,temp->left_child);
        }
    }
    printf("\n");
}
void inorder_traverse(node1 *A[],node1 *rt,int *t)
{
    if(rt == NULL){
        printf("tree is empty\n");
        return ;
    }
    node1 *temp=rt;
    while(1)
    {
        while(temp->left_child != NULL)
        {
            push(A,t,temp);
            temp=temp->left_child;
        }
        while(temp->right_child == NULL){
            printf("%d\t",temp->data);
            if(  is_empty(t) ){
                return ;
            }    
            temp=pop(A,t);
        }   
        printf("%d\t",temp->data);
        temp=temp->right_child;
    }
    printf("\n");
}
void postorder_traverse(node1 *A[],node1 *rt,int *t)
{
    if(rt == NULL){
        printf("tree is empty\n");
        return ;
    }
    node1 *temp=rt;
    node1 *ptr=rt;
    while(1)
    {
        while(temp->left_child != NULL){
            push(A,t,temp);
            temp=temp->left_child;    
        }
        while(temp->right_child == NULL || temp->right_child == ptr ){
            printf("%d\t",temp->data);
            ptr=temp;
            if( is_empty(t) ){
                return ;
            } 
            temp=pop(A,t);   
        }
        push(A,t,temp);
        temp=temp->right_child;
    }    
    printf("\n");
    return ;   
}    
int main ()
{
    int top;
    init_stack(&top);
    node1 *root=create_tree(root);
    node1 *stack[MAX];
    printf("the inorder traversal is \n");
    inorder_traverse(stack,root,&top);
    printf("\n");
    printf("the postorder traversal is \n");
    postorder_traverse(stack,root,&top);
    printf("\n");
    printf("the preorder traversal is \n");
    preorder_traverse(stack,root,&top);
    printf("\n");
    return 0;
}