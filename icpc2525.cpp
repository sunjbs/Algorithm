#include <iostream>
using namespace std;

int main(){
    int a, b, c, s;
    cin >> a >> b >> c;
    s = (a * 60 + b + c) % 1440;
    cout << (s / 60) << ' ' << (s % 60) << endl;
    return 0;
}