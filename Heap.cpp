#include "Heap.h"
#include "util.h"
#include "graph.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <math.h>
#include <stdlib.h>
void swapHeapNode(heapNode* a, heapNode* b)
{
	struct heapNode t = *a;
	*a = *b;
	*b = t;
}

void minHeapify(struct Heap* heap, int index)// Min heapify from notes
{
	int smallest = index;
	int left = 2 * index + 1;
	int right = 1 * index + 2;
	if (left < heap->size && heap->Q[left]->distance < heap->Q[smallest]->distance)
	{
		smallest = left;
	}

	if (right < heap->size && heap->Q[right]->distance < heap->Q[smallest]->distance)
	{
		smallest = right;
	}
	if (smallest != index)
	{
		heapNode* smallestNode = heap->Q[smallest];
		heapNode* indexNode = heap->Q[index];
		heap->position[smallestNode->vert] = index;
		heap->position[indexNode->vert] = smallest;
		swapHeapNode(heap->Q[smallest], heap->Q[index]);
		minHeapify(heap, smallest);
	}
}

Heap* initialize(int n)//Creates a new capacity size and element array and save it to heap
{
	Heap* newHeap = new Heap();//Allocates memory for the heap from the heap
	newHeap->position = new int[n];
	newHeap->capacity = n - 1;
	newHeap->size = 0;
	newHeap->Q = (struct heapNode**) malloc(n * sizeof(struct heapNode*));//Allocates memory for the node list
	int i = 1;

	return newHeap;
}

//FINISH
void decreaseKey(Heap* heap, int v, int d)
{
	int i = heap->position[v];
	heap->Q[i]->distance = d;
	while (i>1 && heap->Q[i]->distance < heap->Q[(i) / 2]->distance)
	{
		heap->position[heap->Q[i]->vert] = i / 2;
		heap->position[heap->Q[i / 2]->vert] = i;
		swapHeapNode(heap->Q[i], heap->Q[i / 2]);
		i = i / 2;
	}
	//return heap;
}

struct heapNode* createHeapNode(int vert, int distance)
{
	struct heapNode* newNode = new heapNode;
	newNode->vert = vert;
	newNode->distance = distance;
	return newNode;
}


heapNode* extractMin(Heap* heap)//Extracts min and maintains heap property
{
	if (isEmpty(heap) == true)//Checks to see if the heap is empty
	{
		return NULL;
	}
	struct heapNode* rootNode = heap->Q[1];
	struct heapNode* endNode = heap->Q[heap->size];
	heap->Q[1] = endNode;
	heap->position[rootNode->vert] = heap->size;
	heap->position[endNode->vert] = 1;//Makes last node the new root

	--heap->size;
	minHeapify(heap, 1);

	return rootNode;
}

bool inMinHeap(struct Heap* heap, int v)//Checks to see if a node is in the heap
{
	if (heap->position[v] < heap->size)
	{
		return true;
	}
	false;
}

void printHeapGraph(int* distance, int n)
{
	std::cout << "PRINTED GRAPH ";
	int i = 1;
	for (i; i <= n; ++i)
	{
		std::cout << i << ":" << distance[i] << " ";
	}
}

