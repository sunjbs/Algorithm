#include <iostream>
#include <vector>
#include <set>
using namespace std;

int dfs(int k, int &group, vector<int> &visited, vector<int> &relation, set<int> &answer){
    if(visited[k])
        if(visited[k] == group) return k;
        else return -1;
    visited[k] = group;
    int until_k = dfs(relation[k], group, visited, relation, answer);
    if(until_k > 0) answer.insert(k);
    if(until_k == k) until_k = -1;
    return until_k;
}

int main(){
    int n, group = 0;
    vector<int> visited, relation;
    set<int> answer;
    cin >> n;
    visited.resize(n + 1);
    relation.resize(n + 1);
    for(int i = 1; i <= n; i++)
        cin >> relation[i];
    
    for(int i = 1; i <= n; i++)
        if(!visited[i])
            dfs(i, ++group, visited, relation, answer);

    cout << answer.size() << '\n';
    for(int k : answer)
        cout << k << '\n';
    return 0;
}