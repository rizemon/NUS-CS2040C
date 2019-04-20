#include <bits/stdc++.h>

using namespace std;

char op[] = {'/', '*', '-', '+'};

int eval(int a, int b, char op){
    switch(op){
        case '/':
            return a/b;
            break;
        case '*':
            return a*b;
            break;
        case '+':
            return a+b;
            break;
        case '-':
            return a-b;
            break;
    }
}

void exec_iit(vector<int> &expr, int &iit, int &jit, int &kit, char op){
    if(expr[iit] == op){
        expr[iit] = eval(expr[iit-1], expr[iit+1], op);
        expr.erase(expr.begin()+iit+1);
        expr.erase(expr.begin()+iit-1);
        jit = jit - 2;
        kit = kit - 2;
    }
}

void exec_jit(vector<int> &expr, int &iit, int &jit, int &kit, char op){
    if(expr[jit] == op){
        expr[jit] = eval(expr[jit-1], expr[jit+1], op);
        expr.erase(expr.begin()+jit+1);
        expr.erase(expr.begin()+jit-1);
        kit = kit - 2;
    }
}

void exec_kit(vector<int> &expr, int &iit, int &jit, int &kit, char op){
    if(expr[kit] == op){
        expr[kit] = eval(expr[kit-1], expr[kit+1], op);
        expr.erase(expr.begin()+kit+1);
        expr.erase(expr.begin()+kit-1);
    }
}

string stringBuilder(int a, int  b, char op){
    string output = "";
    output += '0' + a;
    output += " ";
    output += op;
    output += " ";
    output += '0' + b;
    return output;
}

int main(){
    map<int,string> dataset;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 4; k++){

                vector<int> expr = {4,op[i],4,op[j],4,op[k],4};
                int iit = 1;
                int jit = 3;
                int kit = 5;

                for(int m = 0; m < 4; m++){
                    exec_iit(expr, iit, jit, kit, op[m]);
                    
                    exec_jit(expr, iit, jit, kit, op[m]);
                    
                    exec_kit(expr, iit, jit, kit , op[m]);
                }

                dataset[expr[0]] = stringBuilder(4,4,op[i]) + " " + op[j] + " " + stringBuilder(4,4,op[k]) + " = ";
            }
        }
    }

    int TC, num;
    cin >> TC;
    while(TC--){
        cin >> num;
        string output = dataset[num];
        if(output != "") cout << output << num << endl;
        else cout << "no solution" << endl;
    }
    return 0;
}