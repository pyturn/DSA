#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct stacky15
{
	 struct stacky15 *next;
	char name[20];
};


void push(char name[]);
void pop(char name[]);
int isempty();
struct stacky15* getstacky15();


