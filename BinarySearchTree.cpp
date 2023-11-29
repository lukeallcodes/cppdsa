#include <iostream>
using namespace std;

// Define a node structure for the binary search tree
struct TreeNode {
    int value;
    TreeNode *left, *right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Define the Binary Search Tree class
class BinarySearchTree {
private:
    TreeNode* root;

    // Helper function for insertion
    TreeNode* insert(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }

        if (value < node->value) {
            node->left = insert(node->left, value);
        } else {
            node->right = insert(node->right, value);
        }

        return node;
    }

    // Helper function for in-order traversal
    void inOrderTraversal(TreeNode* node) {
        if (node) {
            inOrderTraversal(node->left);
            cout << node->value << " ";
            inOrderTraversal(node->right);
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    // Function to insert a value into the BST
    void insert(int value) {
        root = insert(root, value);
    }

    // Function for in-order traversal of the BST
    void inOrder() {
        inOrderTraversal(root);
        cout << endl;
    }
};

// Main function
int main() {
    BinarySearchTree bst;
    bst.insert(15);
    bst.insert(10);
    bst.insert(20);
    bst.insert(5);
    bst.insert(16);

    cout << "In-order Traversal of BST: ";
    bst.inOrder();

    return 0;
}
