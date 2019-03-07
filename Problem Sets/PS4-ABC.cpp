#include <bits/stdc++.h>

using namespace std;

struct namecomp {
    bool operator()(const string& leftname, const string& rightname){
        return leftname <rightname;
    }
};
class namer{
private:
    vector<set<string,namecomp>> male;
    vector<set<string,namecomp>> female;
    unordered_map<string,int> gender;
public:
    namer():male(26),female(26){
        gender.reserve(20010);
    }
    void AddSuggestion(string babyName, int genderSuitability){
        char firstchar = babyName[0];
        switch(genderSuitability){
            case 1:
                male[firstchar-'A'].insert(babyName);
                break;
            case 2:
                female[firstchar-'A'].insert(babyName);
                break;
            default:
                male[firstchar-'A'].insert(babyName);
                female[firstchar-'A'].insert(babyName);
                break;
        }
        gender[babyName] = genderSuitability;
    }
    void RemoveSuggestion(string babyName){
        char firstchar = babyName[0];
        switch(gender[babyName]){
            case 1:
                male[firstchar-'A'].erase(babyName);
                break;
            case 2:
                female[firstchar-'A'].erase(babyName);
                break;
            default:
                male[firstchar-'A'].erase(babyName);
                female[firstchar-'A'].erase(babyName);
                break;
        }
    }
    int Query(string START,string END,int gender){
        int counter = 0;
        switch(gender){
            case 1:
                counter = searchMale(START,END);
                break;
            case 2:
                counter = searchFemale(START,END);
                break;
            default:
                counter = searchMale(START,END) + searchFemale(START,END);
                break;
        }
        return counter;
    }
    int searchMale(string START,string END){
        int startchar = START[0] - 'A';
        int endchar = END[0] - 'A';
        int counter = 0;
        set<string,namecomp>::iterator head,tail;
        for(int i = startchar; i <= endchar; i++){
            if(male[i].empty()){
                continue;
            }
            head = male[i].lower_bound(START);
            tail = male[i].lower_bound(END);
            if (head == male[i].begin() && tail == male[i].end()){
                counter += male[i].size();
            }else{
                while(head != tail){
                    counter++;
                    head++;
                }
            }
        }
        return counter;
    }
    int searchFemale(string START,string END){
        int startchar = START[0] - 'A';
        int endchar = END[0] - 'A';
        int counter = 0;
        set<string,namecomp>::iterator head,tail;
        for(int i = startchar; i <= endchar; i++){
            if(female[i].empty()){
                continue;
            }
            head = female[i].lower_bound(START);
            tail = female[i].lower_bound(END);
            if (head == female[i].begin() && tail == female[i].end()){
                counter += female[i].size();
            }else{
                while(head != tail){
                    counter++;
                    head++;
                }
            }
        }
        return counter;
    }
};

int main() {
    //freopen("test.txt","r",stdin);
    string buffer,name,START,END;
    int choice,gender;
    namer namelist;
    while(getline(cin,buffer)){
        stringstream iss(buffer);
        iss >> choice;
        if(choice == 0 ){
            break;
        }
        switch(choice){
            case 1:
                iss >> name >> gender;
                namelist.AddSuggestion(name,gender);
                break;
            case 2:
                iss >> name;
                namelist.RemoveSuggestion(name);
                break;
            case 3:
                iss >> START >> END >> gender;
                cout << namelist.Query(START,END,gender) << endl;
                break;
        }
    }

    return 0;
}