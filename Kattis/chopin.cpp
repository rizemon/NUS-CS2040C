#include <bits/stdc++.h>

using namespace std;

int main() {
    int counter = 0;
    string note, tonality;

    unordered_map<string,string> notes;
    notes["A"] = "A";
    notes["B"] = "B";
    notes["C"] = "C";
    notes["D"] = "D";
    notes["E"] = "E";
    notes["F"] = "F";
    notes["G"] = "G";
    notes["A#"] = "Bb";
    notes["Bb"] = "A#";
    notes["C#"] = "Db";
    notes["Db"] = "C#";
    notes["D#"] = "Eb";
    notes["Eb"] = "D#";
    notes["F#"] = "Gb";
    notes["Gb"] = "F#";
    notes["G#"] = "Ab";
    notes["Ab"] = "G#";



    while(cin >> note >> tonality){
        counter++;
        cout << "Case " << counter << ": ";
        if(note == notes[note]){
            cout << "UNIQUE" << endl;
        }else{
            cout << notes[note] << " " << tonality << endl;
        }
    }

    return 0;
}