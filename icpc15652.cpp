#include <iostream>
#include <vector>
using namespace std;

void func(int start, int n, int remain, vector<int> &arr) {
    if (!remain) {
        for (int k : arr) cout << k << ' ';
        cout << '\n';
        return;
    }
    for (int i = start; i <= n; i++) {
        arr.push_back(i);
        func(i, n, remain - 1, arr);
        arr.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    vector<int> arr;
    cin >> n >> m;
    arr.reserve(m);
    func(1, n, m, arr);
    return 0;
}