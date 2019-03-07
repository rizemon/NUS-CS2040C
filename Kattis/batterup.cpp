#include <bits/stdc++.h>

using namespace std;



int main() {
  int N, input;
  int hit = 0, total = 0;
  cin >> N;
  while(N--){
    cin >> input;
    if(input == -1) continue;
    hit++;
    total += input;
  }
  cout << setprecision(17) << (double)total/hit << endl;
}