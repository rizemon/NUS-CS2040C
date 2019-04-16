#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> fact;
    fact.push_back(1);
    for(int i = 1; i < 10; i++){
        fact.push_back(fact[i-1] * (i+1));
    }

    int n, N;
    cin >> n ;
    while(n--){
        cin >> N;
        cout << fact[N-1]%10 << endl;
    }

    return 0;
}