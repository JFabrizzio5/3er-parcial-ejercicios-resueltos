#include <iostream> //1CV11 HERNANDEZ GONZALEZ JOSEPH FABRIZZIO
using namespace std;

// Función para generar un cuadrado mágico de orden n
void generarCuadradoMagico(int n, int cuadrado[][10]) {
    // Inicializar el cuadrado con 0
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cuadrado[i][j] = 0;

    int num = 1;
    int i = 0, j = n / 2; // Comenzamos en la mitad de la fila superior

    while (num <= n * n) {
        if (i < 0 && j == n) { // Caso 3: Si la posición está fuera del cuadrado
            i += 2;
            j--;
        }
        if (i < 0) { // Caso 4: Si la fila está fuera del cuadrado
            i = n - 1;
        }
        if (j == n) { // Caso 4: Si la columna está fuera del cuadrado
            j = 0;
        }
        if (cuadrado[i][j] != 0) { // Si la celda ya está ocupada
            i += 2;
            j--;
            continue;
        }
        cuadrado[i][j] = num++; // Asignamos el número y aumentamos
        i--;
        j++;
    }
}

// Función para imprimir el cuadrado mágico
void imprimirCuadrado(int n, int cuadrado[][10]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << cuadrado[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    const int maxOrden = 10; // Máximo orden soportado
    int cuadrado[maxOrden][maxOrden];
    int n;

    cout << "Ingrese el orden del cuadrado mágico (max 10): ";
    cin >> n;

    if (n % 2 == 0 || n > maxOrden) {
        cout << "El orden debe ser impar y menor o igual a 10." << endl;
        return 1;
    }

    generarCuadradoMagico(n, cuadrado);
    imprimirCuadrado(n, cuadrado);

    return 0;
}

