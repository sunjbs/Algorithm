#include <iostream>
using namespace std;

int fibo(int a, int b, int d){
    int c;
    for(int i = 0; i < d; i++){
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main(){
    int a, b, d, k;
    cin >> d >> k;
    for(a = 1; ; a++){
        int f;
        for(b = a; ; b++){
            f = fibo(a, b, d - 2);
            if(f >= k)
                break;
        }
        if(f == k)
            break;
    }
    cout << a << endl << b << endl;
    return 0;
}