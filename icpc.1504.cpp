#include <stdio.h>
#define MAX_V 810

int min(int x, int y){
    return (x < y) ? x : y;
}

void dijkstra(int n, int s, int graph[][MAX_V], int dist[]){
    const int INF = 2400000;
    int now = s;
    int visited[MAX_V] = { 0, };
    dist[s] = 0;
    while(now){
        for(int next = 1; next <= n; next++)
            dist[next] = min(dist[next], dist[now] + graph[now][next]);
        visited[now] = 1;
        int d = INF;
        now = 0;
        for(int i = 1; i <= n; i++)
            if(!visited[i] && dist[i] < d){
                now = i;
                d = dist[i];
            }
    }
}

int main(){
    const int INF = 2400000;
    int n, m;
    int p, q;
    int graph[MAX_V][MAX_V];
    int distFrom1[MAX_V], distFromN[MAX_V], distpq[MAX_V];
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        distFrom1[i] = distFromN[i] = distpq[i] = INF;
        for(int j = 1; j <= n; j++)
            graph[i][j] = INF;
    }
    for(int i = 0; i < m; i++){
        int u, v, d;
        scanf("%d %d %d", &u, &v, &d);
        graph[u][v] = graph[v][u] = min(graph[u][v], d);
    }
    scanf("%d %d", &p, &q);
    dijkstra(n, 1, graph, distFrom1);
    dijkstra(n, p, graph, distpq);
    dijkstra(n, n, graph, distFromN);

    int Answer = distFrom1[p] + distpq[q] + distFromN[q];
    Answer = min(distFrom1[q] + distpq[q] + distFromN[p], Answer);
    if(Answer > INF)
        Answer = -1;
    printf("%d", Answer);
    return 0;
}