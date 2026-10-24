#include <stdio.h>
#include <limits.h>

#define INF 999999

struct Edge {
	int u, v, w;
};

void printPath(int parent[], int v) {
	if (parent[v] == -1) {
		printf("%d", v);
		return;
	}

	printPath(parent, parent[v]);
	printf("->%d", v);
}

int main() {
	int V, E;

	scanf("%d", &V);
	scanf("%d", &E);

	struct Edge edge[E];

	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);
	}

	int source;
	scanf("%d", &source);

	int dist[V + 1];
	int parent[V + 1];

	for (int i = 1; i <= V; i++) {
		dist[i] = INF;
		parent[i] = -1;
	}

	dist[source] = 0;

	for (int i = 1; i <= V -1; i++) {
		int changed = 0;

		for (int j = 0; j < E; j++) {
			int u = edge[j].u;
			int v = edge[j].v;
			int w = edge[j].w;

			if (dist[u] != INF && dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				parent[v] = u;
				changed = 1;
			}
		}

		if (!changed)
			break;
	}

	for (int i = 0; i < E; i++) {
		int u = edge[i].u;
		int v = edge[i].v;
		int w = edge[i].w;

		if (dist[u] != INF && dist[u] + w < dist[v]) {
			printf("Negative cycle detected\n");
			return 0;
		}
	}

	for (int i = 1; i <= V; i++) {
		if (i == source)
			continue;

		if (dist[i] == INF) {
			printf("%d INF None\n", i);
			} else {
				printf("%d %d ", i, dist[i]);
			printPath(parent, i);
			printf("\n");
		}
	}

	return 0;
}
