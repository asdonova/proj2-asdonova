#include "Heap.h"
#include "util.h"
#include "graph.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main()
{
	int s, t, flag, n, m, u, v, w;//initalizes variables that will be used
	char input;
	graph* newGraph = NULL;//Initializes to NULL
	Heap* heap = NULL;//initalizes to null
	bool checkInitialization = false;//used to check if initialized
	string line;
	ifstream inFile;
	ELEMENT* temp;
	while (1)
	{
		cin >> input; // Takes in char
		cout << "COMMAND: " << input;

		switch (input)// Dictates which case will be used
		{
		case 'e':
		case 'E':
			cout << "." << endl;
			cout << "The program is going to be terminated." << endl;
			return 0; //Exit functions

		case 'i':
		case 'I':
			cout << "." << endl;
			inFile.open("Ginput.txt");

			if (!inFile.is_open())//Chekcs to see if there is a file that exists
			{
				cout << "There was a problem opening file Ginput.txt for reading." << endl;
			}
			else
			{
				inFile >> n;
				inFile >> m;
				if (getFileSize(m) == false)//Checks to see if the indicated number of edges matches the amount given
				{
					cout << "Error:  The number of edges is less than as specified in the beginning of the file." << endl;
				}
				else
				{
					newGraph = initializeGraph(n, m);
					newGraph->list = (struct node**) malloc(newGraph->nodes * sizeof(struct graph));//Allocates memory from heap
					int counter = 1;
					int i = 1;
					for (i; i <= newGraph->nodes; i++)
					{
						newGraph->list[i] = NULL;//Initializes all the indexes to NULL
					}
					for (counter; counter <= m; counter++)
					{

						inFile >> u;
						inFile >> v;
						inFile >> w;
						node* newNode = createNode(w, v);//Creates a new Node struct
						if (newGraph->list[u] == NULL)
						{
							newGraph->list[u] = newNode;
						}
						else
						{
							node* tail = newGraph->list[u];
							while (tail->next != NULL)//Finds the last element of linked list
							{
								tail = tail->next;
							}
							tail->next = newNode;//Insert new object at the end of linked list
						}
						checkInitialization = true;//Inidcates that the graph was initalized
					}
					inFile.close();
				}
			}
			break;

		case 'w':
		case 'W':
			cout << "." << endl;
			if (checkInitialization == false)//Fails if the graph was not initialized
			{
				cout << "Error:  There is no graph to print." << endl;
			}
			else
			{
				cout << n << " " << m << endl;//Displays first 2 values of file
				printGraph(newGraph);
			}
			break;
		case 'c':
		case 'C':
				cin >> s;
				cout << " " << s << " ";
				cin >> t;
				cout << t << " ";
				cin >> flag;
				cout << flag << "." << endl;
				if (checkInitialization == false)//Checks to see if graph was initalized
				{
					cout << "Error:  There is no graph to run Dijkstra's algorithm on." << endl;
				}
				else
				{
					if (inGraph(newGraph, s) == true && inGraph(newGraph, t) == true)//Checks to see if both values are in the graph.
					{
						if (flag != 0 && flag != 1)
						{
							cout << "Error:  Invalid flag value." << endl;
						}
						else
						{
							DijkstrasLength(newGraph, s, t, flag);
						}
					}
					else
					{
						cout << "Error:  One or more of the nodes is invalid." << endl;
						if (flag != 0 && flag != 1)
						{
							cout << "Error:  Invalid flag value." << endl;
						}
					}
				}
			break;
		}
	}
	return 0;
}
