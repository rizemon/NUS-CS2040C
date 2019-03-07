#include <bits/stdc++.h>

using namespace std;

int main() {
    int asd[3];
    for(int i = 0; i < 3; i++){
        cin >> asd[i];
    }
    sort(asd,asd + 3);
    char choice;
    for(int i = 0; i < 3; i++){
        cin >> choice;
        cout << asd[choice-'A'] << " ";
    }
    cout << endl;


    return 0;
}