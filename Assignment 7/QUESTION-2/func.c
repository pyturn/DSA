#include <stdio.h>
#include <stdlib.h>
#include "func.h"


struct adj_listnode *newadj_listnode(int dest)
{
	struct adj_listnode *newnode = (struct adj_listnode*) malloc(sizeof(struct adj_listnode));
	newnode->dest = dest;
	newnode->link = NULL;
	
	return newnode;
}

struct adj_list *newadj_list(int v)
{
	struct adj_list *vertex = (struct adj_list*) malloc(sizeof(struct adj_list));
	vertex->vertex = v;
	vertex->link = NULL;
	vertex->head = NULL;
	
	return vertex;
}

struct Graph* createGraph()
{
	struct Graph *graph = (struct Graph*) malloc(sizeof(struct Graph));
	graph->head = NULL;
    
	return graph;
}


void addNode(struct Graph* graph, int vertex)
{
	struct adj_list* node = newadj_list(vertex);
	struct Graph *last = graph;
	if(graph->head == NULL)
	{
		graph->head = node;
	}
	else
	{
		while(last->head->link != NULL)
		{
			last->head = last->head->link;
		}
		
		last->head->link = node;
	}		
}

void addEdge(struct Graph* graph, int src, int dest)
{
	struct adj_listnode *newnode = newadj_listnode(dest);
	struct Graph *last = graph;
	
	while(last->head->vertex != src)
	{
		last->head = last->head->link;
	}
	newnode->link = last->head->head;
	last->head->head = newnode;


	last = graph;
	newnode =  newadj_listnode(src);
	while(last->head->vertex != dest)
	{
		last->head = last->head->link;
	}
	newnode->link = last->head->head;
	last->head->head = newnode;
}

void searchNode(struct Graph *graph, int vertex)
{
	struct Graph *last = graph;
	
	while(last->head != NULL)
	{
		if(last->head->vertex == vertex)
		{
			printf("VERTEX FOUND\n");
			break;
		}
	
		last->head = last->head->link;
	}
	
	if(last->head == NULL)
	{
		printf("VERTEX NOT FOUND\n");	
	}

	return;	
}

void deleteEdge(struct Graph* graph, int src, int dest)
{
	struct Graph *last = graph;
	struct adj_listnode *curr, *prev;
 
	while(last->head->vertex != src)
	{
		last->head = last->head->link;
	}

	curr = last->head->head;

	while(curr->dest != dest)
	{
		prev = curr;
		curr = curr->link;
	}
	
	if(curr == last->head->head)
	{
		last->head->head = curr->link;
		free(curr);
	}
	else
	{
		prev->link = curr->link;
		free(curr);
	}


	last = graph;

	while(last->head->vertex != dest)
	{
		last->head = last->head->link;
	}

	curr = last->head->head;

	while(curr->dest != src)
	{
		prev = curr;
		curr = curr->link;
	}
	
	if(curr == last->head->head)
	{
		last->head->head = curr->link;
		free(curr);
	}
	else
	{
		prev->link = curr->link;
		free(curr);
	}
}
