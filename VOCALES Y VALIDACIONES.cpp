#include <iostream> //1CV11 HERNANDEZ GONZALEZ JOSEPH FABRIZZIO
#include <string>

using namespace std;

int main() {
    string input;
    int vowels[5] = {0}; // a, e, i, o, u

    cout << "Ingresa una cadena: ";
    getline(cin, input);

    // Transformar a minúsculas
    for (size_t i = 0; i < input.length(); ++i) {
        if (input[i] >= 'A' && input[i] <= 'Z') {
            input[i] = input[i] + ('a' - 'A');
        }
    }

    // Contar las vocales
    for (size_t i = 0; i < input.length(); ++i) {
        switch (input[i]) {
            case 'a': vowels[0]++; break;
            case 'e': vowels[1]++; break;
            case 'i': vowels[2]++; break;
            case 'o': vowels[3]++; break;
            case 'u': vowels[4]++; break;
        }
    }

    cout << "Conteo de vocales: " << endl;
    cout << "a: " << vowels[0] << endl;
    cout << "e: " << vowels[1] << endl;
    cout << "i: " << vowels[2] << endl;
    cout << "o: " << vowels[3] << endl;
    cout << "u: " << vowels[4] << endl;

    return 0;
}
