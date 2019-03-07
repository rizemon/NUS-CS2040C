#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;
  int sum = 0;
  while(N--){
    int line;
    cin >> line;
    int number, power;
    power = line % 10;
    number = (line - power)/10;
    sum += (int)pow(number,power);
  }
  cout << sum << endl;
}