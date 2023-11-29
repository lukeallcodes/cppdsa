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

    // Helper function for pre-order traversal
    void preOrderTraversal(TreeNode* node) {
        if (node) {
            cout << node->value << " ";
            preOrderTraversal(node->left);
            preOrderTraversal(node->right);
        }
    }

    // Helper function for post-order traversal
    void postOrderTraversal(TreeNode* node) {
        if (node) {
            postOrderTraversal(node->left);
            postOrderTraversal(node->right);
            cout << node->value << " ";
        }
    }

    // Helper function to find the minimum value node
    TreeNode* findMinValueNode(TreeNode* node) {
        TreeNode* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    // Helper function for deletion
    TreeNode* deleteNode(TreeNode* root, int value) {
        if (root == nullptr) return root;

        if (value < root->value) {
            root->left = deleteNode(root->left, value);
        } else if (value > root->value) {
            root->right = deleteNode(root->right, value);
        } else {
            // Node with only one child or no child
            if (root->left == nullptr) {
                TreeNode* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }

            // Node with two children: Get the inorder successor (smallest in the right subtree)
            TreeNode* temp = findMinValueNode(root->right);

            // Copy the inorder successor's content to this node
            root->value = temp->value;

            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->value);
        }
        return root;
    }

    // Helper function for searching
    bool search(TreeNode* root, int value) {
        if (root == nullptr) return false;

        if (root->value == value) return true;

        if (value < root->value)
            return search(root->left, value);
        else
            return search(root->right, value);
    }

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int value) {
        root = insert(root, value);
    }

    void remove(int value) {
        root = deleteNode(root, value);
    }

    bool contains(int value) {
        return search(root, value);
    }

    void inOrder() {
        inOrderTraversal(root);
        cout << endl;
    }

    void preOrder() {
        preOrderTraversal(root);
        cout << endl;
    }

    void postOrder() {
        postOrderTraversal(root);
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

    cout << "In-order Traversal: ";
    bst.inOrder();

    cout << "Pre-order Traversal: ";
    bst.preOrder();

    cout << "Post-order Traversal: ";
    bst.postOrder();

    if (bst.contains(10)) {
        cout << "10 found in the BST." << endl;
    } else {
        cout << "10 not found in the BST." << endl;
    }

    bst.remove(10);
    cout << "In-order Traversal after deleting 10: ";
    bst.inOrder();

    return 0;
}
