#include <bits/stdc++.h>

using namespace std;

int main() {
  int N,input;
  cin>> N;
  while(N--){
    cin >> input;
    if(input%2==0) cout << input << " is even" << endl;
    else cout << input << " is odd" << endl;
  }
}