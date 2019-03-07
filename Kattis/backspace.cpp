#include <bits/stdc++.h>

using namespace std;

int main() {
    list<char> input;
    char curr;
    while(cin >> curr){
        if(curr== '<'){
            input.pop_back();
        }else{
            input.push_back(curr);
        }
    }
    for(auto& i: input){
        cout << i;
    }
    cout << endl;

    return 0;
}