#include <stdio.h>
#include <stdlib.h>
struct node *case_a(struct node *root,struct node *par,struct node *ptr);
struct node *case_b(struct node *root,struct node *par,struct node *ptr);
struct node *case_c(struct node *root,struct node *par,struct node *ptr);
typedef enum{false,true} boolean ;
struct node {
    int data;
    struct node *left,*right;
    boolean rthread,lthread;
} ;
struct node *in_succ(struct node *ptr)
{
    if(ptr->rthread == true ){
        return ptr->right;
    }
    else 
    {   
        ptr=ptr->right;
        while(ptr->lthread == false){
            ptr=ptr->left;
        }
        return ptr;
    }    

    
}
struct node *in_pre(struct node *ptr)
{
    if(ptr->lthread == true ){
        return ptr->left;
    }
    else 
    {
        ptr=ptr->left;
        while(ptr->rthread == false ){
            ptr=ptr->right;
        }
        return ptr;
    }    
}
void inorder_traversal(struct node *root )
{
    if(root == NULL){
        printf("tree is empty\n");
        return ;
    }
    struct node *ptr=root ;
    while(ptr->lthread == false){
        ptr=ptr->left;
    }
    while(ptr != NULL){
        printf("%d\t",ptr->data);
        ptr=in_succ(ptr);
    }
    printf("\n");
}
void preorder_traversal(struct node *root)
{
    struct node *ptr=root;
    struct node *parent=NULL;
    if(root == NULL){
        printf("tree is empty\n");
        return ;
    }
    while(ptr != NULL)
    {
        printf("%d\t",ptr->data);
        if(ptr->lthread == false ){
            ptr=ptr->left;
            parent=ptr;
        }
        else if(ptr->rthread ==false ){
            ptr=ptr->right;
            parent=ptr;
        }
        else {
            while(ptr != NULL && ptr->rthread ==true){
                ptr=ptr->right;
            }
            if(ptr != NULL){
                ptr=ptr->right;
            }    
        }
    } 
    printf("\n");   

}    
struct node *insert2(struct node *root ,int x)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->lthread=true;
    newnode->rthread=true;
    if(root == NULL){
        root=newnode;
        newnode->left=NULL;
        newnode->right=NULL;
        return root;
    }
    struct node *ptr=root,*parent=NULL;
    while(ptr != NULL){
        if(x == ptr->data){
            printf("duplicate key found\n");\
            //break;
            return root;
        }
        parent=ptr;
        if(x < ptr->data){
            if(ptr->lthread ==false){
                ptr=ptr->left;
            }
            else {
                break;
            }
        }
        else if(x > ptr->data){
            if(ptr->rthread ==false){
                ptr=ptr->right;
            }
            else {
                break;
            }
        }
    }
    if(x <parent->data){
        parent->lthread=false ;
        parent->left=newnode;
        newnode->right=parent ;
        newnode->left=parent->left;
    }
    else if(x >parent->data){
        newnode->left=parent;
        newnode->right=parent->right;
        parent->rthread=false;
        parent->right=newnode;
    }
    return root;
}

struct node *delete(struct node *root,int x)
{
    if(root == NULL){
        printf("tree is empty, nothing to be deleted\n");
        return NULL;
    }
    //searching the key 
    int found=0;
    struct node *ptr=root;
    struct node *parent=NULL;
    while(ptr != NULL){
        if(x == ptr->data){
            found=1;
            break;
        }
        parent=ptr;
        if(x < ptr->data){
            if(ptr->lthread ==false){
                ptr=ptr->left;
            }
            else {
                break;
            }
        }
        else if(x > ptr->data){
            if(ptr->rthread ==false){
                ptr=ptr->right;
            }
            else {
                break;
            }
        }
    }
    struct node *temp;
    if(found == 1)
    {
        if(ptr->lthread == false  && ptr->rthread == false ){
            root=case_c(root,parent,ptr);
        }
        else if(ptr->lthread == false ){
            root=case_b(root,parent,ptr);
        }
        else if(ptr->rthread == false ){
            root=case_b(root,parent,ptr);
        }
        else {
             root=case_a(root,parent,ptr);
        }
    }
    else {
        printf("value not present in the tree\n");
    }    
    return root;

}

int main ()
{
    int choice,item ;
    struct node *root=NULL;
    while(1)
    {
        printf("1.insert\n");
        printf("2.delete\n");
        printf("3.inorder traversal\n");
        printf("4.preorder traversal\n");
        printf("5.Quit\n");
        printf("enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("enter the element to be insertd\n");
                scanf("%d",&item);
                root=insert2(root,item);
                break;
            case 2:
                printf("enter the element to be deleted \n");
                scanf("%d",&item);
                root=delete(root,item);
                break;
            case 3:
                printf("the inorder traversal is\n");
                inorder_traversal(root);  
                break;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
            case 4:
                printf("the preorder traversal is\n");
                preorder_traversal(root);
                break;

            case 5:
                printf("THANK YOU, HAVE A NICE DAY\n");
                return 0;
            default:
                printf("wrong choice entered\n");
        }
    }    

}
//when the node to be deleted has no child
struct node *case_a(struct node *root,struct node *par,struct node *ptr)
{
    if(par== NULL){
        root=NULL;
    }
    else if(ptr ->lthread == true && ptr->rthread ==true)
    {
            //no children 
            if(par== NULL){
                root=NULL;
            }
            else if(par->left == ptr){
                par->lthread=true;
                par->left=ptr->left;
            }
            else if(par->right == ptr){
                par->rthread=true;
                par->right=ptr->right;
            }
            
    }   
    free(ptr);
    return root;     
}
//when the node to be deleted has only on child 
struct node *case_b(struct node *root,struct node *par,struct node *ptr)
{
    struct node *child;//child of the ptr 
    struct node *s; // s is pointer to the inorder successor
    struct node *p; // p is pointer to the inorder predecessor
    s=in_succ(ptr);
    p=in_pre(ptr);
    if(ptr->lthread == false ){
        child=ptr->left;
    }
    else if(ptr->rthread == false ){
        child=ptr->right;
    }

    if(par == NULL){
        root=child;
    }
    else
    {
        if(par->right == ptr){
            par->right=child;
        }
        else if(par->left == ptr){
            par->left=child;
        }
    }  
    if(ptr->lthread == false ){
        p->right=s;
    }
    else if(ptr->rthread == false){
        s->left=p;
    }
    free(ptr);
    return root;  
}
struct node *case_c(struct node *root, struct node *par,struct node *ptr)
{
    struct node *succ;
    //s-->inorder succesor of ptr and 
    struct node *parent_succ=ptr;
    succ=ptr->right;
    while(succ ->lthread == false ){
        parent_succ=succ;
        succ=succ->left;
    }
    ptr->data=succ->data;
    if(succ->lthread == true && succ->rthread == true ){
        root=case_a(root,parent_succ,succ);
    }
    else {
        root=case_b(root,parent_succ,succ);
    }
    return root;
}