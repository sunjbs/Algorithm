#include <iostream>
#include <set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    set<string> office;
    cin >> n;
    for(int i = 0; i < n; i++){
        string name, state;
        cin >> name >> state;
        if(state == "enter") office.insert(name);
        else office.erase(name);
    }
    for(set<string>::reverse_iterator riter = office.rbegin(); riter != office.rend(); riter++)
        cout << *riter << '\n';
    return 0;
}