#include<stdio.h>
#include<stdlib.h>
# define bool int
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
struct node* insert(struct node *root, int data);
struct node* search(struct node* root, int data);

int main()
{
	int option,data,lh,rh;
	struct node *root=NULL, *temp;
	do{
		printf("Press 1 to create Binary Search Tree\n");
		printf("Press 2 to search the data.\n");
		printf("Press 3 to traverse the data in preorder.\n");
		printf("Press 4 to traverse the data in inorder.\n");
		printf("Press 5 to traverse the data in postorder.\n");
		printf("Press 6 to exit.\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
			printf("Enter the data\n");
			scanf("%d",&data);
			root=insert(root,data);
			break;
			case 2:
			printf("Enter the data which you want to search\n");
			scanf("%d",&data);
			struct node *ptr=search(root,data);
			if(ptr==NULL)
			printf("No such data exsists\n");
			else
			printf("Data Exsists\n");
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
struct node* insert(struct node *root, int data)
{
	struct node *ptr=root;
	if(ptr==NULL)
	{
		//printf("Enter if\n");
		struct node *node1;
		node1=getnode();
		node1->info=data;
		node1->left=node1->right=NULL;
		return node1;
	}
	if(ptr->info < data)
	{
		ptr->right=insert(ptr->right,data);
	}
	else
	{
		ptr->left=insert(ptr->left,data);
	}
	return ptr;
}


struct node* search(struct node* root, int data)
{
    
    if (root == NULL || root->info == data)
       return root;
    
    if (root->info < data)
       return search(root->right, data);
 
    return search(root->left, data);
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
