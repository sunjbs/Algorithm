#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    vector<vector<bool> > dist;
    cin >> n;
    dist.resize(n, vector<bool>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++){
            int k;
            cin >> k;
            dist[i][j] = (bool)k;
        }

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dist[i][j] = dist[i][j] || (dist[i][k] && dist[k][j]);

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout << dist[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}