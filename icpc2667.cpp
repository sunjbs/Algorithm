#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dfs(int r, int c, int n, vector<vector<bool> > &board, vector<int> &R, vector<int> &C){
    board[r][c] = false;
    int cnt = 1;
    for(int d = 0; d < R.size(); d++){
        int nr = r + R[d], nc = c + C[d];
        if(board[nr][nc])
            cnt += dfs(nr, nc, n, board, R, C);
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    vector<int> answer;
    vector<int> R = {0, 1, 0, -1};
    vector<int> C = {1, 0, -1, 0};
    vector<vector<bool> > board;
    cin >> n;
    board.resize(n + 2, vector<bool>(n + 2, false));

    for(int r = 1; r <= n; r++)
        for(int c = 1; c <= n; c++){
            char status;
            cin >> status;
            if(status == '1') board[r][c] = true;
        }
    
    for(int r = 1; r <= n; r++)
        for(int c = 1; c <= n; c++)
            if(board[r][c])
                answer.push_back(dfs(r, c, n, board, R, C));
    
    sort(answer.begin(), answer. end());
    cout << answer.size() << '\n';
    for(int k : answer)
        cout << k << '\n';
    return 0;
}