#include <bits/stdc++.h>

using namespace std;

int main(){
    string line;
    int index = 1;
    while(getline(cin,line)){
        stringstream iss(line);
        string number;
        vector<int> numbers;
        getline(iss,number,' ');
        while(getline(iss,number,' ')){
            numbers.push_back(stoi(number));
        }
        int min = *min_element(numbers.begin(),numbers.end());
        int max = *max_element(numbers.begin(),numbers.end());
        cout << "Case " << index << ":" << " " << min << " " << max << " " << (max-min) << endl;
        index++;

    }
}