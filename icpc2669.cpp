#include <iostream>
#include <vector>
using namespace std;

int main(){
    int bx, by, tx, ty, answer = 0;
    vector<vector<bool> > plane(100, vector<bool>(100, true));
    for(int i = 0; i < 4; i++){
        cin >> bx >> by >> tx >> ty;
        for(int x = bx; x < tx; x++)
            for(int y = by; y < ty; y++){
                answer += plane[x][y];
                plane[x][y] = false;
            }
    }
    cout << answer << endl;
    return 0;
}