#include <iostream>

using namespace std;

bool esSimetrica(int** matriz, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matriz[i][j] != matriz[j][i]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n;
    cout << "Ingrese el ancho de la matriz (n): ";
    cin >> n;

    // Pedir el alto de la matriz (se asume que es igual al ancho para hacerla cuadrada)
    int m;
    cout << "Ingrese el alto de la matriz (m): ";
    cin >> m;

    if (m != n) {
        cout << "La matriz no es cuadrada. Por favor, ingrese dimensiones iguales para ancho y alto." << endl;
        return 1;
    }

    // Crear la matriz din�mica
    int** matriz = new int*[n];
    for (int i = 0; i < n; ++i) {
        matriz[i] = new int[n];
    }

    // Pedir al usuario que ingrese los elementos de la matriz
    cout << "Ingrese los elementos de la matriz:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matriz[i][j];
        }
    }

    // Mostrar la matriz ingresada
    cout << "Matriz ingresada:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    // Verificar si la matriz es sim�trica usando el namespace std
    if (esSimetrica(matriz, n)) {
        cout << "La matriz es sim�trica." << endl;
    } else {
        cout << "La matriz no es sim�trica." << endl;
    }

    // Liberar la memoria din�mica
    for (int i = 0; i < n; ++i) {
        delete[] matriz[i];
    }
    delete[] matriz;

    return 0;
}

