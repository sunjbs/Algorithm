#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    for (int testcase = 0; testcase < T; testcase++) {
        int n, answer;
        vector<vector<int> > count;
        cin >> n;
        answer = n * (n - 1) * (n - 2) / 6;
        count.resize(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            int in[2] = {0, 0};
            for (int j = i + 1; j < n; j++) {
                int k;
                cin >> k;
                in[k]++;
                count[j][k]++;
            }
            answer -= in[0] * in[1];
            for(int j = 0; j < 2; j++) {
                answer -= in[j] * count[i][1 - j];
                answer += count[i][j] * (count[i][j] - 1) / 2;
            }
        }
        cout << answer / 2 << '\n';
    }
    return 0;
}