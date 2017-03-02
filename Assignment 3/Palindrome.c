#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	char data;
	struct node* next;
	struct node* previous;
};

struct node* front=NULL;
struct node* rear=NULL;

struct node* create()
{
	struct node* d=(struct node*)malloc(sizeof(struct node));
	d->next=NULL;
	d->previous=NULL;
	return d;
}

void EnqueueFront(char str)
{
	struct node* d=create();
	d->data=str;
	d->previous=NULL;
	d->next=front;
	if(front==NULL)
	{
		front=d;
		rear=d;
	}
	else
	{	front->previous=d;
		front=d;
	}
}

void EnqueueEnd(char str)
{
	struct node* d=create();
	d->data=str;
	d->next=NULL;
	d->previous=rear;
	if(rear==NULL&&front==NULL)
	{
		front=d;
		rear=d;
	}
	else
	{	rear->next=d;
		rear=d;
	}
}

char DequeueFront()
{
	if(front==NULL)
	printf("Underflow\n");
	else
	{
	struct node* temp;
	temp=front;
	front=temp->next;
	front->previous=NULL;
	return temp->data;
	}
}

char DequeueEnd()
{
	if(rear==NULL)
	{	printf("Underflow\n");
		return ;
	}
	else
    {
	struct node* temp;
	temp=rear;
	rear=temp->previous;
	if(rear!=NULL)
	 rear->next=NULL;
	return temp->data;
	}
}

void Print()
{
	struct node* temp;
	temp=front;

	while(temp!=NULL)
	{
		printf("%c ",temp->data);
		temp=temp->next;
	}
}
int main()
{
	int i,flag;
	char x,y;
	char str[100],finale[100];
	printf("Input the String\n");
	scanf("%[^\n]",str);
	//gets(str);
	for(i=0;i<strlen(str);i++)
    {
            EnqueueEnd(str[i]);
    }
    /*for(i=0;i<strlen(str)/2;i++)
    {
        x=DequeueFront();
        y=DequeueEnd();
        printf("X=%c Y=%c\n",x,y);
        if(x==y)
            flag=1;
        else
        {
             printf("NOT PALINDROME\n");
             return;
        }
    }
    if(flag==1)
        printf("PALINDROME\n");
    return 0;
    */
    for(i=0;i<strlen(str);i++)
    {
         finale[i]=DequeueEnd();
    //     printf("%c ",finale[i]);
    }
    finale[i]='\0';
    //printf("%s %s\n",str,finale);
    if(strcmp(finale,str))
        printf("NOT PALINDROME\n");
    else
        printf("PALINDROME\n");

}

