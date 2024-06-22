#include <iostream> //1CV11 HERNANDEZ GONZALEZ JOSEPH FABRIZZIO
#include <string>

using namespace std;

// Definición de la estructura para un libro
struct Libro {
    string titulo;
    string autor;
    int anio;
};

int main() {
    // Creación de una instancia de la estructura Libro
    Libro miLibro;
    
    // Agregar datos al libro
    miLibro.titulo = "El Principito";
    miLibro.autor = "Antoine de Saint-Exupéry";
    miLibro.anio = 1943;

    // Mostrar datos del libro
    cout << "Título: " << miLibro.titulo << endl;
    cout << "Autor: " << miLibro.autor << endl;
    cout << "Año: " << miLibro.anio << endl;

    // Modificar datos del libro
    miLibro.titulo = "Don Quijote de la Mancha";
    miLibro.autor = "Miguel de Cervantes";
    miLibro.anio = 1605;

    // Mostrar datos del libro modificados
    cout << "Título Modificado: " << miLibro.titulo << endl;
    cout << "Autor Modificado: " << miLibro.autor << endl;
    cout << "Año Modificado: " << miLibro.anio << endl;

    return 0;
}

