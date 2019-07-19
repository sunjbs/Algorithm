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
        func(i + 1, n, remain - 1, arr);
        arr.pop_back();
    }
}

int main() {
    int n, m;
    vector<int> arr;
    cin >> n >> m;
    arr.reserve(m);
    func(1, n, m, arr);
    return 0;
}