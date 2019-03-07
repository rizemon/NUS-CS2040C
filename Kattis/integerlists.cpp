#include <bits/stdc++.h>

using namespace std;

int main() {
    int TC;
    cin >> TC;
    while(TC--){
        string command;
        cin >> command;
        int count;
        cin >> count;
        string contents;
        cin >> contents;
        contents.erase(contents.begin());
        contents.pop_back();
        deque<int> input;
        istringstream iss(contents);
        string token;
        while(getline(iss,token,',')){
            int number = stoi(token);
            input.push_back(number);
        }
        bool reversed = false;
        bool error = false;
        for(auto& i: command){
            if(i == 'R'){
                reversed = !reversed;
            }else{
                if(input.empty()){
                    error = true;
                    break;
                }else{
                    if(reversed){
                        input.pop_back();
                    }else{
                        input.pop_front();
                    }
                }
            }
        }
        if(error){
            cout << "error" << endl;
        }else{
            string output = "[";
            if(input.size() != 0){
                if(!reversed){
                for(int i = 0; i < input.size(); i++){
                    output += to_string(input[i]) + ",";
                }
                }else{
                    for(int i = input.size()-1; i >= 0; i--){
                        output += to_string(input[i]) + ",";
                    }
                }
                output[output.size()-1] = ']';
            }else{
                output += "]";
            }
            
            cout << output << endl;
        }


    }

    return 0;
}