#include <iostream>
#include <vector>
using namespace std;

int unionFind(int x, vector<int>& parent) {
    if (x == parent[x]) return x;
    return parent[x] = unionFind(parent[x], parent);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int v, e;
    vector<int> group, count;
    cin >> v >> e;
    group.resize(v + 1);
    for (int i = 1; i <= v; i++) group[i] = i;
    count.resize(v + 1, 1);
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        int uParent = unionFind(u, group);
        int vParent = unionFind(v, group);
        if (uParent == vParent) continue;
        int child = max(uParent, vParent), parent = min(uParent, vParent);
        count[parent] += count[child];
        group[child] = group[parent];
    }

    cout << count[1] - 1 << endl;
    return 0;
}