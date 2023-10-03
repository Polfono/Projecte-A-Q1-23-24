#include <iostream>
#include "Tree.hh"
using namespace std;

int main() {
    //int d = 3;
    vector<double> a(3);
    for (int i = 0; i < 3; ++i) {
        a[i] = 0.1*double(i);
    }
    
    BinaryTree Arbol = BinaryTree(3,a);
    vector<double> b(3);
    for (int i = 0; i < 3; ++i) {
        b[i] = 0.2*double(i) + 0.1;
    }

    Arbol.insertInit(b);

    Arbol.printInit();
}

