#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void func(int remain, vector<bool> &check, vector<int> &arr, vector<int> &num) {
    if (!remain) {
        for (int i : arr) cout << num[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 0; i < check.size(); i++)
        if (!check[i]) {
            check[i] = true;
            arr.push_back(i);
            func(remain - 1, check, arr, num);
            check[i] = false;
            arr.pop_back();
        }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    vector<bool> check;
    vector<int> arr, num;
    cin >> n >> m;
    check.resize(n);
    arr.reserve(m);
    num.resize(n);
    for (int &k : num) cin >> k;
    sort(num.begin(), num.end());
    func(m, check, arr, num);
    return 0;
}