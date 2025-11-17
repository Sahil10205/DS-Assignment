#include <iostream>
using namespace std;

int main() {
    int a[10][10], dist[10], visited[10];
    int n, i, j, start, min, next;

    cin >> n;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            cin >> a[i][j];

    cin >> start;

    for (i = 0; i < n; i++) {
        dist[i] = 9999;
        visited[i] = 0;
    }

    dist[start] = 0;

    for (int count = 0; count < n - 1; count++) {
        min = 9999;
        for (i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                next = i;
            }
        }

        visited[next] = 1;

        for (i = 0; i < n; i++) {
            if (!visited[i] && a[next][i] && dist[next] + a[next][i] < dist[i]) {
                dist[i] = dist[next] + a[next][i];
            }
        }
    }

    for (i = 0; i < n; i++)
        cout << "Distance from " << start << " to " << i << " is " << dist[i] << endl;

    return 0;
}