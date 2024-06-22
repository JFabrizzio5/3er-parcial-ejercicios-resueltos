// 1CV11 HERNANDEZ GONZALEZ JOSEPH FABRIZZIO VOCALES Y VALIDACIONES 
#include <iostream>
#include <map>
using namespace std;

void countVowels(char str[]) {
    map<char, int> vowelCount = {
        {'a', 0}, {'e', 0}, {'i', 0}, {'o', 0}, {'u', 0},
        {'á', 0}, {'é', 0}, {'í', 0}, {'ó', 0}, {'ú', 0},
        {'A', 0}, {'E', 0}, {'I', 0}, {'O', 0}, {'U', 0},
        {'Á', 0}, {'É', 0}, {'Í', 0}, {'Ó', 0}, {'Ú', 0}
    };

    for (int i = 0; str[i] != '\0'; i++) {
        if (vowelCount.find(str[i]) != vowelCount.end()) {
            vowelCount[str[i]]++;
        }
    }

    cout << "Cuenta de vocales en la frase:" << endl;
    for (auto &pair : vowelCount) {
        if (pair.second > 0) {
            cout << pair.first << ": " << pair.second << endl;
        }
    }
}

int main() {
    char myString[200];
    cout << "Ingrese una frase: ";
    cin.getline(myString, 200);
    countVowels(myString);
    return 0;
}

