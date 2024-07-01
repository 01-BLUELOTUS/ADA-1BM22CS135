#include <stdio.h>
#define INF 99999
#define MAX 100


void printSolution(int dist[MAX][MAX], int V);


void floyd(int graph[MAX][MAX], int V) {
    int dist[MAX][MAX], i, j, k;


    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];


    for (k = 0; k < V; k++) {

        for (i = 0; i < V; i++) {

            for (j = 0; j < V; j++) {

                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    printSolution(dist, V);
}

void printSolution(int dist[MAX][MAX], int V) {
    printf("The following matrix shows the shortest distances between every pair of vertices \n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int V, i, j;
    int graph[MAX][MAX];

    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    printf("Enter the adjacency matrix (use %d for infinity):\n", INF);
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);

    floyd(graph, V);

    return 0;
}
