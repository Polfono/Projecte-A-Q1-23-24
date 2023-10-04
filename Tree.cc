#include "Tree.hh"

BinaryTree::BinaryTree(int d) {
    k = d;
    arrel = nullptr;
}

//Destructora
BinaryTree::~BinaryTree() {
    
}

void BinaryTree::BorrarInit() {
    BorrarBinaryTree(arrel);
    arrel = nullptr;
}

void BinaryTree::BorrarBinaryTree(node* n) {
    if (n != nullptr) {
        BorrarBinaryTree(n->left);
        BorrarBinaryTree(n->right);
        delete n;
    }
}

//Comenca les crides recursives per inserir un node amb clau a 
void BinaryTree::insertInit(const vector<double>& a) {

    if (arrel == nullptr) {
        arrel = new node;  // Allocate memory for the root node
        arrel->clau = a;
        arrel->h = 0;
        arrel->right = arrel->left = nullptr;
        return;
    }
    
    int j = 0;
    if (a[j] < arrel->clau[j]) insert(arrel, arrel->left, arrel->h + 1, a); //izquierda
    else insert(arrel, arrel->right, arrel->h + 1, a); //derecha
}

//Inserta el node amb clau c correctament a l'arbre
void BinaryTree::insert(node* padre, node* n, int height, const vector<double>& c) {
    if (n == nullptr) {         // no existe
        int j = (height - 1)%k;
        node* nuevo = new node;
        nuevo->clau = c;
        nuevo->h = height;
        nuevo->right = nuevo->left = nullptr;

        if (padre->clau[j] < c[j]) padre->right = nuevo;
        else padre->left = nuevo;
    }
    
    else {                      // existe
        int j = (n->h)%k;
        if (c[j] < n->clau[j]) insert(n,n->left, n->h + 1, c); //izquierda
        else insert(n,n->right, n->h + 1, c); //derecha
    }
}


// Imprimir arbre recursivament
void BinaryTree::print2DUtil(node* root, int space)
{
    if (root == nullptr)
        return;

    const int spaceIncrement = 10;

    print2DUtil(root->right, space + spaceIncrement);

    cout << endl << string(space, ' ');

    for (const auto& value : root->clau)
        cout << value << " ";

    cout << endl;

    print2DUtil(root->left, space + spaceIncrement);
}

// Imprimeix l'arbre
void BinaryTree::print2D()
{
    print2DUtil(arrel, 0); //space = 0
}

//Constructora d'un arbre k-d random donats una k i una n fixes
BinaryTree::BinaryTree(int k, int n) {
    arrel = nullptr;
    this->k = k;
    srand(time(NULL));

    for (int j = 0; j < n; ++j) {
        vector<double> values(k);

        for (int i = 0; i < k; i++) {
            double v = static_cast<double>(rand() % 10000) / 10000.0; // 5 decimales
            values[i] = v;
        }

        insertInit(values);
    }
}

