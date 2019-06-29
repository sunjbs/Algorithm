#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

class point{
public:
    int r;
    int c;
    point(){};
    point(int _r, int _c):r(_r), c(_c){};

    point operator+(point p){
        return point(r + p.r, c + p.c);
    }
};

void fill(point now, char color, vector<string> &image){
    point direction[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    queue<point> wait;
    wait.push(now);
    char change = image[now.r][now.c];
    while(wait.size()){
        now = wait.front(); wait.pop();
        for(point dir : direction){
            point next = now + dir;
            if(next.r < 0 || next.r >= image.size()) continue;
            if(next.c < 0 || next.c >= image[0].size()) continue;
            if(change != image[next.r][next.c]) continue;
            image[next.r][next.c] = color;
            wait.push(next);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int rows, cols;
    int row, col;
    char color;
    vector<string> image;
    cin >> rows >> cols;
    image.resize(rows);
    for(int row = 0; row < rows; row++)
        cin >> image[row];
    cin >> row >> col >> color;
    fill(point(row, col), color, image);
    for(string &line : image)
        cout << line << '\n';
    return 0;
}