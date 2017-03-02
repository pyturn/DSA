#include"header.h"
struct stacky15 *top=NULL;
struct stacky15* getstacky15()
{
	struct stacky15 *s;
	s=(struct stacky15*)malloc(sizeof(struct stacky15));
	return s;
}
void push(char name[])
{
	struct stacky15 *ptr,*temp;
	ptr=getstacky15();
	if(top==NULL)
	{
		top=ptr;
		top->next=NULL;
	}
	else
	{
		temp=top;
		top=ptr;
		top->next=temp;
	}
	strcpy(top->name,name);
	return;
}
void pop(char name[])
{
	struct stacky15 *ptr,*temp;
	if(isempty())
		printf("Underflow\n");
	else
	{
		ptr=top;
		top=top->next;		
		strcpy(name,ptr->name);
	}
return ;
}
int isempty()
{
	if(top==NULL)
		return 1;
	else
		return 0;
}
