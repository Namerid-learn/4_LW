#include <iostream>
#include <windows.h>
#include <string.h>

using namespace std;

bool in_array(string str, char c) {
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

    int array_size;

    cout << "Ââåäèòå êîëè÷åñòâî ñëîâ: ";
    cin >> array_size;
    cin.ignore(32767, '\n'); 

    if (cin.fail() || array_size <= 0) {
        cout << "Îøèáêà ââîäà" << endl;
        return 1;
    }

    cout << "Ââåäèòå ñòðîêó (ðàçäåëèòåëü ñëîâ - ïðîáåë): ";
    getline(cin, s);
    s += '\n';
    int len_s = s.length();

    int count_space = 0;

    for (int i = 0; i < len_s; i++)
    {
        if (s[i] == ' ')
        {
            count_space ++;
        }
    }

    if (cin.fail() || ++count_space != array_size) {
        cout << "Îøèáêà ââîäà" << endl;
        return 1;
    }

    float A[array_size];

    string consonants = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZáâãäæçêëìíïðñòôõö÷øùÁÂÃÄÆÇÊËÌÍÏÐÑÒÔÕÖ×ØÙ";
    
    int count_consonants = 0;
    float count_letters = 0;
    int index = 0;

    for (int i = 0; i <= len_s; i++){
        if (s[i] == ' ' || s[i] == '\n') 
        {   
            // cout << count_letters << endl;
            // cout << count_consonants << endl;
            if (count_consonants == 0)
            {
                A[index] = 0;
            }
            else
            {
                A[index] = (count_consonants / count_letters) * 100;
            }
            count_consonants = 0;
            count_letters = 0;
            index ++;
        }
        else 
        {
            if (in_array(consonants, s[i]))
            {
                count_consonants ++;
                count_letters ++;
            }
            else
            {
                count_letters ++;
            }
        }
    }
    
    cout << "Ñëîâà:" << endl;
    for (int i = 0; i < array_size; i++){
        int share = A[i];
        cout << i + 1 <<": " << share << '%' << endl;
    }

    return 0;
}