#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;
  int number, ans = 0;
  while(N--){
    cin >> number;
    if(number < 0){
      ans++;
    }
  }
  cout << ans << endl;
  
}