#include <stdio.h>

int main() {
    int n, e, u, v, vertex;
    int graph[20][20] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    for(int i=0;i<e;i++) {
        printf("Enter edge (u v): ");
        scanf("%d%d", &u, &v);
        graph[u][v] = 1;
    }

    printf("\nAdjacency Matrix:\n");
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++)
            printf("%d ", graph[i][j]);
        printf("\n");
    }

    printf("Enter vertex: ");
    scanf("%d", &vertex);

    int indegree=0, outdegree=0;

    for(int i=0;i<n;i++) {
        outdegree += graph[vertex][i];
        indegree += graph[i][vertex];
    }

    printf("In-degree = %d\n", indegree);
    printf("Out-degree = %d\n", outdegree);

    return 0;
}
