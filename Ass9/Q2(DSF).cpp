#include <iostream>
using namespace std;

int a[10][10], visited[10];
int n;

void dfs(int data) {
    cout << data << " ";
    visited[data] = 1;
    for (int i = 0; i < n; i++) {
        if (a[data][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}

int main() {
    int i, j, start;
    cin >> n;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            cin >> a[i][j];
    for (i = 0; i < n; i++)
        visited[i] = 0;
    cin >> start;
    dfs(start);
    return 0;
}