#include <iostream>
#include <string>

using namespace std;

struct Libro {
    string titulo;
    string autor;
    string isbn;
    int anio;
};

const int MAX_LIBROS = 100; // Tama�o m�ximo del arreglo
Libro libros[MAX_LIBROS];   // Arreglo de libros
int contadorLibros = 0;     // Contador de libros a�adidos

void agregarLibro(Libro libros[], int& contador, const Libro& libro) {
    if (contador < MAX_LIBROS) {
        libros[contador++] = libro;
    } else {
        cout << "Error: No se pueden agregar m�s libros, el arreglo est� lleno." << endl;
    }
}

void listarLibros(const Libro libros[], int contador) {
    for (int i = 0; i < contador; ++i) {
        cout << "T�tulo: " << libros[i].titulo << ", Autor: " << libros[i].autor
             << ", ISBN: " << libros[i].isbn << ", A�o: " << libros[i].anio << endl;
    }
}

void buscarLibroPorTitulo(const Libro libros[], int contador, const string& titulo) {
    for (int i = 0; i < contador; ++i) {
        if (libros[i].titulo == titulo) {
            cout << "Libro encontrado - T�tulo: " << libros[i].titulo << ", Autor: " << libros[i].autor
                 << ", ISBN: " << libros[i].isbn << ", A�o: " << libros[i].anio << endl;
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
        cout << "\nSistema de Gesti�n de Libros" << endl;
        cout << "1. Agregar libro" << endl;
        cout << "2. Listar libros" << endl;
        cout << "3. Buscar libro por t�tulo" << endl;
        cout << "4. Eliminar libro por ISBN" << endl;
        cout << "5. Salir" << endl;
        cout << "Elija una opci�n: ";
        cin >> opcion;

        cin.ignore();  // Para ignorar el salto de l�nea despu�s de la opci�n

        if (opcion == 1) {
            if (contadorLibros >= MAX_LIBROS) {
                cout << "Error: No se pueden agregar m�s libros, el arreglo est� lleno." << endl;
                continue;
            }
            Libro libro;
            cout << "Ingrese el t�tulo: ";
            getline(cin, libro.titulo);
            cout << "Ingrese el autor: ";
            getline(cin, libro.autor);
            cout << "Ingrese el ISBN: ";
            getline(cin, libro.isbn);
            cout << "Ingrese el a�o: ";
            cin >> libro.anio;
            cin.ignore();

            agregarLibro(libros, contadorLibros, libro);
        } else if (opcion == 2) {
            listarLibros(libros, contadorLibros);
        } else if (opcion == 3) {
            string titulo;
            cout << "Ingrese el t�tulo a buscar: ";
            getline(cin, titulo);
            buscarLibroPorTitulo(libros, contadorLibros, titulo);
        } else if (opcion == 4) {
            string isbn;
            cout << "Ingrese el ISBN a eliminar: ";
            getline(cin, isbn);
            eliminarLibroPorISBN(libros, contadorLibros, isbn);
        } else if (opcion != 5) {
            cout << "Opci�n no v�lida. Intente de nuevo." << endl;
        }
    } while (opcion != 5);

    return 0;
}

