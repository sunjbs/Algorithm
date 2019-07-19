#include <iostream>
using namespace std;

int gcd(int x, int y) { return (x % y) ? gcd(y, x % y) : y; }

int main() {
    int x, y, g, answer;
    cin >> x >> y;
    g = gcd(x, y);
    answer = x + y - g;
    cout << answer << '\n';
    return 0;
}