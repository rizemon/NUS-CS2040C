#include <bits/stdc++.h>

using namespace std;

struct NodeStruct{
    string name;
    int pos;
    struct NodeStruct * next;
    struct NodeStruct * prev;
};
typedef struct NodeStruct Node;

class dll{
    private:
        Node * headptr;
        Node * tailptr;
    public:
        dll(){
            headptr = NULL;
            tailptr = NULL;
        }
        Node * createNode(string name, int pos){
            Node * newNode = new Node();
            newNode->name = name;
            newNode->pos = pos;
            newNode->next = NULL;
            newNode->prev = NULL;
            return newNode;
        }
        void addNodeToHead(string name, int pos){
            Node * newNode = createNode(name,pos);
            if (headptr==NULL&&tailptr==NULL){
                headptr = newNode;
                tailptr = newNode;
                return;
            }
            headptr->prev = newNode;
            newNode->next = headptr;
            headptr = newNode;
            return;
        }
        /*void addNodeToTail(string name, int pos){
            Node * newNode = createNode(name,pos);
            if (headptr==NULL&&tailptr==NULL){
                headptr = newNode;
                tailptr = newNode;
                return;
            }
            tailptr->next = newNode;
            newNode->prev = tailptr;
            tailptr = newNode;
            return;
        }*/
        void delNodeFromHead(){
            Node * temp = headptr;;
            if(headptr==tailptr){
                headptr = NULL;
                tailptr = NULL;
            }else{
                headptr = headptr->next;
                headptr->prev = NULL;
            }
            delete temp;
        }
        void delNodeFromTail(){
            Node * temp = tailptr;
            if(headptr==tailptr){
                headptr = NULL;
                tailptr = NULL;
            }else{
                tailptr = tailptr->prev;
                tailptr->next = NULL;
            }
            delete temp;
        }
        void delNode(string target){
            if(headptr->name == target){
                delNodeFromHead();
            }else if(tailptr->name == target){
                delNodeFromTail();
            }else{
                Node * curr = headptr->next;
                while(curr!=NULL){
                    if(curr->name == target){
                        break;
                    }
                    curr = curr->next;
                }
                Node * left = curr->prev;
                Node * right = curr->next;
                left -> next = right;
                right -> prev = left;
                delete curr;
            }
        }
        Node * operator[](string target){
            Node * curr = headptr;
            while(curr!=NULL){
                if(curr->name == target){
                    break;
                }
                curr = curr->next;
            }
            return curr;
        }
};

class hashmap{
    private:
        dll slots[200000];
        hash<string> hashfn;
    public:
        int getIndex(string input){
            int index = hashfn(input) % 200000;
            return index - 1;
        }
        void insert(string name, int pos){
            int index = getIndex(name);
            slots[index].addNodeToHead(name,pos);
        }
        void remove(string name){   
            int index = getIndex(name);
            slots[index].delNode(name);
        }
        int &operator[](string name){
            int index = getIndex(name);
            return slots[index][name]->pos;
        }
};

class Hospital{
    private:
        int size;
        tuple<string,int,int> * pregnant;

        hashmap namelist;

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
            if(left<=size){
                if(!comp(pregnant[left],pregnant[max])){
                    max = left;
                }
            }
            if(right<=size){
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
        Hospital(int length){
            pregnant = new tuple<string,int,int>[length+1];
            size = 0;
            time = 1;
        }
        void ArriveAtHospital(string womanName, int dilation){
            size++;
            pregnant[size] = make_tuple(womanName,dilation,time++);
            namelist.insert(womanName,size);
            shiftUp(namelist[womanName]);
        }
        void UpdateDilation(string womanName, int increaseDilation){
            get<1>(pregnant[namelist[womanName]]) += increaseDilation;
            shiftUp(namelist[womanName]);
        }
        void GiveBirth(string womanName){
            string lastname = get<0>(pregnant[size]);
            swap(namelist[womanName],namelist[lastname]);
            swap(pregnant[namelist[womanName]],pregnant[namelist[lastname]]);
            //namelist.remove(womanName);
            size--;
            shiftUp(namelist[lastname]);
            shiftDown(namelist[lastname]);
        }
        string Query(){
            if(size==0){
                return "The delivery suite is empty";
            }else{
                return get<0>(pregnant[1]);
            }
        }
};

int main() {
    //freopen("test.txt","r",stdin);
    Hospital hospital(200010);
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

