#include <bits/stdc++.h>

using namespace std;

int main() {
    int TC;
    cin >> TC;
    while(TC--){
        int D, M;
        cin >> D >> M;
        deque<int> daycount;
        while(M--){
            int days;
            cin >> days;
            daycount.push_back(days);
        }
        int counter = 0;
        int friday = 0;
        for(int i = 1; i <= D; i++){
            counter++;
            if(counter > daycount.front()){
                counter = 1;
                daycount.pop_front();
            }
            if(counter == 13 && i%7 == 6){
                friday++;
            }
        }
        cout << friday <<endl;
        

        
    }

    return 0;
}