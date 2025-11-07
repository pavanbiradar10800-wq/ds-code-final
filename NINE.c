/*
There are flight paths between cities. If there is a flight between city A and city B then
there is an edge between the cities. The cost of the edge can be the time that flight takes
to reach city B from A or the amount of fuel used for the journey. Represent this as a
graph. The node can be represented by the airport name or name of the city. Use
adjacency list representation of the graph or use adjacency matrix representation of the
graph. Check whether the graph is connected or not
*/

#include <stdio.h>

#define MAX 10  // maximum number of cities

int adj[MAX][MAX]; // adjacency matrix
int visited[MAX];
int n;  // number of cities

// Function to perform DFS (Depth First Search)
void DFS(int v) {
    visited[v] = 1; // mark city as visited

    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

// Function to check if graph is connected
void checkConnected() {
    // Start DFS from first city (index 0)
    DFS(0);

    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            printf("❌ The graph is NOT connected.\n");
            return;
        }
    }

    printf("✅ The graph is CONNECTED.\n");
}

int main() {
    int edges, i, j;
    char cities[MAX][20];

    printf("Enter number of cities: ");
    scanf("%d", &n);

    // Read city names
    printf("Enter city names:\n");
    for (i = 0; i < n; i++) {
        printf("City %d: ", i + 1);
        scanf("%s", cities[i]);
    }

    // Initialize adjacency matrix
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            adj[i][j] = 0;

    printf("\nEnter number of direct flight connections: ");
    scanf("%d", &edges);

    printf("Enter connections (format: city1 city2):\n");
    for (i = 0; i < edges; i++) {
        int src, dest;

        printf("Connection %d (Enter city numbers 1-%d): ", i + 1, n);
        scanf("%d %d", &src, &dest);

        // Since it's an undirected graph
        adj[src - 1][dest - 1] = 1;
        adj[dest - 1][src - 1] = 1;
    }

    // Display adjacency matrix
    printf("\n✈️  Adjacency Matrix (Flight Paths):\n");
    printf("      ");
    for (i = 0; i < n; i++)
        printf("%s ", cities[i]);
    printf("\n");

    for (i = 0; i < n; i++) {
        printf("%s ", cities[i]);
        for (j = 0; j < n; j++) {
            printf("  %d   ", adj[i][j]);
        }
        printf("\n");
    }

    // Initialize visited array to 0
    for (i = 0; i < n; i++)
        visited[i] = 0;

    // Check if the graph is connected
    printf("\nChecking connectivity...\n");
    checkConnected();

    return 0;
}

