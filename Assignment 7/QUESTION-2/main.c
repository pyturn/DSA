#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int main()
{
	struct Graph *graph = createGraph();
	int choice, node, src, dest;
	while(1)
	{	
		printf("ENTER YOUR CHOICE:\n");
		printf("1.ADD NODE TO GRAPH\n");
		printf("2.ADD EDGE TO GRAPH\n");
		printf("3.SEARCH NODE FROM GRAPH\n");
		printf("4.DELETE EDGE FROM GRAPH\n");
		printf("5.EXIT\n");
		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				printf("ENTER A NODE TO GRAPH:\n");
				scanf("%d", &node);
				addNode(graph, node);
				break;
			case 2:
				printf("ENTER SOURCE AND DESTINATION TO ADD EDGE TO GRAPH:\n");
				printf("ENTER SOURCE:\n");
				scanf("%d", &src);
				printf("ENTER DESTINATION:\n");
				scanf("%d", &dest);
				addEdge(graph, src, dest);
				break;
			case 3:
				printf("ENTER A NODE TO SEARCH IN GRAPH:\n");
				scanf("%d", &node);
				searchNode(graph, node);
				break;
			case 4:
				printf("ENTER SOURCE AND DESTINATION TO DELETE EDGE FROM GRAPH:\n");
				printf("ENTER SOURCE:\n");
				scanf("%d", &src);
				printf("ENTER DESTINATION:\n");
				scanf("%d", &dest);
				deleteEdge(graph, src, dest);
				break;
			
			case 5:
				exit(0);
			
			default:
				printf("INVALID CHOICE\n");
				break;
		}		
	}
	return 0;
}
