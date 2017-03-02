struct adj_listnode
{
	int dest;
	struct adj_listnode *link;
};

struct adj_list
{
	int vertex;
	struct adj_list *link;
	struct adj_listNode *head;
};

struct Graph
{
	struct adj_list *head;
};

struct adj_listnode *newadj_listnode(int dest);
struct adj_list *newadj_list(int v);
struct Graph* createGraph();

void addNode(struct Graph* graph, int vertex);
void addEdge(struct Graph* graph, int src, int dest);
void searchNode(struct Graph *graph, int vertex);
void deleteEdge(struct Graph* graph, int src, int dest);
