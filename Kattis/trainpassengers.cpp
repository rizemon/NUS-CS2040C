#include <bits/stdc++.h>

using namespace std;

int main() {
    int stations;
    unsigned long long cap, current = 0;
    bool possible = true;
    unsigned long long in,out,stay;
    cin >> cap >> stations;
    for(int i = 0; i < stations; i++){
        cin >> out >> in >> stay;
        if(i == stations - 1){
            if(in != 0 || stay != 0 || current - out != 0){
                possible = false;
                break;
            }
        }else{
            if(current - out < 0){
                possible = false;
                break;
            }else{
                current -= out;
            }
            if(current + in > cap){
                possible = false;
                break;
            }else{
                current += in;
            }
            if(stay != 0 && current != cap){
                possible = false;
            }
        }
    }
    
    if(possible){
        cout << "possible" << endl;
    }else{
        cout << "impossible" << endl;
    }

    return 0;
}