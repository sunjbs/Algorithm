#include <iostream>
using namespace std;

int main(){
    const int MOD = 10007;
    int n, t = 1;
    int dp[2][10] = { 0, };
    for(int i = 0; i < 10; i++)
        dp[0][i] = 1;
    dp[1][0] = 1;
    cin >> n;
    for(int i = 0; i < n; i++, t = 1 - t)
        for(int j = 1; j < 10; j++)
            dp[t][j] = (dp[1 - t][j] + dp[t][j - 1]) % MOD;
    t = 1 - t;
    cout << dp[t][9];
    return 0;
}