#include <iostream>
using namespace std;

int main() {
    int n, a[10][10], visited[10];
    int i, j, u, v, min, cost = 0;

    cin >> n;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            cin >> a[i][j];

    for (i = 0; i < n; i++)
        visited[i] = 0;

    visited[0] = 1;

    for (int count = 0; count < n - 1; count++) {
        min = 9999;
        for (i = 0; i < n; i++) {
            if (visited[i]) {
                for (j = 0; j < n; j++) {
                    if (!visited[j] && a[i][j] && a[i][j] < min) {
                        min = a[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        visited[v] = 1;
        cost += min;
        cout << u << " " << v << " " << min << endl;
    }

    cout << "Total cost: " << cost << endl;
    return 0;
}