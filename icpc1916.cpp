#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

using pint = pair<int, int>;
int dijkstra(int s, int t, vector<int> &dist, vector<vector<int> > &graph){
    priority_queue<pint, vector<pint>, greater<pint> > pq;
    dist[s] = 0;
    pq.push(pint(s, dist[s]));
    while(!pq.empty()){
        int now = pq.top().second;
        pq.pop();
        if(now == t) break;
        for(int next = 1; next < graph[now].size(); next++){
            if(dist[next] > dist[now] + graph[now][next]){
                dist[next] = dist[now] + graph[now][next];
                pq.push(pint(dist[next],next));
            }
        }
    }
    return dist[t];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    const int INF = 1000000000;
    int n, m, s, t;
    vector<int> dist;
    vector<vector<int> > graph;
    cin >> n >> m;
    dist.resize(n + 1, INF);
    graph.resize(n + 1, vector<int>(n + 1, INF));
    for(int i = 0; i < m ; i++){
        int u, v, d;
        cin >> u >> v >> d;
        graph[u][v] = min(graph[u][v], d);
    }
    cin >> s >> t;
    cout << dijkstra(s, t, dist, graph);
    return 0;
}