#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "boxeador.h"
#include "sorts.h"

using namespace std;
vector<Boxeador> leerBoxeadores(const string& archivo) {
    vector<Boxeador> boxeadores;
    ifstream file(archivo);

    if (!file.is_open()) {
        cout << "Hubo un error al abrir el archivo." << endl;
        return boxeadores; 
    }

    string linea;
    getline(file, linea); //(para saltarse la priemra linea del txt)

    while (getline(file, linea)) {
        stringstream ss(linea);
        string strId;
        string nombre; 
        string categoria; 
        string strPeso; 
        string strW; 
        string strL; 
        string strK;

        getline(ss, strId, ',');
        getline(ss, nombre, ',');
        getline(ss, categoria, ',');
        getline(ss, strPeso, ',');
        getline(ss, strW, ',');
        getline(ss, strL, ',');
        getline(ss, strK);

        boxeadores.push_back(Boxeador(
            stoi(strId),
            nombre,
            categoria,
            stod(strPeso),
            stoi(strW),
            stoi(strL),
            stoi(strK)
        ));
    }

    return boxeadores;
}

void imprimirBoxeadores(const vector<Boxeador>& lista) {
    cout << "Boxeadores ordenados: " << lista.size() << endl;
    for (const Boxeador& b : lista) {
        b.mostrarInfo();
    }
}


int main() {
    vector<Boxeador> boxeadores = leerBoxeadores("Datos.txt");

    if (boxeadores.empty()) {
        return 1;
    }

    Sorts<Boxeador> sorter;
    vector<Boxeador> sortedBoxeadores = sorter.mergeSort(boxeadores);

    imprimirBoxeadores(sortedBoxeadores);

    return 0;
}