#include <iostream>
#include <vector>

using namespace std;

class BinaryTree {
public:
    int val;
    BinaryTree* left;
    BinaryTree* right;

    BinaryTree(int value, BinaryTree* l = nullptr, BinaryTree* r = nullptr) {
        val = value;
        left = l;
        right = r;
    }
};

bool binarySearch(BinaryTree* root, int val) {
    if (root == nullptr) {
        return false;
    }

    if (root->val == val) {
        return true;
    }

    return binarySearch(root->left, val) || binarySearch(root->right, val);
}


int main() {
    // Example usage
    BinaryTree* root = new BinaryTree(10,
        new BinaryTree(5,
            new BinaryTree(2,
                new BinaryTree(1),
                new BinaryTree(3)
            ),
            new BinaryTree(7)
        ),
        new BinaryTree(15,
            new BinaryTree(12,
                new BinaryTree(11),
                nullptr
            ),
            new BinaryTree(20)
        )
    );


    cout << (binarySearch(root, 12) ? "Found" : "Not Found") << endl;
    cout << (binarySearch(root, 7) ? "Found" : "Not Found") << endl;
    cout << (binarySearch(root, 17) ? "Found" : "Not Found") << endl;
    cout << (binarySearch(root, 20) ? "Found" : "Not Found") << endl;
    cout << (binarySearch(root, 100) ? "Found" : "Not Found") << endl;
    cout << (binarySearch(root, 3) ? "Found" : "Not Found") << endl;


    return 0;
}
