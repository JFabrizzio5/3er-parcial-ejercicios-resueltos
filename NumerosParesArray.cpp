#include <iostream> //1CV11 HERNANDEZ GONZALEZ JOSEPH FABRIZZIO

void menorMayor(int arr[], int tam, int &menor, int &mayor) {
    menor = arr[0];
    mayor = arr[0];
    for (int i = 1; i < tam; ++i) {
        if (arr[i] < menor) {
            menor = arr[i];
        }
        if (arr[i] > mayor) {
            mayor = arr[i];
        }
    }
}

int main() {
    const int tam = 15; // Tamaño del arreglo
    int arr[tam]; // Arreglo para almacenar los números ingresados por el usuario
    std::cout << "Ingrese " << tam << " números enteros:\n";
    
    // Ciclo para ingresar los números en el arreglo
    for (int i = 0; i < tam; ++i) {
        std::cout << "Número " << i+1 << ": ";
        std::cin >> arr[i];
    }

    int menor, mayor;
    menorMayor(arr, tam, menor, mayor);
    std::cout << "El menor es: " << menor << std::endl;
    std::cout << "El mayor es: " << mayor << std::endl;
    
    return 0;
}

