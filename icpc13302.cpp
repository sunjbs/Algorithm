#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Voucher{
    int day;
    int price;
    int coupon;
    Voucher();
    Voucher(int d, int p, int c):day(d), price(p), coupon(c){};
};

int Dynamic(int d, int c, vector<bool> &needNot, vector<vector<int> > &answer, vector<Voucher> &voucher){
    if(d >= answer.size())
        return 0;
    if(answer[d][c] < INT32_MAX)
        return answer[d][c];
    for(Voucher v : voucher)
        if(c + v.coupon > -1)
            answer[d][c] = min(answer[d][c], v.price + Dynamic(d + v.day, c + v.coupon, needNot, answer, voucher));
    if(needNot[d])
        answer[d][c] = min(answer[d][c], Dynamic(d + 1, c, needNot, answer, voucher));
    return answer[d][c];
}

int main(){
    int n, m;
    vector<bool> needNot;
    vector<vector<int> > answer;
    vector<Voucher> voucher = {{1, 0, -3}, {1, 10000, 0}, {3, 25000, 1}, {5, 37000, 2}};
    cin >> n >> m;
    answer.resize(n + 1, vector<int>(52, INT32_MAX));
    needNot.resize(n + 1);
    for(int i = 0; i < m; i++){
        int k;
        cin >> k;
        needNot[k] = true;
    }
    cout << Dynamic(1, 0, needNot, answer, voucher) << endl;

    return 0;
}