#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
private:
    vector<int> heap;

    // Function to heapify the tree
    void heapify(int i) {
        int smallest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < heap.size() && heap[left] < heap[smallest])
            smallest = left;

        if (right < heap.size() && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapify(smallest);
        }
    }

public:
    // Function to insert an element into the priority queue
    void insert(int element) {
        heap.push_back(element);
        int i = heap.size() - 1;

        // Adjusting the heap
        while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
            swap(heap[i], heap[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    // Function to remove the element with the highest priority (lowest value)
    int remove() {
        if (heap.size() == 0) {
            cout << "Queue is empty" << endl;
            return -1; // Or throw an exception
        }

        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();

        heapify(0);
        return root;
    }

    // Function to get the element with the highest priority without removing it
    int peek() {
        if (heap.size() == 0) {
            cout << "Queue is empty" << endl;
            return -1; // Or throw an exception
        }
        return heap[0];
    }

    // Function to display the priority queue
    void display() {
        for (int i : heap) {
            cout << i << " ";
        }
        cout << endl;
    }
};

// Main function
int main() {
    PriorityQueue pq;
    pq.insert(30);
    pq.insert(20);
    pq.insert(10);

    cout << "Priority Queue: ";
    pq.display();

    cout << "Removed Element: " << pq.remove() << endl;
    cout << "Priority Queue after removal: ";
    pq.display();

    cout << "Top Element: " << pq.peek() << endl;

    return 0;
}
