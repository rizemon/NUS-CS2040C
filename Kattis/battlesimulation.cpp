#include <bits/stdc++.h>

using namespace std;

char output(char command){
    char out;
    switch(command){
        case 'R':
            out = 'S';
            break;
        case 'B':
            out =  'K';
            break;
        case 'L':
            out = 'H';
            break;
        default:
            out = 'C';
        }
    return out;
}

int main() {
    char asd;
    stack<char> commands;
    string finisher = "";

    while(cin >> asd){
        stack<char> temp;
        unordered_set<char> um;
        commands.push(asd);
        finisher.push_back(output(asd));
        if(commands.size() >= 3 ){
            for(int i = 0; i < 3; i++){
                temp.push(commands.top());
                um.insert(commands.top());
                commands.pop();
            }
            if(um.size() == 3){
                for(int j = 0;j < 3; j++){
                    finisher.pop_back();
                }
                while(!commands.empty()){
                    commands.pop();
                }
                finisher.push_back(output('A'));
            }else{
                while(!temp.empty()){
                    commands.push(temp.top());
                    temp.pop();
                }
            }
            
        }
     }
    cout << finisher << endl;

    return 0;
}