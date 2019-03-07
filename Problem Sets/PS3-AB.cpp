#include <bits/stdc++.h>

using namespace std;

class Hospital{
    private:
        vector<tuple<string,int,int>> pregnant;
        int time;
        bool comp(tuple<string,int,int> a, tuple<string,int,int> b ){
            if(get<1>(a) != get<1>(b)){
                return get<1>(a) < get<1>(b);
            }
            return get<2>(a) > get<2>(b);
        }
        void shiftDown(int index){
            int max = index;
            int left = index*2;
            int right = index*2+1;
            if(left<pregnant.size()){
                if(!comp(pregnant[left],pregnant[max])){
                    max = left;
                }
            }
            if(right<pregnant.size()){
                if(!comp(pregnant[right],pregnant[max])){
                    max = right;
                }
            }
            if(max!=index){
                swap(pregnant[max],pregnant[index]);
                shiftDown(max);
            }
        }
        void shiftUp(int index){
            if(index==1){
                return;
            }
            int parent = index/2;
            if(comp(pregnant[parent],pregnant[index])){
                swap(pregnant[parent],pregnant[index]);
                shiftUp(parent);
            }
        }
    public:
        Hospital(){
            pregnant.push_back(make_tuple("NO_NAME",0,0));
            time = 1;
        }
        void ArriveAtHospital(string womanName, int dilation){
            pregnant.push_back(make_tuple(womanName,dilation,time++));
            shiftUp(pregnant.size()-1);
        }
        void UpdateDilation(string womanName, int increaseDilation){
            int i;
            for(i=1;;i++){
                if(get<0>(pregnant[i]) == womanName){
                    break;
                }
            }
            get<1>(pregnant[i]) += increaseDilation;
            shiftUp(i);
        }
        void GiveBirth(string womanName){
            int i;
            for(i=1;;i++){
                if(get<0>(pregnant[i]) == womanName){
                    break;
                }
            }
            swap(pregnant[i],pregnant[pregnant.size()-1]);
            pregnant.pop_back();
            shiftDown(i);
        }
        string Query(){
            if(pregnant.size()==1){
                return "The delivery suite is empty";
            }else{
                return get<0>(pregnant[1]);
            }
        }
};

int main() {
    //freopen("test.txt","r",stdin);
    Hospital hospital;
    int TC,CMD,VAL;
    string NAME;
    cin >> TC;
    for(int i = 0; i < TC; i++){
        cin >> CMD;
        switch(CMD){
            case 0:
                cin >> NAME >> VAL;
                hospital.ArriveAtHospital(NAME,VAL);
                break;
            case 1:
                cin >> NAME >> VAL;
                hospital.UpdateDilation(NAME,VAL);
                break;
            case 2:
                cin >> NAME;
                hospital.GiveBirth(NAME);
                break;
            case 3:
                cout << hospital.Query() << endl;
                break;
        }
    }
    return 0;
}