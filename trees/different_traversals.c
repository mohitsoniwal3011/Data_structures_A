#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *left_child;
    struct node *right_child;
};
typedef struct node node1;
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

int main ()
{
    node1 *root=create_tree();
    printf("preorder traversal of the binary tree is\n");
    preorder(root);
    printf("\n");
    printf("post order traversal of the tree is \n");
    postorder(root);
    printf("\n");
    printf("inorder traversal of the binary tree is\n");
    inorder(root);
    return 0;
}