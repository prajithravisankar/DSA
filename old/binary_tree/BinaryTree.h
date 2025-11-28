#ifndef BINARYTREE_H
#define BINARYTREE_H

class BinaryTree {

public: 

    int val;
    BinaryTree* left; 
    BinaryTree* right;

    BinaryTree(int value, BinaryTree* l = nullptr, BinaryTree* r = nullptr) : val(value), left(l), right(r) {} 
};

#endif // BINARYTREE_H
