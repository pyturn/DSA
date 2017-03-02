#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node *head=NULL;
struct node *tail=NULL;
struct node* getnode();
void insertfront(int data);
void insertlast(int data);
void print1();
void print2();
void insertn(int data,int n);
void delete1(int n);
int main()
{
	int choice,data,position;
	do{
		printf(" 1.Insert at first position.\n 2.Insert at last position.\n 3.Traverse the list from left to right direction and display the items in the list.\n 4.Traverse the list from right to left direction and display the items in the list.\n 5.Insert an item at the nth position in the list.\n 6.Delete a specified item from the list.\n 7.Exit the program\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
            printf("Enter the data\n");
			scanf("%d",&data);
			insertfront(data);
			break;
			case 2:
			scanf("%d",&data);
			insertlast(data);
			break;
			case 3:
            printf("Elements of the list in forward position are\n");
			print1();
			break;
			case 4:
            printf("Elements of the list in reverse position are\n");
			print2();
			break;
			case 5:
            printf("Enter the data\n");
            scanf("%d",&data);
            printf("Enter the position where you want to insert the data\n");
            scanf("%d",&position);
            insertn(data,position);
            break;
            case 6:
            printf("Enter the position of node which you want to delete\n");
            scanf("%d",&position);
            delete1(position);
            print1();
            break;
            case 7:
                exit(1);
                break;

		}
	  }while(choice<=7);
        exit(1);
}

struct node* getnode()
{
	struct node *ptr;
	ptr=(struct node *)malloc(sizeof(struct node));
	return ptr;
}
void insertfront(int data)
{
	//int i;
	struct node *temp;
	temp=getnode();
	temp->data=data;

		if(head==NULL)
		{
			temp->link=NULL;
			head=temp;
			tail=head;
			return;
		}
		else
		{
			//temp->link=NULL^head;
			temp->link=head;
			//head->link=(head->link)^NULL^temp;
			head->link=(struct node *)((unsigned int)head->link^(unsigned int)temp);
			head=temp;
			return;
		}

}
void insertlast(int data)
{
	struct node *temp;
	temp=getnode();
	temp->data=data;
	if(tail==NULL)
	{
		temp->link=NULL;
		//temp1=temp;
		tail=temp;
		head=tail;
	}
	else
	{
		tail->link=(struct node *)((unsigned int)(tail->link)^(unsigned int)temp);
		temp->link=(tail);
		tail=temp;
	}
}
void print1()
{
	struct node *temp,*prev;
	prev=NULL;
	temp=head;
	while(temp)
	{
		printf("%d\n",temp->data);
		struct node* next=(struct node *)((unsigned int)(temp->link)^(unsigned int)prev);
		prev=temp;
		temp=next;
	}
}
void print2()
{
	struct node *temp,*next;
	next=NULL;
	temp=tail;
	while(temp)
	{
		printf("%d\n",temp->data);
		struct node *prev=(struct node *)((unsigned int)(temp->link)^(unsigned int)next);
		next=temp;
		temp=prev;
	}
}
void insertn(int data,int n)
{
    int i;
    struct node *temp,*prev,*ptr1;
    ptr1=getnode();
    ptr1->data=data;
	prev=NULL;
	temp=head;
	for(i=1;i<n;i++)
	{
		//printf("%d\n",temp->data);
		struct node* next=(struct node *)((unsigned int)(temp->link)^(unsigned int)prev);
		prev=temp;
		temp=next;
		if(temp==NULL)
        {
          insertlast(data);
          return;
        }
        else
            continue;
	}
	ptr1->link=(struct node *)((unsigned int)(temp)^(unsigned int)(prev));
	prev->link=(struct node *)((unsigned int)(prev->link)^(unsigned int)(temp)^(unsigned int)(ptr1));
	temp->link=(struct node *)((unsigned int)(temp->link)^(unsigned int)(prev)^(unsigned int)(ptr1));
}
void delete1(int n)
{
    int i;
    struct node *temp,*prev,*next;
    temp=head;
    prev=NULL;
    for(i=1;i<n;i++)
    {
        next=(struct node *)((unsigned int)(temp->link)^(unsigned int)(prev));
        prev=temp;
        temp=next;
    }
    next=(struct node *)((unsigned int)(temp->link)^(unsigned int)(prev));
    prev->link=(struct node *)((unsigned int)(prev->link)^(unsigned int)(temp)^(unsigned int)(next));
    next->link=(struct node *)((unsigned int)(next->link)^(unsigned int)(temp)^(unsigned int)(prev));
}
