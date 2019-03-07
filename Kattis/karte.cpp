#include <bits/stdc++.h>

using namespace std;

int main(){
    //freopen("test1.txt","r",stdin);
    char suit;
    int number;
    unordered_map<char,unordered_map<int,int>> deck;
    deck['P'][0] = 0;
    deck['K'][0] = 0;
    deck['H'][0] = 0;
    deck['T'][0] = 0;
    vector<char> suits = {'P','K','H','T'};
    while(cin >> suit >> number){
        if(++deck[suit][number] > 1){
            cout << "GRESKA" << endl;
            return 0;   
        }
    }
    for(auto& i: suits){
        cout << 14 - deck[i].size() << " ";
    }
    cout << endl;
}