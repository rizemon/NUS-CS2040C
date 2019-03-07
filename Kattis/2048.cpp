#include <bits/stdc++.h>

using namespace std;

int game[4][4];
vector< vector<int> > state;
int choice;

int dy[] = {0,-1,0,1};
int dx[] = {-1,0,1,0};


void merge(int i, int j){
  if(game[i][j] == 0 || state[i][j] == 1) return;
  int y = i + dy[choice];
  int x = j + dx[choice];
  switch(choice){
    case 0:
      if ( j == 0 ) return;
      break;
    case 1:
      if ( i == 0 ) return;
      break;
    case 2:
      if ( j == 3 ) return;
      break;
    case 3:
      if ( i == 3 ) return;
      break;
  }
  if ( game[y][x] == game[i][j] && state[y][x] == 0 ){
        game[y][x] *= 2;
        game[i][j] = 0;
        state[y][x] = 1;
  }
  if ( game[y][x] == 0){
    game[y][x] = game[i][j];
    game[i][j] = 0;
  }
  merge(y,x);
}

int main() {
  state.assign(4,vector<int>(4,0));
  for(int i = 0; i < 4 ; i++){//row
    for(int j = 0; j < 4; j++){//column
      cin >> game[i][j];
    }
  }
  cin >> choice;
  
  switch(choice){
    case 0: //left
      for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
          merge(i,j);
        }
      }
      break;
    case 1: //up
      for(int j = 0; j < 4; j++){
        for(int i = 0; i < 4; i++){
          merge(i,j);
        }
      }
      break;
    case 2: //right
      for(int i = 0; i < 4; i++){
        for(int j = 3; j >= 0; j--){
          merge(i,j);
        }
      }
      break;
    case 3: //down
      for(int j = 0; j < 4; j++){
        for(int i = 3; i >= 0 ; i--){
          merge(i,j);
        }
      }
      break;
  }


  for(int i = 0; i < 4 ; i++){//row
    for(int j = 0; j < 3; j++){//column
      cout << game[i][j] << " ";
    }
    cout << game[i][3];
    cout << endl;
  }

  
  
 return 0; 
}