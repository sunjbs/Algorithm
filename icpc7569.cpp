#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Point{
public:
    int r;
    int c;
    int h;
    Point(){};
    Point(int _r, int _c, int _h):r(_r), c(_c), h(_h){};

    Point operator+(Point d){
        return Point(r + d.r, c + d.c, h + d.h);
    }
};

using Direction = Point;

void MakeDirection(vector<Direction> &direction){
    int dirValue[3] = {-1, 0, 1};
    direction.reserve(6);
    for(int r : dirValue)
        for(int c : dirValue)
            for(int h : dirValue)
                if(abs(r) + abs(c) + abs(h) == 1)
                    direction.push_back(Direction(r, c, h));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    const int EXIST = 1, NONE = -1;
    int rows, cols, heights, count, answer = 0;
    vector<vector<vector<int> > > tomato;
    vector<Direction> direction;
    queue<Point> nextQueue;
    cin >> heights >> cols >> rows;
    tomato.resize(rows + 2, vector<vector<int> >(cols + 2, vector<int>(heights + 2, -1)));

    count = rows * cols * heights;
    for(int r = 1; r <= rows; r++){
        for(int c = 1; c <= cols; c++){
            for(int h = 1; h <= heights; h++){
                cin >> tomato[r][c][h];
                if(tomato[r][c][h] == EXIST)
                    nextQueue.push(Point(r, c, h));
                else if(tomato[r][c][h] == NONE)
                    count--;
            }
        }
    }

    MakeDirection(direction);
    while(nextQueue.size()){
        Point now = nextQueue.front(); nextQueue.pop();
        count--;
        int& current = tomato[now.r][now.c][now.h];
        answer = max(answer, current);
        for(Direction dir : direction){
            Point next = now + dir;
            int& previous = tomato[next.r][next.c][next.h];
            if(previous) continue;
            previous = current + 1;
            nextQueue.push(next);
        }
    }
    if(count) answer = 0;
    answer -= 1;
    cout << answer << endl;
    return 0;
}