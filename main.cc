#include <iostream>
#include "Tree.hh"
using namespace std;

int main() {

    //Descomentar si quieres usar la tabla del enunciado
    /*vector<vector<double>> tabla = {
        {0.7267, 0.4785},
        {0.6533, 0.4247},
        {0.4467, 0.6022},
        {0.1000, 0.0054},
        {1.0000, 0.9462},
        {0.8100, 0.9140},
        {0.7800, 0.6183},
        {0.7667, 0.5430},
        {0.4067, 0.4892},
        {0.9500, 1.0000},
        {0.0767, 0.5000},
        {0.6733, 0.8387},
        {0.6600, 1.0000},
        {0.7167, 0.8978},
        {0.4700, 0.9785},
        {0.3833, 0.4624},
        {0.3033, 0.3548},
        {0.3767, 0.9570},
        {0.3367, 0.3387},
        {0.9833, 0.9247},
        {0.6667, 0.6022},
        {0.0000, 0.0000}
    };*/


    BinaryTree Arbol(6,10000000);

    /*for (int i = 0; i < tabla.size(); ++i) {
        Arbol.insertInit(tabla[i]);
    }*/

    

    //Arbol.print2D();


    vector<double> consulta = {double(rand())/RAND_MAX, double(rand())/RAND_MAX,double(rand())/RAND_MAX,double(rand())/RAND_MAX,double(rand())/RAND_MAX,double(rand())/RAND_MAX};
    
    vector<double> vecino = Arbol.nearestNeighbor(consulta);

    if (!vecino.empty()) {
        cout << endl << "Vecino de ";
        for(int i = 0; i < consulta.size(); i++) cout << consulta[i] << " ";
        cout << ": ";
        for(int i = 0; i < vecino.size(); i++) cout << vecino[i] << " ";
        cout << endl;
    }

    cout << "-------------------------------------------------------------------------" << endl << "LINEAL RESULT:" << endl;

    vecino = Arbol.nearestNeighborLINEAL(consulta);

    if (!vecino.empty()) {
        cout << endl << "Vecino de ";
        for(int i = 0; i < consulta.size(); i++) cout << consulta[i] << " ";
        cout << ": ";
        for(int i = 0; i < vecino.size(); i++) cout << vecino[i] << " ";
        cout << endl;
    }

    Arbol.BorrarInit();
}

