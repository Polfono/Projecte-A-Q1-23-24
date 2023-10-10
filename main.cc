#include <iostream>
#include "Tree.hh"
using namespace std;

int main() {

    int k, n, t, q;

    cout << "Valor de k: ";
    cin >> k;
    cout << "Valor de n: ";
    cin >> n;
    cout << "Numero de arboles: ";
    cin >> t;
    cout << "Consultas por arbol: ";
    cin >> q;

    // PARTE LOGARITMICA
    
    cout << "Nodos visitados para cada busqueda: ";
    int sum = 0;
    for(int i = 0; i < t; i++) {
        BinaryTree Arbol(k,n);

        for(int j = 0; j < q; j++) {
            vector<double> consulta(k);
            for(int l = 0; l < k; l++) consulta[l] = double(rand())/RAND_MAX;

            vector<double> vecino = Arbol.nearestNeighbor(consulta);

            int aux = Arbol.checkNumNodes();
            cout << aux << " ";
            sum += aux;
        }

        Arbol.BorrarInit();
    }
    cout << endl << "Numero medio de nodos visitados: " << sum/(t*q) << endl;
}

