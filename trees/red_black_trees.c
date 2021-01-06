#include <stdio.h>
#include <stdlib.h>
struct node {
    enum {black,red} colour;
    int data;
    struct node *left,*right;
    struct node *parent;     
}
struct node *rotateright(struct node *p)
{
    struct node *A=p->left;
    p->left=A->right;
    A->right=p;
    return A;
}
struct node *rotateleft(struct node *p)
{
    struct node *A=p->right;
    p->right=A->left;
    A->left=p;
    return A;
}

int main ()
{
    int choice,key;
    while(1)
    {
        printf("1.insert\n");
        printf("2.delete\n");
        printf("3.inorder traversal\n");
        printf("4.display\n");
        printf("5.Quit\n");
        printf("enter choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                root=insert(root)
            case 2:
            case 3:
            case 4:
            case 5:
                printf("THANK YOU, HAVE A NICE DAY\n");
                return 0;
            default :
                printf("wrong choice entered\n");
        }
    }
}
