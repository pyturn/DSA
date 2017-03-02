#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// EMPLOYEE DATABASE STRUCTURE NODE FORMAT
struct EMP_DATABASE
{
	int Emp_id;
	char Emp_name[20];
    int Emp_Salary;
	char Emp_address[30];
	struct EMP_DATABASE *link;

};

// THIS IS HASHTABLE FORMAT
struct HASHTABLE
{
	struct EMP_DATABASE *link;
};


// THE FUNCTION DECLARATION WHICH ARE USED IN THE PROGRAM
struct EMP_DATABASE* getnode();
void Search(struct HASHTABLE hashtable[], int Emp_id);
void Insert(struct HASHTABLE hashtable[], int Emp_id, char Emp_name[],int Emp_Salary,char Emp_address[]);

int main()
{
	int Emp_id, index, choice,Emp_Salary;
	char Emp_name[20],Emp_address[30];

	// HERE WE ARE MAKING ARRAY OF SIZE 1000 OF TYPE HASHTABLE WHICH WILL ONLY CONTAIN THE LINKs
	struct HASHTABLE hashtable[1000];

	// THIS IS DONE IN ORDER FOR INSERT OPERATION TO WORK
	for(index = 0; index < 1000; index++)
	{
		// HERE WE ARE ASSGINING EACH LINK OF THE ARRAY TO BE NULL
		hashtable[index].link = NULL;
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
				Insert(hashtable, Emp_id, Emp_name,Emp_Salary,Emp_address);
				break;
			case 2:
				printf("ENTER EMPLOYEE ID: \n");
				scanf("%d", &Emp_id);
				Search(hashtable, Emp_id);
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

// THIS FUNCTION IS USED FOR GENERATING A NEW NODE I.E. GETTING MEMORY FOR OUR STRUCTURE
struct EMP_DATABASE* getnode()
{
	struct EMP_DATABASE *temp;
	temp = (struct EMP_DATABASE*) malloc(sizeof(struct EMP_DATABASE));
	return temp;
}

// THIS FUNCTION SEARCHES FOR RECORD FOR WHICH USER HAS PROVIDED AN ID
void Search(struct HASHTABLE hashtable[], int Emp_id)
{
	int Index = Emp_id % 1000;;

	struct EMP_DATABASE *temp;

	temp = hashtable[Index].link;

	// THIS CONDITION IS USED WHEN THE INDEX IS NOT USED I.E. THEIR IS NOTHING IN THAT BLOCK OF HASH-TABLE
	if(temp == NULL)
	{
		printf("NO RECORD EXIST\n");
		return;
	}
	else
	{
		// THIS WHILE LOOP IS USED WHEN WE HAVE TO FIND ID WITH SIMILAR INDEXs
		while(temp->Emp_id != Emp_id && temp != NULL)
		{
			temp = temp->link;
		}

		// THIS CONDITION IS APPLICABLE, IF INDEX IS AVAILABLE BUT THEIR IS NO ID IN THE LINKED LIST
		if(temp == NULL)
		{
			printf("NO RECORD EXIST\n");
			return;
		}
		// THIS CONDITION IS APPLICABLE, IF WE HAVE THE INDEX AND WE HAVE FOUND OUT THE ID SPECIFIED BY USER
		else
		{
			printf("EMPLOYEE ID   - %d\n",temp->Emp_id);
			printf("EMPLOYEE NAME - %s\n",temp->Emp_name);
			printf("EMPLOYEE SALARY - %d\n",temp->Emp_Salary);
			printf("EMPLOYEE ADDRESS - %s\n",temp->Emp_address);
            return;
		}
	}

}


// THIS FUNCTION IS USED TO INSERT A RECORD IN THE LINKED LIST SPECIFIED BY A PARTICULAR INDEX USING HASH FUNCTION
void Insert(struct HASHTABLE hashtable[], int Emp_id, char Emp_name[],int Emp_Salary,char Emp_address[])
{
	int Index;

	struct EMP_DATABASE *temp, *newnode;

	// THIS IS OUR HASH FUNCTION
	Index = Emp_id % 1000;

	// NOW WE ARE STORING THE DATA OF THE HASH TABLE AT THE PARTICULAR INDEX IN TEMP VARIABLE
	temp = hashtable[Index].link;

	// THIS CONDITION WILL WORK WHEN THE INDEX IS NOT USED, IT IS THE FIRST TIME WE ARE USING IT
	// ADDING A NODE INTO IT
	if(temp == NULL)
	{
		newnode = getnode();

		newnode->Emp_id = Emp_id;
		strcpy(newnode->Emp_name, Emp_name);
		newnode->Emp_Salary = Emp_Salary;
		strcpy(newnode->Emp_address, Emp_address);
		newnode->link = NULL;

		// THIS STATEMENT WILL LINK THE HASHTABLE LINK TO NEWNODE ADDRESS
		hashtable[Index].link = newnode;

		return;
	}
	// THIS CONDITION WILL WHEN WE HAVE A NODE AT THE INDEX AND WE WANT TO INSERT A NEWNODE WITH THE SAME INDEX
	else
	{

		newnode=getnode();
        newnode->Emp_id = Emp_id;
		strcpy(newnode->Emp_name, Emp_name);
		newnode->Emp_Salary = Emp_Salary;
		strcpy(newnode->Emp_address, Emp_address);


		// SO WHAT WE DO IS THAT WE INSERT THE NEWNODE AT THE BEGINNING OF THE LINKED LIST
		newnode->link = temp;
		// AND THEN CHANGE THE ADDRESS ACCORDINGLY
		hashtable[Index].link = newnode;

		return;

	}
}
