#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    double answer = 0, mul, start = 0, tmp;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        if(i == 0) mul = tmp;
        else mul = max(mul, start) * tmp;
        start = tmp;
        answer = max({answer, mul, start});
    }
    cout.precision(3);
    cout << fixed <<answer << endl;
    return 0;
}