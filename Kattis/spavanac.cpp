#include <bits/stdc++.h>

using namespace std;

int main() {
  int hour, min; 
  cin >> hour >> min;
  int newmin = min-45;
  int newhour = hour;
  if(newmin<0){
    newhour = newhour - 1;
    newmin = 60 + newmin;
  }
  if(newhour<0){
    newhour = 24 + newhour;
  }
  cout << newhour << " " << newmin  << endl;
}