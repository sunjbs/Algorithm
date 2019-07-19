#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

using lint = long long int;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int k, n;
    lint last = 1;
    vector<lint> primes;
    priority_queue<lint, vector<lint>, greater<lint> > pq;
    cin >> k >> n;
    primes.resize(k);
    for(int i = 0; i < k; i++){
        cin >> primes[i];
        pq.push(primes[i]);
    }
    while(--n){
        lint m = pq.top();
        pq.pop();
        for(lint p : primes){
            pq.push(m * p);
            if(m % p == 0) break;
        }
    }
    cout << pq.top();
    return 0;
}