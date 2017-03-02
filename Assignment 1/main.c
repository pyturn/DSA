#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct database
{
	int id,position;
	char name[20];
	char designation[20];
	int salary;
	struct database *next;
};
struct database *head =NULL;
void addfirst(int a, char b[], char c[], int d);
void append(int a, char b[], char c[], int d);
void addat(int a, char b[], char c[], int d, int e);
void print();

int main()
{
	int id,salary,position,choice,cnt;
	char name[20],designation[20];

	do
	{
		printf("1.Add the record of a new employee at the beginning of database.\n2.Add the record of a new employee at the end of database.\n3.Add the record of a new employee at nth position in the database.\n4.Print the records of all employeee.\n5.Delete a specific record from the database.\n6.Search the record of a specific employee./n7.Count the number of employees\n\8.Reverse the order of employees inserted in database.\n9. Enter 9 to exit the program\n" );
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
			printf("Employee Id-");
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
			printf("Employee Id-");
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
            printf("Employee Id-");
			scanf("%d",&id);
			printf("Name-");
			scanf("%s",name);
			printf("Designation-");
			scanf("%s",designation);
			printf("Salary-");
			scanf("%d",&salary);
			printf("Enter position-");
			scanf("%d",&position);
			addat(id,name,designation,salary,position);
			break;
			case 4:
			print();
			break;
			case 5:
            printf("Enter the position of record which you want to delete/n");
            scanf("%d",&position);
            del(position);
            break;
            case 6:
            printf("Enter the id of employee\n");
            scanf("%d",&id);
            search(id);
            break;
            case 7:
            cnt=count();
            printf("The number of employees in our collection is %d\n",cnt);
            break;
            case 8:
            printf("List in Reverse is\n");
            reverse();
            print();
            break;
            case 9:
                exit(1);
		}
	}while(choice<=8);
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
	for(i=2;i<position;i++)
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
void del(int position)
{
    int i,id,salary;
    char name[20],designation[20];
	struct database *ptr,*temp;
	temp=head;
	for(i=2;i<=position;i++)
	{
	    ptr=temp;
		temp=temp->next;
	}
	id=ptr->id;
	strcpy(name,ptr->name);
	strcpy(designation,ptr->designation);
	salary=ptr->salary;
	ptr->next=temp->next;
	printf("The data which you have deleted is\n");
    printf("Employee Id- %d\n",id);
    printf("Name- %s\n",name);
    printf("Designation- %s\n",designation);
    printf("Salary- %d\n",salary);
	printf("\n\n NOW THE COLLECTION OF DATABASE IS \n\n");
    print();
}
void search(int id)
{
    struct database *ptr,*temp;
    temp=head;
	while(temp->id!=id)
	{
	    if(temp==NULL)
        {
            printf("Such id do not exsist in our database\n");
            return;
        }
		temp=temp->next;
	}
	printf("The data of the employee is\n");
    printf("Employee Id- %d\n",temp->id);
    printf("Name- %s\n",temp->name);
    printf("Designation- %s\n",temp->designation);
    printf("Salary- %d\n",temp->salary);
}
int count()
{
    struct database *ptr,*temp;
    int count=1;
	temp=head;
	if(head==NULL)
        return 0;
    else
    {
        while(temp->next!=NULL)
        {
            count++;
            temp=temp->next;
        }
    }
    return count;

}
void reverse()
{
    struct database *current, *prev,*temp;
    current=head;
    prev=NULL;
    while(current!=NULL)
    {
        temp=current->next;
        current->next=prev;
        prev=current;
        current=temp;
    }
    head=prev;
    //current->next=NULL;
}









