#ifndef TREE_HH
#define TREE_HH
#include <vector>
#include <iostream>
using namespace std;


class BinaryTree {
private:
    int k;
    struct Node {
        Node* left;
        Node* right;
        vector<double> claus;   
        int h;  //altura
    };

    Node* arrel;

public:
    // Creadora: d = dimensions del arbre, a = vector de claus de la arrel
    BinaryTree(int d, vector<double> a);

    // Destructora
    ~BinaryTree();

    // 
    void insert(vector<double> a);


};



#endif
