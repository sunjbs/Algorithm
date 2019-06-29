#include <iostream>
#include <string>
using namespace std;

const int MOD = 20150523;

int toNumber(char c){
    return c - '0';
}

int countClap(string num){
    int dp[2][3] = { 0 }, s = 0, clap = 0, t = 0;
    int mod3[3] = {1, 3, 3};
    bool flag;
    for(int idx = 0; idx < num.size(); idx++, t = 1 - t){
        int n = toNumber(num[idx]);
        for(int i = 0; i < 3; i++)
            dp[t][i] = 0;
        for(int i = 0; i < 3; i++){
            clap = (clap + dp[1 - t][i] * 3) % MOD;
            for(int j = 0; j < 3; j++)
                dp[t][(i + j) % 3] = (dp[t][(i + j) % 3] + dp[1 - t][i] * mod3[j]) % MOD;
        }
        for(int k = 0; k < n; k++)
            if(k && k % 3 == 0) clap++;
            else dp[1 - t][(s + k) % 3]++;
        if(bool)
        s = (s + n) % 3;
    }
    if(!s) clap++;
    return (clap + dp[1 - t][0]) % MOD;
}

int main(){
    string a, b;
    int answer;
    cin >> a >> b;
    (*a.rbegin())--;
    for(auto it = a.rbegin(); *it < '0';){
        (*it) = '9';
        (*++it)--;
    }
    answer = (countClap(b) - countClap(a)) % MOD;
    cout << answer << endl;
    return 0;
}