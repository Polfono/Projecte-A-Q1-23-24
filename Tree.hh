#ifndef TREE_HH
#define TREE_HH
#include <vector>
#include <iostream>
#include <random>
#include <time.h>
#include <cmath>
#include <utility>
using namespace std;


class BinaryTree {
private:
    int k;
    struct node {
        node* left;
        node* right;
        vector<double> clau;   
        int j;  //discriminante
    };
    int count = 0;
    node* arrel;

    // Insertar nodo standard recursivo
    BinaryTree::node* insertRecursive(node* actual, const vector<double>& c, int height);
    
    // Print árbol recursivo
    void print2DUtil(node* root, int space);

    // Borrar árbol recursivo
    void BorrarBinaryTree(node* n);

    // Calcular distnacia euclidiana entre dos puntos P, Q
    double CalcDistancia(const vector<double>& P, const vector<double>& Q);

    // Búsqueda vecino recursivo
    void nearestNeighbor(node* actual, const vector<double>& origen, node*& vecino, double& millorDistancia);

    // Búsqueda vecino recursivo LINEAL
    void nearestNeighborLINEAL(node* actual, const vector<double>& origen, node*& vecino, double& millorDistancia);

    // Insertar nodo tipo relaxed recursivo
    BinaryTree::node* insertRelaxed(node* actual, const vector<double>& c);

    // Insertar nodo tipo squarish recursivo
    BinaryTree::node* insertSquarish(node* actual, const vector<double>& c, vector<pair<double,double>> minIMax);


public:
    // Creadora: d = dimensions del arbre, a = clau (vector amb els valors) de la arrel
    BinaryTree(int d);

    // Constructora árbol aleatorio
    BinaryTree(int k, int n, int treeType);

    // Insertar nodo standard base
    void insert(const vector<double>& a);

    // Print árbol
    void print2D();

    // Borrar el árbol
    void BorrarInit();

    // Devuelve el vecino mas cercano al punto origen
    vector<double> nearestNeighbor(const vector<double>& origen);

    // Devuelve el vecino mas cercano al punto origen LINEAL
    vector<double> nearestNeighborLINEAL(const vector<double>& origen);

    // Mirar numero de nodos recorridos y inicializar a 0
    int checkNumNodes();

    // Insertar nodo tipo relaxed base
    void insertRelaxed(const vector<double>& a);

    // Insertar nodo tipo squarish base
    void insertSquarish(const vector<double>& a);

};

#endif
