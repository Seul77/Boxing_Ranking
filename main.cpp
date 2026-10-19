#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "boxeador.h"
#include "sorts.h"
#include "gestorDatos.h"
#include "linkedList.h"

using namespace std;

const string archivo = "Datos.txt";

void menu() {
    cout << "\nBoxing Ranking" << endl;
    cout << "1. Ranking por % de KO" << endl;
    cout << "2. Buscar por ID" << endl;
    cout << "3. Filtrar por categoria" << endl;
    cout << "4. Agregar boxeador" << endl;
    cout << "5. Eliminar boxeador" << endl;
    cout << "6. Guardar cambios" << endl;
    cout << "0. Salir" << endl;
}

void opcionRanking(const List<Boxeador>& boxeadores) {
    vector<Boxeador> temp;
    for (int i = 0; i < boxeadores.length(); i++) {
        temp.push_back(boxeadores.get(i));
    }

    Sorts<Boxeador> sorter;
    vector<Boxeador> ordenados = sorter.mergeSort(temp);
    
    cout << "\nBoxeadores ordenados por % de KO:" << endl;
    for (const Boxeador& b : ordenados) {
        b.mostrarInfo();
    }
}

void buscID(List<Boxeador>& boxeadores, GestorDatos& gestor) {
    int id;
    cout << "ID a buscar: ";
    cin >> id;
    cin.ignore();
 
    Boxeador bEncontrado;
    if (gestor.buscarBoxeador(boxeadores, id, bEncontrado)) {
        bEncontrado.mostrarInfo();
    } 
    else {
        cout << "No existe el boxeador con ID " << id << endl;
    }
}

void filtCat(const List<Boxeador>& boxeadores, GestorDatos& gestor) {
    string categoria;
    cout << "Categoria (Pesado, Supermediano, etc): ";
    getline(cin, categoria);
 
    List<Boxeador> resultado = gestor.filtrarPorCategoria(boxeadores, categoria);
    if (resultado.empty()) {
        cout << "No hay boxeadores en esa categoria" << endl;
        return;
    }
    for (int i = 0; i < resultado.length(); i++) {
        resultado.get(i).mostrarInfo();
    }
}

bool add(List<Boxeador>& boxeadores, GestorDatos& gestor) {
    int id, wins, losses, kos;
    string nombre, categoria;
    double peso;
 
    cout << "ID: ";
    cin >> id;
    cin.ignore();
    
    if (gestor.existeId(boxeadores, id)) {
        cout << "Ese ID ya está en uso" << endl;
    return false;
}
 
    cout << "Nombre: ";
    getline(cin, nombre);
    cout << "Categoria: ";
    getline(cin, categoria);
    cout << "Peso (kg): ";
    cin >> peso;
    cout << "Victorias: ";
    cin >> wins;
    cout << "Derrotas: ";
    cin >> losses;
    cout << "Victorias por KO (no mayor a victorias): ";
    cin >> kos;
    while (kos > wins){
        cout << "Las victorias por KO no pueden ser mayores al numero de victorias, ingresalo de nuevo: " << endl;
        cin >> kos;
    } 
    cin.ignore();
    
    boxeadores.add(Boxeador(id, nombre, categoria, peso, wins, losses, kos));
    cout << "Boxeador agregado" << endl;
    return true;
}

bool remove(List<Boxeador>& boxeadores) {
    int id;
    cout << "ID a eliminar: ";
    cin >> id;
    cin.ignore();
 
    for (int i = 0; i < boxeadores.length(); i++) {
        Boxeador b = boxeadores.get(i);
        if (b.getId() == id) {
            string r;
            cout << "Eliminar a " << b.getNombre() << "? (s/n): ";
            getline(cin, r);
            if (r == "s") {
                boxeadores.remove(i); 
                return true;
            }
            cout << "Cancelado" << endl;
            return false;
        }
    }
    cout << "No existe un boxeador con ID " << id << "." << endl;
    return false;
}

int main() {
    GestorDatos gestor;
    List<Boxeador> boxeadores = gestor.leerBoxeadores(archivo);
    if (boxeadores.empty()) {
        return 1;
    }

    int opcion;
    while (opcion !=0) {
        menu();
        cout << "Elige una opcion: ";
        cin >> opcion;
        cin.ignore();
 
        switch (opcion) {
            case 1: opcionRanking(boxeadores); break;
            case 2: buscID(boxeadores, gestor); break;
            case 3: filtCat(boxeadores, gestor); break;
            case 4: add(boxeadores,gestor); break;
            case 5: remove(boxeadores); break;
            case 6: gestor.guardarBoxeadores(archivo, boxeadores); break;
            case 0: cout << "Hasta luego." << endl;
            break;
        }
    }
}