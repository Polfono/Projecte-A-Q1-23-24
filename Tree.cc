#include "Tree.hh"

BinaryTree::BinaryTree(int d) {
    k = d;
    arrel = nullptr;
}

//Destructora
BinaryTree::~BinaryTree() {
    
}

void BinaryTree::BorrarInit() {
    if (arrel != nullptr) {
        if (arrel->left != nullptr) BorrarBinaryTree(arrel->left);
        if (arrel->right != nullptr) BorrarBinaryTree(arrel->right);
        delete arrel;
        arrel = nullptr;
    }
}

void BinaryTree::BorrarBinaryTree(node* n) {
    if (n != nullptr) {
        if (n->left != nullptr) BorrarBinaryTree(n->left);
        if (n->right != nullptr) BorrarBinaryTree(n->right);
        delete n;
        n = nullptr;
    }
}

//Comenca les crides recursives per inserir un node amb clau a 
void BinaryTree::insertInit(const vector<double>& a) {

    if (arrel != nullptr) {
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
    else {
        arrel = new node;  // Allocate memory for the root node
        arrel->clau = a;
        arrel->h = 0;
        arrel->right = arrel->left = nullptr;
    }
}

//Inserta el node amb clau c correctament a l'arbre
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


// Function to print binary tree in 2D
// It does reverse inorder traversal
void BinaryTree::print2DUtil(node* root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += 10;

    // Process right child first
    print2DUtil(root->right, space);

    // Print current node after space
    // count
    cout << endl;
    for (int i = 10; i < space; i++)
        cout << " ";
    for (int i = 0; i < root->clau.size(); ++i) cout << root->clau[i] << " ";
    cout << endl;

    // Process left child
    print2DUtil(root->left, space);
}

// Wrapper over print2DUtil()
void BinaryTree::print2D()
{
    // Pass initial space count as 0
    print2DUtil(arrel, 0);
}

//Constructora d'un arbre k-d random donats una k i una n fixes
BinaryTree::BinaryTree(int k, int n) {
    arrel = nullptr;
    this->k = k;
    srand(time(NULL));
    for (int j = 0; j < n; ++j) {
        vector<double> values(k);
        for (int i = 0; i < k; i++) {
            int x = rand()%10000;
            double v = double(x)/double(10000);
            values[i] = v;
        }
        insertInit(values);
    }
}

