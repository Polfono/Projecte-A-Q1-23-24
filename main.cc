#include <iostream>
#include <random>
#include <omp.h>
#include "Tree.hh"
using namespace std;

int main() {

    random_device myRandomDevice;
    unsigned seed = myRandomDevice();
    uniform_real_distribution<double> Uniforme(0.0, 1.0);
    default_random_engine RNG(seed);
    

    int q, t, c, typeTree;
    /*
    cout << "Elige tipo de arbol (0-kd, 1-Relaxed, 2-Squarish): ";
    cin >> typeTree;
    while(typeTree < 0 or typeTree > 2) cin >> typeTree;
    cout << "Valor de k: ";
    cin >> k;
    cout << "Valor de n: ";
    cin >> n;
    cout << "Numero de arboles: ";
    cin >> t;
    cout << "Consultas por arbol: ";
    cin >> q;
    cout << "Ver nodos visitados por consulta? 0-no 1-sí: ";
    cin >> c;
    */



    // PARTE LOGARITMICA
    
    //if(c) cout << "Nodos visitados para cada busqueda: ";
    cout << "Elige tipo de arbol (0-kd, 1-Relaxed, 2-Squarish): ";
    cin >> typeTree;

    t = 100;
    c = 0;

    cout << endl << "[";
    for (int n = 2000; n <= 100000; n += 2000) {
        q = n / 2;
        cout << endl << "[";
        for (int k = 2; k <= 6; ++k) {
            int sum = 0;

            #pragma omp parallel for num_threads(omp_get_max_threads()) reduction(+:sum)
            for(int i = 0; i < t; i++) {
                BinaryTree Arbol(k, n, typeTree);

                for(int j = 0; j < q; j++) {
                    vector<double> consulta(k);
                    for(int l = 0; l < k; l++) consulta[l] = Uniforme(RNG);

                    vector<double> vecino = Arbol.nearestNeighbor(consulta);

                    int aux = Arbol.checkNumNodes();
                    if(c) cout << aux << " ";
                    sum += aux;
                }
                Arbol.BorrarInit();
            }
            cout << sum/(t*q);
            if (k != 6) cout << ",";
        }
        cout << "],";
    }
    cout << "]" << endl;
}

