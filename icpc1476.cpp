#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int e, s, m, answer;
    cin >> e >> s >> m;
    e--;
    s--;
    m--;
    answer += s;
    while (answer % 15 != e) answer += 28;
    while (answer % 19 != m) answer += 420;
    answer++;
    cout << answer;
    return 0;
}