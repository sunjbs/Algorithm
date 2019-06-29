#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, answer = 0, low = 0, high = 0, before = -1;
    cin >> n;
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        if(k < before)
            high = 0;
        else if(k > before)
            low = 0;
        high++; low++;
        answer = max(answer, max(low, high));
        before = k;
    }
    cout << answer << endl;
    return 0;
}