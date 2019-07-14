#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    vector<int> sum;
    cin >> n >> m;
    sum.resize(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> sum[i];
        sum[i] += sum[i - 1];
    }
    for(int i = 0; i < m; i++){
        int s, e;
        cin >> s >> e;
        cout << sum[e] - sum[s - 1] << '\n';
    }
    return 0;
}