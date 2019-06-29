#include <stdio.h>
#define MAX_V 1010

void dfs(int u, int edge[], int graph[][MAX_V], int visited[]) {
    printf("%d ", u);
    visited[u] = 1;
    for(int i = 0; i < edge[u]; i++){
        int v = graph[u][i];
        if(visited[v] == 0)
            dfs(v, edge, graph, visited);
    }
}

int main() {
    int n, m, s;
    int edge[MAX_V] = {
        0,
    };
    int visited[MAX_V] = {
        0,
    };
    int graph[MAX_V][MAX_V] = {
        0,
    };
    scanf("%d %d %d", &n, &m, &s);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][edge[u]++] = v;
        graph[v][edge[v]++] = u;
    }
    dfs(s, edge, graph, visited);
    return 0;
}