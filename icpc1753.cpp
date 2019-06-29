#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

// first -> d, second -> v
using Edge = pair<int, int>;

void dijkstra(int s, vector<int> &dist, vector<list<Edge> > &graph){
    priority_queue<Edge, vector<Edge>, greater<Edge> > pq;
    dist[s] = 0;
    pq.push(Edge(dist[s], s));
    while(pq.size()){
        int u = pq.top().second;
        pq.pop();
        for(Edge edge : graph[u]){
            int d = edge.first, v = edge.second;
            if(dist[v] != -1 && dist[v] <= dist[u] + d) continue;
            dist[v] = dist[u] + d;
            pq.push(Edge(dist[v], v));
        }
        graph[u].clear();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int v, e, k;
    vector<int> dist;
    vector<list<Edge> > graph;
    cin >> v >> e >> k;
    dist.resize(v + 1, -1);
    graph.resize(v + 1);
    for(int i = 0; i < e; i++){
        int u, v, d;
        cin >> u >> v >> d;
        graph[u].push_back(Edge(d, v));
    }
    dijkstra(k, dist, graph);
    for(int i = 1; i <= v; i++)
        if(dist[i] < 0)
            cout << "INF\n";
        else
            cout << dist[i] << '\n';
}