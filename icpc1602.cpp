#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

using pint = pair<int, int>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, q;
    const int limit = 987654321;
    vector<pint> bother;
    vector<vector<int> > dist, maxBother;
    cin >> n >> m >> q;
    bother.resize(n + 1);
    dist.resize(n + 1, vector<int>(n + 1, limit));
    maxBother.resize(n + 1, vector<int>(n + 1, limit));
    for (int i = 1; i <= n; i++) {
        cin >> bother[i].first;
        bother[i].second = i;
        dist[i][i] = 0;
        maxBother[i][i] = bother[i].first;
    }
    for (int i = 0; i < m; i++) {
        int u, v, t;
        cin >> u >> v >> t;
        dist[u][v] = dist[v][u] = t;
    }

    sort(bother.begin(), bother.end());
    for (int k = 1; k <= n; k++) {
        int s = bother[k].second;
        int b = bother[k].first;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][s] + dist[s][j]);
                maxBother[i][j] =
                    min(maxBother[i][j],
                        max(dist[i][j] + max(maxBother[i][i], maxBother[j][j]),
                            dist[i][s] + dist[s][j] + b));
            }
        }
    }

    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        cout << ((maxBother[u][v] < limit) ? maxBother[u][v] : -1) << '\n';
    }
    return 0;
}