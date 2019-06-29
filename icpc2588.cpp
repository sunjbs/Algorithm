#include <iostream>
using namespace std;

int main(){
    int a, b, answer = 0, m = 1;
    cin >> a >> b;
    while(b){
        int k = b % 10;
        cout << a * k << endl;
        answer += (a * k * m);
        m *= 10;
        b /= 10;
    }
    cout << answer << endl;
}