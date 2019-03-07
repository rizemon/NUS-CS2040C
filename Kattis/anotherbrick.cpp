#include <bits/stdc++.h>

using namespace std;

int main() {
    int height, length, bricks;
    int curr =0;
    int currh = 0;
    int incoming;
    cin >> height >> length >> bricks;
    while(bricks--){
        cin >> incoming;
        if(curr+incoming < length){
            curr += incoming;
        }else if(curr + incoming == length){
            curr = 0;
            currh++;
        }else{
            break;
        }
    }
    if(currh < height){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }

    return 0;
}