#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
struct node {
    struct node *left;
    struct node *right;
    int data;
    int balance; //balance = height of left subtree - height of right subtree
};
struct node *insert_left_check(struct node *p,int *ptaller );
struct node *insert_right_check(struct node *p,int *ptaller );
struct node *insert_left_balance(struct node *p);
struct node *insert_right_balance(struct node *p);
struct node *delete_left_check(struct node *p,int *pshorter);
struct node *delete_right_balance(struct node *p,int *pshorter);
struct node *delete_right_check(struct node *p, int *pshorter) ;
struct node *delete_left_balance(struct node *p,int *pshorter);


struct node *rotateright(struct node *p)
{
    //p is the pointer about which we have to perform the rotation
    struct node *A;
    A=p->left; //now A points to the left subtree of p
    p->left=A->right; //A's right subtree becomes the left subtree of p
    A->right=p; //p becomes the root right subtree of A
    return A; // A becomes the new root of the subtree initially rooted at p
}//end of the right rotation 

struct node *rotateleft(struct node *p)
{
    //p is the poiter about which we have to perform rotation
    struct node *A;
    A=p->right;//A pointes to the right subtree of p
    p->right=A->left; //left subtree of A becomes the right subtree of p
    A->left=p;//p becomes the root of the left subtree of A
    return A;//A becomes the new root of the subtree initially rooted at p 
}//end of the left rotation

struct node *insert(struct node *p,int key)
{
    static int taller;
    if(p == NULL){
        p=(struct node *)malloc(sizeof(struct node));
        p->data=key;
        p->left=NULL;
        p->right=NULL;
        p->balance=0;
        taller=true;
    }
    else if(key < p->data) //insertion in the left subtree 
    {
        p->left=insert(p->left,key);
        if(taller == true ){
            p=insert_left_check(p,&taller);
        }
    }
    else if(key > p->data)//insertion in the right subtree.
    {
        p->right=insert(p->right,key);
        if(taller == true ){
            p=insert_right_check(p,&taller);
        }
    }
    else //duplicate key found. 
    {
        printf("duplicate key found\n");
        taller = false;
    }
    return p;
}

struct node *insert_left_check(struct node *p,int *ptaller )
{
     switch(p->balance)
     {
         case 0: //when the node is balanved before insertion
            p->balance=1;
            break;
         case -1: //when the node was right heavy 
            p->balance=0;
            *ptaller = false; 
            break;
         case 1: //when the node is left heavy
            p=insert_left_balance(p);//this function will make the tree balanced 
            *ptaller=false;
     }
     return p;

 }
 struct node *insert_left_balance(struct node *p)
 {
     //when the node is inserted in left subtree of left child of node p
     struct node *A,*B;
     A=p->left;
     if(A->balance == 1)
     {
        A->balance= 0;
        p->balance =0;
        p=rotateright(p);
     }
    //when the node is inserted in the right subtree of right subtree of left child of p
    else
    {
        B=A->right;
        switch (B->balance)//we are checking the balance after insertion of the node 
        {
            case -1: // key is inserted in the right of B
                A->balance=1;
                p->balance=0;
                break;
            case 1: // key is inserted in the left of B
                A->balance=0;
                p->balance= -1;
                break;
            case 0: //right of A is empty
                A->balance=0;
                p->balance=0;
                break;
        }
        B->balance=0;
        //A=rotateleft(A); -->doing this will make the program incorrect 
        p->left=rotateleft(A);
        p=rotateright(p);
    } 
    return p;
}

struct node *insert_right_check(struct node *p, int *ptaller)
{
    
    switch(p->balance)
    {
        case 0:
            p->balance = -1;
            break;

        case 1:
            p->balance = 0;
            *ptaller=false ;
            break;
        case -1:
            p=insert_right_balance(p);
            *ptaller=false ;
    }
    return p;
}



struct node *insert_right_balance(struct node *p)
{
    struct node *A,*B;
    A=p->right;
    if(A->balance == -1)
    {
        A->balance =0;
        p->balance =0;
        p=rotateleft(p) ;
    }
    else
    {
        B=A->left;
        switch(B->balance)//we are checking the balance of B after insertion 
        {
            case -1: // key is inserted at the left of B
                p->balance=1;
                A->balance=0 ;
                break;
    
            case 1:
                p->balance=0;
                A->balance=-1;
                break;
    
            case 0:
                p->balance=0;
                A->balance=0;
                break;
        }
        B->balance=0;
        p->right=rotateright(A); // we can not do A=rotateright(A)
        //becuase we want p's right to point to the subtree rotated about A.
        p=rotateleft(p);
    } 
    return p;
}


void preorder_traversal(struct node *root) 
{
    /*struct node *p=root;
    if(p ==NULL){
        return ;
    }
    else
    {
        printf("node-->%d\t      balance = %d  \n",p->data,p->balance);
        preorder_traversal(p->left);
        preorder_traversal(p->right);
    } */
    if(root ==NULL){
        return ;
    }
    else
    {
        printf("node-->%d\t      balance = %d  \n",root->data,root->balance);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

void inorder_traversal(struct node *root) 
{
    if(root==NULL){
        return ;
    }
    else
    {
        inorder_traversal(root->left);
        printf("node-->%d\t      balance = %d  \n",root->data,root->balance);
        inorder_traversal(root->right);
    }
}

void postorder_traversal(struct node *root) 
{
    if(root ==NULL){
        return ;
    }
    else
    {
        postorder_traversal(root->left);
        postorder_traversal(root->right);
        printf("node-->%d\t      balance = %d  \n",root->data,root->balance);
    }
}

struct node *delete(struct node *p,int key)
{
    struct node *succ; 
    struct node *temp;
    static int shorter;
    if(p == NULL){
        printf("key not present in the tree\n");
        shorter =false;
        return p;
    } 
    if(key < p->data){
        p->left=delete(p->left,key);
        if(shorter == true ){
            p=delete_left_check(p,&shorter);
        }
    }
    else if(key >p->data){
        p->right=delete(p->right,key);
        if(shorter == true ){
            p=delete_right_check(p,&shorter);
        }
    }
    else 
    {  
        if(p->left != NULL && p->right != NULL) // the node to be deleted has both childs
        {
            succ =p->right;
            while(succ->left != NULL){
                succ =succ->left;
            }
            p->data=succ->data;
            p->right=delete(p->right,succ->data);  
            if(shorter == true ){
                p=delete_right_check(p,&shorter);
            }
        }
        else 
        {
            temp=p;
            if(p->left != NULL ) // only left child.
            {
                p=p->left;
            }
            else if(p->right != NULL)  // only right child.
            {
                p=p->right;
            }
            else //no child. 
            {
                p=NULL;
            }
            free(temp);
            shorter=true ; //we have found the key so initially we are setting the shorter = true and
            //after balancing is done we wil make it false   
        }
    }
    return p;
}

struct node *delete_left_check(struct node *p,int *pshorter)
{
    switch(p->balance)
    {
        case 0:
            p->balance=-1;
            *pshorter =false ; // we can make shorter false because the height of subtree is not affected 
            break;
        case 1:
            p->balance =0; // we can not make shorter false because here the height of subtree will be affected
            break;
        case -1:
            p=delete_right_balance(p,pshorter); //balance factor becomes -2 so we need to balance the tree 
            break;
    }
    // check again
    return p;
}
struct node *delete_right_balance(struct node *p,int *pshorter)
{
    struct node *A;
    A=p->right;
    struct node *B;
    if(A->balance == 0)
    {
        p->balance = -1;
        A->balance = 1;
        *pshorter= false ;
        p=rotateleft(p); 
        
    }
    else if( A->balance == -1)
    {
        A->balance =0;
        p->balance= 0;
        p=rotateleft(p);
    }
    else //if(A->balance == 1)
    {
        B=A->left;
        switch(B->balance)
        {
            case 0:
                p->balance=0;
                A->balance=0;
                break;
            case 1:
                p->balance= 0;
                A->balance= -1 ;
                break;
            case -1:
                p->balance= 1;
                A->balance= 0;
                break;
        }
        B->balance =0;
        p->right=rotateright(A);
        p=rotateleft(p);
    }
    return p;
}

struct node *delete_right_check(struct node *p, int *pshorter)
{
    switch(p->balance)
    {
        case 0:
            p->balance = 1;
            *pshorter=false ;
            break;
        case -1:
            p->balance = 0;
            break;
        case 1:
            p=delete_left_balance(p,pshorter);
            break;
    }
    return p;
}    

struct node *delete_left_balance(struct node *p,int *pshorter)
{
    struct node *A,*B;
    A=p->left;
    if(A->balance == 0)
    {
        A->balance = -1;
        p->balance = 1;
        *pshorter=false ; // because the total height remains the same 
        p=rotateright(p);   
    }
    else if(A->balance == 1)
    {
        A->balance = 0;
        p->balance = 0;
        p=rotateright(p);
        //we can not make pshorter false because total height decreases
    }
    else  //if(A->balance == -1)
    {
        B=A->right;
        switch(B->balance)
        {
            case 0:
                A->balance =0;
                p->balance =0;
                break;
            case 1:
                A->balance =0;
                p->balance =-1;
                break;
            case -1:
                A->balance = 1;
                p->balance = 0;
                break;
            //we can not make pshorter false because total height decreases
        }
        B->balance = 0;
        p->left=rotateleft(A);
        p=rotateright(p);    
    }
    return p;
}



int main ()
{
    int choice,key;
    struct node *root= NULL;
    while(1)
    {
        printf("1.insert\n");
        printf("2.delete\n");
        printf("3.preorder traversal\n");\
        printf("4.postorder traversla\n");
        printf("5.inorder traversal\n");
        printf("6.Quit\n");
        printf("enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("enter the value to be inserted\n");
                scanf("%d",&key);
                root=insert(root,key) ;
                break;
            case 2:
                printf("enter the value to be deleted \n");
                scanf("%d",&key);
                root=delete(root,key);
                break;
            case 3:
                preorder_traversal(root);
                break;
            case 4:
                inorder_traversal(root);
                break ;
            case 5:
                postorder_traversal(root);
                break;
            case 6:
                printf("THANK YOU, HAVE A NICE DAY\n");
                return 0;
            default :
                printf("wrong choice entered\n");
        }
    }
}