//this program includes all the functions written in recursive aproach 
#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *left_child;
    struct node *right_child;
};
typedef struct node node1;

void preorder(node1 *rt)//rt for root
{
    if(rt == NULL){
        return ;
    }
    else {
        printf("%d\t",rt->data);
        preorder(rt->left_child);
        preorder(rt->right_child);
    }
    return ;
}
void postorder(node1 *rt)
{
    if(rt == NULL){
        return ;
    }
    else {
        postorder(rt->left_child);
        postorder(rt->right_child);
        printf("%d\t",rt->data);
    }
    return ;
}
void inorder(node1 *rt)
{
    if(rt == NULL){
        return ;
    }
    else {
        inorder(rt->left_child);
        printf("%d\t",rt->data);
        inorder(rt->right_child);
    }
    return ;
}
node1 *rec_binary_search(node1 *ptr,int x)
{
    if(ptr == NULL){
        return NULL;
    }
    if(x < ptr->data ){
        rec_binary_search(ptr->left_child,x);
    }
    else if(x > ptr->data){
        rec_binary_search(ptr->right_child,x);
    }
    else {
        return ptr;
    }
}

node1 *rec_min_key(node1 *ptr)
{
    if(ptr == NULL){
        return NULL;
    }
    if(ptr->left_child != NULL){
        return rec_min_key(ptr->left_child);
    }
    return ptr;
}

node1 *rec_max_key(node1 *ptr)
{
    if(ptr == NULL){
        return NULL;
    }
    if(ptr->right_child != NULL){
        return rec_max_key(ptr->right_child);
    }
    else {
        return ptr;
    } 
}
node1 *rec_insert(node1 *ptr,int x)//x is the value to be inserted 
{
    if(ptr == NULL){
        ptr=(node1 *)malloc(sizeof(node1 ));
        ptr->data=x;
        ptr->left_child=NULL;
        ptr->right_child=NULL;  
        return ptr;  
    }
    else if(ptr != NULL)
    {
        if(x < ptr->data){
            ptr->left_child= rec_insert(ptr->left_child,x);
        }
        else if(x > ptr->data){
            ptr->right_child=rec_insert(ptr->right_child,x);
        }
        else {
            printf("key identical to this is present \a \n");
            return ptr;
        }
    }    
    return ptr;
}
int height(node1 *ptr)
{
    int h_left,h_right;
    if(ptr == NULL){
        return 0;
    }
    else {
        h_left=height(ptr->left_child);
        h_right=height(ptr->right_child);
    }
    if(h_right >h_left){
        return 1+h_right;
    }
    else{
        return 1+h_left;
    }
}
int main ()
{
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
        printf("9.height of tree\n");
        printf("enter choice \n");
        scanf("%d",&choice);
        int element;
        switch(choice)
        {
            case 1:
                printf("enter the value to be inserted\n");
                scanf("%d",&element);
                root=rec_insert(root,element);
                break;
            case 2:
                printf("enter the key to be searched\n");
                scanf("%d",&element);
                result=rec_binary_search(root,element);
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
                printf("preorder traversal is \n");
                preorder(root);
                printf("\n");
                break;
            case 4:
                printf("postorder traversal is \n");
                postorder(root);
                printf("\n");
                break;
            case 5:
                printf("inorder traversal is \n");
                inorder(root);
                printf("\n");
                break;
            case 6:
                result=rec_min_key(root);
                printf("the minimum key is %d\n",result->data);
                break;
            case 7:
                result=rec_max_key(root);
                printf("the maximum key is %d\n",result->data);
                break;
            case 8:
                printf("THANK YOU, HAVE A NICE DAY\n");
                break;
            case 9:
                printf("the height of the tree is %d\n ",height(root));
                break;
            default:
                printf("wrong choice\n");
        }
    }
} 