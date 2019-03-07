#include <bits/stdc++.h>

using namespace std;

void printArray(int array[]){
    cout << array[0];
    for(int j = 1 ; j < 5; j++){
        cout << " " << array[j];
    }
    cout << endl;
}


int main() {
    int array[5];
    for(int i = 0; i < 5; i++){
        cin >> array[i];
    }
    bool swapped;
    do{
        swapped=false;
        for(int i = 0; i < 5 - 1; i++){
            if(array[i]>array[i+1]){
                swap(array[i],array[i+1]);
                swapped=true;
                printArray(array);
            }
        }
    }while(swapped);

    return 0;
}