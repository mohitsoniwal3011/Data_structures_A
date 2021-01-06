#include <stdio.h>
#include <stdlib.h>
struct node {
    struct node *left_child;
    int data;
    struct node *right_child;
};
typedef struct node node1;
node1 *create_tree()//rt stands for root
{
    node1 *newnode=(node1 *)malloc(sizeof(node1));
    static int num=1;
    if(num ==1){
        printf("enter data of root node\n");
        num++;
    }       
    //we are using static int because we do node want the statement "enter data of the root node "
    //to be printed again andd aagin .
    // when there is no child of any node then we will provide input as -1
    int x;
    scanf("%d",&x);
    if(x == -1){
        return NULL;
    }
    else {
        newnode->data= x;
        printf("enter the left child of %d\n",x);
        newnode->left_child=create_tree();
        printf("enter the right child of %d\n",x);
        newnode->right_child= create_tree();
    }
    return newnode;

}
int main ()
{
    node1 *root;
    root=create_tree();
    return 0;  
}