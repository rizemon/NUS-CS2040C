#include <bits/stdc++.h>

using namespace std;

#define MOVE true
#define STOP false

typedef pair<int,int> ii;

int main() {
  int start1, start2;
  int N1, N2;
  set<ii> timeline;
  int input;
  bool status1 = STOP, status2 = STOP;
  cin >> start1 >> start2;
  cin >> N1;
  while(N1--){
    cin >> input;
    timeline.insert(ii(input,1));
  }
  cin >> N2;
  while(N2--){
    cin >> input;
    timeline.insert(ii(input,2));
  }
  for(int i = 1;i < 10000000; i++){
    if(status1) start1++;
    if(status2) start2++;
    if(abs(start1-start2) <= 4.4){
      cout << "bumper tap at time " << i << endl;
      return 0;
    }
    if(timeline.find(ii(i,1)) != timeline.end()) status1 = !status1;
    if(timeline.find(ii(i,2)) != timeline.end()) status2 = !status2;
  }
  cout << "safe and sound" << endl;
}