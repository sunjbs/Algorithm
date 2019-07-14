#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    vector<vector<int> > sum;
    cin >> n >> m;
    sum.resize(n + 1, vector<int>(n + 1));
    for(int r = 1; r <= n; r++)
        for(int c = 1; c <= n; c++){
            cin >> sum[r][c];
            sum[r][c] += sum[r - 1][c] + sum[r][c - 1] - sum[r - 1][c - 1];
        }
    
    for(int i = 0; i < m; i++){
        int sr, sc, er, ec;
        cin >> sr >> sc >> er >> ec;
        cout << (sum[er][ec] - sum[er][sc - 1] - sum[sr - 1][ec] + sum[sr - 1][sc - 1]) << '\n';
    }
    return 0;
}