#include <bits/stdc++.h>
using namespace std;
int main(){
    unsigned long long A,B;
    while(true){
        scanf(" %lld %lld",&A, &B);
        if (A == 0 && B == 0){
            break;
        }
        cout << A+B << endl;
    }
    return 0;
}