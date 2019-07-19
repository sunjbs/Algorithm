#include <iostream>
using namespace std;

int main(){
    int n;
    int f[3] = {1, 1, 0};
    cin >> n;
    for(int i = 2; i <= n; i++){
        f[0] = f[1] + f[2];
        f[2] = f[1];
        f[1] = f[0];
    }
    cout << f[0];
    return 0;
}