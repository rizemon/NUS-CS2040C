#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("test1.txt","r",stdin);
    set<unsigned long long> values;
    int TC;
    unsigned long long number,total=0;
    cin >> TC;
    unsigned long long * alphabets = new unsigned long long[TC];
    for(int i = 0; i < TC; i++ ){
        cin >> number;
        while(values.find(number)!=values.end()){
            if(number == 0){
                break;
            }
            number--;
        }
        if(number!=0){
            values.insert(number);
        }
        alphabets[i] = number;
    }
    for(int j = 0; j < TC; j++){
        total += alphabets[j];
    }
    cout << total << endl;


    return 0;
}