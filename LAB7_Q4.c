#include <stdio.h>

int main() {
    int n;
    int graph[20][20];

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    printf("Enter adjacency matrix:\n");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&graph[i][j]);

    int undirected = 1;

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(graph[i][j] != graph[j][i]) {
                undirected = 0;
                break;
            }
        }
    }

    if(undirected)
        printf("Graph is Undirected\n");
    else
        printf("Graph is Directed\n");

    return 0;
}
