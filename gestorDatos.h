#ifndef GESTOR_DATOS_H
#define GESTOR_DATOS_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "boxeador.h"
#include "linkedList.h"
using namespace std;

class GestorDatos{
    public: 
    List<Boxeador> leerBoxeadores(const string& archivo) {
    List<Boxeador> boxeadores;
    ifstream file(archivo);

    if (!file.is_open()) {
        cout << "Hubo un error al abrir el archivo." << endl;
        return boxeadores; 
    }

    string linea;
    getline(file, linea); //(para saltarse la priemra linea del txt)

    while (getline(file, linea)) {
        stringstream ss(linea);
        string strId, nombre, categoria, strPeso, strW, strL, strK;

        getline(ss, strId, ',');
        getline(ss, nombre, ',');
        getline(ss, categoria, ',');
        getline(ss, strPeso, ',');
        getline(ss, strW, ',');
        getline(ss, strL, ',');
        getline(ss, strK);

        boxeadores.add(Boxeador(
                stoi(strId),
                nombre,
                categoria,
                stod(strPeso),
                stoi(strW),
                stoi(strL),
                stoi(strK)
            ));
        }
        file.close();
        return boxeadores;
    }


void guardarBoxeadores(const string& archivo, const List<Boxeador>& lista){
    ofstream file(archivo);

    if (!file.is_open()){
        cout << "Hubo un error al abrir el archivo" << endl;
        return;
    }
        file << "id, nombre, categoría, peso (kg), W, L, K \n";
        for (int i = 0; i < lista.length(); i++) {
            Boxeador b = lista.get(i);
            file << b.getId() << ","
                 << b.getNombre() << ","
                 << b.getCategoria() << ","
                 << b.getPeso() << ","
                 << b.getWins() << ","
                 << b.getLosses() << ","
                 << b.getKOs() << "\n";
        }
        file.close();
        cout << "Datos guardados en " << archivo << endl;
    }

bool buscarBoxeador(List<Boxeador>& lista, int idBuscado, Boxeador& resultado) {
        for (int i = 0; i < lista.length(); i++) {
            Boxeador b = lista.get(i);
            if (b.getId() == idBuscado) {
                resultado = b; 
                return true; 
            }
        }
        return false;
    }

bool existeId(List<Boxeador>& lista, int idBuscado) {
    for (int i = 0; i < lista.length(); i++) {
        if (lista.get(i).getId() == idBuscado) {
            return true; 
        }
    }
    return false; 
}

    List<Boxeador> filtrarPorCategoria(const List<Boxeador>& lista, const string& categoriaBuscada) {
        List<Boxeador> resultado;
        for (int i = 0; i < lista.length(); i++) {
            Boxeador b = lista.get(i);
            if (b.getCategoria() == categoriaBuscada) {
                resultado.add(b);
            }
        }
        return resultado;
    }
};

#endif