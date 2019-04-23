struct node
{
	int weight;
	int edge;
	node* next;
};

struct graph
{
	node** list;
	int nodes;
	int edges;
};


graph* initializeGraph(int v,int e);

node* createNode(int w, int e);

void printGraph(graph* newGraph);

bool inGraph(graph* Graph, int value);

void DijkstrasLength(graph* Graph, int s, int t, int flag);

void DijkstrasPath(int* parent, int* path, int s, int t, int iter);
