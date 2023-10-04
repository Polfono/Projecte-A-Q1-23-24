#ifndef TREE_HH
#define TREE_HH
#include <vector>
#include <iostream>
#include <random>
#include <time.h>
#include <cmath>
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

    node* arrel;

    // Insertar recurs
    void insert(node* padre, node* n, int height, const vector<double>& c);
    
    // Print recurs
    void print2DUtil(node* root, int space);

    // Borrar recurs
    void BorrarBinaryTree(node* n);

    // Calcular distnacia euclidiana entre dos puntos P, Q
    double CalcDistancia(const vector<double>& P, const vector<double>& Q);

    // Busqueda vecino recurs
    void nearestNeighbor(node* actual, const vector<double>& origen, node*& vecino, double& millorDistancia);


public:
    // Creadora: d = dimensions del arbre, a = clau (vector amb els valors) de la arrel
    BinaryTree(int d);

    //Constructora random
    BinaryTree(int k, int n);

    // Destructora
    ~BinaryTree();

    //insertar inicial
    void insertInit(const vector<double>& a);

    //Escriu arbre per terminal
    void print2D();

    // Borrar el árbol
    void BorrarInit();

    // Devuelve el vecino mas cercano del punto origen
    vector<double> nearestNeighbor(const vector<double>& origen);

};

#endif
