#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string t, p;
    vector<int> failure;
    queue<int> answer;
    getline(cin, t);
    getline(cin, p);
    failure.resize(p.size());

    for (int i = 1, f = 0; i < p.size(); i++) {
        while (f > 0 && p[i] != p[f]) f = failure[f - 1];
        if (p[i] == p[f]) failure[i] = ++f;
    }

    for (int i = 0, f = 0; i < t.size(); i++) {
        while (f > 0 && t[i] != p[f]) f = failure[f - 1];
        if (t[i] == p[f]) {
            if (++f == p.size()) {
                answer.push(i - f + 2);
                f = failure[f - 1];
            }
        }
    }
    cout << answer.size() << '\n';
    while (answer.size()) {
        cout << answer.front() << '\n';
        answer.pop();
    }
    return 0;
}