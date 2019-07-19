#include <iostream>
#include <vector>
using namespace std;

void func(int remain, vector<bool> &check, vector<int> &arr) {
    if (!remain) {
        for (int k : arr) cout << k << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1; i <= check.size(); i++)
        if (!check[i]) {
            check[i] = true;
            arr.push_back(i);
            func(remain - 1, check, arr);
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
    vector<int> arr;
    cin >> n >> m;
    check.resize(n);
    arr.reserve(m);
    func(m, check, arr);
    return 0;
}