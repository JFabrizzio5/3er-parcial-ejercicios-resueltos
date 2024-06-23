#include <iostream> //Catorce numeros pares e impares 1CV11 HERNANDEZ GONZALEZ JOSEPH FABRIZZIO

using namespace std;

int main() {
    const int SIZE = 14;
    int numbers[SIZE];
    int evenNumbers[SIZE];
    int oddNumbers[SIZE];
    int evenCount = 0;
    int oddCount = 0;

    // Llenar el array con números del 1 al 14
    for (int i = 0; i < SIZE; ++i) {
        numbers[i] = i + 1;
    }

    // Determinar pares e impares
    for (int i = 0; i < SIZE; ++i) {
        if (numbers[i] % 2 == 0) {
            evenNumbers[evenCount++] = numbers[i];
        } else {
            oddNumbers[oddCount++] = numbers[i];
        }
    }

    // Mostrar números pares
    cout << "Numeros pares: ";
    for (int i = 0; i < evenCount; ++i) {
        cout << evenNumbers[i] << " ";
    }
    cout << endl;

    // Mostrar números impares
    cout << "Numeros impares: ";
    for (int i = 0; i < oddCount; ++i) {
        cout << oddNumbers[i] << " ";
    }
    cout << endl;

    // Mostrar conteo de pares e impares
    cout << "Cantidad de numeros pares: " << evenCount << endl;
    cout << "Cantidad de numeros impares: " << oddCount << endl;

    return 0;
}

