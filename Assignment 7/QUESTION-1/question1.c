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
bool isBalanced(struct node *root);
int max(int a, int b);
int height(struct node *root);
struct node* search(struct node* root, int data);

int main()
{
	int option,data,lh,rh;
	struct node *root=NULL, *temp;
	do{
		printf("Press 1 to create Binary Search Tree\n");
		printf("Press 2 to check whether it is height balanced or not.\n");
		printf("Press 3 to evaluate the balanced factor\n");
		/*printf("Press 4 for inorder traversal.\n");
		printf("Press 5 for postorder traversal.\n");
		printf("Press 6 to exit.\n");*/
		scanf("%d",&option);
		switch(option)
		{
			case 1:
			printf("Enter the data\n");
			scanf("%d",&data);
			root=insert(root,data);
			break;
			case 2:
			if(isBalanced(root))
				printf("Tree is balanced\n");
			else
				printf("Tree is not balanced\n");
			break;
			case 3:
			printf("Enter the data of node whose balanced factor you want to evaluate\n");
			scanf("%d",&data);
			struct node *ptr=search(root,data);
			lh = height(ptr->left);
 	 		rh = height(ptr->right);
			printf("%d\n",lh-rh);
			break;
			/*case 4:
			printf("Traverse in-order\n");
			inorder(&root);
			break;
			case 5:
			printf("Traverse post-order\n");
			postorder(&root);
			break;
			case 6:
			exit(1);
			break;*/
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

int height(struct node *root)
{
	if(root==NULL)
		return 0;
	return 1+max(height(root->left),height(root->right));
}
int max(int a, int b)
{
	if(a>b)
		return a;
	else
		return b;
}
bool isBalanced(struct node *root)
{
   int lh; 
   int rh;  
 	if(root == NULL)
    	return 1;
 	 lh = height(root->left);
 	 rh = height(root->right);
 
   if( abs(lh-rh) <= 1 &&
       isBalanced(root->left) &&
       isBalanced(root->right))
     	return 1;
 	return 0;
}
struct node* search(struct node* root, int data)
{
    
    if (root == NULL || root->info == data)
       return root;
    
    if (root->info < data)
       return search(root->right, data);
 
    return search(root->left, data);
}
