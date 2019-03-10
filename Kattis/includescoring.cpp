#include <bits/stdc++.h>


using namespace std;


typedef tuple<int,int,int> iii;

struct cmp {
    bool operator()(iii a, iii b) {
        if(get<0>(a) > get<0>(b)){
          return true;
        }else if(get<0>(a) == get<0>(b)){
          if(get<1>(a) < get<1>(b)){
            return true;
          }else if(get<1>(a) == get<1>(b)){
            if(get<2>(a) < get<2>(b)){
              return true;
            }else{
              return false;
            }
          }else{
            return false;
          }
        }else{
          return false;
        }
    }
};

typedef map<iii, vector<int>, cmp> miii;
miii score_to_indexes;
vector<int> scores;

int dx[] = {100, 75, 60, 50, 45 ,40, 36, 32, 29, 26, 24, 22, 20, 18, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

int slot = 0;

void calc(){
  for(miii::iterator it = score_to_indexes.begin(); it != score_to_indexes.end(); it++){
    int sum = 0;
    int n = (*it).second.size();
    for(int i = 0; i < n; i++){
      if(slot < 30) sum += dx[slot++];
      else sum += 0;
    }
    int average = ceil(sum/(double)n);
    for(int i = 0; i < n; i++){
      scores[(*it).second[i]] += average;
    }
  }
}




int main() {
//   freopen("input.txt","r",stdin);
  int n, s, p, f, o;
  cin >> n;
  scores.assign(n, 0);
  for(int i = 0; i < n; i++){
    cin >> s >> p >> f >> o;
    scores[i] = o;
    score_to_indexes[make_tuple(s,p,f)].push_back(i);
  }
  calc();

  for(auto& i: scores){
    cout << i << endl;
  }



}