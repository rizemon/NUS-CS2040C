#include <bits/stdc++.h>
using namespace std;
int main(){
    string input;
    vector<unsigned long long> numbers;
    while(getline(cin,input)){
        stringstream iss(input);
        string number;
        while(getline(iss,number,' ')){
            numbers.push_back(stoull(number));
        }
        if (numbers.size() == 2 && numbers.at(0) == 0 && numbers.at(1) == 0){
            break;
        }
        unsigned long long total = 0;
        for(auto i:numbers){
            total += i;
        }
        cout << total << endl;
        numbers.clear();
    }

    return 0;
}