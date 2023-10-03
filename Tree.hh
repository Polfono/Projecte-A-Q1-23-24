#ifndef TREE_HH
#define TREE_HH
#include <vector>
#include <iostream>
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

public:
    // Creadora: d = dimensions del arbre, a = clau (vector amb els valors) de la arrel
    BinaryTree(int d, const vector<double>& a);

    // Destructora
    ~BinaryTree();

    //insertar inicial
    void insertInit(const vector<double>& a);

    //insertar recurs
    void insert(node* padre, node* n, int height, const vector<double>& c);


    //Printea los valores del arbol (prueba)
    void printInit();

    //Recursively print the left subtree then the right subtree
    void print(node* n);

};



#endif
