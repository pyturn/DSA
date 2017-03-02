#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
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

void EnqueueFront(int x)
{
	struct node* d=create();
	d->data=x;
	d->previous=NULL;
	if(front==NULL)
	{
		front=d;
		rear=d;
		d->next=NULL;
	}
	else
	{	front->previous=d;
        d->next=front;
		front=d;
	}

}

void EnqueueEnd(int x)
{
	struct node* d=create();
	d->data=x;
	d->next=NULL;
	if(rear==NULL&&front==NULL)
	{
		front=d;
		rear=d;
		d->previous=NULL;
	}
	else
	{	rear->next=d;
        d->previous=rear;
		rear=d;
	}
}

void DequeueFront()
{
	if(front==NULL)
	printf("Underflow\n");
	else
	{
	struct node* temp;
	temp=front;
	front=temp->next;
	//rear=temp->previous;
	if(front!=NULL)
	front->previous=NULL;
	else
		;
	free(temp);
	}
}

void DequeueEnd()
{
	if(rear==NULL)
	{	printf("Underflow\n");
		return ;
	}
	else{
	struct node* temp;
	temp=rear;
	rear=temp->previous;
	//front=temp->next;
	if(rear!=NULL)
        rear->next=NULL;
	else
        front=NULL;
	free(temp);
	}
}
void Isempty()
{
    if(front==rear&&front==NULL&&rear==NULL)
        printf("Empty\n");
    else
        printf("Not empty\n");
}

void Isfull()
{
    if(front==rear&&front!=NULL&&rear!=NULL)
        printf("Full\n");
    else
        printf("Not full\n");
}

void Print()
{
	struct node* temp;
	if(front==NULL)
        printf("No data in the list\n");
    else
    {


	temp=front;
    while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp=temp->next;
	}
    }

}
int main()
{
	int n,x;
	while(1)
	{
		printf("\nPress 1 to Enqueue at Front\nPress 2 to Enqueue at end\nPress 3 to Dequeue from Front\nPress 4 to Dequeue from end");
		printf("\nPress 5 for to check the Deque is Empty\nPress 6 to check whether Deque is Full\nPress 7 to Exit\n");
		scanf("%d",&n);
		switch(n)
		{

			case 1 : printf("Input : ");
				 scanf("%d",&x);
				 EnqueueFront(x);
				 Print();
				 break;
			case 2 : printf("Input : ");
				 scanf("%d",&x);
				 EnqueueEnd(x);
				 Print();
				 break;
			case 3 : DequeueFront();
				 Print();
				 break;
			case 4 : DequeueEnd();
				 Print();
				 break;
            case 5 : Isempty();
                     break;
            case 6 : Isfull();
                     break;
			case 7 : exit(1);
		}
	}

}
