#include <stdio.h>
#include <stdlib.h>
struct student {
	char name[30];
	float cgpa;
	struct student *next;
};
void traverse_list(struct student *head);
int main ()
{	
	struct student *start=(struct student *)malloc(20*sizeof(char) +1*sizeof(float) + 1*sizeof(struct student *));	
	struct student *second =(struct student *)malloc(20*sizeof(char) +1*sizeof(float) + 1*sizeof(struct student *));	
	struct student *thired=(struct student *)malloc(20*sizeof(char) +1*sizeof(float) + 1*sizeof(struct student *));	
	struct student *fourth=(struct student *)malloc(20*sizeof(char) +1*sizeof(float) +1*sizeof(struct student *));
	struct student *last=(struct student *)malloc(20*sizeof(char) +1*sizeof(float)+ 1*sizeof(struct student *));
	printf("enter the info for student 1:\n");
	fgets(start->name,30,stdin);
	scanf("%f",&(start->cgpa) );
	getchar();
	start->next=second;
	printf("enter the info for student 2:\n");
	fgets(second->name,30,stdin);
	scanf("%f",&(second->cgpa) );
	getchar();
	second->next=thired;
	printf("enter the info for student 3:\n");
	fgets(thired->name,30,stdin);
	scanf("%f",&(thired->cgpa) );
	getchar();
	thired->next=fourth;
	printf("enter the info for student 4:\n");
	fgets(fourth->name,30,stdin);
	scanf("%f",&(fourth->cgpa) );
	getchar();
	fourth->next=last;
	printf("enter the info for student 5:\n");
	fgets(last->name,30,stdin);
	scanf("%f",&(last->cgpa) );
	getchar();
	last->next=NULL;
	traverse_list(start);
	return 0;
}
void traverse_list(struct student *head)
{
	struct student *p;
	int i=1;
	p=head;
	printf("the complete list is \n");
	while(p != NULL){
		fputs(p->name,stdout);
		printf("%.2f  ",p->cgpa);
		p=p->next;
		printf("\n\n") ;
	}
	// printf("value of i= %d \n",i);
	return ;
}	
	
	