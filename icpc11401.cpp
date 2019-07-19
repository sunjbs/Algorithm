#include <algorithm>
#include <iostream>
using namespace std;

using lint = long long int;

int getInverseModulo(int k, const int m) {
    if (k == 1) return 1;
    int p = m - 2;
    lint inverse = 1;
    while (p) {
        if (p & 1) inverse = inverse * k % m;
        k = (lint)k * k % m;
        p >>= 1;
    }
    return (int)inverse;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    const int MOD = 1000000007;
    int n, k, answer = 1;
    cin >> n >> k;
    k = min(k, n - k);
    for (int i = n; i > n - k; i--) answer = (lint)answer * i % MOD;
    for (int i = 1; i <= k; i++)
        answer = (lint)answer * getInverseModulo(i, MOD) % MOD;
    cout << answer;
    return 0;
}