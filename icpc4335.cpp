#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    const string HIGH = "too high";
    const string LOW = "too low";
    const string RIGHT = "right on";
    const string HONEST = "Stan may be honest\n";
    const string DISHONEST = "Stan is dishonest\n";
    while (true) {
        int s = 1, e = 10, answer;
        while (true) {
            string str;
            cin >> answer;
            if (!answer) break;
            getline(cin, str);
            getline(cin, str);
            if (str == HIGH)
                e = min(e, answer - 1);
            else if (str == LOW)
                s = max(s, answer + 1);
            else
                break;
        }
        if (!answer)
            break;
        else if (answer < s || e < answer)
            cout << DISHONEST;
        else
            cout << HONEST;
    }
    return 0;
}