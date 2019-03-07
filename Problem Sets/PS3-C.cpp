#include <bits/stdc++.h>

using namespace std;

class Hospital{
    private:
        vector<tuple<string,int,int>> pregnant; //name,dilation,time
        unordered_map<string,int> namelist; //name,pos
        int time;
        bool comp(tuple<string,int,int> a, tuple<string,int,int> b ){
            if(get<1>(a) != get<1>(b)){
                return get<1>(a) < get<1>(b);
            }
            return get<2>(a) > get<2>(b);
        }
        void shiftDown(int index){
            string maxname, indexname;
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
                maxname = get<0>(pregnant[max]);
                indexname = get<0>(pregnant[index]);
                swap(namelist[maxname],namelist[indexname]);
                swap(pregnant[max],pregnant[index]);
                shiftDown(max);
            }
        }
        void shiftUp(int index){
            if(index==1){
                return;
            }
            string parentname, indexname;
            int parent = index/2;
            if(comp(pregnant[parent],pregnant[index])){
                parentname = get<0>(pregnant[parent]);
                indexname = get<0>(pregnant[index]);
                swap(namelist[parentname],namelist[indexname]);
                swap(pregnant[parent],pregnant[index]);
                shiftUp(parent);
            }
        }
    public:
        Hospital(){
            pregnant.push_back(make_tuple("NO_NAME",0,0));
            time = 1;
            namelist.reserve(200010);
        }
        void ArriveAtHospital(string womanName, int dilation){
            pregnant.push_back(make_tuple(womanName,dilation,time++));
            namelist[womanName] = pregnant.size()-1;
            shiftUp(namelist[womanName]);
            //print();
        }
        void UpdateDilation(string womanName, int increaseDilation){
            get<1>(pregnant[namelist[womanName]]) += increaseDilation;
            shiftUp(namelist[womanName]);
            //print();
        }
        void GiveBirth(string womanName){
            string lastname = get<0>(pregnant[pregnant.size()-1]);
            swap(namelist[womanName],namelist[lastname]);
            swap(pregnant[namelist[womanName]],pregnant[namelist[lastname]]);
            pregnant.pop_back();
            shiftUp(namelist[lastname]);
            shiftDown(namelist[lastname]);
            //namelist.erase(womanName);
            //print();
        }
        string Query(){
            if(pregnant.size()==1){
                return "The delivery suite is empty";
            }else{
                return get<0>(pregnant[1]);
            }
        }
        void print(){
            for(int i = 1; i < pregnant.size(); i++){
                cout << i << ")" <<get<0>(pregnant[i]) << ":" <<get<1>(pregnant[i])<< endl;
            }
            for(auto& i: namelist){
                cout << i.first << ":" << i.second << endl;
            }
            cout << endl;
        }
};

int main() {
    /*
    Hospital hospital;
    //hospital.ArriveAtHospital("MARIA", 42);
    hospital.ArriveAtHospital("GRACE", 32);
    hospital.ArriveAtHospital("ASTRID", 53);
    //hospital.ArriveAtHospital("CINDY", 77);
    //hospital.UpdateDilation("GRACE",100);
    //hospital.GiveBirth("MARIA");
    //hospital.GiveBirth("CINDY");
    hospital.GiveBirth("GRACE");
    //hospital.GiveBirth("MARIA");*/
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