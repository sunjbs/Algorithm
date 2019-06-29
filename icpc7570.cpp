#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, answer = 0;
    vector<int> line;
    cin >> n;
    line.resize(n + 1);
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        line[k] = line[k - 1] + 1;
        answer = max(answer, line[k]);
    }
    answer = n - answer;
    cout << answer << endl;
    return 0;
}