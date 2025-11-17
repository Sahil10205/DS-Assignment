#include <iostream>
using namespace std;

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify(int arr[], int n, int i, bool maxHeap) {
    int extreme = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (maxHeap) {
        if (l < n && arr[l] > arr[extreme]) extreme = l;
        if (r < n && arr[r] > arr[extreme]) extreme = r;
    } else {
        if (l < n && arr[l] < arr[extreme]) extreme = l;
        if (r < n && arr[r] < arr[extreme]) extreme = r;
    }

    if (extreme != i) {
        swap(&arr[i], &arr[extreme]);
        heapify(arr, n, extreme, maxHeap);
    }
}

void heapsort(int arr[], int n, bool increasing) {
    bool maxHeap = increasing;

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, maxHeap);

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0, maxHeap);
    }
}

int main() {
    int arr[] = {40, 10, 30, 50, 20, 60};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapsort(arr, n, true);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";

    heapsort(arr, n, false);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";

    return 0;
}