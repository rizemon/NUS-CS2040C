#include <bits/stdc++.h>

using namespace std;
vector<pair<int,int>>rect;

#define LEFT 1
#define RIGHT 2

void dfs(int i, int lr){
  if(rect[i].first == rect[i+1].first){
    dfs(i+1, LEFT);
  }else if(rect[i].second == rect[i+1].second){
    dfs(i+1, RIGHT);
  }else{
    if(lr == LEFT){
      cout << rect[i+1].first << " " << rect[i].second << endl;
    }else{
      cout << rect[i].first << " " << rect[i+1].second << endl;
    }
  }
}


int main() {
  int n = 3;
  int x,y;
  while(n--){
    cin >> x >> y;
    rect.push_back({x,y});
  }
  sort(rect.begin(), rect.end());
  rect.push_back(rect[0]);
  dfs(0,0);


}