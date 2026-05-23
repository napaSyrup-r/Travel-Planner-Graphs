#include <stdio.h>
#include <limits.h>
#define MAX 100

int graph[MAX][MAX];
int n;

void dijkstra(int source, int destination) {
    int dist[MAX], visited[MAX], parent[MAX];
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
        parent[i] = -1;
    }
    dist[source] = 0;
    for (int count = 0; count < n - 1; count++) {
        int min = INT_MAX, u;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && dist[v] <= min) {
                min = dist[v], u = v;
            }
        }
        visited[u] = 1;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }
    printf("\nShortest distance from location %d to location %d: %d\n", source, destination, dist[destination]);
}

void floydWarshall() {
    int dist[MAX][MAX];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = graph[i][j];
            if (i != j && graph[i][j] == 0) dist[i][j] = INT_MAX;
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    printf("\nAll-pairs shortest paths computed using Floyd-Warshall Algorithm.\n");
}

void bellmanFord(int source) {
    int dist[MAX];
    for (int i = 0; i < n; i++) dist[i] = INT_MAX;
    dist[source] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int u = 0; u < n; u++) {
            for (int v = 0; v < n; v++) {
                if (graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                }
            }
        }
    }
    printf("\nShortest paths from location %d using Bellman-Ford Algorithm computed.\n", source);
}

int main() {
    int choice, source, destination, weightType;
    printf("Enter number of locations: ");
    scanf("%d", &n);
    printf("\nChoose weight type for travel:\n");
    printf("1. Distance\n");
    printf("2. Time\n");
    printf("3. Cost\n");
    printf("Enter your choice: ");
    scanf("%d", &weightType);

    printf("\nEnter weights for every route between locations:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                printf("Enter weight from location %d to location %d: ", i, j);
                scanf("%d", &graph[i][j]);
            } else {
                graph[i][j] = 0;
            }
        }
    }

    while (1) {
        printf("\nChoose an algorithm to compute the shortest path:\n");
        printf("1. Dijkstra's Algorithm (Single Source Shortest Path)\n");
        printf("2. Floyd-Warshall Algorithm (All Pairs Shortest Paths)\n");
        printf("3. Bellman-Ford Algorithm (Single Source Shortest Path)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 4) break;
        if (choice == 1 || choice == 3) {
            printf("\nEnter source location (index 0 to %d): ", n - 1);
            scanf("%d", &source);
            printf("Enter destination location (index 0 to %d): ", n - 1);
            scanf("%d", &destination);
            if (choice == 1) dijkstra(source, destination);
            else bellmanFord(source);
        } else if (choice == 2) {
            floydWarshall();
        } else {
            printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}

