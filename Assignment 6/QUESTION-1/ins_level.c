#include<stdio.h>
#include<stdlib.h>
struct node* getnode();
struct Queue* getqueue();
void enqueue(struct node *ptr1);
struct Queue* dequeue();
int isemptyqueue();
void Deletequeue();
void insert(int data,struct node **root);
void display(struct node **root);
void preorder(struct node **root);
void inorder(struct node **root);
void postorder(struct node **root);
struct node
{
	int info;
	struct node *left;
	struct node *right;
};
struct node* getnode()
{
	struct node *ptr;
	ptr= (struct node *)malloc(sizeof(struct node));
	return ptr;
}
struct Queue
{
	struct node *ptr;
	struct Queue *queue;
};
struct Queue* getqueue()
{
	struct Queue *queue;
	queue= (struct Queue*)malloc(sizeof(struct Queue));
	return queue;
}
struct Queue *Q=NULL;

int main()
{
	int option,data;
	struct node *root=NULL;
	do{
		printf("Press 1 to insert data in tree\n");
		printf("Press 2 to to traverse level wise.\n");
		printf("Press 3 for preorder traversal.\n");
		printf("Press 4 for inorder traversal.\n");
		printf("Press 5 for postorder traversal.\n");
		printf("Press 6 to exit.\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
			printf("Enter the data\n");
			scanf("%d",&data);
			insert(data,&root);
			break;
			case 2:
			printf("Traverse Level Wise \n");
			display(&root);
			break;
			case 3:
			printf("Traverse in pre-order\n");
			preorder(&root);
			break;
			case 4:
			printf("Traverse in-order\n");
			inorder(&root);
			break;
			case 5:
			printf("Traverse post-order\n");
			postorder(&root);
			break;
			case 6:
			exit(1);
			break;
		}
	 }while(option<=6);
}
void enqueue(struct node *ptr1)
{
	struct Queue *temp,*ptr2;
	ptr2=Q;
	temp=getqueue();
	temp->ptr=ptr1;
	if(ptr2==NULL)
	{
		temp->queue=NULL;
		Q=temp;
		return;
	}
	else
	{
		while(ptr2->queue!=NULL)
		{
			ptr2=ptr2->queue;
		}
		ptr2->queue=temp;
		temp->queue=NULL;
	}
	return;
}	
struct Queue* dequeue()
{
	struct Queue *temp,*ptr2;
	ptr2=Q;
	Q=ptr2->queue;
	return ptr2;
}
int isemptyqueue()
{
	if(Q==NULL)
		return 0;
	else
		return 1;
}
void Deletequeue()
{
	Q=NULL;
	return;
}
void insert(int data,struct node **root)
{
	struct node *node1,*node2;
	struct Queue *queue1;
	node2=getnode();
	node2->info=data;
	node2->left=node2->right=NULL;
	if(*root==NULL)
	{
		*root=node2;
		return;
	}
	else
	{
		enqueue(*root);
		int flag=isemptyqueue();
		while(flag!=0)
		{
			queue1=dequeue();
			struct node *node3=queue1->ptr;
			if(node3->left)
			{
				enqueue(node3->left);
				flag=isemptyqueue();
			}
			else
			{
				node3->left=node2;
				Deletequeue();
				return;
			}
			if(node3->right)
			{
				enqueue(node3->right);
				flag=isemptyqueue();
			}	
			else
			{
				node3->right=node2;
				Deletequeue();
				return;
			}
		}
	}
}
void display(struct node **root)
{
	struct node *node1,*node2;
	struct Queue *queue1;
	if(*root==NULL)
	{
		printf("Tree is empty\n");
		return;
	}
	else
	{
		
		enqueue(*root);
		int flag=isemptyqueue();
		while(flag!=0)
		{
			queue1=dequeue();
			struct node *node3=queue1->ptr;
			printf("%d\n",node3->info);
			if(node3->left)
			{
				enqueue(node3->left);
			}
			
			if(node3->right)
			{
				enqueue(node3->right);
			}	
			flag=isemptyqueue();
		}
		return;
	}
}				
void preorder(struct node **root)
{
	struct node *ptr;
	ptr=*root;
	if(ptr)
	{
		printf("%d\n",ptr->info);
		preorder(&(ptr->left));
		preorder(&(ptr->right));
	}
}
void inorder(struct node **root)
{
	struct node *ptr;
	ptr=*root;
	if(ptr)
	{
		inorder(&(ptr->left));
		printf("%d\n",ptr->info);
		//preorder(&(ptr->left));
		inorder(&(ptr->right));
	}
}		
void postorder(struct node **root)
{
	struct node *ptr;
	ptr=*root;
	if(ptr)
	{
		postorder(&(ptr->left));
		postorder(&(ptr->right));
		printf("%d\n",ptr->info);
	}
}	













		 
	
