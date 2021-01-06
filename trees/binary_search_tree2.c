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
void preorder(node1 *A[],node1 *rt,int *t)
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
void inorder(node1 *A[],node1 *rt,int *t)
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
}
void postorder(node1 *A[],node1 *rt,int *t)
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
node1 *delete(node1 *rt,int x)
{
    node1 *ptr=rt;
    node1 *parent=NULL;
    if(rt == NULL){
        printf("tree is empty");
        return rt;
    }
    while(ptr != NULL)
    {
        if(x == ptr->data){
            break;
        }
        parent=ptr;
        if(x < ptr->data){
            ptr=ptr->left_child;
        }
        else {
            ptr=ptr->right_child; 
        }
    }
    if(ptr == NULL){
        printf("value not found \n");
        return rt;
    }    
    if(ptr->left_child == NULL && ptr->right_child == NULL)//no children
    {
        if(parent == NULL ){
            rt =NULL;
        }
        else if(parent->left_child == ptr){
            parent->left_child = NULL;
        }
        else {
            parent->right_child = NULL;
        }    
        free(ptr);
        return rt;
    }
    else if(ptr->left_child != NULL && ptr->right_child == NULL)//only left child
    {
        if(parent == NULL){
            rt=ptr->left_child;
        }
        else if(parent->right_child == ptr){
            parent->right_child = ptr->left_child;
        }
        else {
            parent->left_child=ptr->left_child;
        }
        free(ptr);
        return rt;
    }
    else if(ptr->left_child == NULL && ptr->right_child != NULL)//only right child
    {
        if(parent == NULL){
            rt= ptr->right_child;
        }
        else if(parent->left_child == ptr){
            parent->left_child=ptr->right_child;
        }
        else {
            parent->right_child=ptr->right_child;
        }
        free(ptr);
        return rt;
    }
    else{
        node1 *parent_succ=ptr;
        node1 *in_succ=ptr->right_child;
        while(in_succ->left_child != NULL ){
            parent_succ=in_succ;
            in_succ=in_succ->left_child;
        }
        ptr->data=in_succ->data;
        if(in_succ->right_child != NULL){
            parent_succ->left_child=in_succ->right_child;
        }
        else {
            parent_succ->left_child = NULL;
        }
        free(in_succ);
        return rt;
    }
}
node1 *nonrec_insert(node1 *rt,int x)
{
    node1 *ptr=rt;
    node1 *parent= NULL;
    while(ptr != NULL)
    {   
        parent=ptr;
        if(x < ptr->data){
            ptr=ptr->left_child;
        }
        else if(x > ptr->data){
            ptr=ptr->right_child;
        }
        else {
            printf("duplicate key found \n");
            return rt;
        }
    }
    node1 *newnode =(node1 *)malloc(sizeof(node1 ));
    newnode->data=x;
    newnode->left_child=NULL;
    newnode->right_child=NULL;
    if(parent == NULL){
        rt=newnode;
    }
    else if(x < parent->data){
        parent->left_child=newnode;
    }
    else {
        parent->right_child=newnode;
    }
    return rt;
}
node1 *nonrec_binary_search(node1 *ptr, int x)
{
    while(ptr != NULL){
        if(x < ptr->data){
            ptr=ptr->left_child; //key is present in the left subtree
        }
        else if(x >ptr->data){
            ptr=ptr->right_child; //key is present in the right subtree
        }
        else {
            return ptr;
        }
    }
    return NULL; // key not found
}
node1 *nonrec_min_key(node1 *ptr)
{
    if(ptr == NULL){
        return NULL;
    }
    else if(ptr != NULL){
        while ( ptr->left_child != NULL){
            ptr=ptr->left_child;
        }   
    }   
    return ptr;
}
node1 *nonrec_max_key(node1 *ptr)
{
    if(ptr == NULL){
        return NULL;
    }
    else if(ptr != NULL){
        while (ptr->right_child != NULL){
            ptr=ptr->right_child;
        }
    }
    return ptr;    
}
int main ()
{
    int top;
    node1 *stack[MAX];
    init_stack(&top);
    node1 *result,*root=NULL;
    int choice ;
    while(1){
        printf("1.insert the value\n");
        printf("2.binary search.\n");
        printf("3.preorder traversal\n");
        printf("4.postorder traversal\n");
        printf("5.inorder traversal\n");
        printf("6.search min key\n");;
        printf("7.search max key\n");
        printf("8.Quit\n");
        printf("9.delete\n");
        printf("enter choice \n");
        scanf("%d",&choice);
        int element;
        switch(choice)
        {
            case 1:
                printf("enter the value to be inserted\n");
                scanf("%d",&element);
                root=nonrec_insert(root,element);
                break;
            case 2:
                printf("enter the key to be searched\n");
                scanf("%d",&element);
                result=nonrec_binary_search(root,element);
                if( result != NULL)
                {
                    printf("key is  present \n");
                }
                else
                {
                    printf("key is not present\n");
                }
                break;
            case 3:
                init_stack(&top);
                printf("preorder traversal is \n");
                preorder(stack,root,&top);
                printf("\n");
                break;
            case 4:
                init_stack(&top);
                printf("postorder traversal is \n");
                postorder(stack,root,&top);
                printf("\n");
                break;
            case 5:
                init_stack(&top);
                printf("inorder traversal is \n");
                inorder(stack,root,&top);
                printf("\n");
                break;
            case 6:
                result=nonrec_min_key(root);
                if(result != NULL){
                    printf("the minimum key is %d\n",result->data);
                }
                else {
                    printf("no elements in the tree\n");
                } 
                break;
            case 7:
                result=nonrec_max_key(root);
                if(result !=NULL){
                printf("the maximum key is %d\n",result->data);
                }
                else {
                    printf("no elements in the tree \n");
                }
                break;
            case 8:
                printf("THANK YOU, HAVE A NICE DAY\n");
                break;
            case 9:
                printf("enter the value to be deleted\n");
                scanf("%d",&element);
                root=delete(root,element);
                break;
            default:
                printf("wrong choice\n");
        }
    }
}