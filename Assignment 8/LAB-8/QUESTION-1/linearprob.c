#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "func.h"
// EMPLOYEE DATABASE STRUCTURE FORMAT
struct EMP_DATABASE
{
	int Emp_id;
	int Emp_Salary;
	char Emp_name[20];
	char Emp_address[30];
};

// DECLARATION OF THE FUNCTION USED IN THE PROGRAM TO PERFORM SIMPLE TASKS
void Search(struct EMP_DATABASE Database[], int Emp_id);
void Insert(struct EMP_DATABASE Database[], int Emp_id, char Emp_name[],int Emp_Salary,char Emp_address[]);


int main()
{
	int Emp_id, index, choice, Emp_Salary;
	char Emp_name[20],Emp_address[30];

	// CREATING ARRAY OF EMP_DATABASE TYPE
	struct EMP_DATABASE Database[2000];

	// HERE WHAT WE ARE DOING IS THAT WE ARE ASSIGNING ALL THE Emp_id EQUAL TO 'ZERO'
	for(index = 0; index < 2000; index++)
	{
		Database[index].Emp_id = 0;
	}

	while(1)
	{
		printf("ENTER A CHOICE:\n\n");
		printf("1.INSERT A RECORD IN EMPLOYEE DATABASE\n");
		printf("2.SEARCH AN EMPLOYEE RECORD FROM DATABASE\n");
		printf("3.EXIT\n");

		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("ENTER EMPLOYEE ID: \n");
				scanf("%d", &Emp_id);
				printf("ENTER EMPLOYEE NAME: \n");
				scanf("%s", Emp_name);
				printf("ENTER EMPLOYEE SALARY: \n");
				scanf("%d", &Emp_Salary);
				printf("ENTER EMPLOYEE ADDRESS: \n");
				scanf("%s", Emp_address);
				Insert(Database, Emp_id, Emp_name,Emp_Salary,Emp_address);
				break;
			case 2:
				printf("ENTER EMPLOYEE ID: \n");
				scanf("%d", &Emp_id);
				Search(Database, Emp_id);
				break;
			case 3:
				exit(0);
			default:
				printf("INVALID CHOICE\n");
				break;
		}
	}
	return 0;
}

void Search(struct EMP_DATABASE Database[], int Emp_id)
{
	int Index = Emp_id % 2000;
	int i;

	for(i = 0; i < 2000; i++)
	{

		if(Database[(Index + i) % 2000].Emp_id == Emp_id)
		{
			Index = (Index + i) % 2000;
			break;
		}
	}

	printf("EMPLOYEE ID   - %d\n",Database[Index].Emp_id);
	printf("EMPLOYEE NAME - %s\n",Database[Index].Emp_name);
    printf("EMPLOYEE SALARY- %d\n",Database[Index].Emp_Salary);
    printf("EMPLOYEE ADDRESS - %s\n",Database[Index].Emp_address);
}


void Insert(struct EMP_DATABASE Database[], int Emp_id, char Emp_name[],int Emp_Salary,char Emp_address[])
{
	int Index;
	Index = Emp_id % 2000;
	while(Database[Index].Emp_id != 0)
	{
		if(Index == 1999)
		{
			Index = 0;
			continue;
		}
		Index++;
   	}
	Database[Index].Emp_id = Emp_id;
	Database[Index].Emp_Salary = Emp_Salary;
	strcpy(Database[Index].Emp_name, Emp_name);
	strcpy(Database[Index].Emp_address, Emp_address);

}

