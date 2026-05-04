#include <stdio.h>

int graph[20][20], visited[20], n;

void dfs(int vertex) {
    visited[vertex]=1;
    printf("%d ", vertex);

    for(int i=0;i<n;i++) {
        if(graph[vertex][i] && !visited[i])
            dfs(i);
    }
}

int main() {
    int start;

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    printf("Enter adjacency matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&graph[i][j]);

    printf("Enter starting vertex: ");
    scanf("%d",&start);

    printf("DFS Traversal: ");
    dfs(start);

    return 0;
}
