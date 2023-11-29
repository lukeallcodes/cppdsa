#include <iostream>
using namespace std;

// Define a node structure for the stack
struct Node {
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Define the Stack class
class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    // Function to add an element to the stack
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    // Function to remove and return the top element of the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return -1; // Or throw an exception
        }

        Node* temp = top;
        top = top->next;
        int poppedValue = temp->data;
        delete temp;
        return poppedValue;
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Function to get the top element of the stack
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1; // Or throw an exception
        }
        return top->data;
    }

    // Function to display the stack
    void display() {
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Main function
int main() {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Stack: ";
    stack.display();

    cout << "Popped: " << stack.pop() << endl;
    cout << "Stack after pop: ";
    stack.display();

    cout << "Top element: " << stack.peek() << endl;

    return 0;
}
