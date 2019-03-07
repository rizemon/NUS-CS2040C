#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("test.txt","r",stdin);
    int TC,size;
    unsigned long long cm,m;
    unsigned long long int * array = NULL;
    cin >>TC;
    for(int j = 0; j < TC; j++){
        cin >> size;        
        array = new unsigned long long int[size];
        cin >> array[0];
        cm = array[0];
        //cout << " " << array[0] <<" (" <<  array[0] << ")" <<  endl;
        unsigned long long number;
        for(int i = 1; i < size; i++){
            cin >> number;
            int j;
            for(j = i - 1; j >= 0 && array[j] > number; j--){
                array[j+1]=array[j];
            }
            array[j+1] = number;
            if((i+1)%2==1){
                m = array[(i+1)/2];
            }else{
                m = (array[(i+1)/2 -1] + array[(i+1)/2]) / 2;
            }
            cm+=m;

            /*for(int k = 0; k < i+1;k++){
                cout << " " << array[k];
            }
            cout <<" (" <<  cm << ")";
            cout << endl;*/
        }
        cout << cm << endl;
        delete [] array;
    }
    return 0;
}