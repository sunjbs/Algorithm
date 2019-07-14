#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    priority_queue<int, vector<int>, greater<int> > pq;
    int n, answer = 0;
    cin >> n;
    for(int i = 0; i < n ; i++){
        int k;
        cin >> k;
        pq.push(k);
    }
    while(n){
        answer += n-- * pq.top();
        pq.pop();
    }
    cout << answer;
    return 0;
}