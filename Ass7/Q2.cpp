#include <iostream>
using namespace std;

int main() {
    cout << "Enter the number of elements in the array: ";
    int n;
    cin >> n;

    int arr[100];
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "The given array is: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    for (int i = 0; i < n / 2; i++) {
        int index1 = i;
        int index2 = i;
        for (int j = i; j < n - i; j++) {
            if (arr[j] < arr[index1]) {
                index1 = j;
            }
            if (arr[j] > arr[index2]) {
                index2 = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[index1];
        arr[index1] = temp;

        if (index2 == i) {
            index2 = index1;
        }

        temp = arr[n - i - 1];
        arr[n - i - 1] = arr[index2];
        arr[index2] = temp;
    }

    cout << endl << "Sorted array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
