#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

using pint = pair<int, int>;

int toTime(int k){
    int h = k / 100;
    int m = k % 100;
    return h * 60 + m;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, answer = 0, last = 600;
    vector<pint> rides;
    cin >> n;
    rides.resize(n + 1);
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        rides[i].first = toTime(k) - 10;
        cin >> k;
        rides[i].second = toTime(k) + 10;
    }
    rides[n] = pint(1320, INT_MAX);
    sort(rides.begin(), rides.end());
    for(int i = 0; i < rides.size(); i++){
        answer = max(answer, rides[i].first - last);
        last = max(last, rides[i].second);
    }
    cout << answer << endl;
    return 0;
}