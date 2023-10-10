#include "Tree.hh"

BinaryTree::BinaryTree(int d) {
    k = d;
    arrel = nullptr;
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
void BinaryTree::insert(const vector<double>& a) {
    arrel = insertRecursive(arrel, a, 0);
}

//Inserta el node amb clau c correctament a l'arbre
BinaryTree::node* BinaryTree::insertRecursive(node* actual, const vector<double>& c, int height) {
    if (actual == nullptr) {
        node* newNode = new node;
        newNode->clau = c;
        newNode->h = height;
        newNode->left = newNode->right = nullptr;
        return newNode;
    }

    int dimension = height % k;
    if (c[dimension] < actual->clau[dimension])
        actual->left = insertRecursive(actual->left, c, height + 1);
    else
        actual->right = insertRecursive(actual->right, c, height + 1);

    return actual;
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
    random_device myRandomDevice;
    unsigned seed = myRandomDevice();
    uniform_real_distribution<double> Uniforme(0.0, 1.0);
    default_random_engine RNG(seed);

    arrel = nullptr;
    this->k = k;
    vector<double> values(k);
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < k; i++) values[i] = Uniforme(RNG);

        insert(values);
    }
}

//Calcula distancia euclidiana en K dimensiones
double BinaryTree::CalcDistancia(const vector<double>& P, const vector<double>& Q) {
    double distancia = 0.0;
    for(int i = 0; i < k; i++) {
        distancia += pow(P[i] - Q[i], 2);
    }
    return sqrt(distancia);
}

//Inicia la cerca del veí mes proper  al node origen
vector<double> BinaryTree::nearestNeighbor(const vector<double>& origen) {
    if (arrel == nullptr) return{}; // arbre buit

    node* vecino = nullptr;
    double millorDistancia = numeric_limits<double>::max();

    nearestNeighbor(arrel, origen, vecino, millorDistancia);
    if (vecino != nullptr) return vecino->clau;
    else return {};
}

//Cerca recursiva
void BinaryTree::nearestNeighbor(node* actual, const vector<double>& origen, node*& vecino, double& millorDistancia) {
    if (actual == nullptr) return;
    ++count;

    double actualDistancia = CalcDistancia(actual->clau, origen);

    if (actualDistancia < millorDistancia and actualDistancia != 0.0) {
            vecino = actual;
            millorDistancia = actualDistancia;
    }

    int j = actual->h % k;
    double valorOrigen = origen[j];
    double valorActual = actual->clau[j];

    if (valorOrigen < valorActual) {
        nearestNeighbor(actual->left, origen, vecino, millorDistancia);
        if (valorActual - valorOrigen <= millorDistancia) {
            nearestNeighbor(actual->right, origen, vecino, millorDistancia);
        }
    } else {
        nearestNeighbor(actual->right, origen, vecino, millorDistancia);
        if (valorOrigen - valorActual <= millorDistancia) {
            nearestNeighbor(actual->left, origen, vecino, millorDistancia);
        }
    }
}


//Inicia la cerca del veí mes proper  al node origen LINEAL
vector<double> BinaryTree::nearestNeighborLINEAL(const vector<double>& origen) {
    if (arrel == nullptr) return{}; // arbre buit

    node* vecino = nullptr;
    double millorDistancia = numeric_limits<double>::max();

    nearestNeighborLINEAL(arrel, origen, vecino, millorDistancia);
    if (vecino != nullptr) return vecino->clau;
    else return {};
}


//Cerca recursiva LINEAL
void BinaryTree::nearestNeighborLINEAL(node* actual, const vector<double>& origen, node*& vecino, double& millorDistancia) {
    if (actual == nullptr) return;
    ++count;

    double actualDistancia = CalcDistancia(actual->clau, origen);

    if (actualDistancia < millorDistancia and actualDistancia != 0.0) {
            vecino = actual;
            millorDistancia = actualDistancia;
    }
    //IZQUIERDA
    nearestNeighborLINEAL(actual->left, origen, vecino, millorDistancia);
    //DERECHA
    nearestNeighborLINEAL(actual->right, origen, vecino, millorDistancia);
}

int BinaryTree::checkNumNodes() {
    int aux = count;
    count = 0;
    return aux;
}

