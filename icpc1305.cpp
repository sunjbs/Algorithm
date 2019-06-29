#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    string p;
    vector<int> failure;
    cin >> n;
    getline(cin, p);
    getline(cin, p);
    failure.resize(p.size());

    for (int i = 1, f = 0; i < p.size(); i++) {
        while (f > 0 && p[i] != p[f]) f = failure[f - 1];
        if (p[i] == p[f]) failure[i] = ++f;
    }
    cout << n - failure[n - 1];
    return 0;
}