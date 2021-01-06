
#include<stdio.h>
void heapsort(int *,int,int);
void heapify(int *,int,int);
int main()
{
	int a[20],n,i;
	printf("how many values\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	for (i=(n-2)/2;i>=0;i--)
	heapify(a,i,n-1);
	printf("initial heap made\n");
	heapsort(a,0,n-1);
	for(i=0;i<n;i++)
	printf("%d\n",a[i]);
}
void heapsort(int *a, int root,int end)
{
	int t;
	//printf("going in %d %d\n",root,end);
	if(root<end)
	{
		heapify(a,root,end);
		//printf("xchanging %d %d\n",a[root],a[end]);
		t=a[root];
		a[root]=a[end];
		a[end]=t;	
		//printf("after xchanging %d %d\n",a[root],a[end]);
		heapsort(a,root,end-1);
}
}
void heapify(int *a,int root,int end)
{  
	int maxchild,left,right,t;
	 if (root<=(end-1)/2)
	 {
	 left=root*2+1;
	 right=root*2+2;
	 if (left==end)
		maxchild=left;
	else if (a[left]>a[right])		
		maxchild=left;
	else
		maxchild=right;
	if (a[root]<a[maxchild])	
	{
		t=a[root];
		a[root]=a[maxchild];
		a[maxchild]=t;
	    heapify(a,maxchild,end);
	}	
    }
}