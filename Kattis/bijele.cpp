#include <bits/stdc++.h>

using namespace std;

int main() {
  int correct[] = {1,1,2,2,2,8};
  int input;
  for(int i = 0; i < 6; i++){
    cin >> input;
    cout << correct[i] - input << " ";
  }
}