#include <bits/stdc++.h>

using namespace std;

vector<string> digits = {
    "***   * *** *** * * *** *** *** *** ***", 
    "* *   *   *   * * * *   *     * * * * *", 
    "* *   * *** *** *** *** ***   * *** ***", 
    "* *   * *     *   *   * * *   * * *   *", 
    "***   * *** ***   * *** ***   * *** ***"
};

int getDigit(vector<string> input, int index){
    if(index > 0){
        index = index * 3 + index;
    }

    for(int digit = 0; digit <= 9; digit++){
        bool isDigit = true;
        int position = digit;
        if(digit > 0){
            position = digit*3 + digit;
        }
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < 3; j++){
                if(input[i][index+j] != digits[i][position+j]){
                    isDigit = false;
                    break;
                }
            }
            if(isDigit == false) break;
        }
        if(isDigit==true) return digit;
    }
    return -1;

}

int main(){
    vector<string> input(5,"");
    for(int i = 0; i < 5; i++){
        getline(cin,input[i]);
    }
    int numberOfDigits = 1 + (input[0].size() - 3) / 4;

    int sum = 0;

    for(int i = 0; i < numberOfDigits; i++){
        int digit = getDigit(input,i);
        if(digit == -1){
            cout << "BOOM!!" << endl;
            return 0;
        }else{
            sum = sum * 10 + digit;
        }
    }
    if(sum%6 != 0) cout << "BOOM!!" << endl;
    else cout << "BEER!!" << endl;
    return 0;
}