#include <iostream> //1CV11 HERNANDEZ GONZALEZ JOSEPH FABRIZZIO
using namespace std;

// Funci�n para generar un cuadrado m�gico de orden n
void generarCuadradoMagico(int n, int cuadrado[][10]) {
    // Inicializar el cuadrado con 0
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cuadrado[i][j] = 0;

    int num = 1;
    int i = 0, j = n / 2; // Comenzamos en la mitad de la fila superior

    while (num <= n * n) {
        if (i < 0 && j == n) { // Caso 3: Si la posici�n est� fuera del cuadrado
            i += 2;
            j--;
        }
        if (i < 0) { // Caso 4: Si la fila est� fuera del cuadrado
            i = n - 1;
        }
        if (j == n) { // Caso 4: Si la columna est� fuera del cuadrado
            j = 0;
        }
        if (cuadrado[i][j] != 0) { // Si la celda ya est� ocupada
            i += 2;
            j--;
            continue;
        }
        cuadrado[i][j] = num++; // Asignamos el n�mero y aumentamos
        i--;
        j++;
    }
}

// Funci�n para imprimir el cuadrado m�gico
void imprimirCuadrado(int n, int cuadrado[][10]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << cuadrado[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    const int maxOrden = 10; // M�ximo orden soportado
    int cuadrado[maxOrden][maxOrden];
    int n;

    cout << "Ingrese el orden del cuadrado m�gico (max 10): ";
    cin >> n;

    if (n % 2 == 0 || n > maxOrden) {
        cout << "El orden debe ser impar y menor o igual a 10." << endl;
        return 1;
    }

    generarCuadradoMagico(n, cuadrado);
    imprimirCuadrado(n, cuadrado);

    return 0;
}

