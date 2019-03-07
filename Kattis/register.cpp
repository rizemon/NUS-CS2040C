#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("test.txt","r",stdin);
    int array[] = {1,2,3,5,7,11,13,17,19};
    int content;
    int result = 0;
    int multiplier = 1;
    for(int i = 1; i < 9; i++){
        cin >> content;
        content = array[i] - 1 - content;
        multiplier *= array[i-1]; 
        result += content * multiplier;
    }
    cout << result << endl;
    return 0;
}