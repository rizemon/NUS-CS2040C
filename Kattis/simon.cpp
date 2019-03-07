#include <bits/stdc++.h>

using namespace std;

int main() {
    int TC;
    string line;
    string token,first,second;
    cin >> TC >> ws;
    while(TC--){
        string output;
        getline(cin,line);
        istringstream iss(line);
        iss >> first;
        iss >> second;
        if(first == "simon" && second == "says"){
            while(iss >> token){
                output += token + " ";
            }
        }
        cout << output << endl;
        
    }


    return 0;
}