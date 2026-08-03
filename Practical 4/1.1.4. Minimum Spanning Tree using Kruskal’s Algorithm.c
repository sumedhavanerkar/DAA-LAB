#include <stdio.h>
#include <stdlib.h>
#include <limits.h>



void kruskalMST(int **cost, int V) {

	// Write your code here...
	int parent[100];

	for (int i = 0; i < V; i++)
		parent[i] = i;

	int edges = 0, mincost = 0;

	while (edges < V - 1)
	{
		int min = INT_MAX;
		int a = -1, b = -1;

		for (int i = 0; i < V; i++)
			{
				for (int j = i + 1; j < V; j++)
					{
						if (cost[i][j] < min)
						{
							min = cost[i][j];
							a = i;
							b = j;
						}
					}
			}

			if (a == -1)
				break;
}