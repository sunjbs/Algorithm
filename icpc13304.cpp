#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k, answer = 0;
    int students[5] = {0};
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int s, g;
        cin >> s >> g;
        g = --g / 2;
        switch (g){
        case 0:
            students[g]++;
            break;
        default:
            students[g * 2 - s]++;
        }
    }
    for(int s : students)
        answer += (s + k - 1) / k;
    cout << answer << endl;
    return 0;
}