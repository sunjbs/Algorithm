#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void func(int start, int n, int remain, vector<int> &arr, vector<int> &num) {
    if (!remain) {
        for (int i : arr) cout << num[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = start; i < n; i++) {
        arr.push_back(i);
        func(i, n, remain - 1, arr, num);
        arr.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    vector<int> arr, num;
    cin >> n >> m;
    arr.reserve(m);
    num.resize(n);
    for (int &k : num) cin >> k;
    sort(num.begin(), num.end());
    func(0, n, m, arr, num);
    return 0;
}