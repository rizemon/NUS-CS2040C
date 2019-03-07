#include <bits/stdc++.h>

using namespace std;

unordered_map<char,int> pieces = {
  {'P',0},
  {'N',1},
  {'B',2},
  {'R',3},
  {'Q',4},
  {'K',5},
};

string print_piece(string a){
  string output = "";
  if(a[0] == 'P'){
    output += a[1];
    output += a[2];
  }else{
    output = a;
  }
  return output;
}

class white_compare{
  public:
  bool operator()(string a, string b){
    if(pieces[a[0]] > pieces[b[0]]){//Tye
      return false;
    }else if (pieces[a[0]] < pieces[b[0]]){
      return true;
    }else{
      if(a[2] < b[2]){//Row
        return false;
      }else if (a[2] > b[2]){
        return true;
      }else{
        if(a[1] < b[1]){//Letter
          return false;
        }else{
          return true;
        }
      }
    }
  }
};

class black_compare{
  public:
  bool operator()(string a, string b){
    if(pieces[a[0]] > pieces[b[0]]){
      return false;
    }else if (pieces[a[0]] < pieces[b[0]]){
      return true;
    }else{
      if(a[2] > b[2]){
        return false;
      }else if (a[2] < b[2]){
        return true;
      }else{
        if(a[1] < b[1]){
          return false;
        }else{
          return true;
        }
      }
    }
  }
};

priority_queue<string,vector<string>,white_compare> white;
priority_queue<string,vector<string>,black_compare> black;

int main() {
  string divider, squares;
  int row = 8;
  while(getline(cin,divider)&&getline(cin,squares)){
    istringstream iss(squares);
    string square;
    
    row--;
    char letter = 'a';
    while(getline(iss,square,'|')){
      if(square=="") continue;
      if(square[1]==':'||square[1]=='.'){}
      else{
        string output = "";
        output += toupper(square[1]);
        output += letter;
        output += '1' + row;
        if(isupper(square[1])){
          white.push(output);
        }else{
          black.push(output);
        }
      }
      letter++;
    }
  }
  cout << "White: ";
  while(white.size() > 1){
    cout << print_piece(white.top()) << ",";
    white.pop();
  }
  if(!white.empty()) cout << print_piece(white.top());

  cout << endl;

  cout << "Black: ";
  while(black.size() > 1){
    cout << print_piece(black.top()) << ",";
    black.pop();
  }
  if(!black.empty()) cout << print_piece(black.top());

  cout << endl;
  

    


  
}