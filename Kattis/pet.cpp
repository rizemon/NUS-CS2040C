#include <bits/stdc++.h>

using namespace std;

int main() {
  int N = 5;
  int a,b,c,d;
  int current = 0, winner;
  int total;
  while(N--){
    cin >> a >> b >> c >> d;
    total = a + b + c + d;
    if(total > current){
      current = total;
      winner = 5 - N;
    }
  }
  cout << winner << " " << current << endl;
}