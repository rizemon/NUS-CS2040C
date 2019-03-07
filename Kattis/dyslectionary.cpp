#include <bits/stdc++.h>

using namespace std;


bool Compare(string& word1,string& word2){
  string::reverse_iterator word1_it = word1.rbegin();
  string::reverse_iterator word2_it = word2.rbegin();
  while(word1_it != word1.rend() && word2_it != word2.rend()){
    if(*word1_it < *word2_it){
      return true;
    }else if(*word1_it > *word2_it){
      return false;
    }else{
      word1_it++;
      word2_it++;
    }
  }
  if(word1.length() < word2.length()){
    return true;
  }else{
    return false;
  }
}

int main() {
  string line;
  int maxlen = 0;
  vector<string> wordgroup;
  while(getline(cin,line)){
    if(line == "") {
      sort(wordgroup.begin(),wordgroup.end(),Compare);
      string format= "%" + to_string(maxlen) + "s\n";

      for(int i = 0; i < wordgroup.size();i++){
        printf(format.c_str(),wordgroup[i].c_str());
      }
      cout << endl;

      maxlen = 0;
      wordgroup.clear();
    }else{
      int linelength = line.length();
      maxlen = max(linelength,maxlen);
      wordgroup.push_back(line);
    }
  }
  sort(wordgroup.begin(),wordgroup.end(),Compare);
  string format= "%" + to_string(maxlen) + "s\n";

  for(int i = 0; i < wordgroup.size();i++){
    printf(format.c_str(),wordgroup[i].c_str());
  }
}