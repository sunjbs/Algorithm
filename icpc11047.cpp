#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k, answer = 0;
    int prev = 1;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int current;
        cin >> current;
        int rate = current / prev;
        answer += k % rate;
        k /= rate;
        prev = current;
    }
    answer += k;
    cout << answer;
    return 0;
}