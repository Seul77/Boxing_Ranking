#ifndef BOXEADOR_H
#define BOXEADOR_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Boxeador{
    private:
    int id;
    string nombre;
    string categoria;
    double peso;
    int wins;
    int losses;
    int KOs;

    public:
    Boxeador() : id(0), nombre(""), categoria(""), peso(0.0), wins(0), losses(0), KOs(0) {}
    Boxeador(int i, string n, string c, double p, int w, int l, int k){
        id = i;
        nombre = n;
        categoria = c;
        peso = p;
        wins = w;
        losses = l;
        KOs = k;
    }

    //getters
    int getId() const { 
        return id; 
    }

    string getNombre() const {
        return nombre; 
    }

    string getCategoria() const {
        return categoria; 
    }

    double getPeso() const {
        return peso; 
    }

    int getWins() const {
        return wins; 
    }

    int getLosses() const { 
        return losses; 
    }

    int getKOs() const {
        return KOs; 
    }

    //setters
    void setNombre(string n) {
        nombre = n; 
    }

    void setCategoria(string c) { 
        categoria = c; 
    }

    void setPeso(double p) { 
        peso = p; 
    }

    void setWins(int w) { 
        wins = w; 
    }

    void setLosses(int l) { 
        losses = l; 
    }

    void setKOs(int k) { 
        KOs = k; 
    }

    //cálculos
    double getPorcentajeKO() const {
            if (wins == 0){
                return 0.0;
            }
            return (KOs * 100.0) / wins;
        }

    void mostrarInfo() const {
        cout << "- ID: " << id 
             << "- Nombre: " << nombre 
             << "- Categoria: " << categoria 
             << "- Peso: " << peso << " kg"
             << "- Carrera: " << wins << "-" << losses << "-" << KOs
             << "- % KO: " << getPorcentajeKO() << "%"
             << endl;
    }
};

#endif