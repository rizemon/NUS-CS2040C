#include <bits/stdc++.h>

using namespace std;

#define RED 0
#define BLUE 1


int main() {
  int TC, S;
  cin >> TC;
  string token;
  
  for(int i = 1; i <= TC; i++){
    cin >> S;
    priority_queue<int> red, blue;
    int output = 0;
    while(S--){
      cin >> token;
      char color = token.back();
      token.pop_back();
      int length = stoi(token);
      if(color == 'R') red.push(length);
      else blue.push(length);
    }
    if(red.size() == 0 || blue.size() == 0){
      output = 0;
    }else{
      int size = min(red.size(), blue.size());
      for(int j = 0; j < size; j++){
        output += red.top() + blue.top();
        red.pop();
        blue.pop();
      }
      output -= size*2;
    }
    cout << "Case #" << i << ": " << output << endl;


  }


}