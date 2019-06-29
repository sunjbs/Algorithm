#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while (true) {
        string p;
        vector<int> failure;
        getline(cin, p);
        if (p == ".") break;
        failure.resize(p.size());

        for (int i = 1, f = 0; i < p.size(); i++) {
            while (f > 0 && p[i] != p[f]) f = failure[f - 1];
            if (p[i] == p[f]) failure[i] = ++f;
        }
        int g = p.size() - failure[p.size() - 1];
        if(p.size() % g) cout << "1\n";
        else cout << p.size() / g << '\n';
    }
    return 0;
}