#include <iostream>

using namespace std;

class BinaryTree {
public: 
    int val;
    BinaryTree* left = nullptr;
    BinaryTree* right = nullptr;

    BinaryTree(int value, BinaryTree* l = nullptr, BinaryTree* r = nullptr) {
        val = value;
        left = l;
        right = r;
    }

    void printTreeInOrder() {
        if (left != nullptr) {
            left->printTreeInOrder();
        } 

        cout << val << " ";

        if (right != nullptr) {
            right->printTreeInOrder();
        }
    }
};

int countNodes(BinaryTree* root) {
    if (root == nullptr) {
        return 0;
    } else {
        int leftCount = countNodes(root->left);
        int rightCount = countNodes(root->right);
        return 1 + leftCount + rightCount;
    }
}

int main() {

    BinaryTree* root = new BinaryTree(
        5,
        new BinaryTree(3, new BinaryTree(1), new BinaryTree(4)),
        new BinaryTree(7, new BinaryTree(6), new BinaryTree(8))
    );



    if (root != nullptr) {
        root->printTreeInOrder();
    }
    cout << endl;

    cout << "total nodes: " << countNodes(root);

    return 0;
}
