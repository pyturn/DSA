#include"header.h"
int main()
{
	char name[20],name1[20];;
	int ch;
	do{
		printf("1. Press 1 to inserts a student name\n");
		printf("2. Press 2 to delete the name\n");
		printf("3. Press 3 to exit from the program\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: 
			printf("Enter the name of the student\n");
			scanf("%s",name);
			push(name);
			//printf("%s",top->name);
			break;
			case 2:
			pop(name);
			printf("The name which you have deleted %s\n",name);
			break;
			
		}
	}while(ch<3);
exit(1);
}

