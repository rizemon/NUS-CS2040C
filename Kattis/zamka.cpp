#include <bits/stdc++.h>

using namespace std;



int main(){
    int L,D,X,N,M;
    cin >> L;
    cin >> D;
    cin >> X;

    for(N=L;N<=D;N++){
        int number = N;
        int sum = 0;
        while(number > 0){
            sum += number %10;
            number = number/10;
        }
        if (sum == X){
            cout << N << endl;
            break;
        }
    }
    for(M=D;M>=L;M--){
        int number = M;
        int sum = 0;
        while(number > 0){
            sum += number %10;
            number = number/10;
        }
        if (sum == X){
            cout << M << endl;
            break;
        }
    }
    return 0;
    
}