#ifndef TREE_HH
#define TREE_HH
#include <vector>
#include <iostream>
#include <random>
#include <time.h>
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

    //insertar recurs
    void insert(node* padre, node* n, int height, const vector<double>& c);
    void print2DUtil(node* root, int space);
    void BorrarBinaryTree(node* n);
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

    void BorrarInit();

};



#endif
