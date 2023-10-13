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
        int h;  //altura
    };
    int count = 0;
    node* arrel;

    // Insertar recurs
    BinaryTree::node* insertRecursive(node* actual, const vector<double>& c, int height);
    
    // Print recurs
    void print2DUtil(node* root, int space);

    // Borrar recurs
    void BorrarBinaryTree(node* n);

    // Calcular distnacia euclidiana entre dos puntos P, Q
    double CalcDistancia(const vector<double>& P, const vector<double>& Q);

    // Busqueda vecino recurs
    void nearestNeighbor(node* actual, const vector<double>& origen, node*& vecino, double& millorDistancia);

    // Busqueda vecino recurs LINEAL
    void nearestNeighborLINEAL(node* actual, const vector<double>& origen, node*& vecino, double& millorDistancia);

    BinaryTree::node* insertRelaxed(node* actual, const vector<double>& c);

    BinaryTree::node* insertSquarish(node* actual, const vector<double>& c, vector<pair<double,double>> minIMax);


public:
    // Creadora: d = dimensions del arbre, a = clau (vector amb els valors) de la arrel
    BinaryTree(int d);

    //Constructora random
    BinaryTree(int k, int n, int treeType);

    //insertar inicial
    void insert(const vector<double>& a);

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

    void KDRelaxedTree(int k, int n);

    void insertRelaxed(const vector<double>& a);

    void insertSquarish(const vector<double>& a);

};

#endif
