#include <bits/stdc++.h>

using namespace std;

#define MAX 1000000

typedef unordered_map<string,double> ms;


int main() {
    int currencycount;
    while(cin >> currencycount >> ws){
        if(currencycount == 0){
            break;
        }
        unordered_map<string,int> curtopos;
        int freshpos = 0;
        //unordered_map<string,ms> AM;
        bool arbitrage = false;
        vector<vector<double>> AM;
        AM.assign(currencycount,vector<double>(currencycount,0));
        while(currencycount--){
            string country;
            cin >> country;
            AM[freshpos][freshpos] = 1;
            curtopos[country] = freshpos;
            freshpos++;
            //AM[country][country] = 1;
        }
        int rates;
        cin >> rates >> ws;
        while(rates--){
            string line,currency1,currency2,rate,token;
            int num,den;
            char delimiter;
            getline(cin,line);
            istringstream iss1(line);
            iss1 >> currency1 >> currency2 >> rate;
            istringstream iss2(rate);
            iss2 >> num >> delimiter >> den;
            //AM[currency1][currency2] = ((double)den) /num;
            AM[curtopos[currency1]][curtopos[currency2]] = ((double)den)/num;
        }

        // for(auto& k: AM){
        //     for(auto& i: AM){
        //         for(auto& j: AM){
        //             AM[i.first][j.first] = max(AM[i.first][j.first],AM[i.first][k.first] * AM[k.first][j.first]);
        //         }
        //     }
        // }
        for(auto& k:curtopos){
            for(auto& i: curtopos){
                for(auto& j:curtopos){
                    AM[i.second][j.second] = max(AM[i.second][j.second], AM[i.second][k.second] * AM[k.second][j.second]);
                }
            }
        }

        for(auto& lmao: curtopos){
            if(AM[lmao.second][lmao.second] > 1){
                arbitrage = true;
                break;
            }
        }
        
        if(arbitrage){
            cout << "Arbitrage" << endl;
        }else{
            cout << "Ok" << endl;
        }
        for(int i = 0; i < AM.size(); i++){
            for(int j = 0; j < AM.size(); j++){
                AM[i][j] = 0;
            }
        }
        

    }

    return 0;
}