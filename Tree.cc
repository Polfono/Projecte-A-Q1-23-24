#include "Tree.hh"


BinaryTree::BinaryTree(int d, vector<double> a) {
    k = d;
    arrel->clau = a;
    arrel->h = 0;
}

// acabar
BinaryTree::~BinaryTree() {}

void BinaryTree::insertInit(vector<double> a) {
    int j = arrel->h%k;
    //izquierda
    if (a[j] < arrel->clau[j]) {
        insert(arrel, arrel->left, arrel->h + 1, a);
    }
    //derecha
    else if (a[j] > arrel->clau[j]) {
        insert(arrel, arrel->right, arrel->h + 1, a);
    }
}

//
void BinaryTree::insert(node* padre, node* n, int height, vector<double> c) {
    //Si existe comparar
    if (n != NULL) {
        int j = n->h%k;
        //izquierda
        if (c[j] < n->clau[j]) {
            insert(n,n->left, n->h + 1, c);
        }
        //derecha
        else if (c[j] > n->clau[j]) {
            insert(n,n->right, n->h + 1, c);
        }
    }
    //crear si no existe
    else {
        int j = (height-1)%k;
        node* nuevo;
        nuevo->clau = c;
        nuevo->h = height;
        if (padre->clau[j] < c[j]) {
            padre->right = nuevo;
        }
        else if (padre->clau[j] > c[j]) {
            padre->right = nuevo;
        }
    }
}



