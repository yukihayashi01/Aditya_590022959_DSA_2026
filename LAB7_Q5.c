#include <stdio.h>

int graph[20][20], visited[20], queue[20];
int n;

void bfs(int start) {
    int front=0, rear=0;

    visited[start]=1;
    queue[rear++]=start;

    while(front<rear) {
        int current = queue[front++];
        printf("%d ", current);

        for(int i=0;i<n;i++) {
            if(graph[current][i] && !visited[i]) {
                visited[i]=1;
                queue[rear++]=i;
            }
        }
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

    printf("BFS Traversal: ");
    bfs(start);

    return 0;
}
