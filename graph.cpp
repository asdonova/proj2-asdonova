#include <iostream>
#include "Heap.h"
#include "graph.h"
#include "util.h"
using namespace std;

graph* initializeGraph(int v, int e)//Initalizes a graph ogject
{
	graph* newGraph = new graph();//Allocates memory on the heap
	newGraph->nodes = v;
	newGraph->edges = e;
	return newGraph;
}

node* createNode(int w, int e)//Creates a new Node object
{
	node* newNode = new node();//Allocates memory on the heap for the new node
	newNode->weight = w;
	newNode->edge = e;
	newNode->next = NULL;
	return newNode;
}

void printGraph(graph* newGraph)//Prints out the list
{
	int arrayIt = 1;
	for (arrayIt; arrayIt <=  newGraph->nodes; arrayIt++)//iterates through the array
	{
		cout << arrayIt << " : ";
		node* listIt = newGraph->list[arrayIt];//starts at the head node of a specific index
		while (listIt != NULL)//Iterates through the linked lists
		{
			cout << "(" << listIt->edge << ", " << listIt->weight << ")";
			if (listIt->next != NULL)
			{
				cout << "; ";
			}
			listIt = listIt->next;
		}
		cout << endl;
	}
}
bool inGraph(graph* Graph, int value)//Used to check to see if the the node is within the graph
{
	bool returnCheck = false;
	int arrayIt = 1;
	for (arrayIt; arrayIt <= Graph->nodes; arrayIt++)//Iterates through the array
	{
		node* listIt = Graph->list[arrayIt];
		while (listIt != NULL)//Iterates through the linked lists
		{
			if (listIt->edge == value)
			{
				returnCheck = true; //returns true if value is found
			}
			listIt = listIt->next;
		}
	}
	return returnCheck; //returns false if the value is not found
}
void DijkstrasLength(graph* Graph, int s, int t, int flag)
{
	
	int numOfV = Graph->nodes;
	int* distance = new int[numOfV+1];
	int* parent = new int[numOfV + 1];
	int* path = new int[numOfV + 1];
	for (int i = 1; i <= numOfV; i++)//Initalizes all the integers to NULL
	{
		parent[i] = NULL;
		path[i] = NULL;
	}
	int iterator = 1;
	struct Heap* minHeap = initialize(numOfV + 1);
	int iter = 1;
	for (iter; iter <= numOfV; ++iter)//Iterates through the vertexes
	{
		distance[iter] = 1000;//Sets the weight of all nodes to 1000
		heapNode* temp = createHeapNode(iter, distance[iter]);//Creates a heapnode
		minHeap->Q[iter] = temp;
		minHeap->position[temp->vert] = iter;
	}

	minHeap->Q[s] = createHeapNode(s, distance[s]);
	minHeap->position[s] = s;
	distance[s] = 0; //Sets the soruce vertex to 0
	decreaseKey(minHeap, s, distance[s]); //Decreases key of the the selected node
	minHeap->size = numOfV;
	
	while (isEmpty(minHeap) == false)//Extracts nodes from heap
	{

		struct heapNode* minNode = extractMin(minHeap);
		int extracted = minNode->vert;
		node* traversal = Graph->list[extracted];
		while(traversal != NULL)//Traverses through the linked list
		{

			int v = traversal->edge;
			if (traversal->weight + distance[extracted] < distance[v])
			{
				distance[v] = distance[extracted] + traversal->weight; //increases weight
				parent[v] = extracted;//sets parent to extraced
				decreaseKey(minHeap, v, distance[v]);
			}
			traversal = traversal->next;
		}
	}
	if (flag == 0)
	{
		if (distance[t] == 1000)	//If the node is not reachable from soruce
		{
			cout << "Sorry, node " << t << " is not reachable from node " << s << endl;
		}
		else
		{
			cout << "LENGTH: " << distance[t] << endl;
		}
	}
	else if (flag == 1)
	{
		if (distance[t] == 1000)//If the node is not reachable from source
		{
			cout << "Sorry, node " << t << " is not reachable from node " << s << endl;
		}
		else
		{
			DijkstrasPath(parent, path, s, t, iterator);
		}
	}

}

void DijkstrasPath(int* parent, int* path, int s, int t, int iter)
{
	if (t == s)//Base case of recursion
	{
		int i;
		path[iter] = s;
		for (i = 1; i <= iter; i++) // finds the end of the list to iterate backwards
		{
			//cout << path[i] << endl;
		}
		cout << "PATH: ";
		for (i = i - 1; i != 0; i--)//iterates backwards
		{
			cout << path[i];
			if (i != 1)
			{
				cout << ", ";
			}

		}
		cout << endl;
	}
	else
	{
		path[iter] = t;
		t = parent[t];//sets t equal to its parent
		iter++;
		DijkstrasPath(parent, path, s, t, iter);//Recursivley calls dijkstras.
	}
}



