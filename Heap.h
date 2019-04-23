
#ifndef Heap_h
#define Heap_h
struct ELEMENT
{
	int key;
};

struct Heap
{
	int capacity;
	int size;
	int *position;
	struct heapNode** Q;
};

struct heapNode
{
	int vert;
	int distance;
	int pi;
};
	
	void minHeapify(Heap* heap, int index);

	Heap* initialize(int n);

	void decreaseKey(Heap* heap, int v, int d);

	heapNode* createHeapNode(int vert, int distance);

	heapNode* extractMin(Heap* heap);

	void printHeapGraph(int* distance, int n);

	bool inMinHeap(struct Heap* heap, int v);


#endif
