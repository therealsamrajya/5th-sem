#include <iostream>
#include <string>
using namespace std;

// Function to generate the Vigenère cipher table
void generateVigenereTable(char vigenereTable[26][26]) {
    for (int row = 0; row < 26; ++row) {
        for (int col = 0; col < 26; ++col) {
            vigenereTable[row][col] = ((row + col) % 26) + 'A';
        }
    }
}

// Function to perform Vigenère encryption
string vigenereCipher(const string& plaintext, const string& key) {
    string ciphertext = "";
    char vigenereTable[26][26];
    generateVigenereTable(vigenereTable);

    int keyLength = key.length();
    int textLength = plaintext.length();

    for (int i = 0; i < textLength; ++i) {
        char plainChar = plaintext[i];
        char keyChar = key[i % keyLength];

        if (isalpha(plainChar)) {
            char base = islower(plainChar) ? 'a' : 'A';
            char encryptedChar = vigenereTable[keyChar - 'A'][plainChar - base];
            ciphertext += encryptedChar;
        } else {
            // Non-alphabetic characters are left unchanged in the ciphertext
            ciphertext += plainChar;
        }
    }

    return ciphertext;
}

int main() {
    string plaintext, key;

    cout << "Enter the plaintext: ";
    getline(cin, plaintext);

    cout << "Enter the key: ";
    cin >> key;

    string encryptedText = vigenereCipher(plaintext, key);

    cout << "Encrypted text: " << encryptedText << endl;

    return 0;
}

