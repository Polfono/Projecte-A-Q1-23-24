#include <iostream>
#include "Tree.hh"
using namespace std;

int main() {

    int k, n, t;

    cout << "Valor de k: ";
    cin >> k;
    cout << endl;
    cout << "Valor de n: ";
    cin >> n;
    cout << endl; 
    cout << "Numero de arboles: ";
    cin >> t;
    cout << endl; 

    // PARTE LOGARITMICA

    int sum = 0;
    for(int i = 0; i < t; i++) {
        BinaryTree Arbol(k,n);

        vector<double> consulta(k);
        for(int j = 0; j < k; j++) consulta[j] = double(rand())/RAND_MAX;

        vector<double> vecino = Arbol.nearestNeighbor(consulta);

        sum += Arbol.checkNumNodes();
        Arbol.BorrarInit();
    }
    cout << "Numero medio de nodos visitados con algoritmo logaritmico: " << sum/t << endl;
        
    // PARTE LINEAL
    sum = 0;
    for(int i = 0; i < t; i++) {
        BinaryTree Arbol(k,n);

        vector<double> consulta(k);
        for(int j = 0; j < k; j++) consulta[j] = double(rand())/RAND_MAX;

        vector<double> vecino = Arbol.nearestNeighborLINEAL(consulta);

        sum += Arbol.checkNumNodes();
        Arbol.BorrarInit();
    }
    cout << "Numero medio de nodos visitados con algoritmo lineal: " << sum/t << endl;
}

