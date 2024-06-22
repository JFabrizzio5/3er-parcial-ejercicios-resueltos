#include <iostream>
#include <string>

using namespace std;

struct Libro {
    string titulo;
    string autor;
    string isbn;
    int anio;
};

const int MAX_LIBROS = 100; // Tamaño máximo del arreglo
Libro libros[MAX_LIBROS];   // Arreglo de libros
int contadorLibros = 0;     // Contador de libros añadidos

void agregarLibro(Libro libros[], int& contador, const Libro& libro) {
    if (contador < MAX_LIBROS) {
        libros[contador++] = libro;
    } else {
        cout << "Error: No se pueden agregar más libros, el arreglo está lleno." << endl;
    }
}

void listarLibros(const Libro libros[], int contador) {
    for (int i = 0; i < contador; ++i) {
        cout << "Título: " << libros[i].titulo << ", Autor: " << libros[i].autor
             << ", ISBN: " << libros[i].isbn << ", Año: " << libros[i].anio << endl;
    }
}

void buscarLibroPorTitulo(const Libro libros[], int contador, const string& titulo) {
    for (int i = 0; i < contador; ++i) {
        if (libros[i].titulo == titulo) {
            cout << "Libro encontrado - Título: " << libros[i].titulo << ", Autor: " << libros[i].autor
                 << ", ISBN: " << libros[i].isbn << ", Año: " << libros[i].anio << endl;
            return;
        }
    }
    cout << "Libro no encontrado" << endl;
}

void eliminarLibroPorISBN(Libro libros[], int& contador, const string& isbn) {
    for (int i = 0; i < contador; ++i) {
        if (libros[i].isbn == isbn) {
            for (int j = i; j < contador - 1; ++j) {
                libros[j] = libros[j + 1];
            }
            --contador;
            cout << "Libro con ISBN " << isbn << " eliminado" << endl;
            return;
        }
    }
    cout << "Libro no encontrado" << endl;
}

int main() {
    int opcion;

    do {
        cout << "\nSistema de Gestión de Libros" << endl;
        cout << "1. Agregar libro" << endl;
        cout << "2. Listar libros" << endl;
        cout << "3. Buscar libro por título" << endl;
        cout << "4. Eliminar libro por ISBN" << endl;
        cout << "5. Salir" << endl;
        cout << "Elija una opción: ";
        cin >> opcion;

        cin.ignore();  // Para ignorar el salto de línea después de la opción

        if (opcion == 1) {
            if (contadorLibros >= MAX_LIBROS) {
                cout << "Error: No se pueden agregar más libros, el arreglo está lleno." << endl;
                continue;
            }
            Libro libro;
            cout << "Ingrese el título: ";
            getline(cin, libro.titulo);
            cout << "Ingrese el autor: ";
            getline(cin, libro.autor);
            cout << "Ingrese el ISBN: ";
            getline(cin, libro.isbn);
            cout << "Ingrese el año: ";
            cin >> libro.anio;
            cin.ignore();

            agregarLibro(libros, contadorLibros, libro);
        } else if (opcion == 2) {
            listarLibros(libros, contadorLibros);
        } else if (opcion == 3) {
            string titulo;
            cout << "Ingrese el título a buscar: ";
            getline(cin, titulo);
            buscarLibroPorTitulo(libros, contadorLibros, titulo);
        } else if (opcion == 4) {
            string isbn;
            cout << "Ingrese el ISBN a eliminar: ";
            getline(cin, isbn);
            eliminarLibroPorISBN(libros, contadorLibros, isbn);
        } else if (opcion != 5) {
            cout << "Opción no válida. Intente de nuevo." << endl;
        }
    } while (opcion != 5);

    return 0;
}

