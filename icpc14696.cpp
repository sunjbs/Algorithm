#include <iostream>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    for(int testcase = 1; testcase <= T; testcase++){
        int n, k;
        string a, b;
        a = "     ";
        b = "     ";
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> k;
            a[5 - k]++;
        }
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> k;
            b[5 - k]++;
        }
        if(a > b) cout << "A\n";
        else if(a < b) cout << "B\n";
        else cout << "D\n";
    }
    return 0;
}