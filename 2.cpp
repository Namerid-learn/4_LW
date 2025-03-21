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

    string s1;
    string s2;

    float count_consonants_1 = 0;
    float count_consonants_2 = 0;
    double share1;
    double share2;

    cout << "������� ������ �����: ";
    cin >> s1;
    int len_s1 = s1.length();

    if (cin.fail()) {
        wcout << "������ �����" << endl;
        return 1;
    }

    cout << "������� ������ �����: ";
    cin >> s2;
    int len_s2 = s2.length();

    if (cin.fail()) {
        cout << "������ �����" << endl;
        return 1;
    }

    string consonants = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ����������������������������������������";

    for(int i = 0; i < len_s1; i++) {
        if (in_array(consonants, s1[i])) {
            count_consonants_1++;
        }
    }

    for(int i = 0; i < len_s2; i++) {
        if (in_array(consonants, s2[i])) {
            count_consonants_2++;
        }
    }

    share1 = (count_consonants_1 / len_s1);
    share2 = (count_consonants_2 / len_s2);

    if (share1 > share2) 
        cout << endl << "���� ��������� � ����� 1 ������" << endl;
    else if (share1 < share2)
        cout << endl << "���� ��������� � ����� 2 ������" << endl;
        else
            cout << endl << "���� ��������� � ������ �����" << endl;
      
        
    cout << endl << "���� ��������� � ����� 1: " << share1 * 100 << "%" << endl;
    cout << endl << "���� ��������� � ����� 2: " << share2 * 100 << "%" << endl;

    return 0;
}