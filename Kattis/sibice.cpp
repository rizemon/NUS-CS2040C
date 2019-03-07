#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, w,h ;
  cin >> N >> w >> h;
  int input;
  double limit = sqrt(pow(w,2) + pow(h,2));
  while(N--){
    cin >> input;
    if(input <= limit){
      cout << "DA" << endl;
    }else{
      cout << "NE" << endl;
    }
  }
}