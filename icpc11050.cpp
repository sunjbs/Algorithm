#include <iostream>
#include <vector>
using namespace std;

int getBinomialCoefficient(int n, int k,
                           vector<vector<int> >& binomialCoefficient) {
    int& value = binomialCoefficient[n][k];
    if (value) return value;
    if (k == 0 || k == n) return value = 1;
    return value = getBinomialCoefficient(n - 1, k - 1, binomialCoefficient) +
                   getBinomialCoefficient(n - 1, k, binomialCoefficient);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    vector<vector<int> > binomialCoefficient(11, vector<int>(11));
    cin >> n >> k;
    cout << getBinomialCoefficient(n, k, binomialCoefficient);
    return 0;
}