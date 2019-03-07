#include <bits/stdc++.h>

using namespace std;


int goback(int p,int q ){
    if (p == 1 && q == 1){
        return 1;
    }
    if ( p > q){
        return goback(p-q,q) * 2 + 1;
    }else{
        return goback(p,q-p) * 2;
    }
}





int main() {
    //freopen("test1.txt","r",stdin);
    int TC;
    int p,q;
    int curr;
    char slash;
    cin >> TC;
    while(TC--){
        cin >> curr >> p >> slash >> q;
        cout << curr << " " << goback(p,q) << endl;

    }    

    return 0;
}