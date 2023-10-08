#ifndef RELAXEDREE_HH
#define RELAXEDTREE_HH
#include <vector>
#include <iostream>
#include <random>
#include <time.h>
#include <cmath>
using namespace std;


class RelaxedBinaryTree {
private:
    int k;
    struct node {
        node* left;
        node* right;
        vector<double> clau;
        int h;  //altura
        int clauAUtilitzar; // [0, k-1]
    };
    int count = 0;
    node* arrel;

    // Insertar recurs
    void insert(node* padre, node* n, int height, const vector<double>& c);

    // Print recurs
    void print2DUtil(node* root, int space);

    // Borrar recurs
    void BorrarRelaxedBinaryTree(node* n);

    // Calcular distnacia euclidiana entre dos puntos P, Q
    double CalcDistancia(const vector<double>& P, const vector<double>& Q);

    // Busqueda vecino recurs
    void nearestNeighbor(node* actual, const vector<double>& origen, node*& vecino, double& millorDistancia);

    // Busqueda vecino recurs LINEAL
    void nearestNeighborLINEAL(node* actual, const vector<double>& origen, node*& vecino, double& millorDistancia);


public:
    // Creadora: d = dimensions del arbre, a = clau (vector amb els valors) de la arrel
    RelaxedBinaryTree(int d);

    //Constructora random
    RelaxedBinaryTree(int k, int n);

    //insertar inicial
    void insertInit(const vector<double>& a);

    //Escriu arbre per terminal
    void print2D();

    // Borrar el árbol
    void BorrarInit();

    // Devuelve el vecino mas cercano del punto origen
    vector<double> nearestNeighbor(const vector<double>& origen);

    // Devuelve el vecino mas cercano del punto origen LINEAL
    vector<double> nearestNeighborLINEAL(const vector<double>& origen);

    // Mirar numero de nodos y inicializar a 0
    int checkNumNodes();

};

#endif