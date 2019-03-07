#include <bits/stdc++.h>

using namespace std;

int main() {
    int x;
    cin >> x;
    int months;
    cin >> months;
    int avail = 0;
    int used;
    
    for(int i =0 ; i < months; i++){
        avail += x;
        cin >> used;
        avail -= used;
    }
    cout << avail + x << endl;

    return 0;
}