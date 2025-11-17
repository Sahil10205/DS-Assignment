#include <iostream>
using namespace std;

int main() {
    int a[10][10], visited[10], q[10];
    int n, i, j, start;
    int left = 0, right = 0;

    cin >> n;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            cin >> a[i][j];

    for (i = 0; i < n; i++)
        visited[i] = 0;

    cin >> start;
    q[right++] = start;
    visited[start] = 1;

    while (left < right) {
        int data = q[left++];
        cout << data << " ";
        for (i = 0; i < n; i++) {
            if (a[data][i] == 1 && visited[i] == 0) {
                q[right++] = i;
                visited[i] = 1;
            }
        }
    }

    return 0;
}