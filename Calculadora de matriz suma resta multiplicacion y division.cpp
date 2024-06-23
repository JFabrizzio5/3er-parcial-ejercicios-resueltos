#include <iostream> //1CV11 Hernandez Gonzalez Joseph Fabrizzio

using namespace std;

void inputMatrix(int** matrix, int rows, int cols) {
    cout << "Introduce los valores de la matriz (" << rows << "x" << cols << "):\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Elemento [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void addMatrices(int** result, int** matrix1, int** matrix2, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void subtractMatrices(int** result, int** matrix1, int** matrix2, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void multiplyMatrices(int** result, int** matrix1, int** matrix2, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = matrix1[i][j] * matrix2[i][j];
        }
    }
}

void divideMatrices(int** result, int** matrix1, int** matrix2, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix2[i][j] != 0) {
                result[i][j] = matrix1[i][j] / matrix2[i][j];
            } else {
                cout << "Error: Division por cero en la posicion [" << i << "][" << j << "]" << endl;
                result[i][j] = 0; // O cualquier otro valor que consideres adecuado
            }
        }
    }
}

void deleteMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    int rows, cols, option;

    cout << "Introduce el numero de filas: ";
    cin >> rows;
    cout << "Introduce el numero de columnas: ";
    cin >> cols;

    int** matrix1 = new int*[rows];
    int** matrix2 = new int*[rows];
    int** result = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix1[i] = new int[cols];
        matrix2[i] = new int[cols];
        result[i] = new int[cols];
    }

    cout << "Matriz 1:\n";
    inputMatrix(matrix1, rows, cols);
    cout << "Matriz 2:\n";
    inputMatrix(matrix2, rows, cols);

    cout << "Elige la operacion: 1. Sumar  2. Restar  3. Multiplicar  4. Dividir: ";
    cin >> option;

    switch (option) {
        case 1:
            addMatrices(result, matrix1, matrix2, rows, cols);
            break;
        case 2:
            subtractMatrices(result, matrix1, matrix2, rows, cols);
            break;
        case 3:
            multiplyMatrices(result, matrix1, matrix2, rows, cols);
            break;
        case 4:
            divideMatrices(result, matrix1, matrix2, rows, cols);
            break;
        default:
            cout << "Opcion no valida" << endl;
            deleteMatrix(matrix1, rows);
            deleteMatrix(matrix2, rows);
            deleteMatrix(result, rows);
            return 1;
    }

    cout << "Resultado:\n";
    printMatrix(result, rows, cols);

    deleteMatrix(matrix1, rows);
    deleteMatrix(matrix2, rows);
    deleteMatrix(result, rows);

    return 0;
}

