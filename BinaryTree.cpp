#include <iostream>
using namespace std;

// Define a node structure for the binary tree
struct Node {
    int data;
    Node *left, *right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Define the Binary Tree class
class BinaryTree {
private:
    Node* root;

    // Helper function for insertion in the binary tree
    Node* insertNode(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insertNode(node->left, value);
        } else {
            node->right = insertNode(node->right, value);
        }

        return node;
    }

    // Helper function for in-order traversal
    void inOrderTraversal(Node* node) {
        if (node != nullptr) {
            inOrderTraversal(node->left);
            cout << node->data << " ";
            inOrderTraversal(node->right);
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    // Function to insert a value in the binary tree
    void insert(int value) {
        root = insertNode(root, value);
    }

    // Function to perform in-order traversal of the binary tree
    void inOrder() {
        inOrderTraversal(root);
        cout << endl;
    }
};

// Main function
int main() {
    BinaryTree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);

    cout << "In-order Traversal: ";
    tree.inOrder();

    return 0;
}
