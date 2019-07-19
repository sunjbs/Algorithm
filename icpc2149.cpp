#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<pair<char, int> > order;
    string answer, code;
    {
        string key;
        cin >> key;
        order.resize(key.size());
        for (int i = 0; i < key.size(); i++) order[i] = {key[i], i};
    }
    cin >> code;
    answer.resize(code.size());
    sort(order.begin(), order.end());
    for (int i = 0, n = order.size(); i < n; i++)
        for (int j = 0, m = code.size() / order.size(); j < m; j++)
            answer[j * n + order[i].second] = code[i * m + j];
    cout << answer << '\n';
    return 0;
}