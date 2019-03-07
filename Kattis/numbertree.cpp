#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("test.txt","r",stdin);
    

    string input,token;
    getline(cin,input);
    istringstream iss(input);
    getline(iss,token,' ');
    int height = stoi(token);
    getline(iss,token,' ');
    int index = 1;
    for(char& dir:input){
        if(dir == 'L'){
            index = index * 2;
        }else if(dir=='R'){
            index = index * 2 + 1;
        }           
    }

    cout << int(pow(2,height+1)) - index << endl;
    

    return 0;
}