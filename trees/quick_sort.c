#include <stdio.h>
#define N 10
void quick_sort(int A[],int s,int e) ;
int partition(int A[],int s,int e) ;
int main ()
{
    int A[N] ;
    int i;
    printf("enter the values \n");
    for(i=0;i<N;i++){
        scanf("%d",&A[i]);
    }
    quick_sort(A,0,N-1);
    printf("values in the sorted order are: \n");
    for(i=0;i<N;i++){
        printf("%d\t",A[i]);
    }
    printf("\n");
    return 0;
}
void quick_sort(int A[],int s,int e)
{
    int p;
    if(s<e){
        p=partition(A,s,e);
        quick_sort(A,s,p-1);
        quick_sort(A,p+1,e);
    }
}
int partition(int A[],int s,int e)
{
    int pivot=s;
    int left=e;
    int right=s+1;
    int temp;
    while(left<=right){
        while(A[pivot] < A[right]){
            right=right+1;
        }
        while(A[pivot] >A[left] && left>=s){
            left=left-1;
        }
    }
    if(right <left){
        temp=A[right];
        A[right]=A[left];
        A[left]=temp;
    }
    temp=A[pivot];
    A[pivot]=A[left];
    A[left]=temp;
    return left;
}
