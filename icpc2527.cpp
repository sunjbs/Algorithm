#include <iostream>
using namespace std;

using lint = long long int;

struct Rect{
    lint bx, by;
    lint tx, ty;
};

int main(){
    for(int i = 0; i < 4; i++){
        Rect r1, r2;
        bool x_meet, y_meet, x_intersect, y_intersect;
        cin >> r1.bx >> r1.by >> r1.tx >> r1.ty;
        cin >> r2.bx >> r2.by >> r2.tx >> r2.ty;
        x_meet = (r1.bx == r2.tx) || (r1.tx == r2.bx);
        y_meet = (r1.by == r2.ty) || (r1.ty == r2.by);
        x_intersect = (r1.tx - r1.bx + r2.tx - r2.bx) > max(r1.tx - r2.bx, r2.tx - r1.bx);
        y_intersect = (r1.ty - r1.by + r2.ty - r2.by) > max(r1.ty - r2.by, r2.ty - r1.by);
        if(x_meet){
            if(y_meet)
                cout << "c";
            else if(y_intersect)
                cout << "b";
            else
                cout << "d";
        }
        else if(x_intersect){
            if(y_meet)
                cout << "b";
            else if(y_intersect)
                cout << "a";
            else
                cout << "d";
        }
        else
            cout << "d";
        cout << '\n';
    }
    return 0;
}