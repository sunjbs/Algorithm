#include <iostream>
using namespace std;

int main(){
    int row, col, answer = 0;
    for(int r = 1; r <= 9; r++)
        for(int c= 1; c <= 9; c++){
            int k;
            cin >> k;
            if(k > answer){
                answer = k;
                row = r;
                col = c;
            }
        }
    cout << answer << endl << row << ' ' << col << endl;
    return 0;
}