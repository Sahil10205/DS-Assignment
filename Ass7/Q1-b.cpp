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

    for (int i = 0; i < n 
    ; i++) {
        for (int j = i ; j > 0; j--) {
            if (arr[j] < arr[j-1]) {
                int temp = arr[j];
        arr[j] = arr[j-1];
        arr[j-1] = temp;
            }
        }
    }

    cout << endl << "Sorted array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}