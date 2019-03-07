#include <bits/stdc++.h>

using namespace std;

vector<int> digits;

void split(int number){
  while (number > 0) {
        int digit = number%10;
        number /= 10;
        digits[digit]++;
  }
}


void print(){
  int total = 0;
  for(int i = 0; i < 10; i++){
    printf("Make %d digit %d\n",digits[i],i);
    total += digits[i];
  }
  if(total > 1){
    printf("In total %d digits\n",total);
  }else{
    printf("In total %d digit\n",total);
  }
}

int main() {
  //freopen("test.txt","r",stdin);
  int TC;
  cin >> TC >> ws;
  while(TC--){
    digits.assign(10,0);
    string roadName,addressLine;
    int addresses;
    getline(cin, roadName);
    getline(cin, addressLine);
    istringstream iss1(addressLine);
    iss1 >> addresses;
    while(addresses){
      string input;
      vector<string> fields(4,"");
      getline(cin,input);
      if(input[0] == '+'){
        istringstream iss2(input);
        for(int i = 0; i < 4; i++){
          getline(iss2,fields[i],' ');
        }
        int start = stoi(fields[1]);
        int end = stoi(fields[2]);
        int step = stoi(fields[3]);
        for(int j = start; j <= end; j += step ) {
          split(j);
          addresses--;
        }
      }else{
        split(stoi(input));
        addresses--;
      }
    }
    cout << roadName << endl;
    cout << addressLine << endl;
    print();
  }
    
}