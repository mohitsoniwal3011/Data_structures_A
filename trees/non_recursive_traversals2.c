#include <stdio.h>
#include <stdlib.h>
#define MAX 7
int top;
struct node {
    int data;
    struct node *left_child;
    struct node *right_child;
};
typedef struct node node1;
node1 *stack[MAX];
void init_stack()
{
    top =-1 ;
    return ;
}
int is_empty()
{
    if( top == -1){
        return 1;
    }
    else {
        return 0;
    }
}
int is_full()
{
    if(top == MAX-1){
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
void push(node1 *item)
{
   //int *temp=t
    if( is_full() ){
        printf("stack overflow\n");
    }
    top=top+1;
    stack[top]=item;
    return ;
}
node1 *pop()
{
    //int *temp=t;
    if( is_empty() ){
        printf("stack underflow\n");
        return  NULL;
    }
    node1 *item=stack[top];
    top=top-1;
    return item;
}
void preorder_traverse(node1 *rt)
{
    
    if(rt ==  NULL){
        printf("tree is empty\n");
        return ;
    }
    node1 *temp=rt;
    push(temp);
    while( !is_empty() )
    {   
        temp=pop();
        printf("%d\t",temp->data);
        if(temp->right_child != NULL){
            push(temp->right_child);
        }
        if(temp->left_child != NULL){
            push(temp->left_child);
        }
    }    
}
void inorder_traverse(node1 *rt)
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
            push(temp);
            temp=temp->left_child;
        }
        while(temp->right_child == NULL){
            printf("%d\t",temp->data);
            if(  is_empty() ){
                return ;
            }    
            temp=pop();
        }   
        printf("%d\t",temp->data);
        temp=temp->right_child;
    }
}
void postorder_traverse(node1 *rt)
{
     if(rt == NULL){
        printf("tree is empty\n");
        return ;
    }
    node1 *temp=rt;
    node1 *ptr=rt;
    while(1)
    {
        while(temp->left_child != NULL)
        {
            push(temp);
            temp=temp->left_child;
        }
        while(temp->right_child == NULL || temp->right_child == ptr)
        {
            printf("%d\t",temp->data);
            ptr=temp;
            if( is_empty() ){
                return;
            }
            temp=pop();
        }
        push(temp);
        temp=temp->right_child;
    }
}
int main ()
{
    init_stack(&top);
    node1 *root=create_tree(root);
    printf("the postorder traversal is \n");
    postorder_traverse(root);
    printf("\n");
    printf("the preorder traversal is\n");
    preorder_traverse(root);
    printf("\n");
    printf("the ineorder traversal is\n");
    inorder_traverse(root);
    printf("\n");
    return 0;
}