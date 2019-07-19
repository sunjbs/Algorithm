#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    for (int testcase = 0; testcase < T; testcase++) {
        int n, d, t = 1;
        vector<int> visit;
        string str;
        cin >> n >> d;
        visit.resize(d);
        cout << n / d << '.';
        n %= d;
        do {
            visit[n] = t++;
            n *= 10;
            str += (char)(n / d) + '0';
            n = n % d;
        } while (!visit[n]);
        cout << str.substr(0, visit[n] - 1) << '(' << str.substr(visit[n] - 1)
             << ')' << '\n';
    }
    return 0;
}