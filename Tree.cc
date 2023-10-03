#include "Tree.hh"


BinaryTree::BinaryTree(int d, const vector<double>& a) {
    k = d;
    k = d;
    arrel = new node;  // Allocate memory for the root node
    arrel->clau = a;
    arrel->h = 0;
    arrel->right = arrel->left = nullptr;
}

// acabar
BinaryTree::~BinaryTree() {}

void BinaryTree::insertInit(const vector<double>& a) {
    //h%k es 0 en altura 0
    int j = 0;
    //izquierda
    if (a[j] < arrel->clau[j]) {
        insert(arrel, arrel->left, arrel->h + 1, a);
    }
    //derecha
    else if (a[j] > arrel->clau[j]) {
        insert(arrel, arrel->right, arrel->h + 1, a);
    }
}

void BinaryTree::insert(node* padre, node* n, int height, const vector<double>& c) {
    //Si existe comparar
    if (n != NULL) {
        int j = (n->h)%k;
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
        node* nuevo = new node;
        nuevo->clau = c;
        nuevo->h = height;
        nuevo->right = nuevo->left = nullptr;
        if (padre->clau[j] < c[j]) {
            padre->right = nuevo;
        }
        else if (padre->clau[j] > c[j]) {
            padre->left = nuevo;
        }
    }
}

void BinaryTree::printInit() {
    if (arrel != nullptr)
        print(arrel);
}

void BinaryTree::print(node* n) {
    if (n != nullptr) {
        if (n->left != nullptr) print(n->left);
        if (n->right != nullptr) print(n->right);
        for (int i = 0; i < n->clau.size(); ++i) {
            cout << n->clau[i] << " ";
        }
        cout << endl;
    }
}



