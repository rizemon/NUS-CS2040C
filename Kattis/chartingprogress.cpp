#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;

map<int,int> chart;

int limit;
int linenumber;

void printChart(){
  int end = limit - 1;
  for(int i = 0; i < linenumber; i++){
    int start = end - chart[i] + 1;
    for(int j = 0; j < limit; j++){
      if(j >= start && j <= end) cout << "*";
      else cout << ".";
    }
    cout << endl;
    end = start - 1;
  }
  linenumber = 0;
  chart.clear();
}


int main() {
  string line;
  linenumber = 0;
  limit = 0;
  while(getline(cin, line)){
    if(line.size() > 0){
      limit = line.size();
      chart[linenumber] = 0;
      for(int i = 0; i < limit; i++){
        if(line[i] == '*') chart[linenumber]++;
      }
      linenumber++;
    }else{
      printChart();
      cout << endl;
    }

  }
  printChart();
}