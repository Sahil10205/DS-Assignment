#include <iostream>
using namespace std;

class MaxHeap {
    int heap[100];
    int size;

public:
    MaxHeap() {
        size = 0;
    }

    void insert(int value) {
        heap[size] = value;
        int i = size;
        size++;

        while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
            int temp = heap[i];
            heap[i] = heap[(i - 1) / 2];
            heap[(i - 1) / 2] = temp;
            i = (i - 1) / 2;
        }
    }

    int extractMax() {
        if (size == 0) return -1;
        int maxVal = heap[0];
        heap[0] = heap[size - 1];
        size--;

        int i = 0;
        while (true) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int largest = i;

            if (left < size && heap[left] > heap[largest]) largest = left;
            if (right < size && heap[right] > heap[largest]) largest = right;

            if (largest == i) break;

            int temp = heap[i];
            heap[i] = heap[largest];
            heap[largest] = temp;
            i = largest;
        }

        return maxVal;
    }

    int getMax() {
        if (size == 0) return -1;
        return heap[0];
    }

    bool isEmpty() {
        return size == 0;
    }
};

int main() {
    MaxHeap pq;
    pq.insert(40);
    pq.insert(20);
    pq.insert(60);
    pq.insert(10);
    pq.insert(50);

    while (!pq.isEmpty()) {
        cout << pq.extractMax() << " ";
    }

    return 0;
}