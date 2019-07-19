#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void func(int start, int n, int remain, vector<bool> &check, vector<int> &arr,
          vector<int> &num) {
    if (!remain) {
        for (int i : arr) cout << num[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = start; i < n; i++)
        if (!check[i]) {
            if (i && num[i - 1] == num[i] && !check[i - 1]) continue;
            check[i] = true;
            arr.push_back(i);
            func(i + 1, n, remain - 1, check, arr, num);
            check[i] = false;
            arr.pop_back();
        }
}

int main() {
    int n, m;
    vector<bool> check;
    vector<int> arr, num;
    cin >> n >> m;
    check.resize(n);
    arr.reserve(m);
    num.resize(n);
    for (int &k : num) cin >> k;
    sort(num.begin(), num.end());
    func(0, n, m, check, arr, num);
    return 0;
}