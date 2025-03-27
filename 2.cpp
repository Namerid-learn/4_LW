#include <iostream>
#include <windows.h>
#include <string.h>

using namespace std;

bool in_string(string str, char c)
{
    c = tolower(c);
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == c) {
            return true;
        }
    }

    return false;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string s;
    string consonants = "bcdfghjklmnpqrstvwxyz��������������������";
    string other_letters = "aeiouy�����������";

    cout << "������� ������ (����������� ���� - ������, ��������� - exit): ";

    

    if (cin.fail()) {
        cout << "������ �����" << endl;
        return 1;
    }

    
    
    int count_consonants = 0;
    float count_letters = 0;
    string max_word;
    int proportion;
    int max_proportion = 0; 
    
    int index = 1;

    while (cin >> s){
        if (s == "exit") {
            break;
        }

        for (int i = 0; i <= s.length(); i++){   
            if (in_string(other_letters, s[i])) {
                count_letters++;
            }
            else { 
                if (in_string(consonants, s[i])) {
                count_consonants++;
                count_letters++;
                }
            }
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
            cout << "max_word: " << max_word << endl;
        }

        cout << index << ". " << s << " - " << proportion << "%" << endl;

        count_consonants = 0;
        count_letters = 0;
        index++;
    }

    cout << "����� � ������������ ����� ���������: " << max_word << " - " << max_proportion << "%" << endl;

    return 0;
}