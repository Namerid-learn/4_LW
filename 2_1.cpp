#include <iostream>
#include <windows.h>
#include <string.h>
#include <sstream>

using namespace std;

bool in_string(string str, char c){
    c = tolower(c);
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == c) {
            return true;
        }
    }

    return false;
}

bool check_all_is_space(string s){
    for (int i = 0; i < s.length(); i++){
        if (s[i] != ' '){
            return false;
        }
    }
    return true;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    string input_s;
    string s;
    string consonants = "bcdfghjklmnpqrstvwxyzáâãäæçêëìíïðñòôõö÷øù";

    cout << "Ââåäèòå ñòðîêó (ðàçäåëèòåëü ñëîâ - ïðîáåë): ";

    getline(cin, input_s);
    if (cin.fail() || check_all_is_space(input_s)) {
        cout << "Îøèáêà ââîäà" << endl;
        return 1;
    }
    stringstream str(input_s);
    
    int count_consonants = 0;
    float count_letters = 0;
    string max_word;
    int proportion;
    int max_proportion = 0; 
    
    int index = 1;

    while (str >> s){

        for (int i = 0; i < s.length(); i++){   
            if (in_string(consonants, s[i])) {
                count_consonants++;
            }
            count_letters++;
        }
        
        if (count_consonants == 0){
            proportion = 0;
        }   
        else {
            proportion = (count_consonants / count_letters) * 100;
        }

        if (proportion > max_proportion) {
            max_proportion = proportion;
            max_word = s;
        }

        cout << index << ". " << s << " - " << proportion << "%" << endl;

        count_consonants = 0;
        count_letters = 0;
        index++;
    }

    cout << "Ñëîâî ñ ìàêñèìàëüíîé äîëåé ñîãëàñíûõ: " << max_word << " - " << max_proportion << "%" << endl;

    return 0;
}