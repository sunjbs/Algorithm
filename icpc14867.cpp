#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

using lint = long long int;

lint getCase(lint a, lint b, lint nowA, lint nowB){
    if(nowA == 0) return 0;
    if(nowB == 0) return 1;
    if(nowA == a) return 2;
    if(nowB == b) return 3;
    return 4;
}

lint getIndex(lint nowA, lint nowB, lint nowCase){
    switch (nowCase)
    {
    case 0:
        return nowB;
    case 1:
        return nowA;
    case 2:
        return nowB;
    case 3:
        return nowA;
    }
    return 0;
}

int main(){
    lint a, b, c, d, e;
    vector<vector<int> > answer;
    queue<lint> next;
    cin >> a >> b >> c >> d;
    e = b + 1;
    answer.resize(5, vector<int>(max(a, b) + 1, -1));
    answer[0][0] = 0;
    next.push(0);
    while(next.size()){
        lint nowA = next.front() / e, nowB = next.front() % e;
        lint nowCase = getCase(a, b, nowA, nowB);
        lint nowIndex = getIndex(nowA, nowB, nowCase);
        lint nextA, nextB, nextCase, nextIndex;
        next.pop();
        // F(A)
        nextA = a;
        nextB = nowB;
        nextCase = getCase(a, b, nextA, nextB);
        nextIndex = getIndex(nextA, nextB, nextCase);
        if(answer[nextCase][nextIndex] < 0){
            answer[nextCase][nextIndex] = answer[nowCase][nowIndex] + 1;
            next.push(nextA * e + nextB);
        }
        // F(B)
        nextA = nowA;
        nextB = b;
        nextCase = getCase(a, b, nextA, nextB);
        nextIndex = getIndex(nextA, nextB, nextCase);
        if(answer[nextCase][nextIndex] < 0){
            answer[nextCase][nextIndex] = answer[nowCase][nowIndex] + 1;
            next.push(nextA * e + nextB);
        }
        // M(A, B)
        nextB = min(b, nowA + nowB);
        nextA = max(0ll, nowA + nowB - b);
        nextCase = getCase(a, b, nextA, nextB);
        nextIndex = getIndex(nextA, nextB, nextCase);
        if(answer[nextCase][nextIndex] < 0){
            answer[nextCase][nextIndex] = answer[nowCase][nowIndex] + 1;
            next.push(nextA * e + nextB);
        }
        // M(B, A)
        nextA = min(a, nowB + nowA);
        nextB = max(0ll, nowB + nowA - a);
        nextCase = getCase(a, b, nextA, nextB);
        nextIndex = getIndex(nextA, nextB, nextCase);
        if(answer[nextCase][nextIndex] < 0){
            answer[nextCase][nextIndex] = answer[nowCase][nowIndex] + 1;
            next.push(nextA * e + nextB);
        }
        // E(A)
        nextA = 0;
        nextB = nowB;
        nextCase = getCase(a, b, nextA, nextB);
        nextIndex = getIndex(nextA, nextB, nextCase);
        if(answer[nextCase][nextIndex] < 0){
            answer[nextCase][nextIndex] = answer[nowCase][nowIndex] + 1;
            next.push(nextA * e + nextB);
        }
        // E(B)
        nextB = 0;
        nextA = nowA;
        nextCase = getCase(a, b, nextA, nextB);
        nextIndex = getIndex(nextA, nextB, nextCase);
        if(answer[nextCase][nextIndex] < 0){
            answer[nextCase][nextIndex] = answer[nowCase][nowIndex] + 1;
            next.push(nextA * e + nextB);
        }
    }

    lint answerCase = getCase(a, b, c, d);
    lint answerIndex = getIndex(c, d, answerCase);
    cout << answer[answerCase][answerIndex] << endl;
    for(int c = 0; c < 5; c++){
        for(int i = 0; i <= max(a, b); i++)
            printf("%5d", answer[c][i]);
        printf("\n");
    }
    return 0;
}