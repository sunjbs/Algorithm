#include <iostream>
#include <vector>
using namespace std;

void fill(int s, vector<bool> &answer){
    for(int i = 0; i < answer.size(); i++)
        if(i + s < answer.size())
            answer[i + s] = answer[i + s] | answer[i];
}

int main(){
    int a, b, c, n;
    vector<bool> answer;
    cin >> a >> b >> c >> n;
    answer.resize(n + 1);
    answer[0] = true;
    fill(a, answer);
    fill(b, answer);
    fill(c, answer);
    cout << answer[n] << endl;
    return 0;
}