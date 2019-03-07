#include <bits/stdc++.h>

using namespace std;

int main() {
  string line;
  getline(cin,line);
  istringstream iss(line);
  string word;
  while(getline(iss,word,'-')){
    cout << word[0];
  }
}