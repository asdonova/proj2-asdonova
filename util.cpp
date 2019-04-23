#include "Heap.h"
#include "util.h"
#include "graph.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;
void swap(int *x, int *y)//used to swap nodes of a heap
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

bool isInitialized(Heap* heap)
{
	int capacity = heap->capacity;
	cout << capacity;
	if (&heap == NULL)
	{
		return false;
	}
	return true;
}

bool getFileSize(int size)
{
	ifstream inFile;
	inFile.open("Ginput.txt");
	int input;
	int input1;
	int input2;
	inFile >> input;
	inFile >> input;
	int counter = 0;
	while (inFile >> input >> input1 >> input2)
	{
		counter++;
	}
	if (counter < size)
	{
		return false;
	}
	return true;
}

bool isEmpty(Heap* heap)//Checks to see if heap is empty
{
	int size = heap->size;
	if (size == 0)
	{
		return true;
	}
	return false;
}
void printMenu()
{
	std::cout << "S. The Program Stops" << std::endl << "C n. Creates an Empty Heap with Capacity Equal to n"
		<< std::endl << "R. Builds a Heap from Array A Inside of HEAPinput.txt" << std::endl << "W. Prints Heap information" <<
		std::endl << "I f k. Inserts an ELEMENT into Heap" << std::endl <<
		"D f. Deletes Minimum Element from Heap and Print its Key" << std::endl <<
		"K f i v. Decreases the Key of the Element with Index i to v" << std::endl;
}