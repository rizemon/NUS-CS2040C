#include <bits/stdc++.h>


using namespace std;

int main() {
  int X,Y,N;
  cin >> X >> Y >> N;
  for(int i = 1; i <= N; i++){
    if(i%X!=0&&i%Y!=0) cout << i;
    if(i%X==0) cout << "Fizz";
    if(i%Y==0) cout << "Buzz";
    cout << endl;
  }
}