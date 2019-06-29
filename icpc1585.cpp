#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int gcd(int x, int y){
    return (x % y) ? gcd(y, x % y) : y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, answer = 0;
    vector<int> failure;
    vector<char> roulette, meat;
    cin >> n;
    roulette.resize(n * 2);
    meat.resize(n);
    failure.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> roulette[i];
        roulette[n + i] = roulette[i];
    }
    for(int i = 0; i < n; i++)
        cin >> meat[i];

    for(int i = 1, f = 0; i < n; i++){
        while(f > 0 && meat[i] != meat[f])
            f = failure[f - 1];
        if(meat[i] == meat[f])
            failure[i] = ++f;
    }

    for(int i = 0, f = 0; i < roulette.size() - 1; i++){
        while(f > 0 && roulette[i] != meat[f])
            f = failure[f - 1];
        if(roulette[i] == meat[f]){
            if(++f == n){
                answer++;
                f = failure[f - 1];
            }
        }
    }

    int g = gcd(answer, n);
    cout << answer / g << '/' << n / g << endl;
    return 0;
}