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

void addfirst(int a, char b[], char c[], int d);
void append(int a, char b[], char c[], int d);
void addat(int a, char b[], char c[], int d, int e);
void print();
	
