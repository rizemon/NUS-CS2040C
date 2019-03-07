#include <bits/stdc++.h>

using namespace std;

struct NodeStruct{
    unsigned int value;
    struct NodeStruct * next;
};
typedef struct NodeStruct Node;

class sll{
    public:
        Node * headptr;
        Node * tailptr;
        sll(){
            headptr = NULL;
            tailptr = NULL;
        }   
        Node * createNode(int data){
            Node * newNode = new Node();
            newNode->value = data;
            newNode->next = NULL;
            return newNode;
        }
        void addNodeToHead(Node * newNode){
            if(empty()){
                this->headptr = newNode;
                this->tailptr = newNode;
                return;
            }
            newNode->next = this->headptr;
            this->headptr = newNode;
        }   
        void addNodeToTail(Node * newNode){
            if(empty()){
                this->headptr = newNode;
                this->tailptr = newNode;
                return;
            }
            this->tailptr->next = newNode;
            this->tailptr =newNode;
        }
        void delNodeFromHead(){ 
            Node * temp = this->headptr;
            if(this->headptr == this->tailptr){
                this->headptr = NULL;
                this->tailptr = NULL;
            }else{
                this->headptr = this->headptr->next;
            }
            delete temp;
        }
        int top(){
            return this->headptr->value;
        }
        bool empty(){
            return (this->headptr == NULL && this->tailptr == NULL);
        }
        void clear(){
            while(!empty()){
                delNodeFromHead();
            }
        }
        void print(){
            Node * temp = this->headptr;
            while(temp!=NULL){
                cout << temp->value << endl;
                temp = temp->next;
            }
        }
};

class pqueue{
    public:
        int * array;
        int length;
    pqueue(int size){
        array = new int[size+1];
        length = 0;
    }
    void shiftDown(int index){
        int max = index;
        int left = index*2;
        int right = index*2+1;
        if(left <= length && array[left] > array[max]){
            max = left;
        }
        if(right <= length && array[right] > array[max]){
            max = right;
        }
        if(max != index){
            swap(array[max],array[index]);
            shiftDown(max);
        }
    }
    void shiftUp(int index){
        if(index == 1){
            return;
        }
        int parent = index/2;
        if(array[parent] < array[index]){
            swap(array[parent],array[index]);
            shiftUp(parent);
        }
    }
    void insert(int value){
        length++;
        array[length] = value;
        shiftUp(length);
    }
    void extractMax(){
        array[1] = array[length];
        array[length] = 0;
        length--;
        shiftDown(1);
    }

    int top(){
        return array[1];
    }
    void print(){
        for(int i = 1; i<=length;i++){
            cout << array[i] << endl;
        }
    }
    bool empty(){
        return (length == 0);
    }
    void clear(){
        for(int i = 1;i<=length;i++){
            array[i] = 0;
        }
        length = 0;
    }

};

int main() {

    //freopen("test.txt","r",stdin);
    int TC,op,val;
    bool isStack,isQueue,isPQueue;
    sll testStack,testQueue;
    pqueue testPQueue(1000000);
    while(true){
        cin >> TC;
        if(TC == 0){
            return 0;
        }
        isStack = true;
        isQueue = true;
        isPQueue = true;
        for(int i = 0; i < TC; i++){
            cin >> op;
            cin >> val;
            if(op == 1){
                testStack.addNodeToHead(testStack.createNode(val));
                testQueue.addNodeToTail(testQueue.createNode(val));
                testPQueue.insert(val);
            }else if(testStack.empty()||testQueue.empty()||testPQueue.empty()){
                isStack = false;
                isQueue = false;
                isPQueue = false;
            }else{
                if(isStack){
                    if(testStack.top() != val){
                        isStack = false;
                    }else{
                        testStack.delNodeFromHead();
                    }
                }
                if(isQueue){
                    if(testQueue.top() != val){
                        isQueue = false;
                    }else{
                        testQueue.delNodeFromHead();
                    }
                }
                if(isPQueue){
                    if(testPQueue.top() != val){
                        isPQueue = false;
                    }else{
                        testPQueue.extractMax();
                    }
                }
            }
        }
        testStack.clear();
        testQueue.clear();
        testPQueue.clear();
        if((isStack&&isQueue&&isPQueue)||(isStack&&isQueue)||(isStack&&isPQueue)||(isQueue&&isPQueue)){
            cout << "not sure" << endl;
        }else if(isStack){
            cout << "stack" << endl;
        }else if(isQueue){
            cout << "queue" << endl;
        }else if(isPQueue){
            cout << "priority queue" << endl;
        }else{
            cout << "impossible" << endl;
        }
    }
    
    return 0;
}