#include <iostream>
using namespace std;

// Define a node structure for the doubly linked list
struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

// Define the Doubly Linked List class
class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() : head(nullptr) {}

    // Function to add a node at the end
    void append(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

    // Function to delete a node by value
    void deleteNode(int value) {
        if (head == nullptr) return;

        Node* temp = head;
        if (temp->data == value) {
            head = head->next;
            if (head != nullptr) head->prev = nullptr;
            delete temp;
            return;
        }

        while (temp != nullptr && temp->data != value) {
            temp = temp->next;
        }

        if (temp == nullptr) return; // Value not found

        if (temp->next != nullptr) temp->next->prev = temp->prev;
        if (temp->prev != nullptr) temp->prev->next = temp->next;

        delete temp;
    }

    // Function to display the list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "null" << endl;
    }
};

// Main function
int main() {
    DoublyLinkedList list;
    list.append(10);
    list.append(20);
    list.append(30);

    cout << "Doubly Linked List: ";
    list.display();

    list.deleteNode(20);
    cout << "Doubly Linked List after deleting 20: ";
    list.display();

    return 0;
}
