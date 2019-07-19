#include <iostream>
#include <vector>
using namespace std;

int getKthPrimeNumber(int k) {
    if (k == 1) return 2;
    vector<bool> check(1 << 23);
    for (int i = 2; i < check.size(); i += 2) check[i] = true;
    k--;
    for (int p = 3;; p += 2)
        if (!check[p]) {
            for (int i = p * 2; i < check.size(); i += p) check[i] = true;
            if (!--k) return p;
        }
}

int main() {
    int k;
    cin >> k;
    cout << getKthPrimeNumber(k);
    return 0;
}