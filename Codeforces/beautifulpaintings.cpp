#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("test1.txt","r",stdin);
    int TC,number,count,total = 0;
    cin >> TC;
    multiset<int> next,temp;
    unordered_set<int> curr;
    for(int i = 0; i < TC; i++){
        cin >> number;
        if(curr.find(number)!=curr.end()){
            next.insert(number);
        }else{
            curr.insert(number);
        }
    }
    total += curr.size() - 1;
    curr.clear();
    while(next.size() > 0){
        for(auto i:next){
            if(curr.find(i)==curr.end()){
                curr.insert(i);
            }else{
                temp.insert(i);
            }
        }
        total += curr.size() - 1;
        next = temp;
        curr.clear();
        temp.clear();
    }
    cout << total << endl;

    //     //cout << curr.size() << endl;
    //     next = temp;
    //     total += curr.size() - 1;
    //     curr.clear();
    //     temp.clear();
    
     //cout << total << endl;



    return 0;
}