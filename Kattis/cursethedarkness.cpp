#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("test1.txt","r",stdin);
    int TC;
    cin >> TC;
    while(TC--){
        pair<double,double> book;
        bool near = false;
        double x ,y;
        int candles;
        double distance;
        cin >> x >> y;
        book = {x,y};
        cin >> candles;
        while(candles--){
            cin >> x >> y;
            distance = sqrt( (x-book.first)*(x-book.first) + (y-book.second)*(y-book.second) );
            if (distance <= 8){
                near = true;
            }
        }
        if(near){
            cout << "light a candle" << endl;
        }else{
            cout << "curse the darkness" << endl;
        }
    }

    return 0;
}