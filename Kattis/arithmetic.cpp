#include <bits/stdc++.h>

using namespace std;

string toBinary(char octal){
  int num = octal - '0';
  int digit;
  string output = "";
  while(num > 0){
    digit = num % 2;
    num /= 2;
    output = (char)(digit+'0') + output;
  }
  if(output.length() == 0) return "000";
  if(output.length() % 3 != 0) return string(3-output.length()%3,'0') + output;
  return output;
}

string pad(string binary){
  if(binary.length() % 4 != 0) return string(4-binary.length()%4,'0') + binary;
  return binary;
}

int main() {
  string input;
  getline(cin,input);
  string fullbinary = "";
  for(string::iterator it = input.begin(); it != input.end(); it++){
    fullbinary += toBinary(*it);
  }
  fullbinary = pad(fullbinary);
  string output = "";

  for(int i = 0; i < fullbinary.length(); i += 4){
    int sum  = 0;
    for(int j = 0; j < 4; j++){
      sum += (fullbinary[i+j]-'0') * pow(2,3-j);
    }
    if ( sum >= 10) output += (char)(sum-10+'A');
    else output += (char)(sum+'0');
  }
  if(output == "0") cout << 0 << endl;
  if(output[0] == '0') cout << output.substr(1,output.length()-1);
  else cout << output << endl;
}