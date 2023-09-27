#include <iostream>
#include <string>
using namespace std;

void generateVigenereTable() {
    cout << "Vigenère Cipher Table:" << endl;
    cout << "   ";
    for (char col = 'A'; col <= 'Z'; ++col) {
        cout << col << " ";
    }
    cout << endl;
    for (char row = 'A'; row <= 'Z'; ++row) {
        cout << row << " ";
        for (char col = 'A'; col <= 'Z'; ++col) {
            char encryptedChar = ((row - 'A' + col - 'A') % 26) + 'A';
            cout << encryptedChar << " ";
        }
        cout << endl;
    }
}

int main() {
    generateVigenereTable();
    return 0;
}

