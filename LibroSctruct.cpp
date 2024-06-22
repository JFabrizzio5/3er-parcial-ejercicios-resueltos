#include <iostream> //1CV11 HERNANDEZ GONZALEZ JOSEPH FABRIZZIO
#include <string>

using namespace std;

// Definici�n de la estructura para un libro
struct Libro {
    string titulo;
    string autor;
    int anio;
};

int main() {
    // Creaci�n de una instancia de la estructura Libro
    Libro miLibro;
    
    // Agregar datos al libro
    miLibro.titulo = "El Principito";
    miLibro.autor = "Antoine de Saint-Exup�ry";
    miLibro.anio = 1943;

    // Mostrar datos del libro
    cout << "T�tulo: " << miLibro.titulo << endl;
    cout << "Autor: " << miLibro.autor << endl;
    cout << "A�o: " << miLibro.anio << endl;

    // Modificar datos del libro
    miLibro.titulo = "Don Quijote de la Mancha";
    miLibro.autor = "Miguel de Cervantes";
    miLibro.anio = 1605;

    // Mostrar datos del libro modificados
    cout << "T�tulo Modificado: " << miLibro.titulo << endl;
    cout << "Autor Modificado: " << miLibro.autor << endl;
    cout << "A�o Modificado: " << miLibro.anio << endl;

    return 0;
}

