#include <bits/stdc++.h>


using namespace std;

int main() {
  int w, shatter, total = 0;
  cin >> w >> shatter;
  int a,b;
  while(shatter--){
    cin >> a >> b;
    total += a*b;
  }
  cout << total/w << endl;
}