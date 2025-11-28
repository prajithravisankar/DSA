#include "../BinaryTree.h"
#include <iostream>

using namespace std;

void binarySearchPreorderTraversal(BinaryTree* root) {
    if (root == nullptr) {
        cout << "";
        return;
    } else {
        cout << root->val << " ";
        binarySearchPreorderTraversal(root->left);
        binarySearchPreorderTraversal(root->right);
    }
    return;
}

int main() {

    BinaryTree* root = new BinaryTree(10,
    new BinaryTree(5,
        new BinaryTree(2),
        new BinaryTree(7)
    ),
    new BinaryTree(15)
);

    binarySearchPreorderTraversal(root);

    return 0;
}
