#include <bits/stdc++.h>
using namespace std;

int main(){
    string numberoflines;
    getline(cin,numberoflines);
    for(int i = 0;i < stoi(numberoflines);i++){
        string line,name,date1,date2,courses,status;
        getline(cin,line);
        stringstream iss(line);
        getline(iss,name,' ');
        getline(iss,date1,' ');
        getline(iss,date2,' ');
        getline(iss,courses,' ');

        if(stoi(date1.substr(0,4)) >= 2010 || stoi(date2.substr(0,4)) >= 1991 ){
            status = "eligible";
        }else if(stoi(courses) >= 41){
            status = "ineligible";
        }else{
            status = "coach petitions";
        }
        cout << name << " " << status << endl;
        
    }
}