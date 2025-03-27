#include <iostream>
#include <windows.h>
#include <string.h>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n1;
    int n2; 
    string s1;
    string s2;
    // string s_helper;

    cout << "������� n1: ";
    cin >> n1;
    cin.ignore(32767, '\n'); 

    if (cin.fail() || n1 <= 0 ) {
        cout << "������ �����" << endl;
        return 1;
    }

    cout << "������� n2: ";
    cin >> n2;
    cin.ignore(32767, '\n'); 

    if (cin.fail() || n2 <= 0) {
        cout << "������ �����" << endl;
        return 1;
    }

    cout << "������� s1: ";
    // cin >> s1;
    getline(cin, s1);
    // s1 += s_helper;

    if (cin.fail() || n1 > s1.length()) {
        cout << "������ �����" << endl;
        return 1;
    }

    cout << "������� s2: ";
    // cin >> s2;
    getline(cin, s2);
    // s2 += s_helper;

    if (cin.fail() || n2 > s2.length()) {
        cout << "������ �����" << endl;
        return 1;
    }

    string result = s1.substr(0, n1) + s2.substr((s2.length() - n2), n2);

    cout << "����� ������: " << result << endl;

    return 0;
}