#include"assn.h"
struct database *head=NULL;
void *getdatabase()
{
	struct database *ptr;
	ptr=(struct database *)malloc(sizeof(struct database));
	return ptr;
}
void addfirst(int id, char name[], char designation[], int salary)
{
	struct database *ptr,*temp;
	ptr=getdatabase();
	if(head==NULL)
	{
		head=ptr;
		ptr->next=NULL;
	}
	else
	{
		temp=head;
		head=ptr;
		ptr->next=temp;
	}
	ptr->id=id;
	strcpy(ptr->name,name);
	strcpy(ptr->designation,designation);
	ptr->salary=salary;
}
void append(int id, char name[], char designation[], int salary)
{
	struct database *ptr,*temp;
	ptr=getdatabase();
	temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=ptr;
	ptr->id=id;
	strcpy(ptr->name,name);
	strcpy(ptr->designation,designation);
	ptr->salary=salary;
	ptr->next=NULL;
}
void print()
{
	struct database *ptr;
	ptr=head;
	while(ptr!=NULL)
	{
		printf("Employee id-%d\n",ptr->id);
		printf("Emplyee name-%s\n",ptr->name);
		printf("Employee designation-%s\n",ptr->designation);
		printf("Employee salary-5%d\n",ptr->salary);
		printf("\n\n\n");
		ptr=ptr->next;
	}
}
void addat(int id, char name[], char designation[], int salary, int position)
{
	int i;
	struct database *ptr,*temp;
	ptr=getdatabase();
	temp=head;
	for(i=0;i<position-1;i++)
	{
		temp=temp->next;
	}
	ptr->next=temp->next;
	temp->next=ptr;
	ptr->id=id;
	strcpy(ptr->name,name);
	strcpy(ptr->designation,designation);
	ptr->salary=salary;
}		
	
	
		
