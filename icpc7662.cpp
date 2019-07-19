#include <iostream>
#include <set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    for(int testcase = 0; testcase < T; testcase++){
        int n;
        multiset<int> dpq;
        cin >> n;
        for(int i = 0; i < n; i++){
            int k;
            char cmd;
            cin >> cmd >> k;
            if(cmd == 'I')
                dpq.insert(k);
            else if(dpq.size()){
                if(k == 1)
                    dpq.erase(--dpq.end());
                else
                    dpq.erase(dpq.begin());
            }
        }
        if(dpq.size())
            cout << *dpq.rbegin() << ' ' << *dpq.begin();
        else
            cout << "EMPTY";
        cout << '\n';
    }
    return 0;
}