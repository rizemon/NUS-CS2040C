#include <bits/stdc++.h>

using namespace std;

#define FOLDED 2
#define UP 1
#define DOWN 0

multimap<int, int> players;
map<int, int> hands;
multimap<int, int>::iterator it;

multimap<int,int>::iterator play(multimap<int,int>::iterator curr, int n){

    for(int i = 0; i < n-1; i++){
        advance(curr, 1);
        if(curr == players.end()) curr = players.begin();
    }

    if(curr->second == FOLDED){
        curr->second = UP;
        players.insert({curr->first, UP});
        hands[curr->first] = 2;

    }else if(curr->second == UP){
        curr->second = DOWN;
        advance(curr,1);
        if(curr == players.end()) curr = players.begin();
    }else{
        hands[curr->first]--;
        if(hands[curr->first] == 0) hands.erase(curr->first);
        multimap<int,int>::iterator a = curr;
        advance(curr,1);
        players.erase(a);
        if(curr == players.end()) curr = players.begin();
    }
    return curr;

}

int main(){
    freopen("input.txt", "r", stdin);
    int s, n;
    cin >> s >> n;
    for(int i = 0 ; i < n; i++){
        players.insert({i+1, 2});
        hands[i+1] = 1;
    }
    multimap<int,int>::iterator curr = players.begin();

    while(hands.size() > 1){
        curr = play(curr, s);
    }
    cout << hands.begin()->first << endl;



    return 0;
}