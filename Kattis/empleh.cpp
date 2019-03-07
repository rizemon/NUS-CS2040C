#include <bits/stdc++.h>

using namespace std;

vector<vector<string>> board;

bool blackorwhite(int row,int col){
  if(row%2==0){
    if(col%2==0) return true;
    else return false;
  }else{
    if(col%2==0) return false;
    else return true;
  }
}

void printline(){
  cout << "+";
  for(int i = 0; i < 8; i++){
    cout << "---+";
  }
  cout << endl;
}


int main() {
  board.assign(8,vector<string>(8,""));
  string line,token,pieces;
  while(getline(cin,line)){
    istringstream iss(line);
    iss >> token >> pieces;
    if(pieces == "") continue;
    istringstream iss1(pieces);
    string token1;
    while(getline(iss1,token1,',')){
      if(token1.size() < 3) token1.insert(0,"P");
      int piece = token1[0];
      int row = token1[2]-'1';
      int col = token1[1]-'a';
      if(blackorwhite(row,col)) board[row][col] += ":::";
      else board[row][col] += "...";
      if(token == "White:") board[row][col][1] = toupper(piece);
      else board[row][col][1] = tolower(piece);
    }
  }

  printline();
  for(int i = 7; i >= 0; i--){
    cout << "|";
    for(int j = 0; j < 8; j++){
      if(board[i][j] != "") cout << board[i][j] << "|";
      else{
        if(blackorwhite(i,j)){
          cout << ":::" << "|";
        }else{
          cout << "..." << "|";
        }
      }
    }
    cout << endl;
    printline();
  }




  

  
}