#include <bits/stdc++.h>

using namespace std;

int main() {
    int source,dest, ans;
    cin >> source;
    cin >> dest;
    if(source < dest){
        int diff1 = dest - source;
        int diff2 = 360 - dest + source;
        if(diff1 < diff2){
            ans = diff1;
        }else{
            ans = -(diff2);
        }
    }else{
        int diff1 = source - dest;
        int diff2 = 360 - source + dest;
        if(diff1 < diff2){
            ans = -(diff1);
        }else{
            ans = diff2;
        }
    }
    if(source == dest){
        ans = 0;
    }
    if(abs(source - dest) == 180){
        ans = 180;
    }
    cout << ans << endl;
    
    

    return 0;
}