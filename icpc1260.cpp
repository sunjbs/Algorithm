#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

void dfs(int u, vector<set<int> > &graph, vector<bool> &visited){
    visited[u] = true;
    cout << u << ' ';
    for(int v : graph[u])
        if(!visited[v])
            dfs(v, graph, visited);
}

void bfs(int s, vector<set<int> > &graph){
    queue<int> que;
    vector<bool> visited(graph.size());
    visited[s] = true;
    que.push(s);
    while(que.size()){
        int u = que.front();
        cout << u << ' ';
        que.pop();
        for(int v : graph[u])
            if(!visited[v]){
                visited[v] = true;
                que.push(v);
            }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, v;
    vector<bool> visited;
    vector<set<int> > graph;
    cin >> n >> m >> v;
    visited.resize(n + 1);
    graph.resize(n + 1);
    for(int i = 0; i < m; i++){
        int s, t;
        cin >> s >> t;
        graph[s].insert(t);
        graph[t].insert(s);
    }
    dfs(v, graph, visited);
    cout << '\n';
    bfs(v, graph);
    return 0;
}