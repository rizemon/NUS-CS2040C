#include <bits/stdc++.h>

using namespace std;

int main() {
  //freopen("input.txt","r",stdin);
  int a,b, newa = 0,newb = 0;
  cin >> a >> b;
  for(int i = 2; i >= 0 ; i--){
    int power = (int)pow(10,i);
    newa += (a%10) * power;
    newb += (b%10) * power;
    a /= 10;
    b /= 10;
  }
  if(newa > newb) cout << newa << endl;
  else cout << newb << endl;
}