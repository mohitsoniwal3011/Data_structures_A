#include <stdio.h>
#include <stdlib.h>
struct nodetree {
    int data;
    struct node *left;
    struct node *right;
};
struct nodelist{
    char data;
    struct node *next;
};
typedef struct nodetree node1;
typedef struct nodelist node2;
node2 *get_list(node2 *head)
{   
    node2 *temp=(node2 *)malloc(sizeof(node2));
    scanf("%d",&temp->data);
    if(temp->data == -1){
        return NULL;
    }
    int i=0;
    temp->next=NULL;
    node2 *root=temp;
    node2 *back=temp;
    while(1){
        temp=(node2 *)malloc(sizeof(node2));
        scanf("%d",&temp->data);
        if(temp->data == -1){
            break;
        }
        temp->next=NULL;
        back->next=temp;
        back=temp;
    }

    return root; 
}
node1 *construct_tree(node2 *inorder,node2 *preorder,int num)
{
    node1 *root,*parent,*newnode;
    node2 *p=preorder,*q=inorder;
    if(p == NULL){
        printf("tree is empty\n");
        return NULL;
    }
    newnode->data=p->data;
    newnode->left=NULL;
    newnode->right=NULL;
    root=newnode;
    if(p->next == NULL){
        return root;
    }
    int i=0;
    while(q->data != newnode->data){
        q=q->next;
    }



}
int main ()
{
     printf("enter the preorder \n");
    node2 *pre_head=get_list(pre_head) ;
    printf("root-->data = %d\n",pre_head->data);
    printf("enter the inorder \n");
    node2 *in_head=get_list(in_head);

}