#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next; 
};

struct node* head;
struct node* getnode(int x)
{
	struct node* s=(struct node*)malloc(sizeof(struct node));
	s->data=x ;
	return s;
}

int Delete(struct node* temp)
{
	int x;
	struct node* temp1;
	temp1=temp->next;
	x= temp1->data;
	temp->next=temp1->next;
	return x;
}

void Print(int n)
{	
	int i;	
	struct node* temp=head;
	for(i=0;i<n;i++)
	{
		printf("%d  ",temp->data);
		temp=temp->next;
	}
}

int main()
{
	int m,n,i=1,j,x;
	head=NULL;
	struct node* temp;
	struct node* temp1;
	printf("Number of players : ");
	scanf("%d",&n);
int k=n;
	while(n--)
	{	if(head==NULL)
		{	temp=getnode(i++);
			head=temp;
			temp1=temp;
		}
		else
		{
			temp=getnode(i++);
			temp->next=NULL;
			temp1->next=temp;
			temp1=temp;			
		}
		if(n==0)
		{
			temp->next=head;
		}
	}
	//Print(k);	

	printf("Enter the value of m : ");
	scanf("%d",&m);	
	struct node* tem=head;
	while(k--)
	{
		if(m==0)
		{
			for(i=0;i<k;i++)
			{
				tem=tem->next;
			}
		}
		else
		{
			for(i=0;i<m-1;i++)
			{
				tem=tem->next;
			}
		}
		x=Delete(tem);
		tem=tem->next;
		if(k==0)
		printf("\nWinner is : %d \n",x);
		else
		printf("%d ",x);
	}
	
}
