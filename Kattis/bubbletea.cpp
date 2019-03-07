#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long int number;

int main() {
  int N, M, K, input;
  cin >> N;
  vector<number> teas(N+1);
  for(int i = 1; i <= N; i++){
    cin >> teas[i];
  }

  cin >> M;
  vector<number> toppings(M+1);
  
  for(int i = 1; i <= M; i++){
    cin >> toppings[i];

  }
  number cheapest = 1000000000000;
  for(int i = 1; i <= N; i++){
    cin >> K;
    while(K--){
      cin >> input;
      cheapest = min(cheapest,teas[i]+toppings[input]);
    }
  }
  number money;
  cin >> money;
  int number = money/cheapest - 1;
  if(number <= 0) cout << 0 << endl;
  else cout << number << endl;

  
}