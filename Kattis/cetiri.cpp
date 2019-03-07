#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<int> input(3,0);
  cin >> input[0] >> input[1] >> input[2];
  sort(input.begin(),input.end());
  int diff1 = input[1]-input[0];
  int diff2 = input[2]-input[1];
  double ratio = (double)diff2/diff1;
  if(ratio == 2){
    cout << input[1] + diff1 << endl;
  }else if(ratio == 0.5){
    cout << input[1] - diff2 << endl;
  }else{
    cout << input[2] + diff1 << endl;
  }
}