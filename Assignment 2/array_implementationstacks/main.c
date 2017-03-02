
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct database
{
	int id;
	char name[20];
	char designation[20];
	int salary;
	struct database *next;
};
struct database *head=NULL;
void addfirst(int a, char b[], char c[], int d);
void append(int a, char b[], char c[], int d);
void addat(int a, char b[], char c[], int d, int e);
void print();
int main()
{
	int id,salary,position,choice;
	char name[20],designation[20];

	do
	{
		printf("1.Add the record of a new employee at the beggining of database.\n2Add the record of a new employee at the end of database.\n3.Add the record of a new employee at nth position in the database.\n4.Print the records of all employeee.\n5.Reverse the order of employees inserted in database.\n6.Delete a specific record from the database.\n6.Search the record of a specific employee.\n7.Count the number of employees.\n8. Enter 8 to exit the program\n" );
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
            printf("Employee Id - ");
			scanf("%d",&id);
            printf("Name-");
			scanf("%s",name);
            printf("Designation-");
			scanf("%s",designation);
            printf("Salary-");
			scanf("%d",&salary);
			addfirst(id,name,designation,salary);
			break;

			case 2:
            printf("Employee Id - ");
			scanf("%d",&id);
            printf("Name-");
			scanf("%s",name);
            printf("Designation-");
			scanf("%s",designation);
            printf("Salary-");
			scanf("%d",&salary);
            append(id,name,designation,salary);
			break;

			case 3:
			 printf("Employee Id - ");
			scanf("%d",&id);
            printf("Name-");
			scanf("%s",name);
            printf("Designation-");
			scanf("%s",designation);
            printf("Salary-");
			scanf("%d",&salary);
			printf("Enter Position at which you want to insert-")
			scanf("%d",&position);
			addat(id,name,designation,salary,position);
			break;
			case 4:
			print();
			break;
		}
	}while(choice!=8);
	exit(1);
}


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
	for(i=1;i<position;i++)
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

