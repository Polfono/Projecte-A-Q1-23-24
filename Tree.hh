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
    // Creadora: d = dimensions del arbre, a = vector de claus de la arrel
    BinaryTree(int d, vector<double> a);

    // Destructora
    ~BinaryTree();

    //insertar inicial
    void insertInit(vector<double> a);

    //insertar recurs
    void insert(node* padre, node* n, int height, vector<double> c);


};



#endif
